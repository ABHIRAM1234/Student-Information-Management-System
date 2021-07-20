#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main();
void show_data(int searchkey);
void get_data(int i);
void search_student(int searchkey);
void add_student();
void edit_student(int idnumber);
void fullscreen();
int ts;

struct student
{
	int rollno;
	string name;
	string fname;
	string cell;
	string dob;
	float cgpa;
	string address;
};

student rec[50];
int main()
{
	int choice;
	int idnumber;
	int searchkey;
	
	cout<<"\n\tWhat do you want to do?"<<endl;
	cout<<"\t\t----------------------"<<endl;
	cout<<"\t\t1-Add student"<<endl;
	cout<<"\t\t2-Edit Student"<<endl;
	cout<<"\t\t3-Search Student"<<endl;
	cout<<"\t\t4-Quit Program"<<endl;
	cout<<"\t\t----------------------"<<endl;
	cout<<"Enter your choice: ";
	
	cin>>choice;
	switch(choice)
 	{
 		case 1:
 			cout<<"Enter the Total Number of Student(s)";
 			cin>>ts;
 			while(ts--)
	    		add_student();
	    	main();
	    	
    		break;
   		case 2:         //If there are no records in array then it will ask the user to input records first.
    		if(rec[0].rollno==0)
   			{
    			cout<<"Please Add sudents first."<<endl;
     			system("pause");
    			main();
   			}		
    		else         //If records are present in array then it will show the table.
   			{ 
     			cout<<endl;
			    cout<<"--------------------------------------------------------------------------------"<<endl;
			    cout<<"---------------------------Student record Table---------------------------------"<<endl;
			    cout<<"--------------------------------------------------------------------------------"<<endl; 
			    cout<<"ID\t"<<"Roll\t"<<"Name\t"<<"Father\t"<<"Cell no.\t"<<"DOB\t"<<"CGPA\t"<<"address\n\n";
			    cout<<"--------------------------------------------------------------------------------"<<endl; 

     			for(int i=0;i<=ts;i++)
    			{
      				show_data(i);     //funtion is called with index value to show data.
     			}

     			cout<<"--------------------------------------------------------------------------------"<<endl;
     			cout<<"Which ID number your want to edit: ";
   
     			cin>>idnumber;            //Asking the user at which ID he wants to make a change.
       
    			if(idnumber>ts || idnumber<0)  //Validating the ID number.
    			{	      
          			cout<<"\nInvalid ID Number."<<endl;
       			}
       			else
    			{
          			edit_student(idnumber);    //Passing ID number to Edit Function.
       			}
   			}
   				break;
   
			case 3:
			    if(rec[0].rollno==0)     //If no record exist then ask the user o enter records first.
			   	{   
			    	cout<<"Please Add sudents first."<<endl;
			     	system("pause");
			     	main();         //Return to main so user can input new record.
			    }
			    
				else
			   	{
			    	cout<<"Enter roll_no of student you want to search: ";
			     	cin>>searchkey;     //roll_no as the search key can be entered by user.
			     	search_student(searchkey);
				}
			    break;
   				
			case 4:
    			return 0;        //Terminating the records.
    			break;
   			default:         //Default value for ivalid Input. 
    			cout<<"Invalid number."<<endl;
    			system("pause");
  				main();
  	}

  return 0;
}

  
void get_data(int i)        //Function for receiving data from user and storing in the variables with values.
{   
	cout<<"Enter student roll number: ";
  	cin>>rec[i].rollno;
  	cout<<"Enter student name: ";
	cin>>rec[i].name;
	cout<<"Enter student's Father name: ";
	cin>>rec[i].fname;
	cout<<"Enter student's cell phone number: ";
	cin>>rec[i].cell;
	if(rec[i].cell.length()!=10)
	{
		cout<<"Invalid Length";
		exit(0);
	}
	cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
	cin>>rec[i].dob;
	cout<<"Enter the student's CGPA: ";
	cin>>rec[i].cgpa;
	if((rec[i].cgpa < 0) || (rec[i].cgpa>10))
	{
		cout<<"Invalid Value";
		exit(0);
	}
	cout<<"Enter student's Address: ";
	cin>>rec[i].address;
}

void show_data(int searchkey)      //Function for showing data on the screen.
{    
	int i=searchkey;
	cout<<i<<"    ";
	cout<<rec[i].rollno<<"\t";
	cout<<rec[i].name<<"\t";
	cout<<rec[i].fname<<"\t";
	cout<<rec[i].cell<<"\t";
	cout<<rec[i].dob<<"\t";
	cout<<rec[i].cgpa<<"\t";
	cout<<rec[i].address<<"\n\n";
}

void search_student(int searchkey)
{
	for(int i=0;i<=ts;i++)       //Loop thrugh complete array.
 	{ 
   		if(rec[i].rollno==searchkey)    //If roll number matches to search term.
  		{		   
    		cout<<"ID\t"<<"Roll\t"<<"Name\t"<<"Father\t"<<"Cell no.\t"<<"DOB\t"<<"CGPA\t"<<"Address\n\n";
    		show_data(i);       //A function is used inside another function.
    		system("pause");
   		}
  	}	 
}

void add_student()         //This function is used to add record of new student.
{    
	for(int i=0;i<=ts;i++)
 	{
    	get_data(i);          //Loop was processed 5 times to get input for 5 students.
  	}
  	system("CLS");
  	cout<<endl;
  	cout<<"--------------------------------------------------------------------------------"<<endl;
  	cout<<"---------------------------Student record Table---------------------------------"<<endl;
  	cout<<"--------------------------------------------------------------------------------"<<endl;
  	cout<<"ID\t"<<"Roll\t"<<"Name\t"<<"Father\t"<<"Cell no.\t"<<"DOB\t"<<"CGPA\t"<<"Address\n\n";
  	cout<<"--------------------------------------------------------------------------------"<<endl;

  	for(int i=0;i<=ts;i++)
 	{
    	show_data(i);        //Loop was processed for 5 times to show obtained records.
  	}
  	cout<<"--------------------------------------------------------------------------------"<<endl;
  	cout<<"---------------------------------FINISH-----------------------------------------"<<endl;
  	cout<<"--------------------------------------------------------------------------------"<<endl;
  	system("pause");

  	main();          //Return to main function to again show menu.
}

void edit_student(int idnumber)     //function is used to edit existing record.
{  
	for(int i=0;i<=ts;i++)       
 	{  
   		if(idnumber==i)       //Through loop every value is compared with search term.
  		{         
    		cout<<"\nExisted information about this record.\n\n";
		    cout<<"--------------------------------------------------------------------------------"<<endl;
		    cout<<"ID\t"<<"Roll\t"<<"Name\t"<<"Father\t"<<"Cell no.\t"<<"DOB\t"<<"CGPA\t""Address\n\n";
		    cout<<"--------------------------------------------------------------------------------"<<endl;
		    show_data(i);       //Load information for existing record.
		    cout<<"\n\nEnter new data for above shown record.\n\n";
		    get_data(i);         //Inputing data for that specific record.
		    cout<<"\n\nRecord updated successfully."<<endl;
		    system("pause");
		    main();           //Return to main function.
   		}	
  	}
}
