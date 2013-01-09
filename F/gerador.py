#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       Gerador.py
#       
#       Copyright 2012 João Ferreira <joao@void>

import random

def main(size, f):
	
	events = random.randint(1000, 30000)	
	
	f.write(str(events)+"\n")
	
	for i in xrange(events):
		startTime = random.randint(8,24)
		endTime = random.randint(8,24)
		
		while endTime < startTime:
			endTime = random.randint(8,24)
		
		f.write(str(startTime)+" "+str(endTime)+"\n")
	
	return 0

if __name__ == '__main__':
	
	f = open("test1.in", "w")
	
	for i in xrange(10):
		main(i, f)
	
	f.close()
