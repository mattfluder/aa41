#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

char inputFilename[] = "test.txt";

void setRemoveItem(string code)
{
    string line;
    string code2;
    string description;
    string cost;
    string quantity;
    string text;
    string value;
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
             value = "";
             
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
                     else if (ctr == 4)
                     {
                          value += text[ctr2];
                          ctr++;
                     }
                     if (ctr2 == text.length()-1)
                     { 
                          ctr = 0;
                     }
                     
             }
             cout << "\nCode: " << code2 << "\n";
             cout << "Description: " << description << "\n";
             cout << "COST: " << cost << "\n";
             cout << "QUANTITY: " << quantity << "\n";
             cout << "VALUE: " << value << "\n";
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

void setItemData (string code, string description, long cost, int quantity, int value){
      
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
			outputFile << code <<"\t" << description << "\t" << cost << "\t" << quantity << "\t" << value << "\n";
		}
		else {
			outputFile << currentLine << "\n";
		}
	}
	if (!spotFound){
		outputFile << code <<"\t" << description << "\t" << cost << "\t" << quantity << "\t" << value << "\n";
	}
	//Print(code, description, cost, quantity);
    inputFile.close();
	outputFile.close();
	remove(inputFilename);
	rename("output.txt",inputFilename);
	return;
 }

void getAllItemsInCostRange(string min_cost, string max_cost)
{
   string code;
   string description;
   string cost;
   string quantity;
   string text;
   string value;
   int ctr = 0;
   
   
   string fileDataLine, min_test, max_test;
   ifstream File(inputFilename);
   
   if (!File) {
     cerr << "Can't open input file " << File << endl;
     exit(1);
   }
   
   getline(File, fileDataLine);
   
   for(int ctr2 = 0; ctr2 < fileDataLine.length(); ctr2++)
   {
               if (fileDataLine[ctr2] == '\t')
               {
                          ctr ++;
               }
               else if (ctr == 0)
               {
                          min_test += fileDataLine[ctr2];      
               }
                     
               else if (ctr == 1)
               {
                          max_test += fileDataLine[ctr2];
               }
               if (ctr2 >= fileDataLine.length()-1)
               { 
                          ctr = 0;
               }
               
   }
   //File >> min_test >> max_test;
   cout << min_test;
   if ((min_test.compare(min_cost) == 0) && (max_test.compare(max_cost)) == 0) {
     
    while(!File.eof()) 
    {
       getline(File, fileDataLine);
       cout << fileDataLine;
       
       code = "";
       description = "";
       cost = "";
       quantity = "";
       value = "";
             
       for(int ctr2 = 0; ctr2 < fileDataLine.length(); ctr2++)
       {
               if (fileDataLine[ctr2] == '\t')
               {
                          ctr ++;
               }
               else if (ctr == 0)
               {
                          code +=fileDataLine[ctr2];      
               }
                     
               else if (ctr == 1)
               {
                          description += fileDataLine[ctr2];
               }
                     
               else if (ctr == 2)    
               {
                          cost += fileDataLine[ctr2];
               }
                     
               else if (ctr == 3)
               {
                          quantity += fileDataLine[ctr2];
               }
               else if (ctr == 4)
               {
                          value += fileDataLine[ctr2];
                          ctr++;
               }
               if (ctr2 == fileDataLine.length()-1)
               { 
                          ctr = 0;
               }
       }
       cout << "\nCode: " << code << "\n";
       cout << "Description: " << description << "\n";
       istringstream costBuffer(cost);
       istringstream quantityBuffer(quantity);
       istringstream valueBuffer(value);
       long longCost;
       int intQuantity;
       int intValue;
       costBuffer >> longCost;
       quantityBuffer >> intQuantity;
       valueBuffer >> intValue;
       cout << "COST: " << longCost << "\n";
       cout << "QUANTITY: " << intQuantity << "\n";
       cout << "VALUE: " << intValue << "\n";
       
       if (intValue == 0) {
         
         File.close();
         setRemoveItem(code);
         setItemData (code,description,longCost,intQuantity,1);
         getAllItemsInCostRange(min_cost,max_cost);
       } 
       
    }
   }
        
     
   
   
   
   
   
   File.close();
  return;
}

int main() {
getAllItemsInCostRange("1", "10");
system("PAUSE");
return 0;
}
