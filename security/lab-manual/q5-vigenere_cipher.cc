#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char key[100];
int key_size = 0;

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
  in >> std::noskipws;
  int i = 0;
  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else{
      int ch = c + key[(i++)%key_size] - 'a' - 'A';
      while(ch<0) ch+= 26;
      out<<char(ch % 26 + 'A');
    }
  }
  in.close();
  out.close();

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
  // in.unsetf(std::ios_base::skipws);
  in >> std::noskipws;
  int i = 0;
  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
      else{
        int ch = c - key[(i++)%key_size] - 'A' - 'A';
        while(ch<0) ch+= 26;
        out<<char(ch % 26 + 'a');
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
  in >> std::noskipws;
  while(in.get(c)){
    key[key_size++] = c;
  }
}
void show_key(){
  cout<<"KEY: ";
  for (int i = 0; i < key_size; i++) {
    cout<<key[i];
  }
  cout<<endl;
}
void input_key(){
  string k;
  cout<<"\nENTER KEY: ";
  cin>>k;
  int j = 0;
  for (int i = 0; i < k.length(); i++) {
    if(!isalpha(k[i])) continue;
    key[j++] = toupper(k[i]);
  }
  key_size = k.length();
}
void save_key(){
  cout<<"KEY SAVED IN key.txt\n";
  fstream out;
  out.open("key.txt", fstream::in | fstream::out | fstream::trunc);
  for (int i = 0; i < key_size; i++) {
    out<<key[i];
  }
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY \n(4) SHOW KEY\n(5) INPUT KEY\n(6) SAVE KEY\n(7) EXIT\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      read_key();
    else if(choice == 4)
      show_key();
    else if(choice == 5)
      input_key();
    else if(choice == 6)
      save_key();
    else if(choice == 7)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
