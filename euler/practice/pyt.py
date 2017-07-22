def power(base,p,mod):
	res = 1
	while p>0:
		if p&1:
			res = (res*base)%mod
		base = (base*base)%mod
		p>>=1
	return res%mod


for _ in xrange(int(raw_input())):
	n,mod = map(int,raw_input().split())
	freq = [int(n/mod)]*mod
	freq[0] = 1
	left = n%mod
	for i in xrange(1,left+1):
		freq[i]+=1
	
