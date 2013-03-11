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
     cout << "\n" << code << "\n";
     cout << description << "\n";
     cout << cost << "\n";
     cout << quantity << "\n";
     
     return;
}

 void setItemData (string code, string description, long cost, int quantity){
      
	ifstream inputFile; 
	ofstream outputFile;
	bool spotFound=false;
	string currentLine;
	inputFile.open(inputFilename);//opens input file
	outputFile.open("output.txt");//opens the output file

	if (!inputFile)
	{
		cerr<<"Can't open input file\n";
		system("PAUSE");
		exit(1);
	}
	if (!outputFile)
	{
		cerr<<"Can't open input file\n";
		system("PAUSE");
		exit(1);
	}
	while(!inputFile.eof()){
	getline(inputFile, currentLine);
		if (currentLine.empty()){
			spotFound= true;
			outputFile << code <<"\t" << description << "\t" << cost << "\t" << quantity << "\n";
		}
		else {
			outputFile << currentLine << "\n";
		}
	}
	if (!spotFound){
		outputFile << code <<"\t" << description << "\t" << cost << "\t" << quantity << "\n";
	}
	//Print(code, description, cost, quantity);
    inputFile.close();
	outputFile.close();
	remove(inputFilename);
	rename("output.txt",inputFilename);
	return;
 }
//----------------------------------------------------------------------------------------------------------------------------------------------
void setRemoveItem(string code)
{
    string line;
    string code2;
    string description;
    string cost;
    string quantity;
    string text;
    int ctr = 0;
    //Open Input File
    ifstream in(inputFilename);
    if(!in.is_open())
    {
      cout << "Input File Failed to Open\n";
      return;
    }

    //Open Temporary Output File
    ofstream out ("outfile.txt");
    //Loop to read/write the file.
    while (!in.eof())
       {
             getline(in,text);
             
             code2 = "";
             description = "";
             cost = "";
             quantity = "";
             
             for(int ctr2 = 0; ctr2 < text.length(); ctr2++)
             {
                     if (text[ctr2] == '\t')
                     {
                          ctr ++;
                     }
                     else if (ctr == 0)
                     {
                          code2 +=text[ctr2];      
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
                     if (ctr2 == text.length()-1)
                     { 
                          ctr = 0;
                     }
             }
             if (code2 != code)
             {
                       if (in.eof())
                       {
                          out<< text;
                       }
                       else
                       {
                           out << text << "\n";
                       }
             }
       }          
    in.close();
    out.close();
    //Delete the original file
    remove(inputFilename);
    //Rename Edited File to Infile.txt
    rename("outfile.txt",inputFilename);
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
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
             
             code = "";
             description2 = "";
             cost = "";
             quantity = "";
             
             for(int ctr2 = 0; ctr2 < text.length(); ctr2++)
             {
                     
                     if (text[ctr2] == '\t')
                     {
                          ctr ++;
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
                     if (ctr2 == text.length()-1)
                     {
                              ctr = 0;
                     }
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
             code2 = "";
             description = "";
             cost = "";
             quantity = "";
             
             for(int ctr2 = 0; ctr2 < text.length(); ctr2++)
             {
                 if (text[ctr2] == '\t')
                 {
                          ctr ++;
                 }
                 else if (ctr == 0)
                 {
                      code2 +=text[ctr2];      
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
                 if (ctr2 == text.length()-1)
                 { 
                      ctr = 0;
                 }
                 
                 
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
             
             code2 = "";
             description = "";
             cost = "";
             quantity = "";
             
             for(int ctr2 = 0; ctr2 < text.length(); ctr2++)
             {
                     if (text[ctr2] == '\t')
                     {
                          ctr ++;
                     }
                     else if (ctr == 0)
                     {
                          code2 +=text[ctr2];      
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
                     if (ctr2 == text.length()-1)
                     { 
                          ctr = 0;
                     }
             }
             if (code2 == code)
             {
                     send.at(0) = description;
                     send.at(1) = cost;
             }  
       }        
       return send;
}        

int main(int argc, char *argv[])
{ 
    /*
    vector<string> temp(2);
    cout << "setItemData(\"code9\",\"des69\", 696, 69)\n";
    setItemData("code9","des69", 696, 69);
    cout << "setRemoveItemData\n";
    setRemoveItem("itemnum3");
    cout << "\ngetItemCode\nCode: " << getItemCode("description4") << "\n";
    cout << "\ngetItemCost\nCost: " << getItemCost("itemnum2") << "\n";
    temp = getItemData("itemnum1");
    cout << "\ngetItemData\nDescription: " + temp.at(0) + "\nCost:" + temp.at(1) + "\n";*/
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

      
