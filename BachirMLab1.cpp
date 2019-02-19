
#include"Standards.h"
#include"Inventory.h"
#include"Company.h"

const int inventoryCounts = 50;

int main(void) {

	int inventoryCount;

	ifstream fin;
	ofstream fout;

	//Create and Open Lab1out.txt (Output File)
	fout.open("Lab1Out.txt");

	/*=================================================================================================================
	==============================================[Part 1: Printout Header]============================================
	=================================================================================================================*/

	//Print Course Heading
	PrintCourseHeading(fout);

	//Print File Names
	PrintFileName(fout);

	/*=================================================================================================================
	===============================================[Part 2: The Inventory]=============================================
	=================================================================================================================*/

	//Define Inventory struct
	inventoryStructType inventory[MAX_INVENTORY_STRUCT];

	//Open inventoryInput.txt file
	fin.open("inventoryInput.txt");

	//Get DATA from Inventory File
	inventoryCount = InventoryGettingData(fin, inventory);

	//	InventoryCount calculation checked :D
	cout << "inventory Count ==> [" << inventoryCount << endl;

	//Print Inventory Report - Unsorted
	PrintInventoryData(fout, inventory, inventoryCount, "InventoryReport - Unsorted");

	//Sort Inventory Struct
	InventoryStructSorted(inventory, inventoryCount);

	//Print Inventory Report - Sorted
	PrintInventoryData(fout, inventory, inventoryCount, "InventoryReport - Sorted");

	//Close Inventory File
	fin.close();

	/*=================================================================================================================
	==================================================[Part 3: Company]================================================
	=================================================================================================================*/

	//Company Counters
	int companyCount;

	//Define Company Struct
	companyStructType companyS[MAX_COMPANIES_STRUCT];

	//Open CompanyInput.txt file
	fin.open("CompanyInput.txt");

	//Get DATA from CompanyInput.txt file
	companyCount = CompanyGettingData(fin, companyS);

	//Print out Heading
	PrintCompanyData(fout, companyCount, companyS);


	//Closr ComnpanyInput.txt file
	fin.close();

	/*=================================================================================================================
	=============================================[Part 4: Processing Orders]===========================================
	=================================================================================================================*/

	//Open ProcessInput.txt file
	fin.open("ProcessInput.txt");

	//Close ProcessInput.txt file
	fin.close();



	fout.close();

	return 0;

}

//Divider function
void PrintDivider(ofstream& fout, int width) {

	fout << setfill(SYMBOL) << setw(width) << SYMBOL << setfill(' ') << endl;
}

//Header on the Screen Printout function
void PrintCourseHeading(ofstream& fout) {

	int stringLength;

	string lab_courseNAME;

	lab_courseNAME = COURSE + " - " + LAB_NAME;

	//Divider
	PrintDivider(fout, 100);

	//Print College Name
	stringLength = static_cast<int>(COLLEGE.length());
	fout << setw((100 + stringLength) / 2) << COLLEGE << endl;

	//Programmer Name Printout
	stringLength = static_cast<int>(PROGRAMMER_NAME.length());
	fout << setw((100 + stringLength) / 2) << PROGRAMMER_NAME << endl;

	//Course name and Exercise Printout
	stringLength = static_cast<int>(lab_courseNAME.length());
	fout << setw((100 + stringLength) / 2) << lab_courseNAME << endl;

	PrintDivider(fout, 100);

}

//Print File Name
void PrintFileName(ofstream& fout) {

	fout << "Input can be found in the file, inventoryInput.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	fout << "Input can be found in the file, CompanyInput.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	fout << "Input can be found in the file, ProcessInput.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	fout << "Ouput can be found in the file, Lab1Out.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	//Skip Line
	fout << endl;



}
