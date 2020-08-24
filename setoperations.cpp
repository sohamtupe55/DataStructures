#include<iostream>
using namespace std;
int main()
{	
	int n;//total number of students
	cout<<"ENTER NO. OF STUDENTS IN THE CLASS\n";
	cin>>n;
	int mat[n],sci[n],nm,ns,ems[n],bms[n],om[n],os[n],k=0,key=0;
	cout<<"ENTER NO. OF STUDENTS WHO LIKE MATHS\n";
	cin>>nm;
	cout<<"ENTER NO. OF STUDENTS WHO LIKE SCIENCE\n";
	cin>>ns;	
	cout<<"ENTER ROLL NO. OF STUDENTS WHO LIKE MATHS\n";
	for(int i=0;i<nm;i++)	
		cin>>mat[i];	
	cout<<"ENTER ROLL NO. OF STUDENTS WHO LIKE SCIENCE\n";
	for(int i=0;i<ns;i++)	
		cin>>sci[i];
	cout<<"STUDETS WHO LIKE EITHER MATHS OR SCIENCE:\n";//union
	for(int i=0;i<nm;i++)
	{
		ems[i]=mat[i];
		k++;
	}
	for(int i=0;i<ns;i++)
	{	
		key=0;
		for(int j=0;j<nm;j++)
		{
			if(sci[i]==mat[j])
			{
				key=1;
			}
		}
		if(key==0)
		{	ems[k]=sci[i];
			k++;	}
	}
	for(int i=0;i<k;i++)
	{
		cout<<ems[i]<<endl;
	}
	cout<<"STUDETS WHO LIKE EITHER MATHS OR SCIENCE:\n";//intersection
	k=0;
	for(int i=0;i<ns;i++)
	{	
		key=0;
		for(int j=0;j<nm;j++)
		{
			if(sci[i]==mat[j])
			{
				key=1;
			}
		}
		if(key==1)
		{	bms[k]=sci[i];
			k++;	}
	}
	for(int i=0;i<k;i++)
	{
		cout<<bms[i]<<endl;
	}
	cout<<"STUDETS WHO LIKE ONLY MATHS:\n";//DIFFERENCE
	k=0;
	for(int i=0;i<nm;i++)
	{	
		key=0;
		for(int j=0;j<ns;j++)
		{
			if(sci[j]==mat[i])
			{
				key=1;
			}
		}
		if(key!=1)
		{	om[k]=mat[i];
			k++;	}
	}
	for(int i=0;i<k;i++)
	{
		cout<<om[i]<<endl;
	}
	cout<<"STUDETS WHO LIKE ONLY SCIENCE:\n";//DIFFERENCE
	k=0;
	for(int i=0;i<ns;i++)
	{	
		key=0;
		for(int j=0;j<nm;j++)
		{
			if(sci[i]==mat[j])
			{
				key=1;
			}
		}
		if(key!=1)
		{	os[k]=sci[i];
			k++;	}
	}
	for(int i=0;i<k;i++)
	{
		cout<<os[i]<<endl;
	}
	return 0;
	
}
