// incomplete
#include<iostream>
#include<fstream>

using namespace std;
// J is not there
char key[5][5] = {'P','L','A','Y','F','I','R','E','X','M','B','C','D','G','H','K','N','O','Q','S','T','U','V','W','Z'};
// void encrypt_util(fstream out, fstream in){
//
// }
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
  char c1,c2,c;
  in >> std::noskipws;
  // encrypt_util(out,in);
  bool flag = false;
  while(in.get(c)){
    flag = false;

    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else
      {
        c1 = c;
        again:
        if(in.get(c) == EOF) c2 = 'x';
        if(c == '\n' || c == '\r'){
          flag = 1;
          goto again;
        }
        else if(c == ' '){
          flag = 1;
          goto again;
        }
        else c2 = c;
        if(c1 == c2 && c2 == 'x') c2 = 'q';
        if(c1 == c2 && c2 == 'q') c2 = 'x';
        out<<
      }
  }
  in.close();
  out.close();
}
void decrypt(){

}
void read_key(){
  bool takenkey[25] = {0};
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
  takenkey[9] = 1;
  while(in.get(c)){
    if(c > 'Z' || c < 'A'){
      continue;
    }
    if(takenkey[c-'A'] == 1){
      continue;
    }
    takenkey[c-'A'] = 1;
    key[i/5][i%5] = c;
    i++;
    if(i == 25) break;
  }
  int j = 0;
  while(i < 25){
      while(takenkey[j++] != 0);
      key[i/5][i%5] = --j + 'A';
      takenkey[j] = 1;
      i++;

  }
  cout<<"key: "; for(int i = 0; i < 25 ; i++){ cout<<key[i/5][i%5]<<' ';}cout<<endl;

}
int main(int argc, char const *argv[]){
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
}
