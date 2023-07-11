/*Write a c++ program to read K listsof names and merge them using K-way
merge algorithm with k=8 */

#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>

class record
{
public:char usn[20];
char name[20];
};

int no;

fstream file[8];

char fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};

void merge_file(char *file1,char *file2,char *filename)
{
	record recrd[20];
	int k;
	k=0;
	fstream f1,f2;
	
	f1.open(file1,ios::in);
	f2.open(file2,ios::in);

	while(!f1.eof())
		{
			f1.getline(recrd[k].name,20,'|');
			f1.getline(recrd[k++].usn,20,'\n');
		}
	
	while(!f2.eof())
		{
			f2.getline(recrd[k].name,20,'|');
			f2.getline(recrd[k++].usn,20,'\n');
		}

record temp;
int t,y;

	for(t=0;t<k-2;t++)
	for(y=0;y<k-t-2;y++)

	if(strcmp(recrd[y].name,recrd[y+1].name)>0)
		{
			temp=recrd[y];
			recrd[y]=recrd[y+1];
			recrd[y+1]=temp;
		}

fstream temp1;
temp1.open(filename,ios::out);

	for(t=1;t<k-1;t++)
		temp1<<recrd[t].name<<"|"<<recrd[t].usn<<"\n";
f1.close();
f2.close();
temp1.close();
}


void kwaymerge()
{
char filename[7][20]={"11.txt","22.txt","33.txt","44.txt","111.txt","222.txt","1111.txt"};
int i;
int k=0;
	for(i=0;i<8;i+=2)
		{
			merge_file(fname[i],fname[i+1],filename[k++]);
		}
	
	k=4;

	for(i=0;i<4;i+=2)
		{
			merge_file(filename[i],filename[i+1],filename[k++]);
		}

	merge_file(filename[4],filename[5],filename[6]);
return;
}


int main()
{
int i,no;
record rec[20];
clrscr();

	cout<<"Enter the no of records\n";
	cin>>no;

	cout<<"Enter the details\n";
	for(i=0;i<8;i++)
	file[i].open(fname[i],ios::out);

		for(i=0;i<no;i++)
			{
				cout<<"NAME:";
				cin>>rec[i].name;
				cout<<"USN:";
				cin>>rec[i].usn;
				file[i%8]<<rec[i].name<<"|"<<rec[i].usn<<"\n";
			}

for(i=0;i<8;i++)
file[i].close();

kwaymerge();
fstream result;

result.open("1111.txt",ios::in);
cout<<"Sorted Records:";

char name[20],usn[20];
	
	for(i=0;i<no;i++)
		{
			result.getline(name,20,'|');
			result.getline(usn,20,'\n');
			cout<<"\nNAME:"<<name<<"\nUSN:"<<usn<<"\n";
			getch();
		}
return 0;
}