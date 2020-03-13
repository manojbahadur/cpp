#include<bits/stdc++.h> 
using namespace std;

class Sorting
{
	int n,min,ar[100],t,j,v;
	public:

	void get_array(){
		cout<<"Enter the number of elements"<<endl;
		cin>>n;
		cout<<"Enter the array elements"<<endl;
		for (int i = 0; i < n; ++i)
			cin>>ar[i];
		
		
	}

	void Selection_Sort(){
		for (int i = 0; i < n-2; i++)
		{
			min = i;
			for (int j = i+1; j < n; j++)
			{
				if(ar[j]<ar[min])
					min = j;
			}
			t = ar[i];
			ar[i] = ar[min];
			ar[min] = t;
		}
	}

	void Insertion_Sort(){
		for (int i = 1; i < n; ++i)
		{
			v = ar[i];
			j = i-1;
			while(j>=0 && ar[j]>v){
				ar[j+1] = ar[j];
				j = j-1;
			}
			ar[j+1] = v;
		}
	}

	void Bubble_sort(){
		for (int i = 0; i < n-1; ++i)
 		{
 			for (int j = 0; j < n-1-i; j++)
 			{
 				if(ar[j+1]<ar[j]){
 					t = ar[j];
 					ar[j] = ar[j+1];
 					ar[j+1] = t;
 				}	
 			}
 		}
	}

	void print_elements(){
		cout<<"After sorting ";
		for (int i = 0; i < n; ++i)
			cout<<ar[i]<<" ";
		
	}
		
};



int main()
{
	int op;
	Sorting obj;

	cout<<"Enter"<<endl<<"1 for Selection sort"<<endl<<"2 for Bubble sort"<<endl<<"3 for Insertion sort"<<endl;
	cin>>op;

	switch(op){
		case 1: obj.get_array();
				obj.Selection_Sort();
				obj.print_elements();
				break;
		case 2: obj.get_array();
				obj.Bubble_sort();
				obj.print_elements();
				break;
		case 3: obj.get_array();
				obj.Insertion_Sort();
				obj.print_elements();
				break;
		default: cout<<"Wrong option";
	}


}