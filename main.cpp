// NOTES
// - String limit : 6 characters
// - All characters are capital
// - Input file will contain the commet name first followed by a new line which contains the
//   group name
// - Number conversion for alphabets will be between 1 - 26
// - Input file name will be "ride.in" and Output file name will be "ride.out"

#include <iostream>
#include <fstream>

#define InputFile "ride.in"
#define OutputFile "ride.out"

using namespace std;

ifstream input(InputFile);
ofstream output(OutputFile, std::ofstream::trunc);
string text; // For storing a single line during file read operation 

// For converting alphebts to integer value
int convertChar(char character){
  return (int) character - 64;
}

// For calculating product value
int productVal(string characterString){
  std::cout << endl << "Calculating product val ...";
  int productVal = 1; 
  for(int i=0 ; i < characterString.length() ; i++){
    productVal *= convertChar(characterString[i]);
  }
  return productVal;
}

// For calculating modulo
int calculateMod(int productValue){
  std::cout << endl << "Calculated modulo val ...";
  int modulo = productValue % 47;
  return modulo;
}

int main() {
  string commetName, groupName;
  int commetValue, groupValue;
  while(getline(input, text)){
    commetName = text;
    getline(input, text);
    groupName = text;
    if(groupName ==  ""){
      std::cout << endl << "A group name is missing ....";
      break;
    }
    
    commetValue = productVal(commetName);
    groupValue = productVal(groupName);
    
    if(calculateMod(commetValue) == calculateMod(groupValue)){
      output << "GO" << endl;
    }
    else{
      output << "STAY" << endl;
    }
  }
}