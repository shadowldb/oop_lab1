#include"Standards.h"
#include"Company.h"
#include"Inventory.h"


//Check and look for CompanyID in CompanyStructType && ProcessInput.txt
int CompanyIDChecker(ifstream& fin, int companyCount, companyStructType companyO[], int processCount) {
    
    int indexCompany;
    int index;
    int jIndex;


    string companyStr;
    string companyIDprocess;
 
    bool checker;
    
    checker = false;
    indexCompany = 0;
    index = 0;
    jIndex = 0;

    while (jIndex <= processCount) {
         ///Get first line
    getline(fin, companyIDprocess);
    
    fin.ignore(100, '\n');
    
    //Get only companyID from line 
    companyIDprocess = companyIDprocess.substr(5, 4);

    if (checker == true) {
        break;
    }
    
    while (index <= companyCount) {
        
        if (checker == true) {
            break;
        }
        
        //Convert companyID into string
        companyStr = to_string(companyO[index].companyID);

        //Check if it match and get location 
        if (companyIDprocess == companyStr) {
            indexCompany = index;
            checker = true;

        }

        //Increment
        index++;
    }
        
        //Increment 
        jIndex++;

    }
   
    

    return indexCompany;     
    
}

//Product Number ID from Inventory
int ProductNumberIDo(ifstream& fin, int inventoryCounts, string& productNid, inventoryStructType inventoryO[]) {
    int indexProductNumber;
    
    indexProductNumber = 0;

    return indexProductNumber;
}

//Output Data into Lab1Out.txt
void PrintProcessingOrder(ofstream& fout, companyStructType company[], inventoryStructType inventory[], int companyCount, int inventoryCount, int indexCompany) {
    
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

   //Printout Divider
   PrintDivider(fout, 100);

    
}
