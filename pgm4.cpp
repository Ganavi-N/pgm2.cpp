#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
 
 void insert();
 void pack();
 void unpack();
 void help();
 void modify();
 void search();

 class student
 {
 public:
	char rrn[25],name[25],age[5],sem[5],branch[5],usn[5];
 };
 student s;

 char buffer[55],temp[55];
 int RRN=0;
 fstream fp;
 fstream gp;

 void main()
   {
    int c;
    clrscr();
 	while(1)
	     {
		cout<<"\t*****Enter your choice*****\n";
		cout<<"1.Pack  2.unpack 3.Modify  4.search 5.exit"<<endl;
		cin>>c;

		switch(c)
		{
			case 1:	pack();
			break;
		
			case 2:	unpack();
			break;
		
			case 3:	modify();
			break;
	     
			case 4:	search();
			break;
		
			case 5:	exit(0);
		
			default:	exit(0);
		}
	}
}

 void pack()
  {
	fp.open("RRN.txt",ios::app);
	gp.open("RRN.txt",ios::in);
	RRN=0;
	
	while(!gp.eof())			    //to get next RRN simply counting the number of lines 
	 {					            //in the file.
	gp.getline(buffer,60,'\n');
	RRN++;
	 }
	gp.close();
	
	insert();
	fp<<RRN<<"|"<<buffer<<endl;		//before inserting new data,insert calculated RRN.
	fp.close();
	clrscr();
  }

 void insert()
   {
    cout<<"USN";
	cin>>temp;
	strcpy(buffer,temp);
	strcat(buffer,"|");
	cout<<"Name";help();
	cout<<"sem";help();
	cout<<"age";help();
	cout<<"Branch";help();
   }

void help()
   {
	cin>>temp;
	strcat(buffer,temp);
	strcat(buffer,"|");
   }

void unpack()
   {
    fp.open("rrn.txt",ios::in);
	fp.getline(buffer,60,'\n');
	cout<<"\t*****Unpacked record*****"<<endl;
	cout<<"RRN\tUSN\t\tName\tSEM\tage\tBranch"<<endl;
	while(!fp.eof())
	  {
	  sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s.rrn,s.usn,s.name,s.sem,s.age,s.branch);
	  cout<<s.rrn<<"\t"<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.age<<"\t"<<s.branch<<"\n";
	  fp.getline(buffer,60,'\n');
	  }
      fp.close();
      getch();
      clrscr();
   }

void modify()
  {
	char key[25],RRN[25],modify[55];
	int Notfound=1;
	cout<<"enter the key to Modify (RRN)\n";
	cin>>key;
    fp.open("RRN.txt",ios::in);
    gp.open("RRN1.txt",ios::app);

    fp.getline(buffer,60,'\n');
	while(!fp.eof())
	   {
		sscanf(buffer,"%[^|]|",RRN);
		if(strcmp(RRN,key)!=0)
		  {
			gp<<buffer<<endl;
		  }
		else
		 {
		Notfound=0;
		cout<<"\t*****record found*****"<<endl;
		cout<<"Enter New data"<<endl;

		insert();
		strcpy(modify,buffer);
		gp<<RRN<<"|"<<modify<<endl;
		cout<<"\t*****Record Modification successful*****"<<endl;
		 }
		fp.getline(buffer,60,'\n');
      }
	if(Notfound)
		{
		  cout<<"\t*****Record not found*****"<<endl;
		}
	fp.close();
	gp.close();

	char new1[]={"RRN1.txt"};
	char old[]={"RRN.txt"};

	remove("RRN.txt");
	rename(new1,old);

	getch();
	clrscr();
     }

void search()
   {
	char key[25],RRN[25],modify[55];
	cout<<"enter the key to search (RRN)\n";
	cin>>key;

	fp.open("RRN.txt",ios::in);
	fp.getline(buffer,60,'\n');

	  while(!fp.eof())
	       {
		sscanf(buffer,"%[^|]|",RRN);
		if(strcmp(RRN,key)==0)
		{
		  cout<<"\t*****record found*****"<<endl;
		  cout<<"RRN\tUSN\t\t\NAME\tSEM\tage\tBranch"<<endl;
		  sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s.rrn,s.usn,s.name,s.sem,s.age,s.branch);
		  cout<<s.rrn<<"\t"<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.age<<"\t"<<s.branch<<"\n";
		  break;
		}
	fp.getline(buffer,60,'\n');
		if(fp.eof())
		 {
		  cout<<"\tRecord not found  :("<<endl;
		 }
	 }
	    fp.close();
	    getch();
	    clrscr();
   }