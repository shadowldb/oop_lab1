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
    
    
    getline(fin, inventory1.productName);
    getline(fin, inventory1.productNumber);
    fin.ignore(1000, '\n');
    //Store onHand into Array
    for (int i = 0; i < 3; i++) {
        invetoryCount = 0;
        for (int j = 0; j < 4; j++) {
            fin >> inventory1.onHand[i][j] ;
                invetoryCount +=1;
            
        }
    }
    fin.ignore(1000, '\n');
    fin >> inventory1.minimumOnHandQuantity >> inventory1.cost;
}
