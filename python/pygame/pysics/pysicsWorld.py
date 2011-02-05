from math import sin, cos, radians, copysign, floor, sqrt
from vec2d import vec2d 
import pygame
from pygame.locals import *
from pysicsObj import object
import pprint


class world:
	
	def __init__(self, screen):
		self.screen = screen
		self.objects = []
		self.foundCollisions = []
		self.timeScale = 1
	
	def append(self,object):
		self.objects.append(object)
		return len(self.objects)-1
	
	def update(self, time_passed):
		self.foundCollisions = []
		for object in self.objects:
			object.color = pygame.Color(255,255,255)
			if object.frozen == 0 :
				self.preMove(object, time_passed)
				#for collision in self.foundCollisions:
				#	self.objects[collision[0]].color = pygame.Color(255,100,100)
				self.postMove(object, time_passed)
		return
				
	def preMove(self , object, time_passed , x = None, y = None):
		if x and y:
			object.pos = vec2d(x,y)
			if object.screen.get_rect().collidepoint(self.pos) == 0:
				object.pos -= vec2d(x,y)
				
		elif object.frozen == 0 :
			time_passed_sec = time_passed * .001
			object.vel += object.acc * time_passed_sec
			object.frameVel = object.vel * time_passed_sec
			object.acc = vec2d(0,0)
			#floor(object.vel[0])
			#floor(object.vel[1])
			
			self.collisionCheck(object)
			
			
			
			
	def postMove(self, object, time_passed):
			object.pos[0] += object.vel[0]* time_passed/1000 * self.timeScale	
			object.pos[1] += object.vel[1]* time_passed/1000 * self.timeScale
			
			if object.pos[0] < object.size :
				object.pos[0] = object.size
				object.vel[0] *= -1
			if object.pos[0] > self.screen.get_width()-object.size :
				object.pos[0] = self.screen.get_width()-object.size
				object.vel[0] *= -1	
			if object.pos[1] < object.size :
				object.pos[1] = object.size
				object.vel[1] *= -1
			if object.pos[1] > self.screen.get_height()-object.size : 
				object.pos[1] = self.screen.get_height()-object.size
				object.vel[1] *= -1				
			
	def collisionCheck(self,objecta):
		collide = []
		for objectb in self.objects:
			#print 'testing index: '+str(objecta.index)+' and index: '+ str(objectb.index)
			if objectb.index <= objecta.index:
				#print ' same index break'
				continue
				
			distance = objecta.pos.get_distance(objectb.pos)
			radii = objecta.size + objectb.size
			distance -= radii
			mag = objecta.frameVel.get_length()
			#print str(distance)+' '+str(mag)
			if mag < distance:
				#print "mag < dist"
				continue		
				
			normvel = objecta.frameVel.normalized()
			distvec = objectb.pos - objecta.pos
			dot = normvel.dot(distvec)
			#if dot <= 0 and mag != 0:
				#print "dot < 0"
			#	continue
				
			aftermovetest = (distance * distance) - (dot * dot)
			radiisquared = radii * radii
			if aftermovetest >= radiisquared:
				#print "aftermove > radii2"
				continue
				
			thirdside = radiisquared - aftermovetest
			if thirdside < 0:
				#print "triangulation break"
				continue
				
			movedist = dot - sqrt(thirdside)
			if mag < movedist :
				#print "mag  < movedist"
				continue
			#objecta.vel.normalized
			#objecta.vel * distnace
			
			self.foundCollisions.append((objecta.index,objectb.index))
			objecta.collided = 1
			objectb.collided = 1

		
			
	
	def draw(self):
		self.screen.fill((0,0,0))
		for object in self.objects:
			object.draw()
