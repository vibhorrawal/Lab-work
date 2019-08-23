#include<iostream>
using namespace std;
#define SIZE 2
int key[SIZE*SIZE];

int det(int a[]){
  return a[0]*a[3] - a[1]*a[2];
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
  if(det(key) == 0){
    cout<<"CAN NOT USE A KEY WITH det(A) = 0!!!!!";
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

  char c1,c2;
  int res[SIZE];
  while(in.get(c1) || in.get(c2)){
    if(c1 == '\n' || c1 == '\r' && c2 == c1)
      out<<'\n';
    else if(c1 == ' '){
      out<<' ';
      c1 = c2;
      in.get(c2);
    }
    else if(c2 == ' '){
      matrix_multiply(res,key,c1);
      for (int i = 0; i < SIZE; i++)
        if(res[i] != -1)
          out<<res[i];
    }
    else
      {
        matrix_multiply(res,key,c1,c2);
        for (int i = 0; i < SIZE; i++)
          if(res[i] != -1)
            out<<res[i];
      }
  }
  in.close();
  out.close();

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
