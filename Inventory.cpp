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

//---------------------------------------------------------------------------------------------------------------------
// Name: InventoryHeading - take file-Output(fout) as parameter 
void InventoryHeading(ofstream& fout)
{
	int outerOnHandIndex;
	int innerOnHandIndex;

	char asciiCharactare;

	fout << "Product Name" << right << setw(35) <<
		"Product Number" << right << setw(30) <<
		"On Hand" << right << setw(46) <<
		"Total Quantity" << right << setw(15) <<
		"Min On Hand" << right << setw(15) <<
		"Reorder Flag" << right << setw(15) <<
		"Cost" << right << setw(15) <<
		"Price" << right << setw(15) << endl << right << setw(51);

	//Print OnHand Header
	for (outerOnHandIndex = 1; outerOnHandIndex <= 3; outerOnHandIndex++) {
		for (innerOnHandIndex = 65; innerOnHandIndex <= 68; innerOnHandIndex++) {
			asciiCharactare = static_cast<char>(innerOnHandIndex);
			fout << outerOnHandIndex << asciiCharactare << right << setw(4);
		}
	}

	//Skip line
	fout << endl;

}

int InventoryGettingData(ifstream& fin, inventoryStructType inventory1[])
{
    
	int invetoryCount;
	int totalQuantity;

	invetoryCount = 0;

	while (fin && invetoryCount <= MAX_INVENTORY_STRUCT) 
	{

		//Initialize Total Quantity
		totalQuantity = 0;

		///inventory1[invetoryCount].totalOnHandQuantity = 0;
		getline(fin, inventory1[invetoryCount].productName);
		getline(fin, inventory1[invetoryCount].productNumber);

		//Store onHand into Array  (nested loop) & Calculate total Quantity
		for (int i = 0; i <= 2; i++) 
		{

			for (int j = 0; j <= 3; j++) 
			{

				fin >> inventory1[invetoryCount].onHand[i][j];
				totalQuantity = totalQuantity + inventory1[invetoryCount].onHand[i][j];

			}
		}
		fin >> inventory1[invetoryCount].minimumOnHandQuantity >> inventory1[invetoryCount].cost;

		//Getting value of Reorder Flag
		inventory1[invetoryCount].reorderFlag = ReorderFlag(inventory1[invetoryCount].totalOnHandQuantity, inventory1[invetoryCount].minimumOnHandQuantity);

		//Calculate Price
		inventory1[invetoryCount].price = MARKUP * inventory1[invetoryCount].cost;
		inventory1[invetoryCount].price = inventory1[invetoryCount].price + +inventory1[invetoryCount].cost;
		
		//Get Total Quantity
		inventory1[invetoryCount].totalOnHandQuantity = totalQuantity;

		///inventory1[invetoryCount].totalOnHandQuantity++;

		fin.ignore(1000, '\n');

		invetoryCount++;

	}
    
	return invetoryCount; 

}

//reorder flag
bool ReorderFlag(int quantity, int minOnHand)
{

	bool reorderFlag = false;

	if (quantity < minOnHand)
	{
		reorderFlag = true;
	}

	return reorderFlag;
}

//Print Inventory Report - Unsorted
void PrintInventoryData(ofstream& fout, inventoryStructType inventory[], int inventoryCount, string inventory_title) 
{
	
	int stringLength;
	int index;
	int jIndex;
	int iIndex;
	int inventoryName_length;

	//Initialize Counters
	index = 0;

	//Print Divider
	PrintDivider(fout, 189);

	//Print Inventory Title
	stringLength = static_cast<int>(inventory_title.length());
	fout << setw((189 + stringLength) / 2) << inventory_title << endl;

	//Print Divider
	PrintDivider(fout, 189);

	//Print Inventory Heading
	InventoryHeading(fout);

	//Print Divider
	PrintDivider(fout, 189);
	
	//Print DATA from Inventory Struct

	while (index < inventoryCount) 
	{

		///string n = inventory[index].productName;

		//Get InventoryName length
		inventoryName_length = static_cast<int>(inventory[index].productName.length());

		int setwidth = 47 - inventoryName_length;


		//Algorithmic to set distance between Product Name and Product Number

		fout << inventory[index].productName  <<
			right << setw(setwidth)  << inventory[index].productNumber  << right << setw(5);

		//Print ON Hand Array
		for (iIndex = 0; iIndex <= 2; iIndex++) 
		{
			for (jIndex = 0; jIndex <= 3; jIndex++) 
			{
				fout << inventory[index].onHand[iIndex][jIndex] << right << setw(5);
			}
		}

		fout << right << setw(16) << inventory[index].totalOnHandQuantity << right << setw(15) <<
			inventory[index].minimumOnHandQuantity << right << setw(15) <<
			inventory[index].reorderFlag << right << setw(16) <<
			inventory[index].cost << right << setw(14) <<
			inventory[index].price << right << setw(10) << endl;

		//Increment Index
		index++;
	}

	//Print Divider
	PrintDivider(fout, 189);

	//Print Inventory Counter
	fout << "Inventory Count = " << inventoryCount << endl;

	//Print Divider
	PrintDivider(fout, 189);

	//Skip line
	fout << endl;

}

//Sort InventoryStruct
void InventoryStructSorted(inventoryStructType inventory[], int inventoryCount)
{

	string inventoryProductNumber;
	string inventoryProductNumber2;
	string inventoryProductName;

	int inventoryOnHand[3][4];
	int totalQuantity;
	int minOnHand;
	int number1;
	int number2;
	int index;
	int jIndex;

	double cost;
	double price;

	bool reoredFlag;



	for(index = 0; index < inventoryCount; index++)
	{

		for (jIndex = index + 1; jIndex < inventoryCount; jIndex++) 
		{

			//Get the 2 variables of Product Number
			inventoryProductNumber = inventory[index].productNumber.substr(0, 2);
			inventoryProductNumber2 = inventory[jIndex].productNumber.substr(0, 2);

			//Convert from String to int
			number1 = atoi(inventoryProductNumber.c_str());
			number2 = atoi(inventoryProductNumber2.c_str());

			//Sorting DATA base on condition
			if (number2 < number1) 
			{

				//Sort Product Name
				inventoryProductName = inventory[index].productName;
				inventory[index].productName = inventory[jIndex].productName;
				inventory[jIndex].productName = inventoryProductName;

				//Sort onHand using nested loop
				for (int i = 0; i <= 2; i++)
				{

					for (int j = 0; j <= 3; j++) 
					{

						inventoryOnHand[i][j] = inventory[index].onHand[i][j];
						inventory[index].onHand[i][j] = inventory[jIndex].onHand[i][j];
						inventory[jIndex].onHand[i][j] = inventoryOnHand[i][j];

					}
				}

				//Sort Total Quantity
				totalQuantity = inventory[index].totalOnHandQuantity;
				inventory[index].totalOnHandQuantity = inventory[jIndex].totalOnHandQuantity;
				inventory[jIndex].totalOnHandQuantity = totalQuantity;

				//Sort minimum on Hand
				minOnHand = inventory[index].minimumOnHandQuantity;
				inventory[index].minimumOnHandQuantity = inventory[jIndex].minimumOnHandQuantity;
				inventory[jIndex].minimumOnHandQuantity = minOnHand;

				//Sort Reorder Flag
				reoredFlag = inventory[index].reorderFlag;
				inventory[index].reorderFlag = inventory[jIndex].reorderFlag;
				inventory[jIndex].reorderFlag = reoredFlag;

				//Sort Cost
				cost = inventory[index].cost;
				inventory[index].cost = inventory[jIndex].cost;
				inventory[jIndex].cost = cost;

				//Price
				price = inventory[index].price;
				inventory[index].price = inventory[jIndex].price;
				inventory[jIndex].price = price;

				//Sort Product Number
				inventoryProductNumber = inventory[index].productNumber;
				inventory[index].productNumber = inventory[jIndex].productNumber;
				inventory[jIndex].productNumber = inventoryProductNumber;

			}

		}
		
	}



}

