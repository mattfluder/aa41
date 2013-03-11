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
	//Print(code, description, cost, quantity);
    inputFile.close();
	outputFile.close();
	remove("input.txt");
	rename("output.txt","input.txt");
 }

int main(int argc, char *argv[])
{
	setItemData("code9","des69", 696, 69);
	system("PAUSE");
	return EXIT_SUCCESS;
}


