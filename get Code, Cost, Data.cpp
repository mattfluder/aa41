#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>

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
       string text;
       int ctr = 0;
       
       
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
             getline(inFile,text);
             for(int ctr2 = 0; ctr2 <= text.length(); ctr2++)
            
            if (text[ctr2] == '\t')
             {
                  if (ctr == 3)
                  {
                      ctr = 0;
                  }
                  else
                  {
                      ctr ++;
                  }
             }
             else if (ctr == 0)
             {
                  code = code+text[ctr2];      
             }
             
             else if (ctr == 1)
             {
                  description2 += text[ctr2];
             }
             
             else if (ctr == 2)    
             {
                  cost += text[ctr2];
             }
             
             else if (ctr == 3)
             {
                  quantity += text[ctr2];
             }
             if (description2 == description)
             {
                              return code;
             } 
       }
       
                       
       return "DNE";
}  

string getItemCost(string code)
{
       string code2;
       string description;
       string cost;
       string quantity;
       string text;
       int ctr = 0;
       
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
             getline(inFile,text);
             for(int ctr2 = 0; ctr2 <= text.length(); ctr2++)
            
            if (text[ctr2] == '\t')
             {
                  if (ctr == 3)
                  {
                      ctr = 0;
                  }
                  else
                  {
                      ctr ++;
                  }
             }
             else if (ctr == 0)
             {
                  code2 = code2+text[ctr2];      
             }
             
             else if (ctr == 1)
             {
                  description += text[ctr2];
             }
             
             else if (ctr == 2)    
             {
                  cost += text[ctr2];
             }
             
             else if (ctr == 3)
             {
                  quantity += text[ctr2];
             }
             if (code2 == code)
             {
                              return cost;
             }
       }
       
                       
       return "DNE";
}   

vector<string> getItemData (string code)
{
       string code2;
       string description;
       string cost;
       string quantity;
       string currentLine;
       string text;
       vector<string> send(2);
       int ctr = 0;
       
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
             getline(inFile,text);
             for(int ctr2 = 0; ctr2 <= text.length(); ctr2++)
            
            if (text[ctr2] == '\t')
             {
                  if (ctr == 3)
                  {
                      ctr = 0;
                  }
                  else
                  {
                      ctr ++;
                  }
             }
             else if (ctr == 0)
             {
                  code2 = code2+text[ctr2];      
             }
             
             else if (ctr == 1)
             {
                  description += text[ctr2];
             }
             
             else if (ctr == 2)    
             {
                  cost += text[ctr2];
             }
             
             else if (ctr == 3)
             {
                  quantity += text[ctr2];
             }
             if (code2 == code)
             {
                       send.at(0) = description;
                       send.at(1) = cost;
                       return send;
             }
       }
                       
       return send;
}        

int main(int argc, char *argv[])
{ 
    vector<string> temp(2);
    cout << "getItemCode\nCode: " << getItemCode("This is a test") << "\n";
    cout << "\ngetItemCost\nCost: " << getItemCost("aaaaaaaa") << "\n";
    temp = getItemData("aaaaaaaa");
    cout << "\ngetItemData\nDescription: " + temp.at(0) + "\nCost:" + temp.at(1) + "\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

      
