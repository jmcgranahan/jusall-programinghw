from random import randint, choice
from math import sin, cos, radians, copysign, floor
from vec2d import vec2d
import pygame
from pygame.locals import *

class object:

	def __init__(self, screen, world, name, type = None):
		self.screen = screen
		self.world = world
		self.pos  = vec2d(-1,-1)
		self.box = vec2d(0,0)
		self.vel = vec2d(0,0)
		self.mass = 0
		self.acc = vec2d(0,0)
		self.frozen = 0
		self.name = name
		self.collided = []
		
		if type:
			self.type = type
		self.index = self.world.append(self)
		
	def move(self ,time_passed , x = None, y = None):
		if x and y:
			self.pos += vec2d(x,y)
			if self.screen.get_rect().collidepoint(self.pos) == 0:
				self.pos -= vec2d(x,y)
				
		elif self.frozen == 0 :
			time_passed_ms = time_passed * .001
			self.vel += self.acc * time_passed_ms * 5
			self.acc = vec2d(0,0)
			floor(self.vel[0])
			floor(self.vel[1])
			self.pos[0] += self.vel[0]* time_passed_ms
			'''			
			collide = self.world.check_collision(self)
			if collide:
				obstruction = self.world.objects[collide]
				if obstruction.frozen:
					while self.world.check_collision(self):
						self.pos[0] -= copysign(1,self.vel[0])
					self.vel[0] = 0
				else:
					while self.world.check_collision(self):
						self.pos[0] -= copysign(1,self.vel[0])
					self.vel[0] = (self.vel[0]*(self.mass - obstruction.mass) + 2*obstruction.mass*obstruction.vel[0])/self.mass+obstruction.mass
					obstruction.vel[0] = (obstruction.vel[0]*(obstruction.mass - self.mass) + 2*self.mass*self.vel[0])/self.mass+obstruction.mass
			'''			
			

			self.pos[1] += self.vel[1]* time_passed_ms
			'''
			collide = self.world.check_collision(self)
			if collide:
				obstruction = self.world.objects[collide]
				if obstruction.frozen:
					while self.world.check_collision(self):
						self.pos[1] -= copysign(1,self.vel[1])
					self.vel[1] = 0
				else:
					while self.world.check_collision(self):
						self.pos[1] -= copysign(1,self.vel[1])
					self.vel[1] = (self.vel[1]*(self.mass - obstruction.mass) + 2*obstruction.mass*obstruction.vel[1])/self.mass+obstruction.mass
					obstruction.vel[1] = (obstruction.vel[1]*(obstruction.mass - self.mass) + 2*self.mass*self.vel[1])/self.mass+obstruction.mass
			'''
					
				
	def applyforce(self,force):
		if self.frozen:return 0
		self.acc += force/self.mass
		
		
	def update(self, time_passed):
		self.move(time_passed)
		return

	def draw(self):
		if self.type == 'square' and self.name is not 'player':
			pygame.draw.rect(self.screen, (200, 100, 100), Rect(self.pos[0]-self.box/2,self.pos[1]-self.box/2,self.box,self.box))
		if self.type == 'rect':
			pygame.draw.rect(self.screen, (255, 255, 255), Rect(self.pos[0],self.pos[1],self.box[0],self.box[1]))
		if self.name == 'player':
			pygame.draw.rect(self.screen, (255, 255, 255), Rect(self.pos[0]-self.box/2,self.pos[1]-self.box/2,self.box,self.box))
			print(self.pos)
		
	def rect(self):
		if self.type == 'square':
			return Rect(self.pos[0]-self.box/2,self.pos[1]-self.box/2,self.box,self.box)
		if self.type == 'rect':
			return Rect(self.pos[0],self.pos[1],self.box[0],self.box[1])	