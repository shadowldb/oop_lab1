
#include"Standards.h"
#include"Inventory.h"
#include"Company.h"

int main(void) {

	int inventoryCount;

	ifstream fin;
	ofstream fout;

	/*=================================================================================================================
	===============================================[Part 2: The Inventory]=============================================
	=================================================================================================================*/

	//Define Inventory struct
	inventoryStructType inventory;

	//Open inventoryInput.txt file
	fin.open("inventoryInput.txt");

	//Get DATA from Inventory File
	InventoryGettingData(fin, inventory, inventoryCount);

	//Print Inventory Data
	PrintInventoryData(fout, inventoryCount, "InventoryReport - Unsorted");

	//Close Inventory File
	fin.close();

	/*=================================================================================================================
	==================================================[Part 3: Company]================================================
	=================================================================================================================*/

	//Define Company Struct
	companyStructType companyS;

	//Open CompanyInput.txt file
	fin.open("CompanyInput.txt");



	//Closr ComnpanyInput.txt file
	fin.close();

	/*=================================================================================================================
	=============================================[Part 4: Processing Orders]===========================================
	=================================================================================================================*/


	return 0;

}
