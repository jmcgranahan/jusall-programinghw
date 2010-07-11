import os, sys
from random import randint, choice
from math import sin, cos, radians
import pygame
from pygame.sprite import Sprite
from pygame.locals import *
from vec2d import vec2d
import pysicsObj
import pysicsWorld

def main():

	# sets up pygame
	pygame.init()
	pygame.display.set_caption("Rectangle Collision Correction")
	screen = pygame.display.set_mode((640, 480))
	clock = pygame.time.Clock()
	world = pysicsWorld.world(screen)
	player = pysicsObj.object(screen,world,'rect')
	player.pos = vec2d(320, 240)
	player.box = 10
	
	
	# game loop
	while 1:

		# cap the framerate at 60 frames per second
		elapsed_time = clock.tick(60)
		
		# handle user input
		for e in pygame.event.get():
			if e.type == QUIT or (e.type == KEYDOWN and e.key == K_ESCAPE):
				pygame.quit()
				return

		# move the player rect around if you press the arrow keys
		key = pygame.key.get_pressed()
		if key[K_LEFT]:
			player.vel += vec2d(-10,0)
		if key[K_RIGHT]:
			player.vel += vec2d(10,0)
		if key[K_UP]:
			player.vel += vec2d(0,-10)
		if key[K_DOWN]:
			player.vel += vec2d(0,10)
		
		# draw everything
		screen.fill((0, 0, 0))
		world.update(elapsed_time)
		pygame.display.flip()

if __name__ == "__main__":
	main()