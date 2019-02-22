#include"Standards.h"
#include"Company.h"
#include"Inventory.h"


//Check and look for CompanyID in CompanyStructType && ProcessInput.txt
int CompanyIDChecker(ifstream& fin, int companyCount, companyStructType companyO[], int& processCount) 
{

	int indexCompany;
	int indexCounter;
	int processFileCounter;
	int storingCounter;

	string companyId;
	string companyIdProcess;

	bool loopControler;
		
	loopControler = false;
	storingCounter = 0;

	fin >> processCount;
	fin.ignore(100, '\n');

	for (processFileCounter = 0; processFileCounter < processCount; processFileCounter++)
	{

		//Get only companyID from line 
		getline(fin, companyIdProcess);
		
		companyIdProcess = companyIdProcess.substr(5, 4);

		for (indexCounter = 0; indexCounter < companyCount; indexCounter++) {

			companyId = to_string(companyO[indexCounter].companyID);

			if (companyIdProcess == companyId) {

				//Make return value(indexCompany) equal to indexCounter 
				indexCompany = indexCounter;

				//Break from first loop
				indexCounter = companyCount;

				//Break from second one
				break;
				storingCounter++;
			}


		}
	}


	return indexCompany;

}

//Product Number ID from Inventory
int ProductNumberIDo(ifstream& fin, int inventoryCount, string& productNid, inventoryStructType inventoryO[], int processCount)
{
	int indexProductNumber;
	int indexInventory;
	int indexProcessFile;

	string inventoryProductProcess;
	string productIDprocess;

	indexProductNumber = 0;

	//Skip line 
	fin.ignore(1000, '\n');

	for (indexProcessFile = 0; indexProcessFile < processCount; indexProcessFile++) 
	{

		//Get only companyID from line 
		getline(fin, inventoryProductProcess);
		inventoryProductProcess = inventoryProductProcess.substr(10, 4);

		for (indexInventory = 0; indexInventory <= inventoryCount; indexInventory++) 
		{
			productIDprocess = inventoryO[indexInventory].productNumber;
			if (productIDprocess == inventoryProductProcess)
			{
				//Return location
				indexProductNumber = indexInventory;

				//Break from first loop
				indexProcessFile = processCount;

				//Break from second one
				break;
			}
		}
	}

	return indexProductNumber;
}

//Update Inventory if needed
void UpdateInventory(ifstream& fin, inventoryStructType inventoryO[], int inventoryCounter) 
{
	
	string orderAmounts;
	
	int orderAmounti;
	int inventoryCou;
	int onHandI;
	int onHandJ;

	inventoryCou = 0;

	//Skip line
	fin.ignore(100, '\n');

	//Get quantity from file
	getline(fin, orderAmounts);
	orderAmounts = orderAmounts.substr(15, 4);
	orderAmounti = stoi(orderAmounts);

	//--------------------------------------------------------------------------------------------------------------------
	// - Check file Quantity with inventroyStructType total on-hand Quantity and onHand Quantity
	//--------------------------------------------------------------------------------------------------------------------
	while (inventoryCou <= inventoryCounter) {

		for (onHandI = 0; onHandI <= 2; onHandI++) {
			for (onHandJ = 0; onHandJ <= 3; onHandJ++) {

				if (inventoryO[inventoryCou].totalOnHandQuantity >= orderAmounti)
				{
					if (inventoryO[inventoryCou].onHand[onHandI][onHandJ] > 0)
					{
						if (inventoryO[inventoryCou].onHand[onHandI][onHandJ] <= orderAmounti)
						{
							inventoryO[inventoryCou].totalOnHandQuantity = inventoryO[inventoryCou].totalOnHandQuantity - inventoryO[0].onHand[onHandI][onHandJ];
							orderAmounti = orderAmounti - inventoryO[inventoryCou].onHand[onHandI][onHandJ];
							inventoryO[inventoryCou].onHand[onHandI][onHandJ] = 0;
						}
					}
				}

			}
		}

		

		inventoryCou++;
	}
	

}

//Output Data into Lab1Out.txt
void PrintProcessingOrder(ofstream& fout, companyStructType company[], inventoryStructType inventory[], int companyCount, int inventoryCount, int indexCompany) 
{

	int index;

	string companyID;

	//Counter
	index = 0;

	//Skip lines
	fout << endl << endl;

	//Printout Divider
	PrintDivider(fout, 100);

	//Printout data
	fout << "Bill for " << company[indexCompany].companyName << endl;

	//Printout Divider
	PrintDivider(fout, 100);

	//Print Address
	fout << "Billing Address : " << endl;
	fout << right << setw(30) << company[indexCompany].companyName << endl;
	fout << right << setw(30) << company[indexCompany].address << endl;
	fout << right << setw(30) << company[indexCompany].city << " " << company[indexCompany].state << endl;
	fout << right << setw(30) << company[indexCompany].zip << endl;

	//Printout Divider
	PrintDivider(fout, 100);

	fout << "Order Number: " << endl;
	fout << "Product Name: " << endl;
	fout << "Product Number: " << endl;
	fout << "Product Price: " << endl;
	fout << "Quantity Ordered: " << endl;
	fout << "Billed Amount ----------> " << endl;
	fout << "Company Counter: " << companyCount << endl;

	//Printout Divider
	PrintDivider(fout, 100);


}
