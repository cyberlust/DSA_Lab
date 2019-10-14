#include <bits/stdc++.h>

using namespace std;

struct node
{
	int value;
	char color;
	int disct;
	int fint;
};

class graph
{
	vector<vector<node>> adj;
public:
	graph(int maxu)
	{
		for(int i = 0; i<maxu; i++)
		{
			 vector<node> temp;
			 temp.push_back({-1,'w',0,0});	
			 adj.push_back(temp);
		}
	}

	void insert(int u, int v)
	{
		if(adj[u][0].value==-1)
		{
			vector <node> temp;
			temp.push_back({v,'w',0,0});
			adj[u] = temp;
		}
		else
		{
			adj[u].push_back({v,'w',0,0});
		}
	}

	void display(int maxu)
	{
		for(int i=0; i<maxu; i++)
		{
			for(auto x : adj[i])
			{
				cout<<"->"<<x.value;
			}
			cout<<endl;
		}
	}

};

int main(int argc, char **argv)
{
	ifstream fpi;
	ofstream fpo;
	fpi.open(argv[1]);
	string c;
	string d;
	int maxu = 0;
	int maxv = 0;
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
		
	}
	fpi.close();
	graph g(maxu);
	fpi.open(argv[1]);
	while(fpi>>c)
	{
		int u = stoi(c);
		fpi>>c;
		int v = stoi(c);
		g.insert(u,v);
	}	
	g.display(maxu);
	return 0;
}
