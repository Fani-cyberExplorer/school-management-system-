#include <iostream>
#include<vector>
#include<string>
#include "sameer.h"
#include "UI.h"


int main(){
         loadalldata();
		 
int mainchoice;

while(true)
    {
	cout<<"=====================================\n";
	cout<<"        SCHOOL MANAGMENT SYSTEM      \n";
	cout<<"=====================================\n";
	cout<<"1:Enter new data"<<endl;
	cout<<"2:Display the data"<<endl;
	cout<<"3:Exist the system"<<endl;
	cout<<"Enter your choice"<<endl;
	try{
	if(!(cin>>mainchoice)){
		throw invalid_argument("Please enter a number not a letter!");
	}
    if(mainchoice<1 || mainchoice>3){
		throw out_of_range("Choice must be between 1 and 3!");
	}
	}catch(out_of_range &e){
		cout<<"Invalid input:  "<<e.what()<<"\n";

	}
	catch(invalid_argument &a){
		cout<<"Invalid input:  "<<a.what()<<"\n";
		cin.ignore();
		cin.ignore(1000, '\n');
		continue;
	}
    if(mainchoice==1)
	{
	    datasetmenu();
		
        }
    else if(mainchoice==2)
	{
	    Datadisplaymenu();
        }
    
    else if(mainchoice==3)
	{
	    cout<<"Existing the system:Goodbye!"<<endl;
	    savealldata();
	    break;
        }
        
    // else{
	//     cout<<"Invalid input!\n";
    //     }
    }
}









