#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int key[10000];
int key_size;
int number_of_rail;
void key_generate(){
  srand(time(0));
  // key_size = file_size / number_of_rail;
  // key_size = 10;
  cout<<"ENTER SIZE OF KEY TO GENERATE: ";
  cin>>key_size;
  bool incl[key_size] = {0};
  for(int j=0;j<key_size;j++){
    int order;
    do{
       order = rand() % key_size;
    }while(incl[order] != 0);

    key[j] = order;
    incl[order] = 1;
  }
  cout<<"key: "; for(int i = 0; i < key_size ; i++){ cout<<key[i]<<' ';}cout<<endl;
}
void encrypt(){
  fstream out, in;
  string infile, outfile;
  cout<<"ENTER FILE TO ENCRYPT: ";
  cin>>infile;
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
  cin>>outfile;
  out.open(outfile, fstream::in | fstream::out | fstream::trunc);

  char c;
  int charsize = 0;
  while(in.get(c)){
    if((c <= 'z' && c >= 'a') || c == ' ')
    charsize++;
  }
  // charsize--;
  // cout<<charsize<<endl;
  // return;
  in.close();
  in.open(infile);
  in >> std::noskipws;
  cout<<"ENTER NUMBER OF FENCES: ";
  cin>>number_of_rail;
  char fence[number_of_rail][26];
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < 26; j++) {
      fence[i][j] = 'X';
    }
  }
  int count = 0;
  int number_of_column = ceil(charsize / number_of_rail * 1.0);
  while(in.get(c)){
    if((c <= 'z' && c >= 'a') || c == ' ')
    fence[count % number_of_rail][count / number_of_rail] = c;
    count++;
  }
  // if(charsize > key_size*number_of_rail)
    while (charsize > key_size*number_of_rail) {
      key[key_size] = key_size;
      key_size++;
    }
    int tc = 0;
    int cp = 0;
    while (charsize < key_size) {
      if(key[tc] < charsize / number_of_rail){
        key[tc++] = key[cp];
        key_size++;
      }
      cp++;
      key_size--;
    }
    int ct = 0;
    while(ct<count){
      out<<fence[ct/number_of_column][key[ct%number_of_column]];
      ct++;
    }

  in.close();
  out.close();

}
void show_key(){
  cout<<"key: "; for(int i = 0; i < key_size ; i++){ cout<<key[i]<<' ';}cout<<endl;
}
int find(int k){
  for (int i = 0; i < key_size; i++) {
    if(key[i] == k)
    return i;
  }
  return -1;
}
void decrypt(){
  fstream out, in;
  string infile, outfile;
  cout<<"ENTER FILE TO DECRYPT: ";
  cin>>infile;
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
  cin>>outfile;
  out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  char c;
  int charsize = 0;
  while(in.get(c)){
    if((c <= 'z' && c >= 'a') || c == ' ')
    charsize++;
  }
  in.close();
  in.open(infile);
  in >> std::noskipws;
  cout<<"ENTER NUMBER OF FENCES: ";
  cin>>number_of_rail;
  char fence[number_of_rail][26];
  // for (int i = 0; i < number_of_rail; i++) {
  //   for (int j = 0; j < 26; j++) {
  //     fence[i][j] = 'X';
  //   }
  // }
  int count = 0;
  int number_of_column = charsize / number_of_rail;
  while(in.get(c)){
    if((c <= 'z' && c >= 'a') || c == ' ')
    fence[count %number_of_rail][count / number_of_rail] = c;
    count++;
  }
  int ct = 0;
  while(ct<count){
    out<<fence[ct/number_of_column][find(key[ct%number_of_column])];
    ct++;
  }
  in.close();
  out.close();
}
void read_key(){
  reread:
  fstream in;
  string infile;
  cout<<"ENTER FILE WHERE KEYS ARE STORED: ";
  cin>>infile;
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  char c;
  key_size = 0;
  bool incl['Z' - 'A' + 1] = {0};
  while(in.get(c)){
    if(c > 'Z' || c < 'A'){
      continue;
    }
    key[key_size++] = c - 'A';
    if(incl[c-'A']){
      cout<<"INVALID KEY!! TRY AGAIN!!\n";
      goto reread;
    }
    incl[c-'A'] = 1;
  }
  bool flag;
  for (int i = 0; i < key_size; i++) {
    flag = false;
    for (int j = 0; j < key_size; j++) {
      if(key[j] == i) flag = true;
    }
    if(!flag){
      cout<<"INVALID KEY!! TRY AGAIN!!\n";
      goto reread;
    }
  }
  cout<<"key: "; for(int i = 0; i < key_size ; i++){ cout<<key[i]<<' ';}cout<<endl;
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY\n(4) GENERATE KEY\n(5) SHOW KEY\n(6) EXIT \n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      read_key();
    else if(choice==4)
      key_generate();
    else if(choice == 5)
      show_key();
    else if(choice == 6)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
