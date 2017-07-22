infinity=10**8
n=int(raw_input())
cost=[[0 for i in xrange(n+1)] for j in xrange(n+1)]
flag=[False]*(n+1)
dist=[0]*(n+1)
for i in xrange(1,n+1):
	arr=map(int,raw_input().strip().split())
	for j in xrange(1,n+1):
		if(arr[j-1]!=0): cost[i][j]=arr[j-1]
		else: cost[i][j]=infinity
# the starting vertex
v=int(raw_input())

flag[v]=True
for i in xrange(1,n+1):
	dist[i]=cost[v][i]
count=2
print 
while count<=n:
	u=1
	minimum=infinity
	for i in xrange(1,n+1):
		if dist[i]<minimum and flag[i]==False:
			minimum=dist[i]
			u=i

	flag[u]=True
	for i in xrange(1,n+1):
		if flag[i]==False and (dist[u]+cost[u][i])<dist[i]:
			dist[i]=dist[u]+cost[u][i]
	count+=1

print "The shortest paths are :"
for i in xrange(1,n+1):
	if i!=v:
		print v,"->",i,"cost=",dist[i]
