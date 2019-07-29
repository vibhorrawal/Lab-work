// incomplete
#include<iostream>
#include<fstream>

using namespace std;
// Q is not there
char key[5][5] = {'P','L','A','Y','F','I','R','E','X','M','B','C','D','G','H','K','N','O','J','S','T','U','V','W','Z'};
void encrypt_cipher(char *o, char c1, char c2){
  int x1 = -1, x2 = -1, y1 = -1, y2 = -1, i = 0, j = 0;
  try_again:
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
      if(c1 == key[i]){
        x1 = i, y1 = j;
        break;
      }
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
      if(c1 == key[i]){
        x1 = i, y1 = j;
        break;
      }
  if(x1 == -1){
    c2 = 'X', c1 = c2;
    goto try_again;
  }

}
void encrypt_util(fstream out, fstream in){
  char c1, c2;
  char f;
  char o[2];
  while(in>>c1){
    if(c1 == ' '){
      out<<' ';
      continue;
    }
    else if(c1 == '\n' || c1 == '\r'){
      out<<'\n';
      continue;
    }

    in>>c2;
    if(c1 == c2)
      c2 = 'X';
    if(c2 == ' ' || c2 == '\n' || c2 == '\r')
      c2 = 'X';

    encrypt_cipher(o,c1,c2);
    out<<o;

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
  // char c1,c2;
  in >> std::noskipws;
  encrypt_util(out,in);
  in.close();
  out.close();
}
void decrypt(){

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
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      in>>key[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if(key[i] == key[j] && i != j){
        cout<<"KEY INCORRECT!!";
        return;
      }
    }
  }

}
int main(int argc, char const *argv[]){
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
