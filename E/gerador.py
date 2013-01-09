#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       Gerador.py
#       
#       Copyright 2012 João Ferreira <joao@void>

import random
from string import lowercase

def main(size, f):
	size+=1
	w1size = random.randint(500, 1000)
	w2size = random.randint(500, 1000)
	
	w1 = ''
	w2 = ''
	
	for i in xrange(w1size):
		w1 += random.choice(lowercase)
	for i in xrange(w2size):
		w2 += random.choice(lowercase)
	
	print w1size, w1
	print w2size, w2
	
	f.write(str(w1size)+" "+w1+"\n")
	f.write(str(w2size)+" "+w2+"\n")
	
	return 0

if __name__ == '__main__':
	
	f = open("test2.in", "w")
	
	for i in xrange(10):
		main(i, f)
	
	f.close
