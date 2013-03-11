#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <cstdlib>

using namespace std;

 void setItemData (string code, string description, long cost, int quantity){
      
	ifstream inputFile; 
	ofstream outputFile;
	bool spotFound=false;
	string currentLine;
	inputFile.open("input.txt");//opens input file
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
    inputFile.close();
	outputFile.close();
	remove("input.txt");
	rename("output.txt","input.txt");
 }
 
 int setRemoveItem(string code)
{
    string line;
    //Open Input File
    ifstream in("infile.txt");
    if(!in.is_open())
    {
      cout << "Input File Failed to Open\n";
      return 1;
    }

    //Open Temporary Output File
    ofstream out ("outfile.txt");
    //Loop to read/write the file.
    while (getline(in,line))
    {
        if(line != code)
        out<< line << "\n";
    }
    in.close();
    out.close();
    //Delete the original file
    remove("infile.txt");
    //Rename Edited File to Infile.txt
    rename("outfile.txt","infile.txt");
    return 0;
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

 void setAddQuantity(string code, int increment){
      
	ifstream inputFile; 
	ofstream outputFile;
	string currentLine;
	string tempCode, Description;
	long cost;
	int quantity;
	inputFile.open("input.txt");//opens input file
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
	remove("input.txt");
	rename("output.txt","input.txt");
 }

  void setDeleteQuantity(string code, int decrement){
      
	ifstream inputFile; 
	ofstream outputFile;
	string currentLine;
	string tempCode, Description;
	long cost;
	int quantity;
	inputFile.open("input.txt");//opens input file
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
	remove("input.txt");
	rename("output.txt","input.txt");
 }

 


