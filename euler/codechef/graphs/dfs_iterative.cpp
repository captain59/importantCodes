#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;//pointer to an array containing adjacency list
	void DFSUtil(int v,bool visited[]);
public:
	Graph(int V);//constructor
	void addEdge(int v,int w);//adding an edge
	void DFS(int v);
};

Graph::Graph(int v)
{
	V=v;
	adj = new list<int> [V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator it;

	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(visited[*it]==false)
			DFSUtil(*it,visited);
	}

}
void Graph::DFS(int v)
{
	bool *visited=new bool[V];
	for(int i=1;i<V;i++)
		visited[i]=false;

	DFSUtil(v,visited);
}

int main()
{
	int n,t,a,b,v;
	cin>>n;
	Graph g(n+1);
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		g.addEdge(a,b);
	}
	cin>>v;
	g.DFS(v);
	return 0;
}