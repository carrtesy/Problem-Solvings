#include <iostream>
#include <fstream>

using namespace std;
int main(void){
  string filePath = "input2.txt";

  ofstream writeFile(filePath.data());
  if(writeFile.is_open()){
    writeFile << "100000\n";
    for(int i = 1; i <= 100000; i++){
      writeFile << 1000 << " ";
    }
    writeFile.close();
  }
}
