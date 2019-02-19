//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Company.h
//Associated File:    None
//Header File contains:
// - Struct Type for Inventory

//---------------------------------------------------------------------------------------------------------------------

#ifndef Company_h
#define Company_h

#include"Standards.h"

//Declare Company Struct
struct companyStructType {

	string companyName;
	string address;
	string city;
	string state;
	string zip;

	int companyID;

};

//Get DATA From Company.txt
int CompanyGettingData(ifstream& fin, companyStructType companyStruct[]);

//Print Company Heading
void PrintCompanyHeading(ofstream& fout);

//Print out Company DATA
void PrintCompanyData(ofstream& fout, int companyCount, companyStructType companyStruct[]);

#endif // !Company_h



#endif // !Company_h
