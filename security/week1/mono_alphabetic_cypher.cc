#include<iostream>
#include<fstream>
using namespace std;
char key[26];
void key_generate(){
  char c = 'A';
  for (int i = 0; i < 26; i++) {
    key[i] = c++;
  }
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
      out<<key[int(c - 'A')];
  }
  in.close();
  out.close();

}
char find(char c){
  int i = 0;
  while(key[i] != c)
    i++;

  return i + 'A';
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
        out<<find(c);
    }
  }
  in.close();
  out.close();
}
void read_key(){
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
  while(in.get(c)){
    key[i++] = c;
  }
}
int main(int argc, char const *argv[]){
  key_generate();
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY \n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      read_key();
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
