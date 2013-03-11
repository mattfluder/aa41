#include <iostream> 
#include <string>
#include <fstream>

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

 void setAddQuantity(string code, int increment){
      
	ifstream inputFile; 
	ofstream outputFile;
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

int main(int argc, char *argv[])
{
	setItemData("code1", "des1", 123, 1);
	setItemData("code2", "des2", 456, 2);
	setItemData("code3", "des3", 789, 3);
	setItemData("code4", "des4", 101, 4);
	setAddQuantity("code2", 20);
	setDeleteQuantity("code4", 5);
	setAddQuantity("code4", 4);
	system("PAUSE");
	return EXIT_SUCCESS;
}


