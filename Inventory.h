//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Inventory.h
//Associated File:    Inventory.cpp
//Header File contains:
// - inventoryStructType
// Prototype for:
// - InventoryHeading, InventoryGettingData, ReorderFlag, InventoryStructSorted, PrintInventoryData
 
//---------------------------------------------------------------------------------------------------------------------
#ifndef Inventory_h
#define Inventory_h
#include"Standards.h"

//Declare Inventory Struct Type
struct inventoryStructType{
    string productName;
    string productNumber;
    
    int onHand[3][4];
    int totalOnHandQuantity;
    int minimumOnHandQuantity;
    
    bool reorderFlag;
    
    double cost;
    double price;
};



//Inventory Header
void InventoryHeading(ofstream& fout);

//Declare Inventory Function
int InventoryGettingData(ifstream& fin, inventoryStructType inventory1[]);

//reorder flag
bool ReorderFlag(int quantity, int minOnHand);

//Sort InventoryStruct
void InventoryStructSorted(inventoryStructType inventory[], int inventoryCount);

//Print Inventory Data
void PrintInventoryData(ofstream& fout, inventoryStructType inventory[], int inventoryCount, string inventory_title);

#endif Inventory_h
