#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int a,int b);
	void BFS(int s);
};

Graph::Graph(int v)
{
	V=v;
	adj=new list<int>[V];
}

void Graph::addEdge(int a,int b)
{
	adj[a].push_back(b);
}
void Graph::BFS(int s)
{
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)visited[i]=false;

	queue<int> q;
	q.push(s);
	visited[s]=true;
	list<int>::iterator it;
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();

		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				q.push(*it);
			}
		}
	}
}

int main()
{
	int n,v,t,a,b;
	cin>>n;
	cin>>t;
	Graph g(n+1);
	while(t--)
	{
		cin>>a>>b;
		g.addEdge(a,b);
	}
	cin>>v;
	g.BFS(v);
	return 0;
}
