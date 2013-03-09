#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
char inputFilename[] = "test.txt";

void Print(string code, string description, string cost, string quantity)
{
     cout << code;
     cout << description;
     cout << cost;
     cout << quantity << endl;
     
     return;
}

string getItemCode(string description)
{
       string code;
       string description2;
       string cost;
       string quantity;
       
       ifstream inFile;
       inFile.open(inputFilename, ios::in);
       
       if (!inFile)
       {
                   cerr << "Can't open input file\n";
                   system("PAUSE");
                   exit(1);
       }
       
       while (!inFile.eof())
       {
             inFile >> code >> description2 >> cost >> quantity;
             if (description2 == description)
             {
                              return code;
             }
             //Print(code,description2,cost,quantity); 
       }
       
                       
       return "DNE";
}  

string getItemCost(string code)
{
       string code2;
       string description;
       string cost;
       string quantity;
       
       ifstream inFile;
       inFile.open(inputFilename, ios::in);
       
       if (!inFile)
       {
                   cerr << "Can't open input file\n";
                   system("PAUSE");
                   exit(1);
       }
       
       while (!inFile.eof())
       {
             inFile >> code2 >> description >> cost >> quantity;
             if (code2 == code)
             {
                              return cost;
             }
             //Print(code2,description,cost,quantity); 
       }
       
                       
       return "DNE";
}   

vector<string> getItemData (string code)
{
       string code2;
       string description;
       string cost;
       string quantity;
       vector<string> send(2);
       
       ifstream inFile;
       inFile.open(inputFilename, ios::in);
       
       if (!inFile)
       {
                   cerr << "Can't open input file\n";
                   system("PAUSE");
                   exit(1);
       }
       
       while (!inFile.eof())
       {
             inFile >> code2 >> description >> cost >> quantity;
             if (code2 == code)
             {
                       send.at(0) = description;
                       send.at(1) = cost;
                       return send;
             }
             //Print(code2,description,cost,quantity); 
       }
       
                       
       return send;
}        

int main(int argc, char *argv[])
{ 
    vector<string> temp(2);
    //Print(152,"string",50,4);
    cout << "getItemCode\nCode: " << getItemCode("zzzzzzzzzzzzzzzzzzzzzzzzz") << "\n";
    cout << "\ngetItemCost\nCost: " << getItemCost("aaaaaaaa") << "\n";
    temp = getItemData("aaaaaaaa");
    cout << "\ngetItemData\nDescription: " + temp.at(0) + "\nCost:" + temp.at(1) + "\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

      
