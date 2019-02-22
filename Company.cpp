//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Inventory.cpp
//Associated File:    None
//Inventory.cpp File contains:
// - Calling Inventory.h
// - 
//---------------------------------------------------------------------------------------------------------------------
#include"Standards.h"
#include"Company.h"

//Get DATA from CompanyInput.txt file
int CompanyGettingData(ifstream& fin, companyStructType companyStruct[]) 
{

	int companyCount;

	companyCount = 0;

	while (!fin.eof()) 
	{

		fin >> companyStruct[companyCount].companyID;
		getline(fin, companyStruct[companyCount].companyName);
		getline(fin, companyStruct[companyCount].address);
		getline(fin, companyStruct[companyCount].city);
		getline(fin, companyStruct[companyCount].state);
		getline(fin, companyStruct[companyCount].zip);
		

	
		companyCount++;
	}

	return companyCount;

}

//Print Company Heading
void PrintCompanyHeading(ofstream& fout) 
{

	//Print Out Divider
	PrintDivider(fout, 100);

	//Print out Title
	fout << "Company Report" << endl;

	//Print Out Divider
	PrintDivider(fout, 100);

	fout << "Company ID" << right << setw(15) <<
		"Company Name" << right << setw(17) <<
		"Address" << right << setw(25) <<
		"City" << right << setw(22) <<
		"State" << right << setw(10) <<
		"Zip" << endl;
}

//Print out Company DATA 
void PrintCompanyData(ofstream& fout, int companyCount, companyStructType companyStruct[])
{

	int index;

	index = 0;

	PrintCompanyHeading(fout);

	while (index < companyCount) 
	{

		fout << companyStruct[index].companyID <<
			companyStruct[index].companyName << right << setw(20) <<
			companyStruct[index].address << right << setw(27) <<
			companyStruct[index].city << right << setw(20) <<
			companyStruct[index].state << right << setw(20) <<
			companyStruct[index].zip << endl;

		index++;
	}

	//Print Out Divider
	PrintDivider(fout, 100);

	//Print Company Counter
	fout << "Company Count = " << companyCount << endl;

	//Print Out Divider
	PrintDivider(fout, 100);

}
