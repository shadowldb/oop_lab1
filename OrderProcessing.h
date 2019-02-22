//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Company.h
//Associated File:    OrderProcessing.cpp
//Header File contains:
// Header File contains: None
//Prototype for:
//CompanyIDChecker, ProductNumberIDo, PrintProcessingOrder

//---------------------------------------------------------------------------------------------------------------------

#ifndef OrderProcessing_h
#define OrderProcessing_h
#include"Standards.h"
#include"Company.h"
#include"Inventory.h"


//Check and look for CompanyID in CompanyStructType && ProcessInput.txt
int CompanyIDChecker(ifstream& fin, int companyCount, companyStructType companyO[], int& processCount);

//Product Number ID from Inventory
int ProductNumberIDo(ifstream& fin, int inventoryCounts, string& productNid, inventoryStructType inventoryO[], int processCount);

//Update Inventory if needed
void UpdateInventory(ifstream& fin, inventoryStructType inventoryO[], int inventoryCounter);

//Output Data into Lab1Out.txt
void PrintProcessingOrder(ofstream& fout, companyStructType company[], inventoryStructType inventory[], int companyCount, int inventoryCount, int indexCompany);



#endif // !OrderProcessing_h
