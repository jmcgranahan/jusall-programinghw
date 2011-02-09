#!/usr/bin/python
import pygame, time
from pygame.locals import *
import httplib

def main():
	pygame.init()
	pygame.display.set_caption("boxee remote")
	screen = pygame.display.set_mode((100,100))
	background = pygame.Surface(screen.get_size())
	background = background.convert()
	background.fill((0, 0, 0))
	http = httplib.HTTPConnection("boxee",8800)
	font = pygame.font.Font(None, 12)
	rfont = font.render("",1,(255,255,255))
	text = ""
	

	while 1:
		background.fill((0, 0, 0))
		text = ""
		for e in pygame.event.get():
				if e.type == QUIT or (e.type == KEYDOWN and e.key == K_ESCAPE):
					pygame.quit()
					return
		key = pygame.key.get_pressed()
		if key[K_DOWN]:
			http.request("GET","/xbmcCmds/xbmcHttp?command=SendKey(271)")
			text = "Down"
		elif key[K_UP]:
			http.request("GET","/xbmcCmds/xbmcHttp?command=SendKey(270)")
			text = "UP"
		elif key[K_LEFT]:
			http.request("GET","/xbmcCmds/xbmcHttp?command=SendKey(272)")
			text = "Left"
		elif key[K_RIGHT]:
			http.request("GET","/xbmcCmds/xbmcHttp?command=SendKey(273)")
			text = "Right"
		elif key[K_RETURN]:
			http.request("GET","/xbmcCmds/xbmcHttp?command=Action(7)")
			text = "Enter"
		elif key[K_BACKSPACE]:
			http.request("GET","/xbmcCmds/xbmcHttp?command=SendKey(275)")
			text = "Back"
		
		if text != "":
			time.sleep(0.25)
			r = http.getresponse()
			
		rfont = font.render(text, 1, (255, 255, 255))
		textpos = rfont.get_rect(centerx=screen.get_width()/2,centery=screen.get_height()/2)
		background.blit(rfont, textpos)
		screen.blit(background, (0, 0))
		pygame.display.flip()
		time.sleep(0.075)

if __name__ == "__main__":
	main()

