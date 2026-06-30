#include <iostream>
#include<vector>
#include<string>
#include "sameer.h"
#include "UI.h"
using namespace std;


int main() {
    loadalldata();
    int mainchoice;

    while(true) {
        cout << "\n";
        cout << "  +======================================+\n";
        cout << "  |      SCHOOL MANAGEMENT SYSTEM        |\n";
        cout << "  +======================================+\n";
        cout << "  |   1. Enter New Data                  |\n";
        cout << "  |   2. Display Data                    |\n";
        cout << "  |   3. Exit System                     |\n";
        cout << "  +======================================+\n";

        

        mainchoice = validint("  Enter your choice: ", 1, 3);

        if(mainchoice == 1)      datasetmenu();
        else if(mainchoice == 2) Datadisplaymenu();
        else if(mainchoice == 3) {
            cout << "\n";
            cout << " =========================================\n";
            cout << " ||         Data Saved! Goodbye         ||\n";
            cout << " ==========================================\n";
            savealldata();
            break;
        }
    }
}









