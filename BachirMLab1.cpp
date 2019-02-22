
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


	//Close ComnpanyInput.txt file
	fin.close();

	/*=================================================================================================================
	=============================================[Part 4: Processing Orders]===========================================
	=================================================================================================================*/

	int processingCounter;
    int processOrderCounter;
    int indexCompanyMatch;
    int indexInventoryMatch;

    processingOrderStruct orderStruct[20];

	//Open ProcessInput.txt file
	fin.open("ProcessInput.txt");

	//Store DATA into Struct
    StoreDataIntoStruct(fin, orderStruct, processingCounter);

    for (processOrderCounter = 0; processOrderCounter <= processingCounter; processOrderCounter++) 
    {

        //Check companyID
        indexCompanyMatch = CompanyIDChecker(companyCount, companyS, orderStruct[processOrderCounter].orderCompanyID, processingCounter);
        cout << "Company Match ==> " << indexCompanyMatch << endl;
        cout << "Company Order ==> " << orderStruct[processOrderCounter].orderCompanyID << " Here ==> " << companyS[indexCompanyMatch].companyID << endl;
        //Check product Number
        cout << "Number ==> " << orderStruct[processOrderCounter].orderProductNumber << endl;
        indexInventoryMatch = ProductNumberIDos(orderStruct[processOrderCounter].orderProductNumber, inventoryCount, inventory);

        cout << "Inventory Location: " << indexInventoryMatch  << "==> " << inventory[indexInventoryMatch].productNumber << endl;
        
    }
	

	//Returning to the beginning line of the file
	//fin.seekg(0, ios::beg);

	
    
    
	//Close ProcessInput.txt file
	fin.close();

	fout.close();

	system("pause");

	return 0;

}

//---------------------------------------------------------------------------------------------------------------------
// Print Divider - Pass two parameters file_output(fout) and width.
//---------------------------------------------------------------------------------------------------------------------
void PrintDivider(ofstream& fout, int width)
{

	fout << setfill(SYMBOL) << setw(width) << SYMBOL << setfill(' ') << endl;
}

//---------------------------------------------------------------------------------------------------------------------
// Print Course Heading - Output Course and Programmer Information into file_output. 
//---------------------------------------------------------------------------------------------------------------------
void PrintCourseHeading(ofstream& fout) 
{

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

//---------------------------------------------------------------------------------------------------------------------
// Print File Names - Output all file names that has been opened. 
//---------------------------------------------------------------------------------------------------------------------
void PrintFileName(ofstream& fout)
{

	fout << "Input can be found in the file, inventoryInput.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	fout << "Input can be found in the file, CompanyInput.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	fout << "Input can be found in the file, ProcessInput.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	fout << "Output can be found in the file, Lab1Out.txt" << endl;

	//Print Divider
	PrintDivider(fout, 100);

	//Skip Line
	fout << endl;



}
