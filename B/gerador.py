#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       gerador.py
#       
#       Copyright 2012 João Ferreira <joao@void>
#       

from random import randint

def main():
	
	f = open("test", "w")
	for i in xrange(5000):
		persons = randint(4,15)
		f.write(str(persons)+" ")
		for i in xrange(persons):
			number = randint(1,10)
			if randint(0,1) == 0:
				number*=-1
			f.write(str(number)+" ")
		
		f.write(str(0)+" ")
	f.close()
		
	return 0

if __name__ == '__main__':
	main()
