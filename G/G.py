# actual submission made in C (and also slightly better)

from heapq import heappush, heappop

def genChildren(parent, h, best):
	ind = -parent[1] + 1
	
	# generate left node from parent node and current item values (left node USES current item)
	if parent[4]+items[ind][1] <= maxw and parent[5]+items[ind][2] <= maxv:
		heappush(h, (parent[0],  -ind,  parent[2],  parent[3],  parent[4]+items[ind][1],  parent[5]+items[ind][2]))
		#h.append((parent[0],  -ind,  parent[2],  parent[3],  parent[4]+items[ind][1],  parent[5]+items[ind][2]))
	
	# generate right node from parent node and a new estimate (right node DOESN'T USE current item)
	i = -parent[0] - items[ind][0]
	w =  parent[3] - items[ind][1]
	
	j = parent[2] + 1
	while w < maxw and j <= n:		# allow new items to fill the weight from the removed one
		i += items[j][0]
		w += items[j][1]
		j += 1
	
	if i >= best:
		heappush(h, (-i,  -ind,  j-1,  w,  parent[4],  parent[5]))
		#h.append((-i,  -ind,  j-1,  w,  parent[4],  parent[5]))

def initHeap():
	i = w = 0	# importance, weight
	
	j = 1
	while w < maxw and j <= n:		# make a prediction from importance-and-weight-only
		i += items[j][0]
		w += items[j][1]
		j += 1
	
	# (importance_prediction, item_index, last_index_in_prediction, weight_prediction, current_weight, current_volume)
	h = [(-i, 0, j-1, w, 0, 0)]
	#print "bound",i
	return h


def solve():
	h = initHeap()	# h is a min-heap and we always want the max, so every value must be it's negative
	best = 0
	
	while h:
		node = heappop(h)
		#node = h.pop()
		
		if -node[0] < best:		# remove obsolete item from heap
			#print "obsolete"
			continue
		
		if -node[1] == n:		# if node is leaf (n instead of n-1 because of dummy item)
			#print -node[0], -node[1], node[2], node[3], node[4], node[5], best
			if -node[0] > best:
				best = -node[0]
		else:
			genChildren(node, h, best)
			
	return best


try:
	nTests = int(raw_input())
	for test in xrange(nTests):
		[n, maxw, maxv] = [int(val) for val in raw_input().split()]
		items = [[int(val) for val in raw_input().split()] for item in xrange(n)]

		items.sort(None, lambda x: float(-x[0])/x[1])	# sort items by importance / weight

		#for item in items:
		#	print str(item)+"\t" + str(float(item[0])/item[1])
		items = [[0, 0, 0]] + items		# add dummy item to be used as root (last item is now at index n instead of n-1)
		#print items
		
		print solve()
except (EOFError):
	pass
