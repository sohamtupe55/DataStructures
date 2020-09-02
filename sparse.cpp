#include<iostream>
using namespace std;
typedef struct sparse
{
	int row,col,val;
}Sm;
int ** accept(int m,int n);
Sm* sparse(int** a,int m,int n);
Sm* add(Sm *s1,Sm *s2);
void dispsm(Sm *s);
void simpletranspose(Sm *s);
void fasttranspose(Sm *s);
int main()
{
	int r1,c1,r2,c2;
	cout<<"ENTER NO. OF ROWS AND COLUMN in MATRIX A & B\n";
	cin>>r1>>c1>>r2>>c2;
	int **mat1,**mat2;
	cout<<"ENTER ELEMENTS in MATRIX A\n";
	mat1=accept(r1,c1);
	cout<<"ENTER ELEMENTS in MATRIX B\n";
	mat2=accept(r2,c2);
	cout<<"SPARSE MATRIX A:\n";
	Sm *s1=sparse(mat1,r1,c1);
	dispsm(s1);
	cout<<"SPARSE MATRIX B:\n";
	Sm *s2=sparse(mat2,r2,c2);
	dispsm(s2);
	int ch=1;
	while(ch!=0)
	{
		cout<<"MENU:\n1.ADD\n2.SIMPLE TRANSPOSE\n3.FAST TRANSPOSE\n0.QUIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"ADDITION OF A & B:\n";
			add(s1,s2);
			break;
			case 2:
			cout<<"TRANSPOSE OF SPARSE MATRIX A\n";
			simpletranspose(s1);
			cout<<"TRANSPOSE OF SPARSE MATRIX B\n";
			simpletranspose(s2);
			break;
			case 3:
			cout<<"TRANSPOSE OF SPARSE MATRIX A\n";
			fasttranspose(s1);
			cout<<"TRANSPOSE OF SPARSE MATRIX B\n";
			fasttranspose(s2);
			break;
			case 0:
			break; 
			default:
			cout<<"INVALID OUTPUT\n";
		}
	}
	return 0;
}
int ** accept(int m,int n)
{
	int **a=(int**)malloc(m*sizeof(int*));
	for(int i=0;i<m;i++)
	{
		*(a+i)=(int*)malloc(n*sizeof(int));
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cin>>a[i][j];
		}
	}
	return a;
}
Sm* sparse(int** a,int m,int n)
{
	int n1=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=0)
				n1++;
		}
	}

	Sm *s1=(Sm*)malloc((1+n1)*sizeof(Sm));
	s1[0].row=m;
	s1[0].col=n;
	s1[0].val=n1;
	int k=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				s1[k].row=i;
				s1[k].col=j;
				s1[k].val=a[i][j];
				k++;
			}
		}
	}
	return s1;
}
void dispsm(Sm* s)
{	
	
	for(int i=0;i<=s[0].val;i++)
	{
		cout<<s[i].row<<"\t"<<s[i].col<<"\t"<<s[i].val<<endl;	
	}
	
}
Sm* add(Sm *s1,Sm *s2)
{
	int p1=1,p2=1,p3=1,n=0;
	Sm *s3=(Sm*)malloc((1+s1[0].val+s2[0].val)*sizeof(Sm));
	if (s1[0].row != s2[0].row || s1[0].col != s2[0].col) 
        { 
            cout << "Matrices can't be added"<<endl; 
            
        } 
        else
	{	
		while(p1<=s1[0].val && p2<=s2[0].val)
		{
			if(s1[p1].row==s2[p2].row && s1[p1].col==s2[p2].col)
			{
				s3[p3].row=s1[p1].row;
				s3[p3].col=s1[p1].col;
				s3[p3].val=s1[p1].val+s2[p2].val;
				p1++;
				p2++;
				p3++;
				n++;
			}
			else if(s1[p1].row==s2[p2].row && s1[p1].col<s2[p2].col)
			{
				s3[p3].row=s1[p1].row;
				s3[p3].col=s1[p1].col;
				s3[p3].val=s1[p1].val;
				p1++;
				p3++;
				n++;
			}
			else if(s1[p1].row==s2[p2].row && s1[p1].col>s2[p2].col)
			{
				s3[p3].row=s2[p2].row;
				s3[p3].col=s2[p2].col;
				s3[p3].val=s2[p2].val;
				p2++;
				p3++;
				n++;
			}
			else if(s1[p1].row<s2[p2].row)
			{
				s3[p3].row=s1[p1].row;
				s3[p3].col=s1[p1].col;
				s3[p3].val=s1[p1].val;
				p1++;
				p3++;
				n++;
			}
			else if(s1[p1].row>s2[p2].row)
			{
				s3[p3].row=s2[p2].row;
				s3[p3].col=s2[p2].col;
				s3[p3].val=s2[p2].val;
				p2++;
				p3++;
				n++;
			}
			
		}
		while(p1<=s1[0].val)
		{
			s3[p3].row=s1[p1].row;
			s3[p3].col=s1[p1].col;
			s3[p3].val=s1[p1].val;
			p1++;
			p3++;
			n++;
		}
		while(p2<=s2[0].val)
		{
			s3[p3].row=s2[p2].row;
			s3[p3].col=s2[p2].col;
			s3[p3].val=s2[p2].val;
			p2++;
			p3++;
			n++;
		}
	
	s3[0].row=s1[0].row;
	s3[0].col=s1[0].col;
	s3[0].val=n;
	}
	dispsm(s3);
	
}
void simpletranspose(Sm *s)
{
	Sm *t=(Sm*)malloc((1+s[0].val)*sizeof(Sm));
	t[0].row=s[0].col;
	t[0].col=s[0].row;
	t[0].val=s[0].val;
	int k=1;
	for(int i=0;i<s[0].col;i++)
	{
		for(int j=1;j<=s[0].val;j++)
		{
			if(i==s[j].col)
			{
				t[k].row=s[j].col;
				t[k].col=s[j].row;
				t[k].val=s[j].val;
				k++;
			}	
		}
	}
	dispsm(t);
}
void fasttranspose(Sm *s)
{
	Sm *t=(Sm*)malloc((1+s[0].val)*sizeof(Sm));
	t[0].row=s[0].col;
	t[0].col=s[0].row;
	t[0].val=s[0].val;
	int tot[s[0].col];
	for(int i=0;i<s[0].col;i++)
	{
		tot[i]=0;
	}
	for(int i=1;i<=s[0].val;i++)
		tot[s[i].col]++;
	int index[s[0].col+1];
	index[0]=1;
	for(int i=1;i<=s[0].col;i++)
	{
		index[i]=index[i-1]+tot[i-1];
	}
	for(int i=1;i<=s[0].val;i++)
	{
		int j=index[s[i].col]++;
		t[j].col=s[i].row;
		t[j].row=s[i].col;
		t[j].val=s[i].val;
	}
	dispsm(t);
}
