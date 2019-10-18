// - Plain text will be in small case
// - Cipher text will be in CAPITAL case
// - No special symbols are allowed in Encryption/Decryption
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
  int key;
  cout<<"ENTER KEY: ";
  cin>>key;
  char c;
  in >> std::noskipws;

  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else{
      // adding the key
      char ch = (c - 'a' + key)%26;
      if(ch<0) ch = ch + 26;
      out<<char( ch + 'A');
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
  out.open(outfile);
  if(!out){
    out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  }
  int key;
  cout<<"ENTER KEY: ";
  cin>>key;
  char c;
  // in.unsetf(std::ios_base::skipws);
  in >> std::noskipws;

  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else{
      // subtracting the key
      char ch = (c - 'A' - key);
      while (ch<0) ch += 26;
        out<<char( ch % 26 + 'a');
    }
  }
  in.close();
  out.close();
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) EXIT\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice==3)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
}
