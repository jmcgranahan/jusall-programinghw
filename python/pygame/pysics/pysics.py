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
	player = pysicsObj.object(screen,world, 'player', 'square')
	player.pos = vec2d(320, 240)
	player.box = 10
	player.mass = 10
	lastdraw = 0
	
	for i in range(2):
		object = pysicsObj.object(screen,world, 'box', 'square')
		object.pos = vec2d(250, 240+i*20)
		object.box = 10
		object.mass = 10
	
	# game loop
	while 1:

		# cap the framerate at 60 frames per second
		elapsed_time = clock.tick(100)
		lastdraw += elapsed_time
		
		# handle user input
		for e in pygame.event.get():
			if e.type == QUIT or (e.type == KEYDOWN and e.key == K_ESCAPE):
				pygame.quit()
				return

		# move the player rect around if you press the arrow keys
		key = pygame.key.get_pressed()
		if key[K_LEFT]:
			player.applyforce(vec2d(-100,0))
		if key[K_RIGHT]:
			player.applyforce(vec2d(100,0))
		if key[K_UP]:
			player.applyforce(vec2d(0,-200))
		if key[K_DOWN]:
			player.applyforce(vec2d(0,100))
		
		# draw everything
		
		world.update(elapsed_time)
		if lastdraw > 30:
			screen.fill((0, 0, 0)) 	
			world.draw()
			lastdraw = 0
		pygame.display.flip()

if __name__ == "__main__":
	main()