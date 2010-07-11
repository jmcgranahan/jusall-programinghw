import os, sys
from random import randint, choice
from math import sin, cos, radians

import pygame
from pygame.sprite import Sprite

from vec2d import vec2d


class BotC	(Sprite):

	def __init__(self, screen, SCREEN_WIDTH, SCREEN_HEIGHT, it,index):
		Sprite.__init__(self)
		self.screen = screen
		self.index = index
		if it == 1:
			self.speed = .11
			img_filename = 'It.png'
			self.it = 1

		else:
			self.speed = .1
			img_filename = 'NotIt.png'
			self.it = 1
			
		self.it = it
		self.base_image = pygame.image.load(img_filename).convert_alpha()
		self.image = self.base_image
		self.pos = vec2d(randint(0, SCREEN_WIDTH), randint(0, SCREEN_HEIGHT))		
		self.direction = vec2d(choice([-1, 1]), choice([-1, 1])).normalized() 
		
	def update(self, Bots, time_passed):
		self._change_direction(Bots,time_passed)
		self.image = pygame.transform.rotate(
			self.base_image, -self.direction.angle)
		
		displacement = vec2d(    
			self.direction.x * self.speed * time_passed,
			self.direction.y * self.speed * time_passed)
        
		self.pos += displacement
		
		for Bot in Bots:
			if self.index != Bot.index:
				if self.pos.get_distance(Bot.pos) < 15:
					self.pos -= displacement
					if self.it:
						self.tag(Bots,Bot.index)
		
		self.image_w, self.image_h = self.image.get_size()
		bounds_rect = self.screen.get_rect().inflate(
			-self.image_w, -self.image_h)
        
		if self.pos.x < bounds_rect.left:
			self.pos.x = bounds_rect.left
			self.direction.x *= -1
		elif self.pos.x > bounds_rect.right:
			self.pos.x = bounds_rect.right
			self.direction.x *= -1
		elif self.pos.y < bounds_rect.top:
			self.pos.y = bounds_rect.top
			self.direction.y *= -1
		elif self.pos.y > bounds_rect.bottom:
			self.pos.y = bounds_rect.bottom
			self.direction.y *= -1

	
	def blitme(self):
		draw_pos = self.image.get_rect().move(
			self.pos.x - self.image_w / 2, 
			self.pos.y - self.image_h / 2)
		self.screen.blit(self.image, draw_pos)
           
	
	_counter = 0
	
	def _it(self):
		return self.it	
	def _pos(self):
		return self.pos
		
	def tag(self,Bots,BotI):
		if Bots[BotI].taged(Bots,self.index):
			self.speed = .1
			self.base_image = pygame.image.load('NotIt.png').convert_alpha()
			self.it = 0
			return 1
		else:
			return 0
		
	def taged(self,Bots,BotI):
		if self.pos.get_distance(Bots[BotI].pos) < 20:
			self.speed = 0.0
			self.base_image = pygame.image.load('It.png').convert_alpha()
			self.it = 1
			self.counter = -500
			return 1
		else:
			return 0

	
	
	def _change_direction(self, Bots, time_passed):
		self._counter += time_passed
		if self.it != 1:
			if self._counter > randint(100, 300):
				self.direction.rotate(45 * randint(-1, 1))
				for Bot in Bots:
					if Bot.it:
						if Bot.pos.get_distance(self.pos) < 100:
							self.direction = (self.pos - Bot.pos).normalized() 
				self._counter = 0
		else:
			if self._counter > 1000:
				self.speed = .11
				self._counter = 0
			closest = 9999
			for Bot in Bots:
				if self.pos.get_distance(Bot.pos) < closest:
					if Bot.index != self.index:
						self.direction = (Bot.pos - self.pos).normalized() 
						closest = self.pos.get_distance(Bot.pos)
    

def run_game():
	# Game parameters
	SCREEN_WIDTH, SCREEN_HEIGHT = 400, 400
	BG_COLOR = 0, 0, 0
	N_BOTS = 8

	pygame.init()
	screen = pygame.display.set_mode(
		(SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
	clock = pygame.time.Clock()

	Bots = []    
	for i in range(N_BOTS-1):
		Bots.append(BotC(screen,SCREEN_WIDTH, SCREEN_HEIGHT,0,i))
	Bots.append(BotC(screen,SCREEN_WIDTH, SCREEN_HEIGHT,1,N_BOTS-1))

	while True:	
		time_passed = clock.tick(50)
        
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				exit_game()
				
		screen.fill(BG_COLOR)
        
		for Bot in Bots:
			Bot.update(Bots,time_passed)
			Bot.blitme()

		pygame.display.flip()


def exit_game():
	sys.exit()


run_game()

