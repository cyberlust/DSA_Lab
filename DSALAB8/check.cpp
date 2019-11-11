#include <bits/stdc++.h>

using namespace std;

int main(int agrc,char** argv){

	ifstream ifile;
	ifile.open(argv[1]);
	ifstream iofile;
	iofile.open(argv[2]);
	string c;
	vector <pair <int,int>> p1;
	vector <pair <int,int>> p2;
	vector<int> k;
	int l=0;
	while(ifile >> c){
		int u = stoi(c);
		ifile >> c;
		int v = stoi(c);
		pair <int,int> m;
		m.first = u;
		m.second = v;
		p1.push_back(m);
	}
	ifile.close();

	while(iofile >> c){
		int u = stoi(c);
		iofile >> c;
		int v = stoi(c);
		pair <int,int> m;
		m.first = u;
		m.second = v;
		p2.push_back(m);
	}
	iofile.close();

	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());

	if(p1.size()!=p2.size()){
		l=-1;
	}
	else {
		for(int i=0;i<p1.size();i++){
			if (p1[i].first!=p2[i].first || p1[i].second!=p2[i].second){
				l=-1;
				cout << "F" << endl;
			}
		}
	}
	if(l==0){
		cout << "Matched" << endl;
	}
	else{
		cout << "Not Matched" << endl;
	}	

	return 0;	
}