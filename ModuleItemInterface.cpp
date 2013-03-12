#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <sstream>

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

void setItemData (string code, string description, long cost, int quantity, int value){
      
	ifstream inputFile; 
	ofstream outputFile;
	bool spotFound=false;
	string currentLine;
	inputFile.open(inputFilename);//opens input file
	outputFile.open("outfile.txt", ios::app);//opens the output file

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
	rename("outfile.txt",inputFilename);
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
       string value;
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
             value = "";
             
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
       string value;
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
       string value;
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
             if (code2 == code)
             {
                     send.at(0) = description;
                     send.at(1) = cost;
             }  
       }        
       return send;
}

vector<string> getAllItemsInCostRange(long min_cost, long max_cost)
{
   vector<string> product(2);
   string code;
   string description;
   string cost;
   string quantity;
   string text;
   string value;
   int ctr = 0;
   
   product.at(0) = "";
   product.at(1) = "True";
   
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
   istringstream minBuffer(min_test);
   istringstream maxBuffer(max_test);
   long longMin;
   long longMax;
   minBuffer >> longMin;
   maxBuffer >> longMax;
   if ((longMin == min_cost) && (longMax == max_cost)) {
     
    while(!File.eof()) 
    {
       getline(File, fileDataLine);
       //cout << fileDataLine;
       
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
       
       istringstream costBuffer(cost);
       istringstream quantityBuffer(quantity);
       istringstream valueBuffer(value);
       long longCost;
       int intQuantity;
       int intValue;
       costBuffer >> longCost;
       quantityBuffer >> intQuantity;
       valueBuffer >> intValue;

       if ((intValue == 0) && (!File.eof()) && (longCost >= min_cost) && (longCost <= max_cost)) {
         File.close();
         setRemoveItem(code);
         setItemData (code,description,longCost,intQuantity,1);
         if (File.eof())
         {
               product.at(1) = "False";
         }
         else
         {
             product.at(1) = "True";
         }
         product.at(0) = fileDataLine;
         return product;
         getAllItemsInCostRange(min_cost,max_cost);        
         
       } 
       
    }
    //cout << product.at(0) << "\n" << product.at(1) << "\n";
    //system("pause");
   }
   else
   {
        stringstream stringMinimum; 
        stringMinimum << min_cost;

        setRemoveItem(stringMinimum.str());
        ofstream outputFile;
       	outputFile.open("outfile.txt");//opens the output file
       	outputFile << min_cost << "\t" << max_cost << "\n";
       	
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
           
           istringstream costBuffer(cost);
           istringstream quantityBuffer(quantity);
           istringstream valueBuffer(value);
           long longCost;
           int intQuantity;
           int intValue;
           costBuffer >> longCost;
           quantityBuffer >> intQuantity;
           valueBuffer >> intValue;
           /*cout << "\nCode: " << code << "\n";
           cout << "Description: " << description << "\n";
           cout << "COST: " << longCost << "\n";
           cout << "QUANTITY: " << intQuantity << "\n";
           cout << "VALUE: " << intValue << "\n";
           cout << "min_cost: " << min_cost << "\n";
           cout << "max_cost: " << max_cost << "\n\n";*/
           
           if ((intValue == 1))
           {
               setRemoveItem(code); 
               outputFile << code <<"\t" << description << "\t" << cost << "\t" << quantity << "\t0\n";     
           } 
        }
        File.close();
        outputFile.close();
       	remove(inputFilename);
       	rename("outfile.txt",inputFilename);  
        getAllItemsInCostRange(min_cost,max_cost);         
     }         
   
  File.close();
  return product;
}        

void setAddQuantity(string code, int increment)
{
      
	ifstream inputFile; 
	ofstream outputFile;
	string tempCode, Description;
	long cost;
	int quantity;
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
		cerr<<"Can't open output file\n";
		system("PAUSE");
		exit(1);
	}
	while(!inputFile.eof()){
	inputFile >> tempCode;
		if(!(tempCode=="\n")){
			inputFile>> Description >> cost >> quantity;
			if(Description!=""){
				outputFile << tempCode <<"\t" << Description << "\t" << cost << "\t";
				if(tempCode==code){
					quantity += increment;
				}
			outputFile << quantity << "\n";
			}
		}
	Description = "";
	}

    inputFile.close();
	outputFile.close();
	remove(inputFilename);
	rename("output.txt",inputFilename);
 }   

void setDeleteQuantity(string code, int decrement)
{
      
	ifstream inputFile; 
	ofstream outputFile;
	string tempCode, Description;
	long cost;
	int quantity;
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
		cerr<<"Can't open output file\n";
		system("PAUSE");
		exit(1);
	}
	while(!inputFile.eof()){
	inputFile >> tempCode;
		if(!(tempCode=="\n")){
			inputFile>> Description >> cost >> quantity;
			if(Description!=""){
				outputFile << tempCode <<"\t" << Description << "\t" << cost << "\t";
				if(tempCode==code){
						quantity -= decrement;
				}
			outputFile << quantity << "\n";
			}
		}
	Description = "";
	}

    inputFile.close();
	outputFile.close();
	remove(inputFilename);
	rename("output.txt",inputFilename);
 }
int main(int argc, char *argv[])
{ 
    
    vector<string> temp(2);
    vector<string> temp2(2);
    cout << "setItemData(\"itemnum5\",\"description\", 20, 1500, 0)\n";
    setItemData("itemnum5","description5", 20, 1500, 0);
    cout << "setRemoveItemData\n";
    setRemoveItem("itemnum1");
    cout << "\ngetItemCode\nCode: " << getItemCode("description4") << "\n";
    cout << "\ngetItemCost\nCost: " << getItemCost("itemnum2") << "\n";
    temp = getItemData("itemnum1");
    cout << "\ngetItemData\nDescription: " + temp.at(0) + "\nCost:" + temp.at(1) + "\n";
    cout << "\ngetAllItemsInCostRange(1, 10)\n";
    temp2 = getAllItemsInCostRange(1, 15);
    cout << "Info: " << temp2.at(0) << "\nDone:" << temp2.at(1) << "\n";
    temp2 = getAllItemsInCostRange(1, 15);
    cout << "Info: " << temp2.at(0) << "\nDone:" << temp2.at(1) << "\n";
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

      
