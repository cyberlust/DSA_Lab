#include<bits/stdc++.h>

using namespace std;

void cuttree(int t,int n,vector <vector<int>> &desc,int **a);

int main()
{
	int t,n,k;
	cin>>t>>n>>k;
	int** a = new int*[n];
  	for(int i = 0; i < n; ++i)
    {
      a[i] = new int[n];
    }
    memset(a, 0, sizeof(a[0][0]) *n * n);
	vector <vector<int>> desc;
	for(int i=0;i<k;i++)
	{
		int x,y,h,d,c,p;
		vector <int> single;
		cin>>x>>y>>h>>d>>c>>p;
		single.push_back(x);
		single.push_back(y);
		single.push_back(h);  //height
		single.push_back(d);  //thickness
		single.push_back(c);  //unit weight  //weight = c.d.h
		single.push_back(p);  //unit value   //profit = p.d.h
		a[x][y] = i+1;
		desc.push_back(single);
	}
	cuttree(t,n,desc,a);
	return 0;
}



/*void copyArray(char (&arrayA)[ROWS][COLS], const char (&arrayB)[ROWS][COLS] ) {

    memcpy(arrayA, arrayB, sizeof(arrayB));
}*/

void cuttree(int t,int n,vector <vector<int>> &desc,int **a)
{
		
		int index=0,index1=0;
		int max = 0;
		int flag = 0;
		for(int i=0;i<n;i++)
		{
			int xco=0,yco=0,xco1 = 0,yco1 = 0;
			for(int j=0;j<n;j++)
			{
				
				if(a[i][j])
				{
					index = a[i][j]-1;
					if(desc[index][0]+desc[index][1]+desc[index][3]<=t)
					{
						int value = desc[index][2]*desc[index][3]*desc[index][5];
						int height = desc[index][2];
						int weight1 = desc[index][2]*desc[index][3]*desc[index][4];
						for(int l = 1; l < n; l++)
						{
							for(int k=i+l;k<n and k<=i+height;k++)
							{
								if(a[k][j])
								{
									index = a[k][j]-1;
									int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
									if(weight1>weight2)
									{
										value += desc[index][2]*desc[index][3]*desc[index][5];
									}
								}
								if(value>max)
								{
									t1 = desc[index][0]+desc[index][1]+desc[index][3];
									flag = 1;
									max = value;
									index1 = a[i][j]-1;
								}
							}
							for(int k=i-l;k>=0 and k>=i-height;k--)
							{
								if(a[k][j])
								{
									index = a[k][j]-1;
									int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
									if(weight1>weight2)
									{
										value += desc[index][2]*desc[index][3]*desc[index][5];
									}
								}
								if(value>max)
								{
									t1 = desc[index][0]+desc[index][1]+desc[index][3];
									flag = 2;
									max = value;
									index1 = a[i][j]-1;
								}
							}
							for(int k=j+l;k<n and k<=j+height;k++)
							{
								if(a[i][k])
								{
									index = a[i][k]-1;
									int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
									if(weight1>weight2)
									{
										value += desc[index][2]*desc[index][3]*desc[index][5];
									}
								}
								if(value>max)
								{
									t1 = desc[index][0]+desc[index][1]+desc[index][3];
									flag = 3;
									max = value;
									index1 = a[i][j]-1;
								}
									
							}
							for(int k=j-l;k>=0 and k>=j-height;k--)
							{
								if(a[i][k])
								{
									index = a[i][k]-1;	
									int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
									if(weight1>weight2)
									{
										value += desc[index][2]*desc[index][3]*desc[index][5];
									}
								}
								if(value>max)
								{
									t1 = desc[index][0]+desc[index][1]+desc[index][3];
									flag = 4;
									max = value;
									index1 = a[i][j]-1;
								}	
							}
						}
					}
				}
			}
			
		}
		for(int i=0;i<desc[index1][0];i++)
		{
			cout<<"move right\n";
		}
		for(int i=0;i<desc[index1][1];i++)
		{
			cout<<"move up\n";
		}
		if(flag==3)
		{
			cout<<"cut up\n";
		}
		else if(flag==4)
		{
			cout<<"cut down\n";
		}
		else if(flag==1)
		{
			cout<<"cut right\n";
		}
		else
		{
			cout<<"cut left\n";
		}
		a[desc[index1][0]][desc[index1][1]] = 0;
		cuttree(t1,n,desc,a);
	}