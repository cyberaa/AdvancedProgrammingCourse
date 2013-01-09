#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       untitled.py
#       
#       Copyright 2012 João Ferreira <joao@void>
#       

from string import uppercase
import random

def generate(m, n):
	print str(m) + " " + str(n)
	
	for i in xrange(m):
		spaces = random.randint(0, n/2)
		
		word = ""
		
		for j in xrange(spaces):
			word += " "
		
		
		for j in xrange(n-spaces):
			word += random.choice(uppercase)
		
		
		print word
	

def main():
	generate(4,6)
	return 0

if __name__ == '__main__':
	main()
