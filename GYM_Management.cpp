
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct student   
{
    char name[20];
    int roll_no;
    char DOB[50];
    char time[50];
}s;
class Gym
{
	public:
		void create();
		void display();
		void search();
		void append();
		void del();
};
void Gym::create()
{
	s *student; 
    FILE *fp; 
    int n,i; 
    cout<<"How many gym records to be created:\n";
    cin>>n; 
    fp = fopen("GYM.txt","w"); 
    student=(s *)calloc(n,sizeof(s)); 
    for(i=0;i<n;i++)
    {
        cout<<"\tEnter name of student: "<<endl;
        cin>>student[i].name;
        cout<<"\tEnter Roll_number of last three numbers AP21110010___ of student: "<<endl;
        cin>>student[i].roll_no;
        cout<<"\tEnter D.O.B of student: "<<endl;
        cin>>student[i].DOB;
        cout<<"\tEnter the time slot in 24 clock format (eg: 6-7,14-15....): "<<endl;
        cin>>student[i].time;
        fwrite(&student[i],sizeof(s),1,fp); 
    }
    fclose(fp);
}
void Gym::display()
{
	FILE *fp; 
    fp= fopen("GYM.txt","r"); 
    s student; 
    cout<<"\n\nName\t\tRoll_Number\tD.O.B\t\tTime Slot(24hr Clock)\n";
    while(fread(&student,sizeof(s),1,fp))
    {
        cout<<student.name<<"\t\t"<<student.roll_no<<"\t\t"<<student.DOB<<"\t\t"<<student.time<<"\n"<<endl;
    }
    fclose(fp);
}
void Gym::search()
{
	FILE *fp; 
	s student; 
	int found=0,roll; 
	fp=fopen("GYM.txt","r"); 
	cout<<"\tEnter Roll_number of last three numbers AP21110010___ of student: \n";
	cin>>roll; 
	while((fread(&student,sizeof(s),1,fp)==1)) 
	{
		if(student.roll_no==roll) 
		{
			found=1; 
			cout<<"\n\nStudent details with the roll number: "<<roll<<endl;
			cout<<"Name: "<<student.name<<endl;
			cout<<"Roll number: "<<student.roll_no<<endl;
			cout<<"D.O.B: "<<student.DOB<<endl;
        	cout<<"Slot Alloted: "<<student.time;
			break;
		}
	}
	if(found==0) 
	printf("\nStudent Record not found\n"); 
	fclose(fp);
}
void Gym::append()
{
	s *student; 
    FILE *fp; 
    int n,i; 
    cout<<"How many student records to be created:\n";
    cin>>n; 
    fp = fopen("GYM.txt","a"); 
    student=(s *)calloc(n,sizeof(s)); 
    for(i=0;i<n;i++)
    {
        cout<<"\tEnter name of student: "<<endl;
        cin>>student[i].name;
        cout<<"\tEnter Roll_number of last three numbers AP21110010___ of student: "<<endl;
        cin>>student[i].roll_no;
        cout<<"\tEnter D.O.B of student: "<<endl;
        cin>>student[i].DOB;
        cout<<"\tEnter the time slot in 24 clock format (eg: 6-7,14-15....): "<<endl;
        cin>>student[i].time;
        fwrite(&student[i],sizeof(s),1,fp); 
    }
    fclose(fp);
}
void Gym::del()
{
	s student; 
	FILE *fp,*fp1; 
	fp=fopen("GYM.txt","r"); 
	fp1=fopen("GYM_DEL.txt","w"); 
	int roll,found=0; 
	cout<<"Enter Roll_number of last three numbers AP21110010___ of student to delete:\n";
	cin>>roll; 
	while((fread(&student,sizeof(s),1,fp))) 
	{
		if(student.roll_no==roll) 
			found=1; 
		else
			fwrite(&student,sizeof(s),1,fp1); 
	}
	fclose(fp); 
	fclose(fp1); 
	if(found)
	{
		fp=fopen("GYM.txt","w"); 
		fp1=fopen("GYM_DEL.txt","r"); 
		while(fread(&student,sizeof(s),1,fp1)) 
		{
			fwrite(&student,sizeof(s),1,fp); 
		}
		fclose(fp); 
		fclose(fp1); 
	}
	else
	printf("File not Found\n");
}
int main()
{
	do
	{
		int ch;
		Gym g1;
		cout<<"\t\t\t**SRM GYM MANAGMENT SYSTEM**\n\n";
		cout<<"\n\t1. NEW MEMBER";
		cout<<"\n\t2. DISPLAY ALL RECORDS";
		cout<<"\n\t3. SEARCH FOR A PARTICULAR RECORD ";
		cout<<"\n\t4. APPEND MORE MEMBER DETAILS";
		cout<<"\n\t5. DELETE MEMBER";
		cout<<"\n\t6. Exit\n";
		cout<<"Enter the operation index you want to perform:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g1.create();
				break;
			case 2:
				g1.display();
				break;
			case 3:
				g1.search();
			    break;
			case 4:
				g1.append();
				break;
			case 5:
				g1.del();
				break;
			case 6:
				exit(0);
		}
	}while(1);	
}
