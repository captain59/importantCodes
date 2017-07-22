def isprime(n):
	'''Returns true if prime'''
	if n==2 or n==3:
		return True
	elif n%2==0:
		return False
	elif n%3==0:
		return False

	i=5
	w=2

	while i*i <=n:
		if n%i==0:
			return False
		i+=w
		w=6-w
	return True

def Sieve_Erythrose(a,b,n):
	arr=[]
	arr.append(2)
	i=3
	while i*i<=b:
		if isprime(i):
			arr.append(i)
		i+=2
	div=0
	for i in xrange(a,b+1,1):
		val=i
		count=1
		j=0
		while val!=1 and j<len(arr):
			c=0
			if val%arr[j]==0:
				while val%arr[j]==0:
					val=val/arr[j]
					c+=1
			count*=c+1
			j+=1
		if val!=1:
			count*=2
		if count==n:
			div+=1
	return div
