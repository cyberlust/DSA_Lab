#include <bits/stdc++.h>

using namespace std;

ifstream fpi;
ofstream fpo;

struct node
{
	int value;
	int weight;
};

class graph
{
	vector<vector<node>> adj;
	vector <int> weightu;
	vector<vector <int>> edge_weight;
	vector <pair <int, int>> heap;
public:
	graph(int max)
	{
		for(int i = 0; i<=max; i++)
		{
	 		vector<node> temp;
	 		temp.push_back({-1,-1});	
	 		adj.push_back(temp);
	 		vector <int> tempor;
	 		tempor.push_back(-1);
	 		edge_weight.push_back(tempor);
	 		weightu.push_back(INT_MAX);
		}
		
	}

	void insert(int u, int v, int w)
	{
		if(adj[u][0].value<0) 
		{
			vector <node> temp;
			temp.push_back({v,INT_MAX});
			adj[u] = temp;
			edge_weight[u][0]= w;
		}
		else
		{
			adj[u].push_back({v,INT_MAX});
			vector <int> temp;
			temp.push_back(w);
	 		edge_weight[u].push_back(w);
		}
	}

	void display(int max)
	{
		for(int i=0; i<=max; i++)
		{
			cout<<i;
			for(auto x : adj[i])
			{
				cout<<" -> "<<x.value;
			}
			cout<<endl;
		}
	}

	void dijkstras(int s,int max)
	{
		
		initialize(s);
		build_minheap();
		vector <int> S;
		S.clear();
		while(heap.size()!=0)
		{
			int u = extract_min();
			// cout<<u<<" "<<weightu[u]<<endl;
			
			S.push_back(u);
			// cout<<"size: "<<adj[0].size()<<endl;
			for(int i = 0; i<adj[u].size(); i++)
			{
				relax(u,i);
				// cout<<adj[u][i].value<<endl;
				// cout<<3<<" "<<weightu[0]<<endl;
			}
			build_minheap();
		}
	}

	void relax(int u,int i)
	{	
		if((weightu[adj[u][i].value] > (weightu[u] + edge_weight[u][i])) and adj[u][i].value>=0 and weightu[u]!=INT_MAX)
		{
			int index=-1;
			adj[u][i].weight = weightu[u] + edge_weight[u][i];
			weightu[adj[u][i].value] = weightu[u] + edge_weight[u][i];
			for(int j = 0; j<heap.size(); j++)
			{
				if(heap[j].first==adj[u][i].value)
				{
					index = j;
				}
			}
			if(index>=0)
			{
				heap[index].second = adj[u][i].weight;
				heap[index].first = adj[u][i].value;
			}
		}
	}

	int parent(int i)
	{
		return (i-1)/2;
	}
	int left_child(int i)
	{
		return 2*i+1;
	}
	int right_child(int i)
	{
		return 2*i+2;
	}

	int extract_min()
	{
		int min = -1;
		if(heap.size()>0)
		{	
			min = heap[0].first;
			heap[0].second = heap[heap.size()-1].second;
			heap[0].first = heap[heap.size()-1].first;
			heap.pop_back();
			min_heapify(0);
		}
		if(min>=0)
			return min;
		else
			return 0;
	}

	void build_minheap()
	{
		for(int i = heap.size()-1; i>=0; i--)
		{
			min_heapify(i);
		}
	}

	void min_heapify(int i)
	{
		int smallest = i;
		int l = left_child(i);
		int r = right_child(i);
		if(l<heap.size() and heap[l].second<heap[smallest].second)
		{
			smallest = l;
		}
		if(r<heap.size() and heap[r].second<heap[smallest].second)
		{
			smallest = r;	
		}
		if(smallest!=i)
		{
			swap(heap[i].second,heap[smallest].second);
			swap(heap[i].first,heap[smallest].first);
			min_heapify(smallest);
		}
	}

	void initialize(int s)
	{
		for(int i=0; i<adj.size(); i++)
		{
			for(int j = 0; j<adj[i].size(); j++)
			{
				adj[i][j].weight = INT_MAX;
			}
		}
		weightu[s] = 0;
		for(int i = 0; i<heap.size(); i++)
		{
			if(heap[i].first==s)
			{
				heap[i].second = 0;
			}
		}
	}

	void heapinit(int unique_value)
	{
		pair <int,int>tempo;
	 	tempo.first = unique_value;
	 	tempo.second = INT_MAX;
	 	heap.push_back(tempo);
	}

	void dist(int unique_value)
	{
		if(weightu[unique_value]!=INT_MAX)
			fpo<<unique_value<<" "<<weightu[unique_value]<<endl;
		else 
			fpo<<unique_value<<" "<<"-1"<<endl;
	}	
};

int main(int argc, char *argv[])
{
	fpi.open(argv[1]);
	string c;
	string d;
	int maxu = 0;
	int maxv = 0;
	int s = stoi(argv[2]);
	set <int> unique;
	while(fpi>>c)
	{
		int e = stoi(c);
		if(e>maxu)
		{
			maxu = e;
		}
		fpi>>d;
		e = stoi(d);
		if(e>maxv)
		{
			maxv = e;
		}
		fpi>>c;
	}
	fpi.close();
	int maximum = max(maxu,maxv);
	graph g(maximum);
	fpi.open(argv[1]);
	while(fpi>>c)
	{
		int u = stoi(c);
		fpi>>c;
		unique.insert(u);
		int v = stoi(c);
		unique.insert(v);
		fpi>>c;
		int w = stoi(c);
		g.insert(u,v,w);
	}
	for(auto x : unique)
	{
		g.heapinit(x);
	}
	// cout<<unique.size()<<endl;
	g.dijkstras(s,maximum);
	fpo.open("dijkstra.txt");
	for(auto x : unique)
	{
		g.dist(x);
	}
	fpo.close();
	// g.display(maximum);	

	return 0;
}