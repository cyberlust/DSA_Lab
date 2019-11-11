#include <bits/stdc++.h>

using namespace std;

ifstream fpi;
ofstream fpo;

class node{
public:
	int key;
	int rank;
	node *p;
};

class graph{
	vector <vector<int>> edges;
	vector <pair <int,int>> weight;
	set <int> vertices;
	vector <node*> nodes;
public:
	void insert(int u,int v,int w)
	{
		vector <int> temp;
		temp.push_back(u);
		temp.push_back(v);
		temp.push_back(w);
		edges.push_back(temp);
		pair <int,int> tempo;
		tempo.first = w;
		tempo.second = edges.size()-1;
		weight.push_back(tempo);
		vertices.insert(u);
		vertices.insert(v);
	}

	void makeset(int x)
	{
		node *newnode = (node*)malloc(sizeof(node));
		newnode->key = x;
		newnode->rank = 0;
		newnode->p = newnode;
		nodes.push_back(newnode);
	}

	node* findset(node *x)
	{
		while(x->p!=x)
		{
			x = x->p;
		}
		return x;
	}

	void union_(node* x, node* y)
	{
		link(findset(x),findset(y));
	}

	void link(node *x, node *y)
	{
		if(x->rank > y->rank)
		{
			y->p = x;
		}
		else
		{
			x->p = y;
			if(x->rank==y->rank)
			{
				y->rank+=1;
			}
		}
	}

	node* findnode(int x)
	{
		for(int i = 0; i<nodes.size(); i++)
		{
			if(nodes[i]->key==x)
			{
				return nodes[i];
			}
		}
	}

	void kruskals()
	{

		int count = 0;
		for(auto x : vertices)
		{
			makeset(x);
		}
		sort(weight.begin(), weight.end());
		for(int i = 0; i<weight.size(); i++)
		{
			int u = edges[weight[i].second][0];
			int v = edges[weight[i].second][1];
			int w = edges[weight[i].second][2];
			node *fu = findnode(u);
			node *fv = findnode(v);

			if(findset(fu) != findset(fv))
			{
				count++;
				union_(fu,fv);
				fpo<<u<<" "<<v<<" "<<w<<endl;
			}
		}
	}
};

int main(int argc, char **argv)
{
	string c;
	string d;
	graph g;
	fpi.open(argv[1]);
	while(fpi>>c)
	{
		int u = stoi(c);
		fpi>>c;
		int v = stoi(c);
		fpi>>c;
		int w = stoi(c);
		g.insert(u,v,w);
	}	
	fpo.open("mst.txt");
	g.kruskals();
	fpo.close();
	fpi.close();
}