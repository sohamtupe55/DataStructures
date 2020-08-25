#include<iostream>

using namespace std;

int main()
{
	int m,n,o,p,r,l=1,i,j;
	cout<<"ENTER NO. OF ROWS AND COLUMNS IN MATRIX A & B\n";
	cin>>m;
	cin>>n;
	cin>>o;
	cin>>p;
	int a[m][n],b[o][p];
	cout<<"ENTER VALUES IN MATRIX A\n";
        for (i=1;i<=m;i++)
        {
	    for (j=1;j<=n;j++)
	    cin>>a[i][j];
        }    
        cout<<"Elements of matrix 1 are: ";
        for (i=1;i<=m;i++)
        {
            cout<<endl;
            for (j=1;j<=n;j++)
                cout<<a[i][j]<<" ";
        }
        cout<<"\nEnter the elements of matrix 2: "<<endl;
        for (i=1;i<=o;i++)
        {
            for (j=1;j<=p;j++)
                cin>>b[i][j];
        }
        cout<<"Elements of matrix 2 are: ";
        for (i=1;i<=o;i++)
        {
            cout<<endl;
            for (j=1;j<=p;j++)
                cout<<b[i][j]<<" ";
        }
	cout<<"\nEnter Choice:\n1. ADD\n2. SUBSTRACT\n3. MULTIPLY\n";
    	cin>>r;
    	switch(r)
    	{
        	//ADDITION
        	case 1:
        	
        	if (m==o&&n==p)
           	{
                	cout<<"Addition possible "<<endl;
            	}
            	
            	else
            	{
                	cout<<"Addition not possible ";
                	l=0;
            	}
            	
            	if(l)
            	{
            		cout<<"\nAddition:\nc=a+b=";
            		int c[m][n];
                	for (i=1;i<=m;i++)
                	{
                    	for (j=1;j<=n;j++)
                    	{
                    	    *(*(c+i)+j)=(*(*(a+i)+j))+(*(*(b+i)+j));
                    	}
                	}
                	for (i=1;i<=m;i++)
                	{
                    		cout<<endl;
                    		for (j=1;j<=n;j++)
                        		cout<<*(*(c+i)+j)<<" ";
                	}
            	}
        	break;
        	case 2:
        	if (m==o&&n==p)
		    {
			cout<<"Subtracion possible "<<endl;
		    }
		    else
		    {
			cout<<"Subtraction not possible ";
			l=0;
		    }
		
		    if(l)
		    {
			int c[m][n];
			cout<<"\nSubtraction:\nc=a-b=";
			for (i=1;i<=m;i++)
			{
			    for (j=1;j<=n;j++)
			    {
			        *(*(c+i)+j)=(*(*(a+i)+j))-(*(*(b+i)+j));
			    }
			}
			for (i=1;i<=m;i++)
			{
			    cout<<endl;
			    for (j=1;j<=n;j++)
			        cout<<*(*(c+i)+j)<<" ";
			}
		}
        	break;
        	case 3:
        	if (n==o)
            	{
                	cout<<"Multiplication possible "<<endl;
            	}
            	else
            	{
                	cout<<"Multiplication not possible ";
                	l=0;
            	}
            	if(l)
            	{
            		 cout<<"\n\n\nMultiplication:\nc=aXb=";
            		 int c[m][p];
		        for (i=1;i<=m;i++)
		        {
		            for (j=1;j<=p;j++)
		            {
		                *(*(c+i)+j)=0;
		                for (int k=1;k<=n;k++)
		                {
		                    *(*(c+i)+j)+=((*(*(a+i)+k))*(*(*(b+k)+j)));
		                }
		            }
		        }
		        for (i=1;i<=m;i++)
		        {
		            cout<<endl;
		            for (j=1;j<=p;j++)
		                cout<<*(*(c+i)+j)<<" ";
		        }

            	}	
        	break;
        	default:
        	 cout<<"INVALID INPUT";
	}
	return 0;
}


