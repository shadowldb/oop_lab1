//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Standards.h
//Associated File:    None
//Header File contains:
// - Preprocessor Directives
// - Constant Declarations
//Prototype for: 
//PrintDivider, PrintCourseHeading, PrintFileName
//---------------------------------------------------------------------------------------------------------------------
#ifndef Standards_h
#define Standards_h

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Constants Values for Program
const double MARKUP = 1.75;
const int MAX_INVENTORY_STRUCT = 30;
const int MAX_COMPANIES_STRUCT = 10;


//Heading Constants
const string COLLEGE = "SUNY Broome";
const string COURSE = "CST 150";
const string PROGRAMMER_NAME = "Mohamed Ali Larbi Daho Bachir";
const string LAB_NAME = "Lab 1";

//Screen Information
const char SYMBOL = '-';

//Divider
void PrintDivider(ofstream& fout, int width);

//Header on the Screen Printout function
void PrintCourseHeading(ofstream& fout);

//Print Files Name
void PrintFileName(ofstream& fout);

#endif // !Standards_h
