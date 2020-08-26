#include<iostream>
#include<string.h>
using namespace std;

typedef struct product
{
	int price;
	int qty;
	string name;
	int status;
}P;
void addrec(P *p,int *n);
void disprec(P *p,int n);
void searchrec(P p[],int n);
void delrec(P *p,int n);
void sortrec(P *p,int n);
int main()
{
	P p[50];
	int n=0,ch=1;;
	while(ch!=0)
	{
		cout<<"MENU:\n1.Add Record\n2.Display Records\n3.Search Record\n4.Delete Record\n5.Sort Records\n0.QUIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				addrec(&p[n],&n);
				
				break;
			case 2:
				disprec(p,n);
				break;
			case 3:
				searchrec(p,n);
				break;
			case 4:
				delrec(p,n);
				break;
			case 5:
				sortrec(p,n);
				break;
		}
	}
	return 0;
}
void addrec(P *p,int *n)
{
	cout<<"ENTER NAME, PRICE & QUANTITY OF PRODUCT\n";
	cin>>p->name>>p->price>>p->qty;
	p->status=1;
	(*n)++;
	
}
void disprec(P *p,int n)
{
	
	cout<<"NAME\tPRICE\tQTY\n";
	for(int i=0;i<n;i++)
	{
		
		if(p->status==1){
		cout<<p->name<<"\t"<<p->price<<"\t"<<p->qty<<"\n";
		
		}
		p++;	
	}
}
void searchrec(P p[],int n)
{
	string pname;
	cout<<"ENTER NAME OF PRODUCT TO BE SEARCHED\n";
	cin>>pname;
	int flag=-1;
	for(int i=0;i<n;i++)
	{
		if(p->status==1){
		if(pname==p[i].name)
		{
			flag=i;
			
			break;
		}
		}
	}
	if(flag!=-1)
	{
		cout<<"RECORD FOUND!\n"<<p[flag].name<<"\t"<<p[flag].price<<"\t"<<p[flag].qty<<"\n";
	}
	else 
		cout<<"RECORD NOT FOUND\n";
}
void delrec(P *p,int n)
{	
	string pname;
	cout<<"ENTER NAME OF PRODUCT TO BE DELETED\n";
	cin>>pname;
	int flag=-1;
	for(int i=0;i<n;i++)
	{
		if(p->status==1){
			if(pname==p[i].name)
			{
				flag=i;
				cout<<"RECORD FOUND!\n";
				break;
			}
		}
	}
	if(flag!=-1)
	{
		cout<<"RECORD DELETED!\n"<<p[flag].name<<"\t"<<p[flag].price<<"\t"<<p[flag].qty<<"\n";
		p[flag].status=-1;
	}
	else 
		cout<<"RECORD NOT FOUND!\n";
}
void sortrec(P *p,int n)
{
	P temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(p[i].price>p[j].price)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	cout<<"SORTED IN ASCENDING ORDER OF PRICE\n";
}
