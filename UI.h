#ifndef UI_H
#define UI_H
#include<string>

double validdouble(std::string prompt,double min_value,double max_value);

int validint(std::string messagetoshow, int min_value,int max_value);

void Datadisplaymenu();

void datasetmenu();

void savealldata();

void loadalldata();
#endif