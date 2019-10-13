#include<iostream>
#include<fstream>
using namespace std;
char key[9];
char invkey[9];
bool is2x2 = true;
bool isInvertible(){
  if(is2x2){
    return key[0] * key[3] - key[1] * key[3];
  }
  else{
    return key[0]*(key[4]*key[8] - key[7]*key[5]) - key[1]*(key[3]*key[8] - key[5]*key[6]) + key[2]*(key[3]*key[7] - key[6]*key[4]);
  }
}
void key_generate(){
  srand(time(0));
  cout<<"\nType y if you want to generate a 3x3 key, else a 2x2 key will be generated: ";
  char ch;
  cin>>ch;
  if(ch == 'y') is2x2 = false;
  else is2x2 = true;
  tryagain:
  if(is2x2){
    for (int i = 0; i < 4; i++) {
      key[i] = rand() % 26;
    }
  }
  else{
    for (int i = 0; i < 9; i++) {
      key[i] = rand() % 26;
    }
  }
  if(!isInvertible()) goto tryagain;
  // cout<<"key: "; for(int i = 0; i < 9 ; i++){ cout<<key[i]<<' ';}cout<<endl;
}
int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;

    return -1;
}
void keyInverse(){
  if(is2x2){
    int detA = modInverse(key[0] * key[3] - key[1] * key[3], 26);
    invkey[0] = key[3] * detA % 26;
    invkey[1] = -1 * key[1] * detA % 26;
    invkey[2] = -1 * key[2] * detA % 26;
    invkey[3] = key[0] * detA % 26;
  }
  else{
    int detA = modInverse(key[0]*(key[4]*key[8] - key[7]*key[5]) - key[1]*(key[3]*key[8] - key[5]*key[6]) + key[2]*(key[3]*key[7] - key[6]*key[4]), 26);
    invkey[0] = (key[4] * key[8] - key[7] * key[5]) * detA % 26;
    invkey[1] = (key[2] * key[7] - key[1] * key[8]) * detA % 26;
    invkey[2] = (key[1] * key[5] - key[2] * key[4]) * detA % 26;
    invkey[3] = -1 * (key[3] * key[8] - key[6] * key[5]) * detA % 26;
    invkey[4] = (key[0] * key[8] - key[2] * key[6]) * detA % 26;
    invkey[5] = -1 * (key[0] * key[5] - key[3] * key[2]) * detA % 26;
    invkey[6] = (key[3] * key[7] - key[6] * key[4]) * detA % 26;
    invkey[7] = -1 * (key[0] * key[7] - key[1] * key[6]) * detA % 26;
    invkey[8] = (key[0] * key[4] - key[1] * key[3]) * detA % 26;
  }
  cout<<"invkey: "; for(int i = 0; i < 9 ; i++){ cout<<invkey[i]<<' ';}cout<<endl;
}
void matrixMul(int &res1, int &res2, int x1, int x2, bool useInv){
  if(useInv){
    res1 = invkey[0] * x1 + invkey[1] * x2;
    res2 = invkey[2] * x1 + invkey[3] * x2;
  }
  else{
    res1 = key[0] * x1 + key[1] * x2;
    res2 = key[2] * x1 + key[3] * x2;
  }
}
void matrixMul(int &res1, int &res2, int &res3, int x1, int x2, int x3, bool useInv){
  if(useInv){
    res1 = invkey[0] * x1 + invkey[1] * x2 + invkey[2] * x3;
    res2 = invkey[3] * x1 + invkey[4] * x2 + invkey[5] * x3;
    res3 = invkey[6] * x1 + invkey[7] * x2 + invkey[8] * x3;
  }
  else{
    res1 = key[0] * x1 + key[1] * x2 + key[2] * x3;
    res2 = key[3] * x1 + key[4] * x2 + key[5] * x3;
    res3 = key[6] * x1 + key[7] * x2 + key[8] * x3;
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
  int count = 0;
  int res[3],inp[3];
  while(in.get(c)){
    step1:
    /* if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else */{
      if(is2x2) inp[count++ % 2] = c - 'a';
      else inp[count++ % 3] = c - 'a';
      if(is2x2 && count%2 == 1) goto step2;
      if(!is2x2 && count%3 == 2) goto step2;
    }
  }

  step2:
  if(is2x2){
    matrixMul(res[0],res[1],inp[0],inp[1],false);
    out<<res[0] + 'A';
    out<<res[1] + 'A';
  }
  else{
    matrixMul(res[0],res[1],res[2],inp[0],inp[1],inp[2],false);
    out<<res[0] + 'A';
    out<<res[1] + 'A';
    out<<res[2] + 'A';
  }
  goto step1;

  in.close();
  out.close();

}

void decrypt(){
  // fstream out, in;
  // string infile, outfile;
  // cout<<"ENTER FILE TO DECRYPT: ";
  // cin>>infile;
  // in.open(infile);
  // if(!in){
  //   cout<<"ERROR: File does not exists!\n";
  //   return;
  // }
  // cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
  // cin>>outfile;
  // out.open(outfile);
  // if(!out){
  //   out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  // }
  // char c;
  // in >> std::noskipws;
  //
  // while(in.get(c)){
  //   if(c == '\n' || c == '\r')
  //     out<<'\n';
  //   else if(c == ' ')
  //     out<<' ';
  //   else{
  //       out<<find(c);
  //   }
  // }
  // in.close();
  // out.close();
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
  while(in.get(c)){
    if(c == ' ' | c == '\n') continue;
    if(c > 'Z' || c < 'A'){
      cout<<"INVALID KEY!! TRY AGAIN\n";
      cout<<c<<endl;
      goto reread;
    }
    key[i++] = c - 'A';
  }
  if(i == 4) {
    is2x2 = true;
    if(!isInvertible()){
      cout<<"KEY IS NOT INVERTIBLE! TRY AGAIN!!\n";
      goto reread;
    }
    return;
  }
  if(i == 9){
    is2x2 = false;
    if(!isInvertible()){
      cout<<"KEY IS NOT INVERTIBLE! TRY AGAIN!!\n";
      goto reread;
    }
    return;
  }
  cout<<"INVALID KEYSIZE!! INPUT KEYSIZE OF 2x2 OR 3x3!!! TRY AGAIN\n";
  goto reread;

}
void input_key(){
  retry:
  cout<<"IS KEY OF SIZE 3x3?(y/n): ";
  char ch;
  cin>>ch;
  cout<<"INPUT YOUR KEY"<<endl;
  if(ch == 'y'){
    is2x2 = false;
    for (int i = 0; i < 9; i++) {
      cin>>key[i];
      key[i] -= 'A';
    }
  }
  else{
     is2x2 = true;
     for (int i = 0; i < 4; i++) {
       cin>>key[i];
       key[i] -= 'A';
     }
   }
  if(!isInvertible()){
    cout<<"KEY IS NOT INVERTIBLE! TRY AGAIN!!\n";
    goto retry;
  }

}
void save_key(){
  cout<<"KEY SAVED IN key.txt\n";
  fstream out;
  out.open("key.txt", fstream::in | fstream::out | fstream::trunc);
  int key_size;
  if(is2x2) key_size = 4;
  else key_size = 9;
  for (int i = 0; i < key_size; i++) {
    out<<char(key[i] + 'A');
  }
}
int main(int argc, char const *argv[]){
  // key_generate();
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY\n(4) INPUT KEY\n(5) GENERATE KEY\n(6) SAVE KEY\n(7) EXIT \n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      read_key();
    else if(choice == 4)
      input_key();
    else if(choice == 5)
      key_generate();
    else if(choice==6)
      save_key();
    else if(choice==7)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
