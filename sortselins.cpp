#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int ch,n;
	cout<<"ENTER NUMBER OF STRINGS\n";
	cin>>n;
	string str[n];
	cout<<"ENTER THE "<<n<<" STRINGS\n";
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	while(ch!=0)
	{
	cout<<"MENU:\n1. SORT IN ASCENDING ORDER USING INSERTION SORT\n2. SORT IN DESCENDING ORDER USING SELECTION SORT\n0.QUIT\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"ASCENDING ORDER:\n";
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
		for(int i=0;i<n;i++)
		{
			cout<<str[i]<<endl;
		}
		break;
		case 2:
		cout<<"DESCENDING ORDER:\n";
		for(int i=0;i<n-1;i++)
		{
			string max=str[i];
			int maxl=i;
			for(int j=i+1;j<n;j++)
			{
				if(str[j]>max)
				{
					max=str[j];
					maxl=j;
				}
			}
			string temp;
			temp=str[i];
			str[i]=str[maxl];
			str[maxl]=temp;
		}
		for(int i=0;i<n;i++)
		{
			cout<<str[i]<<endl;
		}
		break;
		default:
			cout<<"INVALID INPUT\n";
	}
	}
	return 0;
}
