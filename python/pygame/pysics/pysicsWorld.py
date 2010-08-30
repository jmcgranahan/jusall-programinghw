from random import randint, choice
from math import sin, cos, radians, copysign
from vec2d import vec2d
import pygame
from pygame.locals import *
from pysicsObj import object


class world:
	

	def __init__(self, screen):
		self.screen = screen
		self.objects = []
		borders = [
			Rect(0,-5,screen.get_width(),10),
			Rect(0,screen.get_height()-5,screen.get_width(),10),
			Rect(-5,5,10,screen.get_height()-10),
			Rect(screen.get_width()-5,5,10,screen.get_height()-10),
			]
		for border in borders:
			borderObj = object(screen, self, 'world','rect')
			borderObj.pos = vec2d(border.x, border.y)
			borderObj.box = vec2d(border.w, border.h)
			borderObj.frozen = 1
	
	def append(self,object):
		self.objects.append(object)
		return len(self.objects)-1
	
	def update(self, time_passed):
		for object in self.objects:
			if object.frozen == 0 :
				object.update(time_passed)
		self.handle_collisions()
		return
		
	def handle_collisions(self):
		allcollisions = []
		for object in self.objects:
			for collision in self.check_collisions(object):
				if collision > object.index : allcollisions.append((object.index,collision))
		#print allcollisions
		for collision in allcollisions:
			self.collide(self.objects[collision[0]],self.objects[collision[1]])
	
	def collide(self, object1, object2):
		object1vel = object1.vel
		object2vel = object2.vel
		#object1.vel = vec2d(0,0)
		#object2.vel = vec2d(0,0)
		
		while object1.rect().colliderect(object2.rect()):
			if object1.frozen == 0:
				object1.pos[0]-= max(1, min(-1, object1vel[0]))
				object1.pos[1]-= max(1, min(-1, object1vel[1]))
			if object2.frozen == 0:
				object2.pos[0]-= max(1, min(-1, object2vel[0]))
				object2.pos[1]-= max(1, min(-1, object2vel[1]))

		
		impulse = vec2d(
			((object1vel[0] * object1.mass) + (object2vel[0] * object2.mass)),
			((object1vel[1] * object1.mass) + (object2vel[1] * object2.mass))
			)
		impulse /= 2
		
		if object1vel.get_length() > object2vel.get_length() : 
			object1.applyforce(-1*impulse)
			object2.applyforce(impulse)
		else:
			object1.applyforce(impuse)
			object2.applyforce(-1*impuse)
		return
			
		
	def check_collisions(self,caller):
		collisions = []
		for object in self.objects:
			if object.index != caller.index:
				if caller.rect().colliderect(object.rect()):
					collisions.append(object.index)
		return collisions
				
	def draw(self):
		for object in self.objects:
			object.draw()