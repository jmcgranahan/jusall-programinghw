from random import randint, choice
from math import sin, cos, radians
from vec2d import vec2d
import pygame
from pygame.locals import *


class world:

	def __init__(self, screen):
		self.screen = screen
		self.objects = []
		self.borders = [
			Rect(0,-5,screen.get_width(),10),
			Rect(0,screen.get_height()-5,screen.get_width(),10),
			Rect(-5,0,10,screen.get_height()),
			Rect(screen.get_width()-5,0,10,screen.get_height()),
			]
	
	def append(self,object):
		self.objects.append(object)
	
	def update(self, time_passed):
		for object in self.objects:
			object.update(time_passed)
		for border in self.borders:
			pygame.draw.rect(self.screen, (255, 255, 255), border)
		return
		
	def check_world_collision(self,object):
		for border in self.borders:
			if border.colliderect(object):
				return 1