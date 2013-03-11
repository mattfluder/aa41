#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void getAllItemsInCostRange(string min_cost, string max_cost)
{
   string fileDataLine, min_test, max_test;
   fstream File("inventory.txt", ios::in | ios::out);
   
   if (!File) {
     cerr << "Can't open input file " << File << endl;
     exit(1);
   }
   
   File >> min_test >> max_test;
      
   if ((min_test.compare(min_cost) == 0) && (max_test.compare(max_cost)) == 0) {
     
    // while(!File.eof()) {
       getline(File, fileDataLine, '~');
       cout << fileDataLine;
       
       if (fileDataLine[fileDataLine.length() - 1] == '0') {
         cout << "hi";
         long pos = File.tellp();
         cout << pos;
         File.seekp(pos-2);
         File.write("z",1); 
         
     //  } 
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
