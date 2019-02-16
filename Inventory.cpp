//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Inventory.cpp
//Associated File:    None
//Inventory.cpp File contains:
// - Calling Inventory.h
// -
//---------------------------------------------------------------------------------------------------------------------
#include"Standards.h"
#include"Inventory.h"

void InventoryGettingData(ifstream& fin, inventoryStructType& inventory1, int& invetoryCount) {

	inventory1.totalOnHandQuantity = 0;

	while (!fin.eof()) {
		getline(fin, inventory1.productName);
		getline(fin, inventory1.productNumber);

		//Store onHand into Array  (nested loop) & Calculate total Quantity
		for (int i = 0; i <= 2; i++) {
			invetoryCount = 0;
			for (int j = 0; j <= 3; j++) {

				fin >> inventory1.onHand[i][j];
				inventory1.totalOnHandQuantity = inventory1.totalOnHandQuantity + inventory1.onHand[i][j];
				invetoryCount += 1;

			}
		}
		fin >> inventory1.minimumOnHandQuantity >> inventory1.cost;

		//Getting value of Reorder Flag
		inventory1.reorderFlag = ReorderFlag(inventory1.totalOnHandQuantity, inventory1.minimumOnHandQuantity);

		//Calculate Price
		inventory1.price = MARKUP * inventory1.cost;
		inventory1.price = inventory1.price + +inventory1.cost;

		inventory1.totalOnHandQuantity++;

		fin.ignore(1000, '\n');

		//Print data into file


	}



}

//reorder flag
bool ReorderFlag(int quantity, int minOnHand) {

	bool reorderFlag = false;

	if (quantity < minOnHand) {
		reorderFlag = true;
	}

	return reorderFlag;
}

//Print Inventory Data
void PrintInventoryData(ofstream& fout, int inventoryCount, string inventory_title) {



}
