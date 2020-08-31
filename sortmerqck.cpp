#include<iostream>
using namespace std;
void mergesort(int a[],int l,int r);
void merge(int arr[],int l,int m,int r);
int partition(int arr[],int l, int r);
void quicksort(int arr[],int l,int r);
int main()
{
	
	int ch,n;
	cout<<"ENTER NUMBER OF ELEMENTS\n";
	cin>>n;
	int arr[n];
	cout<<"ENTER THE "<<n<<" ELEMENT\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	while(ch!=0)
	{
	cout<<"MENU:\n1. SORT USING MERGE SORT \n2. SORT USING QUICK SORT\n0.QUIT\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"ASCENDING ORDER:\n";
		mergesort(arr,0,n-1);
		cout<<"FINAL ORDER:\n";
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<endl;
		}
		break;
		case 2:
		cout<<"ASCENDING ORDER:\n";
		quicksort(arr,0,n-1);
		cout<<"FINAL ORDER:\n";
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<endl;
		}
		break;
	}
	}
}
void mergesort(int a[],int l,int r)
{
	if(l>=r)
		return;
	int m=l+(r-l)/2;
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	merge(a,l,m,r);
	cout<<"SORTED SUBARRAY:\t";
    	for(int i=0;i<r-l+1;i++)
    	{
			cout<<a[i]<<"\t";
    	} 
    	cout<<endl;
}
void merge(int arr[],int l,int m,int r)
{
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    
    i = 0; 
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    
} 
int partition(int arr[],int l,int r)
{
	int pivot=arr[r];
	int partitionindex=l;
	for(int i=l;i<r;i++)
	{
		if(arr[i]<=pivot)
		{
			int temp=arr[i];
			arr[i]=arr[partitionindex];
			arr[partitionindex]=temp;
			partitionindex++;
		}
	}
	int temp1=arr[partitionindex];
	arr[partitionindex]=arr[r];
	arr[r]=temp1;
	return partitionindex;
}
void quicksort(int arr[],int l,int r)
{
	if(l<r)
	{
		int partitionindex=partition(arr,l,r);
		quicksort(arr,l,partitionindex-1);
		quicksort(arr,partitionindex+1,r);
		cout<<"SORTED SUBARRAY:\t";
    		for(int i=l;i<r+1;i++)
    		{
			cout<<arr[i]<<"\t";
    		} 
    		cout<<endl;
	}
}

