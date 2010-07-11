from random import randint, choice
from math import sin, cos, radians
from vec2d import vec2d
import pygame
from pygame.locals import *


class object:

	def __init__(self, screen, world, type = None):
		self.screen = screen
		self.world = world
		self.pos  = vec2d(-1,-1)
		self.box = vec2d(0,0)
		self.vel = vec2d(0,0)
		self.acc = vec2d(0,9.8)
		self.frozen = 0
		
		if type:
			self.type = type
		self.world.append(self)
		
	def move(self,time_passed , x = None, y = None):
		if x and y:
			self.pos += vec2d(x,y)
			if self.screen.get_rect().collidepoint(self.pos) == 0:
				self.pos -= vec2d(x,y)
				
		elif self.vel != 0:
			self.vel += self.acc*time_passed/1000
			
			self.pos[0] += self.vel[0]*time_passed/1000
			
			if self.world.check_world_collision(Rect(self.pos[0]-self.box/2,self.pos[1]-self.box/2,self.box,self.box)):
				
				self.pos[0] -= self.vel[0]*time_passed/1000
				self.vel[0] = 0
				
			self.pos[1] += self.vel[1]*time_passed/1000
			
			if self.world.check_world_collision(Rect(self.pos[0]-self.box/2,self.pos[1]-self.box/2,self.box,self.box)):
			
				self.pos[1] -= self.vel[1]*time_passed/1000
				self.vel[1] = 0
		
	
	def update(self, time_passed):
		self.move(time_passed)
		self.draw()
		return

	def draw(self):
		if self.type == 'rect':
			pygame.draw.rect(self.screen, (255, 255, 255), Rect(self.pos[0]-self.box/2,self.pos[1]-self.box/2,self.box,self.box))
			

	"""
	# Move the player and handle collisions
def move_player(x_speed, y_speed):
    
    # Move the player's x axis and handle collisions
    move_axis_and_check(player_rect, x_speed, 0)
    
    # Move the player's y axis and handle collisions
    move_axis_and_check(player_rect, 0, y_speed) 

# Move a single axis and perform collision checks
def move_axis_and_check(rect, x_speed, y_speed):
    rect.x += x_speed
    rect.y += y_speed
    
    if x_speed != 0 and y_speed != 0:
        print "WARNING: Moving two axes at the same time will produce collision glitches"
  
    # loop through the tiles
    for tile in tiles:
  
        # If the player rect collides with a tile, correct the collision
        if rect.colliderect(tile):
            
            #moving right, so set right of rect to left of tile
            if x_speed > 0: 
                rect.right = tile.left
                
            #moving left, so set left of rect to right of tile
            elif x_speed < 0:
                rect.left = tile.right

            #moving down, so set bottom of rect to top of tile
            if y_speed > 0:
                rect.bottom = tile.top
            
            #moving up, so set top of rect to bottom of tile
            elif y_speed < 0:
                rect.top = tile.bottom
	"""