#include <bits/stdc++.h>

using namespace std;

void mergesort(int p, int r);
void merge(int p, int q, int r);

ifstream fpi;
ofstream fpm,fpq;

vector <int> v;

int main(int argc, char **argv)
{
	fpi.open(argv[1]);
	fpm.open("mergesort.txt");
	fpq.open("quicksort.txt");
	string c;
	int count = 0;
	// vector <int> v;
	while(fpi>>c)
	{
		int d = stoi(c);
		v.push_back(d);
	}
	int p = 0;
	int r = v.size() - 1;
	mergesort(p,r);
}

void mergesort(int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		mergesort(p,q);
		mergesort(q+1,r);
		merge(p,q,r);
	}
	for(int i = 0; i<v.size(); i++)
	{
		// cout<<v[i]<<endl;
		fpm<<v[i]<<endl;
	}
}

void merge(int p, int q, int r)
{
	int L[q-p+2], R[r-q];
	for(int i = 0; i<(q-p+1); i++)
	{
		L[i] = v[p + i];
	}
	for(int i = 0; i<(r-q-1); i++)
	{
		R[i] = v[i + q + 1];
	}
	L[q-p+1] = INT_MAX;
	R[r-q] = INT_MAX;
	int a = 0, b = 0;
	for(int i = p; i<r; i++)
	{
		if(L[a] < R[b])
		{
			v[i] = L[a];
			a+=1;
		}
		else
		{
			v[i] = R[b];
			b+=1;
		}
	}
	
}