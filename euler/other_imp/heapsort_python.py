def max_heaify(i,n,arr=[]):
	l=2*i+1
	r=2*i+2
	largest=i
	if l<=n-1 and arr[l]>arr[i]:
		largest=l
	else:
		largest=i
	if r<=n-1 and arr[r]>arr[largest]:
		largest=r;
	if largest != i:
		arr[largest],arr[i]=arr[i],arr[largest]
		max_heaify(largest,n,arr)
		
def build_heap(arr=[]):
	n=len(arr)
	for i in xrange(n/2-1,-1,-1):
		max_heaify(i,n,arr)

def heapsort(arr):
	build_heap(arr)
	n=len(arr)
	for i in xrange(n-1,-1,-1):
		arr[0],arr[i]=arr[i],arr[0]
		n-=1
		max_heaify(0,i,arr)

n=int(raw_input())
arr=[]
arr=map(int,raw_input().split())
heapsort(arr)
large=arr[n-1]
small=arr[n-2]
for i in xrange(n-3,-1,-1):
	if (small+arr[i])>large :
		large,small=small+arr[i],large
	else:
		small+=arr[i]
print large-small+1