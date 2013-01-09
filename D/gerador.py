#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       gerador.py
#       
#       Copyright 2012 João Ferreira <joao@void>
#       

from random import randint

def main():
	
	f = open("test1.in", "w")
	
	for k in xrange(10):
	
		n = randint(1, 1000)
		m = randint(1, 1000)
		
		while m * n > 250000:
			m = randint(1, 1000)
		
		f.write(str(n)+" "+str(m)+"\n")
		
		for i in xrange(n):
			for j in xrange(m):
				f.write(str(randint(-15,15))+" ")
			f.write("\n")
		print "%d test case is done" % (k+1)
		
	f.close()
	
	return 0

if __name__ == '__main__':
	main()
