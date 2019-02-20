//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name: Mohamed Ali Larbi Daho Bachir
//Lab 1
//Total Possible Points -----------------------------------------------------------------------------------------> 200
//Points Lost---------------------------------------------------------------------------------------------------->-
//Lab Grade ----------------------------------------------------------------------------------------------------->
//Main Requirements
// Main named correctly
// Includes for header files above the main
// Variables named correctly & blocked by type
// Files Opened and closed in the main
// Processing blocked by Parts
// *Part 1
//  -Output file opened, formatting set to 2 decimals
//  -CourseHeading, File Names printed
// *Part 2
//  -Open the inventory input file
//  -Input the inventory data
//  -Calculate the inventory Prices
//  -Calculate the total quantity on hand
//  -Set reorder flags
//  -Print the inventory data
//  -Print the count of the inventory
//  -Sort the inventory data
//  -Print the inventory data
//  -Print the count of the inventory
// *Part 3
//  -Open the company input file
//  -Input the company data
//  -Print the company data
//  -Print the count of the companies
// *Part 4
//  -Open the order input file
//  -Process the orders
//Print the final inventory file updated with all orders processed
//Comments:
//
//
//
//Points Lost---------------------------------------------------------------------------------------------------->
//---------------------------------------------------------------------------------------------------------------------
//Inventory
//-Header and CPP file created, correctly named
//-Correctly documented and formatted, meets all standard Course Requirements
//-Functions included:
//  *Input Inventory
//  *Calculate Inventory Prices
//  *Calculate Total Quantity on hand
//  *Set Reorder Flag
//  *Print Column Headings
//  *Print Inventory
//  *Selection Sort the inventory ascending on product number
//    ^Selection Sort
//    ^Index of Smallest
//    ^Swap
//
//Comments:
//
//
//
//Points Lost---------------------------------------------------------------------------------------------------->
//---------------------------------------------------------------------------------------------------------------------
//Company
//-Header and CPP file created, correctly named
//-Correctly documented and formatted, meets all standard Course Requirements
//-Functions included:
//  *Input Company
//  *Print Company Heading
//  *Print Companies
//Comments:
//
//
//
//Points Lost---------------------------------------------------------------------------------------------------->
//---------------------------------------------------------------------------------------------------------------------
//Order Processing
//-Header and CPP file created, correctly named
//-Correctly documented and formatted, meets all standard Course Requirements
//-Functions included:
//  *Check Company Id
//  *Check Product Number
//  *Update Inventory
//  *Print Bill Error
//  *Print Bill
//  *Process Orders
//Comments:
//
//
//
//Points Lost---------------------------------------------------------------------------------------------------->
//---------------------------------------------------------------------------------------------------------------------

#include"Standards.h"
#include"Inventory.h"
#include"Company.h"
#include"OrderProcessing.h"

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
    
    int indexCompanys;    
    int processCounter;
    string companyIDprocess;
    
    //Inizializing
    indexCompanys = 0;
    
	//Open ProcessInput.txt file
	fin.open("ProcessInput.txt");
    
   
    //Get first value
    fin >> processCounter;    
    //Ignore and go to the next line
    fin.ignore(100, '\n');    

    //Look for companyID
    while (!fin.eof()) {
        //Get Data from CompanyStruct
        indexCompanys = CompanyIDChecker(fin, companyCount, companyS, processCounter);
        
        //Print DATA
        PrintProcessingOrder(fout, companyS, inventory, companyCount, inventoryCount, indexCompanys);
    }
  

    //Look for productNumber
    //Print Process DATA
  
    
	//Close ProcessInput.txt file
	fin.close();



	fout.close();

    ///system("pause");

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

