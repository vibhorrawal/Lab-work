#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
bool key64[64];
bool key56[56];
bool key48[48];
bool initialPermutation_[64];
bool leftPart[32], rightPart[32];
int initialPermutationTable[64] = {
        58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7 };

int keyCompression_[48] = {
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32 };

void initialPermutation(int a, int b){
  for (int i = 0; i < 32; i++) {
    initialPermutation_[i] = (a>>i) & 1; // moving bit by bit
  }
  for (int i = 0; i < 32; i++) {
    initialPermutation_[i] = (b>>i) & 1; // moving bit by bit
  }
  bool temp[64];
  for (int i = 0; i < 64; i++) {
    temp[i] = initialPermutation_[initialPermutationTable[i]-1];
  }
  for (int i = 0; i < 64; i++) {
    initialPermutation_[i] = temp[i];
  }

  for (int i = 0; i < 32; i++) {
    leftPart[i] = initialPermutation_[i];
    rightPart[i] = initialPermutation_[i+32];
  }
}
void shiftLeft28(int s){
  while(s--){
  bool temp = key56[0];
  for (int i = 0; i < 27; i++) {
    key56[i] = key56[i+1];
  }
  key56[27] = temp;

  temp = key56[28];
  for (int i = 28; i < 56; i++) {
    key56[i] = key56[i+1];
  }
  key56[55] = temp;
}
void keyTransformation(int round){
  int shift;
  if(round == 1 || round == 2 || round == 9 || round == 16) shift = 1;
  else shift = 2;
  shiftLeft28(shift);

  for (int i = 0; i < 48; i++) {
    key48[i] = key56[keyCompression_[i]-1];
  }
}
void expansionPermutation(){
  
}
void encrypt(){
//   fstream out, in;
//   string infile, outfile;
//   cout<<"ENTER FILE TO ENCRYPT: ";
//   cin>>infile;
//   in.open(infile);
//   if(!in){
//     cout<<"ERROR: File does not exists!\n";
//     return;
//   }
//   cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
//   cin>>outfile;
//   out.open(outfile, fstream::in | fstream::out | fstream::trunc);
//
//   char c;
//   int charsize = 0;
//   while(in.get(c)){
//     if((c <= 'z' && c >= 'a') || c == ' ')
//     charsize++;
//   }
//   // charsize--;
//   // cout<<charsize<<endl;
//   // return;
//   in.close();
//   in.open(infile);
//   in >> std::noskipws;
//   cout<<"ENTER NUMBER OF FENCES: ";
//   cin>>number_of_rail;
//   char fence[number_of_rail][26];
//   for (int i = 0; i < number_of_rail; i++) {
//     for (int j = 0; j < 26; j++) {
//       fence[i][j] = 'X';
//     }
//   }
//   int count = 0;
//   int number_of_column = ceil(charsize / number_of_rail * 1.0);
//   while(in.get(c)){
//     if((c <= 'z' && c >= 'a') || c == ' ')
//     fence[count % number_of_rail][count / number_of_rail] = c;
//     count++;
//   }
//   // if(charsize > key_size*number_of_rail)
//     while (charsize > key_size*number_of_rail) {
//       key[key_size] = key_size;
//       key_size++;
//     }
//     int tc = 0;
//     int cp = 0;
//     while (charsize < key_size) {
//       if(key[tc] < charsize / number_of_rail){
//         key[tc++] = key[cp];
//         key_size++;
//       }
//       cp++;
//       key_size--;
//     }
//     int ct = 0;
//     while(ct<count){
//       out<<fence[ct/number_of_column][key[ct%number_of_column]];
//       ct++;
//     }
//
//   in.close();
//   out.close();
//
}
void decrypt(){

}
void showKey(){
  cout<<"key: "; for(int i = 0; i < 64 ; i++){ cout<<key64[i]<<' ';}cout<<endl;
}

void inputKey(){
  cout<<"ENTER KEY (it will be hashed to 64 bit): ";
  char ch[64];
  cin>>ch;
  for (int i = 0; i < 64; i++) {
    key64[i] = ch[i]%2;
  }
  cout<<"\nGenerated ";showKey();

  int j = 0;
  for (int i = 0; i < 64; i++) {
    if(i%8 == 7) continue;
    key56[j++] = key64[i];
  }
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) INPUT KEY\n(4) SHOW KEY\n(5) EXIT \n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      inputKey();
    else if(choice==4)
      showKey();
    else if(choice == 5)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
