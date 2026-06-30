#ifndef SAMEER_H
#define SAMEER_H
#include "UI.h"

#include<string>
#include<iostream>
using namespace std;
//=====================================================================================================================
class person{
	protected:
		string name;
        string gender;
		int age;
	public:
		 void setPersonData(){
			   
			cout<<"Enter the name\n";
			//cin.ignore();
			getline(cin,name);
			cout<<"Enter the gender\n";
			
			cin>>gender;
			//cout<<"Enter the age\n";
			age=validint("Enter AGE ",0,100);
		};
		 void displayPersonalData(){
			cout<<"Name :"<<name<<endl;
			cout<<"Gender :"<<gender<<endl;
			cout<<"Age :"<<age<<endl;
		};
		//================================
		//  SETTER & GETTER
		//================================
		string getname(){
			return name;
		}
		string getgender(){
			return gender;
		}
		int getage(){
			return age;
		}
		void setname(string name){
			this->name=name;
		}
		void setgender(string gender){
			this->gender=gender;
		}
		void setage(int age){
			this->age=age;
		}
		//======================================
		person(){
		};
		person(string name,string gender,int age):name(name),gender(gender),age(age) {}
};
//==========================================================================================================================
//                           STUDENT
//==========================================================================================================
class student : public person{
	private:
		int roll_no;
		string section;
		string department;
		double marks;
	public:
		student(){
		}
		
		student(string name,string gender,int age,int roll_no,string section,string department,double marks)
		:person(name,gender,age)
		,roll_no(roll_no),section(section),department(department),marks(marks){
			
		}
	//============================
	//         getters
	//=========================
		int getrollno(){
			return roll_no;
		}
		string getsection(){
			return section;
		}
		string getdepartment(){
			return department;
		}
		double getmarks(){
			return marks;
		}
	//============================
	//      SETTERS
	//============================
	void setrollno(int rollno){
		roll_no=rollno;
	}
	void setsection(string section){
		this->section=section;
	}
	void setdepartment(string department){
		this->department=department;
	}
	void setmarks(double marks){
			this->marks=marks;
		}
	//================================
		
		void showresult(){
			cout<<"The student with roll no "<<roll_no<<" got "<<marks<<" marks"<<endl;
		}
		void studentinfodisplay(){
			cout<<"-------STUDENT DETIAL---------\n";
			displayPersonalData();
			cout<<"Roll number :"<<roll_no<<endl;
			cout<<"Department :"<<department<<endl;
			cout<<"Marks :"<<marks<<endl;
			cout<<"Section :"<<section<<endl;
			
			
		}
	void setstudentdata(){
		setPersonData();
		
		cout<<"Enter the Department "<<endl;
		//cin.ignore();
		getline(cin,department);
		//cout<<"Enter the Roll num "<<endl;	
		roll_no = validint("Enter the Roll num ",0,10000000);
		//cout<<"Enter the Marks "<<endl;
		marks=validdouble("Enter the Marks ",0,10000);
		cout<<"Enter the section "<<endl;
		cin>>section;
		
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class teacher:public person{
	private:
		int ID;
		string subject;
		double salary;
	public:
		teacher(string name,string gender,int age,int ID,string subject,double salary):
			person(name,gender,age){
				this->ID=ID;
				this->subject=subject;
				this->salary=salary;
			}
			teacher(){
			}
		// void teach(string subject){
		// 	this->subject=subject;
		// }
		
	//============================
	//         getters
	//=========================
		string getsubject(){
			return subject;
		}
		double getsalary(){
			return salary;
		}
		int get_ID(){
			return ID;
		}
	//============================
	//          SETTER
	//============================
	void setsubject(string subject){
		this->subject=subject;
	}
	void setSalary(double salary){
    this->salary =salary;
     }

    void setID(int id){
    ID = id;
    }
	//=================================

		void Teacherinfodisplay(){
			cout<<"-------TEACHER DETIAL---------\n";
			displayPersonalData();
			cout<<"ID :"<<ID<<endl;
			cout<<"Subject :"<<subject<<endl;
			cout<<"Salary :"<<salary<<endl;
		}
		void setteacherdata(){
			setPersonData();
			//cout<<"Enter the ID :"<<endl;
			ID=validint("Enter the ID ",0,10000000);
			cout<<"Enter the Subject :"<<endl;
			cin.ignore();
			getline(cin,subject);
			//cout<<"Enter the salary :"<<endl;
			salary=validdouble("Enter the Salary ",0,500000);
			
		}
};
//========================================================================================================================
class admin:public person{
	private:
		int staff_id;
		string duty;
		double salary;
	public:
		admin(string name,string gender,int age,int staff_id,string duty,double salary)
		:person(name,gender,age){
			this->staff_id=staff_id;
			this->duty=duty;
			this->salary=salary;
		}
		admin(){
		}
	//============================
	//         getters
	//=========================
		int getstaff_id(){
			return staff_id;
		}
		string getduty(){
			return duty;
		}
		double getsalary(){
			return salary;
		}
	//===============================
	//        SETTER
	//==============================
		void setduty(string duty){
			this->duty=duty;
		}
		void setstaff_id(int id){
			staff_id=id;
		}
		void setsalary(double salary){
			this->salary=salary;
		}
	//=============================
	    void displayStaffData(){

        cout << "\n----- Staff Data -----\n";

        displayPersonalData();

        cout << "Staff ID: " << staff_id << endl;
        cout << "Duty: " << duty << endl;
        cout << "Salary: " << salary << endl;
    }
     void setStaffData(){

        setPersonData();
       // cout<<"Enter the staff ID:\n";
        staff_id=validint("Enter the staff ID ",0,10000000);
        cout<<"Enter the staff duty:\n";
        cin.ignore();
		getline(cin,duty);
        //cout<<"Enter the salary:\n";
        salary=validdouble("Enter the Salary ",0,500000);
    }

};
#endif