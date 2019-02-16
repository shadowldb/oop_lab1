//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          Inventory.h
//Associated File:    None
//Header File contains:
// - Struct Type for Inventory

//---------------------------------------------------------------------------------------------------------------------
#ifndef Inventory_h
#define Inventory_h
#include"Standards.h"

//Declare Inventory Struct Type
struct inventoryStructType {
    string productName;
    string productNumber;

    int onHand[3][4];
    int totalOnHandQuantity;
    int minimumOnHandQuantity;

    bool reorderFlag;

    double cost;
    double price;
};



//Declare Inventory Function
void InventoryGettingData(ifstream& fin, inventoryStructType& inventory1, int& invetoryCount);

//reorder flag
bool ReorderFlag(int quantity, int minOnHand);

//Print Inventory Data
void PrintInventoryData(ofstream& fout, int inventoryCount, string inventory_title);

#endif Inventory_h
