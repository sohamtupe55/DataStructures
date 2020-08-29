#include<iostream>
#include<string.h>
using namespace std;
int binwithoutrecursion(string s[],int l,int r,string key);
int binwithrecursion(string s[],int l,int r,string key);
int main()
{
	int ch,n,r;
	cout<<"ENTER NUMBER OF STRINGS\n";
	cin>>n;
	string str[n],key;
	cout<<"ENTER THE "<<n<<" STRINGS\n";
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	//sort strings as we need sorted array
	for(int i=1;i<n;i++)
	{
		string key=str[i];
		int j=i-1;
		while(j>=0 && key<str[j])
		{
			str[j+1]=str[j];
			j--;
		}
		str[j+1]=key;
	}
	cout<<"THE STRINGS IN SORTED ORDER ARE:\n";
	for(int i=0;i<n;i++)
	{
		cout<<str[i];
	}
	cout<<"\n";
	while(ch!=0)
	{
	cout<<"MENU:\n1. BINARY SEARCH WITHOUT RECURSION\n2. BINARY SEARCH WITH RECURSION\n0.QUIT\n";
	cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"ENTER THE STRING TO BE SEARCHED:";
			cin>>key;
			r=binwithoutrecursion(str,0,n-1,key);
			if(r==-1)
				cout<<"STRING NOT FOUND\n";
			else
				cout<<"STRING FOUND AT "<<r<<"th Position\n";
			break;
			case 2:
			cout<<"ENTER THE STRING TO BE SEARCHED:";
			cin>>key;
			r=binwithrecursion(str,0,n-1,key);
			if(r==-1)
				cout<<"STRING NOT FOUND\n";
			else
				cout<<"STRING FOUND AT "<<r<<"th Position\n";
			break;
			case 0:
			break;
			default:
				cout<<"INVALID INPUT\n";
			break;
		}
	}
	return 0;
}
int binwithoutrecursion(string s[],int l,int r,string key)
{
	while(l<=r)
	{
		int m=l+(r-l)/2;
		if(s[m]==key)
		{
			return m;
		}
		if(s[m]>key)
		{
			r=m-1;
		}
		else
			l=m+1;
	}
	return -1;
}		
int binwithrecursion(string s[],int l,int r,string key)
{
	if(r>=l)
	{	
		int m=l+(r-l)/2;
		if(s[m]==key)
			return m;
		if(s[m]>key)
			return binwithrecursion(s,l,m-1,key);
		else
			return binwithrecursion(s,m+1,r,key);
	}
	return -1;
}
		
		 
