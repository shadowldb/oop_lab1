#include"Standards.h"
#include"Company.h"
#include"Inventory.h"
#include"OrderProcessing.h"


//Store ProcessInput.txt into Struct
void StoreDataIntoStruct(ifstream& fin, processingOrderStruct orderStruct[], int& processingCounter) 
{

    int counter;

    string data;
    
    //Inizializing Counter
    counter = 0;

    //Store first value in File
    fin >> processingCounter;
    fin.ignore(1000, '\n');

    while (fin && counter <= processingCounter) {

        //Get full line of Data
        getline(fin, data);
        
        //Store data into struct
        orderStruct[counter].orderNumber = data.substr(0, 4);
        orderStruct[counter].orderCompanyID = stoi(data.substr(5, 4));
        orderStruct[counter].orderProductNumber = data.substr(10, 4);
        orderStruct[counter].quantityOrder = stoi(data.substr(15,4));
        
    
        fin.ignore(1000, '\n');
        counter++;
        
        
    }
}

//Check and look for CompanyID in CompanyStructType && ProcessInput.txt
int CompanyIDChecker(int companyCount, companyStructType companyO[], int companyIdProcess, int& processCount) 
{

	int indexCompany;
	int indexCounter;
	int processFileCounter;
	int storingCounter;

	string companyId;

	bool loopControler;
		
	loopControler = false;
	storingCounter = 0;

    indexCompany = 0;

		
		for (indexCounter = 0; indexCounter < companyCount; indexCounter++) {

			if (companyIdProcess == companyO[indexCounter].companyID) {

				//Make return value(indexCompany) equal to indexCounter 
				indexCompany = indexCounter;

				//Break from first loop
				indexCounter = companyCount;

				//Break from second one
				break;
            }
           


	 }
     
     //return CompanyID location
     return indexCompany;

}

//Product Number ID from Inventory
int ProductNumberIDos(string productIDprocess, int inventoryCount, inventoryStructType inventoryO[])
{
	int indexProductNumber;
	int indexInventory;
    
    string productNumberid;

    indexInventory = 0;
    
    for (indexInventory = 0; indexInventory <= inventoryCount; indexInventory++) 
		{
			productNumberid = inventoryO[indexInventory].productNumber;
			if (productIDprocess == productNumberid)
			{
				//Return location
				indexProductNumber = indexInventory;

                //Break from loop
				break;
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

//Function to print Centered Name
void PrintCenteredMessage(ofstream& fout, string titleOrder, int width) {
    int centredTtitleLength;

    //Print Divider
    PrintDivider(fout, width);

    //Print College Name
	centredTtitleLength = static_cast<int>(titleOrder.length());
	fout << setw((100 + centredTtitleLength) / 2) << titleOrder << endl;
    
    //Print Divider
    PrintDivider(fout, width);
}
