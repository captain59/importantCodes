for t in xrange(int(raw_input())):
	blank=raw_input()
	n=int(raw_input())
	arr=[]
	for i in xrange(n):
		arr.append((int(raw_input()),i+1))
	print arr
	arr.sort()
	print arr