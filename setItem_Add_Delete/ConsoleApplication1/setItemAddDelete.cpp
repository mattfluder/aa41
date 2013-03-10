#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

 void setItemData (string code, string description, long cost, int quantity){
	fstream inputFile;
	bool spotFound=false;
	string currentLine;
	inputFile.open("input.txt",ios::in | ios::out | ios::app);
	if (!inputFile)
	{
		cerr<<"Can't open input file\n";
		system("PAUSE");
		exit(1);
	}
	while(!inputFile.eof()&&!spotFound){
	getline(inputFile, currentLine);
		if (currentLine.empty()){
			spotFound= true;
		}
	}
	inputFile << code << "\t" << description << "\t" << cost << "\t" << quantity << "\t";
	inputFile.close();
 }

int main(int argc, char *argv[])
{
	setItemData("code9","description9", 999, 9);
	system("PAUSE");
	return EXIT_SUCCESS;
}


