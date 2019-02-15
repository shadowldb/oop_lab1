//---------------------------------------------------------------------------------------------------------------------
//Programmer's Name:  Mohamed Ali Larbi Daho Bachir
//File Name:          BachirMLab1.cpp
//Associated File:    None
//Inventory.cpp File contains:
// - Calling Inventory.cpp
// - Calling Company.cpp
// - OrderProcessing.cpp
//---------------------------------------------------------------------------------------------------------------------
#include"Standards.h"
#include"Inventory.h"

int main(void) {

    int inventoryCount;
    ifstream fileInput;

    inventoryStructType invent;

    //Open Inventory.txt file
    fileInput.open("inventoryInput.txt");

    InventoryGettingData(fileInput, invent, inventoryCount);

    return 0;
}



