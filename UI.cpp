
#include "UI.h"
#include "sameer.h"
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
//=================================================================================
vector<student>list_of_students;
vector<teacher>list_of_teachers;
vector<admin>list_of_admins;
//====================================================================================
//                DATA DISPLAY MENU
//====================================================================================
void Datadisplaymenu(){
	int choice;
	bool stay=true;
	while(stay){
cout << "\n";
cout << "\n  ****************************************************\n";
cout << "  *            DISPLAY DATA MENU                    *\n";
cout << "  ****************************************************\n";
cout << "\n  --- DISPLAY OPTIONS ---\n";
cout << "  1. Display All Students\n";
cout << "  2. Display All Teachers\n";
cout << "  3. Display All Admin Staff\n";
cout << "  4. Display Everything\n";
cout << "\n  --- SEARCH OPTIONS ---\n";
cout << "  5. Search Specific Teacher\n";
cout << "  6. Search Specific Student\n";
cout << "  7. Search Specific Admin\n";
cout << "\n  --- COUNT OPTIONS ---\n";
cout << "  9. How many Students registered\n";
cout << "  10. How many Teachers registered\n";
cout << "  11. How many Admins registered\n";
cout << "\n  --- NAVIGATION ---\n";
cout << "  8. Back to Main Menu\n";
cout << "  ****************************************************\n";

   
	choice=validint("Enter choice: ",1,11);
	
    if(choice==1 || choice==4){
    	if(list_of_students.empty()){
    		cout<<"[No Student Record Found!]\n";
		}
		else{
		
    	for(int i=0;i<list_of_students.size();i++){
    		list_of_students[i].studentinfodisplay();
		}
	}
    }
    
    else  if(choice==2 ||choice==4){
    	if(list_of_teachers.empty()){
    		cout<<"[No Teacher Record Found!]\n";
		}
		else{
			for(int i=0;i<list_of_teachers.size();i++){
				list_of_teachers[i].Teacherinfodisplay();
			}
		}
	}
	else  if(choice==3||choice==4){
		if(list_of_admins.empty()){
    		cout<<"[No Admin Record Found!]\n";
		}
		else{
			for(int i=0;i<list_of_admins.size();i++){
				list_of_admins[i].displayStaffData();
			}
		}
	}
	else if(choice==5){
		cout<<"Enter the ID of the teacher:\n";
		int a;cin>>a;
		bool flag=false;
		for(int i=0;i<list_of_teachers.size();i++){
				if(a==list_of_teachers[i].get_ID()){
					cout<<"Teacher founded!\n";
					flag=true;
					list_of_teachers[i].Teacherinfodisplay();
					break;
				}
			}
		if(!flag)
		cout<<"No Teacher record found!:"<<endl;
		
	}
	else if(choice==6){
		cout<<"Enter the ID of the Student:\n";
		int a;cin>>a;
		bool flag=false;
		for(int i=0;i<list_of_students.size();i++){
				if(a==list_of_students[i].getrollno()){
					flag=true;
					cout<<"student founded!\n";
					list_of_students[i].studentinfodisplay();
					break;
				}
			}
		if(!flag)
		cout<<"No Student Record Found!:\n";
		
	}
	else if(choice==7){
		cout<<"Enter the ID of the admin:\n";
		int a;cin>>a;
		bool flag=false;
		for(int i=0;i<list_of_admins.size();i++){
				if(a==list_of_admins[i].getstaff_id()){
					flag=true;
					cout<<"Staff founded!\n";
					list_of_admins[i].displayStaffData();
					break;
				}
			}
		if(!flag)
		cout<<"No Admin Record Found!:\n";
		
	}
	else if(choice==8){
         stay=false;
	}
	else if(choice==9){
		cout<<"Total no of students: "<<list_of_students.size()<<endl;
		
	}
	else if(choice==10){
		cout<<"Total no of Teachers: "<<list_of_teachers.size()<<endl;
		
	}
	else if(choice==11){
		cout<<"Total no of Admins: "<<list_of_admins.size()<<endl;
		
	}
    }
}
//===============================================================================================================
//                DATA SET MENU                        
//===============================================================================================================
void datasetmenu() {
    int choice;
	bool stay=true;
	while(stay) {
    cout << "\n";
    cout << "  +======================================+\n";
    cout << "  |          DATA ENTRY MENU             |\n";
    cout << "  +======================================+\n";
    cout << "  |   1.  Add Student                    |\n";
    cout << "  |   2.  Add Teacher                    |\n";
    cout << "  |   3.  Add Admin Staff                |\n";
    cout << "  +======================================+\n";
    cout << "  |   4.  Back to Main Menu              |\n";
    cout << "  +======================================+\n";

    choice = validint("  Enter your choice: ", 1, 4);
    
	if(choice==1){
		student s;
		s.setstudentdata();
		list_of_students.push_back(s);
		cout<<"Student Enter successfully!"<<endl;
	} 
   else if(choice==2){
   	teacher t;
   	t.setteacherdata();
   	list_of_teachers.push_back(t);
   	cout<<"Teacher Enter Successfully!"<<endl;
   }
   else if(choice==3){
   	admin d;
   	d.setStaffData();
   	list_of_admins.push_back(d);
   	cout<<"Admin data enter Successfully!"<<endl;
   }
   else if(choice==4){
	stay=false;
   }
}
}

//====================================================================================================================================
//                 SAVE STUDENT DATA
//=====================================================================================================================
void savestudentdata(){
	ofstream file;
	file.open("studentinfo.txt");
	for(int i=0;i<list_of_students.size();i++){
		file<<list_of_students[i].getrollno()<<"\n"
		    <<list_of_students[i].getname()  <<"\n"
		    <<list_of_students[i].getgender()<<"\n"
		    <<list_of_students[i].getage()   <<"\n"
		    <<list_of_students[i].getdepartment()<<"\n"
		    <<list_of_students[i].getsection()   <<"\n"
		    <<list_of_students[i].getmarks()     <<"\n";
	}
	file.close();
	cout<<"Students data saved to studentsinfo.txt\n";
}
//==============================================================================
//                 SAVE TEACHER DATA
//==============================================================================
void saveteacherdata(){
	ofstream file;
	file.open("teacherinfo.txt");
	for(int i=0;i<list_of_teachers.size();i++){
		file<<list_of_teachers[i].get_ID()  <<"\n"
		    <<list_of_teachers[i].getname() <<"\n"
		    <<list_of_teachers[i].getsubject() <<"\n"
		    <<list_of_teachers[i].getage()     <<"\n"
		    <<list_of_teachers[i].getgender()  <<"\n"
		    <<list_of_teachers[i].getsalary()  <<"\n";
	}
	file.close();
	cout<<"Teachers data saved to studentsinfo.txt\n";
}
//==============================================================================
//                 SAVE Staff   DATA
//==============================================================================
void savestaffdata(){
	ofstream file;
	file.open("admininfo.txt");
		for(int i=0;i<list_of_admins.size();i++){
			file<<list_of_admins[i].getstaff_id()        <<"\n"
			    <<list_of_admins[i].getname()            <<"\n"
			    <<list_of_admins[i].getage()             <<"\n"
			    <<list_of_admins[i].getgender()          <<"\n"
			    <<list_of_admins[i].getduty()            <<"\n"
			    <<list_of_admins[i].getsalary()          <<"\n";
			    
		}
		file.close();
		cout<<"Staff data saved to studentsinfo.txt\n";
	}

//====================================================================================================================================
//                 SAVE ALL     DATA
//=====================================================================================================================

void savealldata(){
	savestudentdata();
	saveteacherdata();
	savestaffdata();
}

//==============================================================================================
//                 lOAD STUDENT DATA
//=========================================================================================
void laodstudentdata(){
	ifstream file;
	file.open("studentinfo.txt");
	if(!file.is_open()){
		cout<<"File not found! \nOR File not opened!"<<endl;
		return;
	}
	string name,gender,department,section;
	int roll,age,marks;
	while(file>>roll){
		file.ignore();
		getline(file,name);
		file>>gender; file.ignore();
		file>>age;  file.ignore();
		getline(file,department);
		file>>section;  file.ignore();
		file>>marks;file.ignore();
		
		student s(name,gender,age,roll,section,department,marks);
		list_of_students.push_back(s);
	}
	file.close();
	cout<<"Students data load successfully:\n";
}

//==========================================================================================
//                    LOAD TEACHER DATA
//==========================================================================================
void loadteacherdata(){
	ifstream file;
	file.open("teacherinfo.txt");
	if(!file.is_open()){
		cout<<"File not found! \nOR File not opened!"<<endl;
		return;
	}
	
	int id,age;
	double salary;
	string name,subject,gender;
	while(file>>id){file.ignore();
		
		getline(file,name);
		getline(file,subject);
		file>>age;file.ignore();
		file>>gender;file.ignore();
		file>>salary;file.ignore();
		teacher t(name,gender,age,id,subject,salary);
        list_of_teachers.push_back(t);
	}
	file.close();
	cout<<"Teachers data load successfully:\n";
}
//==========================================================================================
//                    LOAD admin DATA
//==========================================================================================
void loadadmindata(){
	ifstream file;
	file.open("admininfo.txt");
	if(!file.is_open()){
		cout<<"File not found! \nOR File not opened!"<<endl;
		return;
	}
		    
	int id,age;
	double salary;
	string gender ,name,duty;
	while(file>>id){file.ignore();
		getline(file,name);
		file>>age;file.ignore();
		file>>gender;file.ignore();
		getline(file,duty);
		file>>salary;file.ignore();
		
		admin d(name,gender,age,id,duty,salary);
		list_of_admins.push_back(d);

	}
	file.close();
	cout<<"Admin data load successfully:\n";
}
//=================================================================
//                    LOAD ALL FILES
//===========================================================
void loadalldata(){
	laodstudentdata();
	loadteacherdata();
	loadadmindata();
}
//===============================================================================
//                    Int EXCEPTION HANDLING
//==========================================================================
int validint(string messagetoshow, int min_value,int max_value){
	int value;
	while(true){
		cout<< messagetoshow<<endl;
		try{
			if(!(cin>>value)){
				cin.clear();
				cin.ignore(1000,'\n');
				throw invalid_argument("Enter a number not a letter!");
			}
			if(value<min_value||value>max_value){
				cin.clear();
				cin.ignore(1000,'\n');
			    throw out_of_range("Enter value must be in range of "
				+ to_string(min_value)+" and "+to_string(max_value));	
			}
			cin.ignore();
			return value;
		}
		catch(invalid_argument &e){
			cout<<"Invalid Input:"<<e.what()<<endl;
		}
		catch(out_of_range &e){
			cout<<"Invalid Input:"<<e.what()<<endl;
		}
	}
}
//===================================================================================
//                   Exception handling for doouble
//===================================================================================
double validdouble(string prompt,double min_value,double max_value) {
	double value;
	while(true){
		cout<<prompt<<endl;
		try{
		if(!(cin>>value)){
			cin.clear();
			cin.ignore(1000,'\n');
			throw invalid_argument("Enter a number not a letter!");
		}
		if(value <min_value||value>max_value){
			cin.clear();
			cin.ignore(1000,'\n');
          throw out_of_range("Enter value must be in range of"
		  + to_string(min_value)+" and "+ to_string(max_value));
		}
		return value;
	}

	catch(invalid_argument &e){
		cout<<"Invalid Input!"<<e.what()<<endl;
	}
	catch(out_of_range &e){
		cout<<"Invalid Input!"<<e.what()<<endl;
	}
	}
}