#include <bits/stdc++.h>

using namespace std;

ifstream fpi;
ofstream fpo;

class Heap
{
	vector <int> arr;
	vector <int> arr1;
	int heap_size = 0;
public:
	void insert(int key)
	{
		heap_size +=1;
		arr.push_back(INT_MIN);
		increase_key(heap_size-1,key);
		fpo<<key<<" inserted"<<endl;
		// for(int i = 0; i<heap_size; i++)
		// {
		// 	fpo<<i<<": "<<arr[i]<<" ";
		// }
		// fpo<<endl;
	}
	int increase_key(int i, int key)
	{
		if(arr[i]>key)
			return 1;
		else
		{
			arr[i] = key;
			while(i>0 and arr[i]>arr[parent(i)])
			{
				swap(arr[i],arr[parent(i)]);
				i = parent(i);
			}
			return 2;
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
	void maximum()
	{
		if(heap_size>0)
			fpo<<arr[0]<<endl;
		else
			fpo<<endl;;
	}
	void extract_max()
	{
		if(heap_size>0)
		{	
			int max = arr[0];
			// if(heap_size!=1)
			// {
				arr[0] = arr[heap_size-1];
				heap_size-=1;
				max_heapify(0,heap_size);
				arr.pop_back();
			// }
			// else
			// {
			 	// heap_size-=1;
			 	// arr.clear();
			// }
			fpo<<max<<endl;
			// for(int i = 0; i<heap_size; i++)
			// {	
			// 	fpo<<i<<": "<<arr[i]<<" ";
			// }
			// fpo<<endl;
		}
		else
		{
			fpo<<endl;
		}
	}
	void max_heapify(int i,int heap_size1)
	{
		int largest = i;
		int l = left_child(i);
		int r = right_child(i);
		if(l<heap_size1 and arr[l]>arr[largest])
			largest = l;
		if(r<heap_size1 and arr[r]>arr[largest])
		{
			largest = r;	
		}
		if(largest!=i)
		{
			swap(arr[i],arr[largest]);
			max_heapify(largest,heap_size1);
		}
	}
	void max_heapify1(int i,int heap_size1)
	{
		int largest = i;
		int l = left_child(i);
		int r = right_child(i);
		if(l<heap_size1 and arr1[l]>arr1[largest])
			largest = l;
		if(r<heap_size1 and arr1[r]>arr1[largest])
		{
			largest = r;
		}
		if(largest!=i)
		{
			swap(arr1[i],arr1[largest]);
			max_heapify(largest,heap_size1);
		}
	}
	void heap_sort()
	{	
		arr1 = arr;
		int temp_size = heap_size;
		while(temp_size>1)
		{
			swap(arr1[0],arr1[temp_size-1]);
			temp_size-=1;
			max_heapify1(0,temp_size);
		}
		for(auto i=0; i<heap_size; i++)
		{
			fpo<<arr1[i]<<" ";
		}
		fpo<<endl;
	}
};


int main(int argc, char **argv)
{
	Heap heap;
	fpi.open(argv[1]);
	fpo.open("heap.txt");

	string c,cmd;
	while(fpi>>c)
	{
		cmd = c;
		if(cmd=="insert")
		{
			fpi>>c;
			int key = stoi(c);
			heap.insert(key);
		}
		if(cmd=="maximum")
		{
			heap.maximum();
		}
		if(cmd=="extract-max")
		{
			heap.extract_max();
		}
		if(cmd=="sort")
		{
			heap.heap_sort();
		}
		if(cmd=="increase-key")
		{
			fpi>>c;
			int i = stoi(c);
			fpi>>c;
			int key = stoi(c);
			if(heap.increase_key(i,key)==1)
				fpo<<key<<" is less than the current key at "<<i<<endl;
			else
				fpo<<"Key at "<<i<<" changed to "<<key<<endl;
		}
	}
	return 0;
}
