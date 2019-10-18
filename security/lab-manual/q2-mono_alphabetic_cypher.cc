#include<iostream>
#include<fstream>
using namespace std;
char key[26];
bool takenkey[26] = {0};
void key_generate(){
  srand(time(0));
  // char c = 'A';
  // cout<<rand();
  for (int i = 0; i < 26; i++) {
    // key[i] = c++;
    while(1){
      int randchar = rand() % 26;
      if(takenkey[randchar] == 0){
        key[i] = randchar + 'A';
        //marking for taken character
        takenkey[randchar] = 1;
        break;
      }
    }
  }
  // cout<<"takenkey: "; for(int i = 0; i < 26 ; i++){ cout<<key[i]<<' ';}cout<<endl;
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
  out.open(outfile);
  if(!out){
    out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  }
  char c;
  in >> std::noskipws;

  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else
      // key substitutioon
      out<<key[int(c - 'a')];
  }
  in.close();
  out.close();

}
char find(char c){
  int i = 0;
  while(key[i] != c){
    i++;
    if(i == 26) return 'X';
  }
  return i + 'a';
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
  out.open(outfile);
  if(!out){
    out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  }
  char c;
  in >> std::noskipws;

  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else{
      // key substitutioon of inv
        out<<find(c);
    }
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
  int i = 0;
  for (int i = 0; i < 26; i++) takenkey[i] = 0;
  while(in.get(c)){
    if(c > 'Z' || c < 'A'){
      continue;
    }
    if(takenkey[c-'A'] == 1){
      cout<<"INVALID KEY!!"<<endl;
      goto reread;
    }
    takenkey[c-'A'] = 1;
    key[i++] = c;
  }
  if(i != 26){
    cout<<"INVALID KEY!!"<<endl;
    goto reread;
  }
}
int main(int argc, char const *argv[]){
  key_generate();
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY\n(4) EXIT \n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      read_key();
    else if(choice==4)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
