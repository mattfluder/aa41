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
      
	fstream inputFile;
	bool spotFound=false;
	string currentLine;
	inputFile.open("input.txt", ios::in | ios::out);
	if (!inputFile)
	{
		cerr<<"Can't open input file\n";
		system("PAUSE");
		exit(1);
	}
	while(!inputFile.eof()&&!spotFound){
	getline(inputFile, currentLine);
		if (currentLine.empty()){
            inputFile << code << "\t" << description << "\t" << cost << "\t" << quantity << "\t";
			spotFound= true;
			Print(code, description, cost, quantity);
		}
	}
	if (!spotFound)
	{
         Print(code, description, cost, quantity);
         inputFile << code << "\t" << description << "\t" << cost << "\t" << quantity << "\t";
    }
	//Print(code, description, cost, quantity);
    inputFile.close();
 }

int main(int argc, char *argv[])
{
	setItemData("code9","description9", 999, 9);
	system("PAUSE");
	return EXIT_SUCCESS;
}


