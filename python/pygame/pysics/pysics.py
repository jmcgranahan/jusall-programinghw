import os, sys, pygame, pysicsObj, pysicsWorld, random
from pygame.locals import *
#from numpy import random
from math import sin, cos, radians
from vec2d import vec2d


def main():

	# sets up pygame
	pygame.init()
	pygame.display.set_caption("Pysics")
	screen = pygame.display.set_mode((500,590))
	clock = pygame.time.Clock()
	world = pysicsWorld.world(screen)
	lastdraw = 0
	

	circle = pysicsObj.object(screen, world, 'player', 10,'circle')
	circle.pos = vec2d(320, 240)
	circle.size = 5
	circle.mass = 1
	
	
	for i in range(50):
		circle = pysicsObj.object(screen, world, 'circle'+str(i), 10, 'circle')
		circle.pos = vec2d(random.randint(0,screen.get_width()),random.randint(0,screen.get_height()))
		circle.vel = vec2d(screen.get_size())/2 - circle.pos 
	
	
	circle2 = pysicsObj.object(screen, world, 'circle2', 10,'circle')
	circle2.pos = vec2d(320, 0)
	circle2.vel = vec2d(0,0)
	circle2.size = 5
	circle2.mass = 1
	
	# game loop
	while 1:

		# cap the framerate at 60 frames per second
		elapsed_time = clock.tick(60)
		lastdraw += elapsed_time
		circle = world.objects[0]
		
		# handle user input
		for e in pygame.event.get():
			if e.type == QUIT or (e.type == KEYDOWN and e.key == K_ESCAPE):
				pygame.quit()
				return

		# move the player with the arrow keys
		key = pygame.key.get_pressed()
		if key[K_LEFT]:
			circle.applyforce(vec2d(-100,0))
		if key[K_RIGHT]:
			circle.applyforce(vec2d(100,0))
		if key[K_UP]:
			circle.applyforce(vec2d(0,-200))
		if key[K_DOWN]:
			circle.applyforce(vec2d(0,100))
		if not key[K_DOWN] and  not key[K_LEFT] and not key[K_RIGHT] and not key[K_UP]:
			circle.vel = 0
		circle2.acc = vec2d(0,10)
		# draw everything
		
		
		world.update(elapsed_time)
		if lastdraw > 15:
			world.draw()
			lastdraw = 0
		pygame.display.flip()

if __name__ == "__main__":
	main()
