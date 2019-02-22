//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Company.h
//Associated File:    OrderProcessing.cpp
//Header File contains:
// Header File contains: processingOrderStruct
//Prototype for:
//CompanyIDChecker, ProductNumberIDo, PrintProcessingOrder

//---------------------------------------------------------------------------------------------------------------------

#ifndef OrderProcessing_h
#define OrderProcessing_h
#include"Standards.h"
#include"Company.h"
#include"Inventory.h"

//Creating struct to store ProcessInput.txt file with Company and Inventory Location match. 
struct processingOrderStruct 
{
    string orderNumber;
    string orderProductNumber;
    
    int orderCompanyID;
    int quantityOrder;
    int companyLocation;
    int inventoryLocation;
    
};

//Store ProcessInput.txt into Struct
void StoreDataIntoStruct(ifstream& fin, processingOrderStruct orderStruct[], int& processingCounter);

//Check and look for CompanyID in CompanyStructType && ProcessInput.txt
int CompanyIDChecker(int companyCount, companyStructType companyO[], int companyIdProcess, int& processCount);

//Product Number ID from Inventory
int ProductNumberIDos(string productIDprocess, int inventoryCount, inventoryStructType inventoryO[]);

//Update Inventory if needed
void UpdateInventory(ifstream& fin, inventoryStructType inventoryO[], int inventoryCounter);

//Output Data into Lab1Out.txt
void PrintProcessingOrder(ofstream& fout, companyStructType company[], inventoryStructType inventory[], int companyCount, int inventoryCount, int indexCompany);

//Function to print Centered Name
void PrintCenteredMessage(ofstream& fout, string titleOrder, int width);



#endif // !OrderProcessing_h
