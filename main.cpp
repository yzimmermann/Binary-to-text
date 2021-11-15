#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

// PRE: -
// POST: read an encoded character from the given input stream.
//   It returns a string of length 8 with just 0 and 1 characters if the
//   read value can be converted. Otherwise, it returns an the empty string 
//   if an error occurs or the stream has ended.

std::string readNextEncodedChar(std::istream& in){
  std::string word = std::string(); 
  if (!(in >> word))  {
    // End-of-file
    return std::string();
  }

  // Check that `word` is a valid encoded character: 
  //    it should be a 8-sized string consisting of only '0' or '1' characters.
  if (word.length() != 8) {
    // invalid length
    return std::string();
  }
  for (int i = 0; i < 8; ++i) {
    if (word.at(i) != '1' && word.at(i) != '0') {
      // invalid character found in `word`
      return std::string(); 
    }
  }
  // `word` is a valid encoding of a character 
  return word;
}

unsigned int binary(const std::string& string){
  unsigned int result = 0;
  
  for(int i = 0; i < 8; i++){
    char k = string.at(i);
    int num = (k - 48);
    result += (num * pow(2, 7 - i));
  }
  return result;
}


  

int main(){
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  
  for(int i = 0;;i++){
   std::string u = readNextEncodedChar(in);  
   if(u.size() == 0){
     return 0;
   }
   
   unsigned char v = binary(u);
   std::cout << v;
   
  }
  
  
  //int chara = 01001110;
  //char u = chara;
  //std::cout << u;
  
  
}


