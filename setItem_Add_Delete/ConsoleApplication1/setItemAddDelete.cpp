#include <iostream> 
#include <string>
#include <fstream>

using namespace std;
void Print(string code, string description, long cost, int quantity)
{
     cout << code;
     cout << description;
     cout << cost;
     cout << quantity << endl;
     
     return;
}

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
	string currentLine;
	string tempCode, Description,trash;
	string previousCode;
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
		cerr<<"Can't open input file\n";
		system("PAUSE");
		exit(1);
	}
	while(!inputFile.eof()){
	inputFile >> tempCode;
		if(!(tempCode=="\n")){//&&tempCode != previousCode
			inputFile>> Description >> cost >> quantity;
			if(Description!=""){
				outputFile << tempCode <<"\t" << Description << "\t" << cost << "\t";
				if(tempCode==code){
					quantity += increment;
				}
			outputFile << quantity << "\n";
			}
		}
	previousCode=tempCode;
	Description = "";
	}

    inputFile.close();
	outputFile.close();
	remove("input.txt");
	rename("output.txt","input.txt");
 }

int main(int argc, char *argv[])
{
	//setItemData("code9","des69", 696, 69);
	setAddQuantity("code2", 20);
	system("PAUSE");
	return EXIT_SUCCESS;
}


