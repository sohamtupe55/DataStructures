#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size=0;
typedef struct employee
{
	char name[10];
	int id;
	double salary;
	int flag;
}employee;


void addRecord();
void displayData();
void searchRecord(int sid);
void deleteRecord(int sid);
void modifyRecord(int sid);
void bubbleSort();
void swap(employee e1[],employee e2[]);



int main()
{
	while(1)
	{
	int choice;
	printf("Enter your choice\n");
	printf("\n\n1.Add record\n2.Display record\n3.search record\n4.Delete record\n5.Modify record\n6.Sort using Bubble sort\n7.Exit\n\n");
	scanf("%d",&choice);

	switch(choice)
		{
			case 1:
				{
				    addRecord();
				    break;
				}

			case 2:
				{
					printf("ID\tNAME\tSALARY\n");
					displayData();
					break;
				}
			case 3:
				{
					printf("Enter id of record you want to search \n");
					int n;
					scanf("%d",&n);
					searchRecord(n);
					break;
				}
				case 4:
				{
					printf("Enter id of record you want to delete \n");
					int n;
					scanf("%d",&n);
					deleteRecord(n);
					break;
				}
				case 5:
				{
					printf("Enter id of record you want to modify\n");
					int n;
					scanf("%d",&n);
					modifyRecord(n);
					break;
				}
				case 6:
				{
					printf("Record by bubble sorting are as follows:\n");
					bubbleSort();
					displayData();
					break;
				}
			case 7:
				return 0;
			default:
			printf("Please enter valid choice\n");
		}//switch end
	}//while end
}

void addRecord()
{
	employee e;
	e.flag=1;
	FILE *fp;
	fp=fopen("Myfile.txt","a+");

	if(fp==NULL)
		{
			printf("not able to open file\n");
			return ;
		}
	printf("Enter Employee id\n");
	scanf("%d",&e.id);

	printf("Enter employee name\n");
	scanf("%s",e.name);

	printf("Enter salary of employee\n");
	scanf("%lf",&e.salary);

	fwrite(&e,sizeof(e),1,fp);
	fclose(fp);
}

void displayData()
{
	employee e;
	e.flag=1;
	FILE *fp;
	fp=fopen("Myfile.txt","r");
	fseek(fp,0,SEEK_SET);

	if(fp==NULL)
		{
			printf("not able to open file\n");
			return ;
		}
	while(fread(&e,sizeof(e),1,fp))
	{
		size++;
		if(e.flag==1)
		{
		printf("%d\t",e.id);
		printf("%s\t", e.name);
		printf("%lf\n",e.salary);
		}

	}
	fclose(fp);
}

void searchRecord(int sid)
{
	employee e;
	FILE *fp;
	fp=fopen("Myfile.txt","r");

	if(fp==NULL)
		{
			printf("not able to open file\n");
			return ;
		}
	while(fread(&e,sizeof(e),1,fp))
	{
		if(e.id==sid && e.flag==1)
		{
        	printf("Record found\n");
		printf("%d\t",e.id);
		printf("%s\t", e.name);
		printf("%lf\n",e.salary);
		fclose(fp);
		return ;
		}
	}
	printf("Cannot find record\n");
	fclose(fp);
}

void deleteRecord(int sid)
{
	employee e;
	FILE *fp;
	fp=fopen("Myfile.txt","r+");

	if(fp==NULL)
		{
			printf("not able to open file\n");
			return ;
		}

	while(fread(&e,sizeof(e),1,fp))
	{
		if(e.id==sid && e.flag==1)
		{
			e.flag=0;
			fseek(fp,-sizeof(e),SEEK_CUR);
			fwrite(&e,sizeof(e),1,fp);
		}
	}
	fclose(fp);
}

void modifyRecord(int sid)
{
	deleteRecord(sid);
	addRecord();
}

void bubbleSort()
{
	FILE *fp;
	fp=fopen("Myfile.txt","r");

	if(fp==NULL)
		{
			printf("not able to open file\n");
			return ;
		}

	int i=0;
	employee em[size],e;

	while(fread(&e,sizeof(e),1,fp))
	{
		em[i].id = e.id;
		em[i].salary = e.salary;
		em[i].flag = e.flag;
		strcpy(em[i].name, e.name);
		i++;
	}
	fclose(fp);

	for(int i=size-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(em[j].id>em[j+1].id)
				swap(&em[j] ,&em[j+1]);
		}
	}

	FILE *fps;
	fps=fopen("Myfile.txt","w");
	fseek(fp,0,SEEK_SET);
	if(fps==NULL)
		{
			printf("not able to write in file\n");
			return ;
		}
	int j=0;
	while(size--)
	{
		fwrite(&em[j],sizeof(em[j]),1,fps);
		j++;
	}
	fclose(fps);
}

void swap(employee e1[],employee e2[])
{
	int c=e1->id;
	e1->id = e2->id;
	e2->id = c;

	int f = e1->flag;
	e1->flag =e2->flag;
	e2->flag = f;

	double p = e1->salary;
	e1->salary = e2->salary;
	e2->salary = p;

	char ch[10];
	strcpy(ch,e1->name);
	strcpy(e1->name, e2->name);
	strcpy(e2->name, ch);
}

