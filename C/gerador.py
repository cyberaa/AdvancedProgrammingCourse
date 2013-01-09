#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       gerador.py
#       
#       Copyright 2012 João Ferreira <joao@void>
#       

from random import randint

def main():
	
	members = randint(1, 12)
	connections = randint(0, members*members)
	
	matrix = [[0 for j in xrange(members)] for i in xrange(members)]
	
	f = open('inputG1', 'w')
	
	print members, connections
	
	f.write(str(members)+" ")
	f.write(str(connections)+"\n")
	
	while connections > 0:
		x = randint(0,members-1)
		y = randint(0,members-1)
		
		if matrix[x][y] == 0:
			matrix[x][y] = 1
			connections-=1
	
	for i in matrix:
		print i
	
	for i in xrange(members):
		for j in xrange(members):
			if matrix[i][j] == 1:
				f.write(str(i)+" "+str(j)+"\n")
	
	f.close()
	
	return 0

if __name__ == '__main__':
	main()
