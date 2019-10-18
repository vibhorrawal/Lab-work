// incomplete
#include<iostream>
#include<fstream>

using namespace std;
// J is not there
char key[5][5] = {'P','L','A','Y','F','I','R','E','X','M','B','C','D','G','H','K','N','O','Q','S','T','U','V','W','Z'};

void find(char c, int &i, int &j){
  for (i = 0; i < 5; i++) {
    for ( j = 0; j < 5; j++) {
      if(c == key[i][j]) return;
    }
  }
  find('X',i,j);
}
string encrypt_util(char c1, char c2, bool flag){
  string res = "";
  int i1,j1,i2,j2;
  find(c1 - 'a' + 'A',i1,j1);
  // cout<<"i1 "<<i1<<" j1 "<<j1<<endl;
  find(c2 - 'a' + 'A',i2,j2);
  // cout<<"i2 "<<i2<<" j2 "<<j2<<endl;

  if(i1 == i2){ // same row
    res += key[i1][++j1 % 5];
    if(flag) res += " ";
    res += key[i2][++j2 % 5];
  }
  else if(j1 == j2){ // same column
    res += key[++i1 % 5][j1];
    if(flag) res += " ";
    res += key[++i2 % 5][j2];
  }
  else{ // taking edges
    res += key[i1][j2];
    if(flag) res += " ";
    res += key[i2][j1];
  }
  return res;
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
        nextc:
        in.get(c);
        if(c == '\n'){
          flag = 1;
          in.get(c);
        }
        else if(c == ' '){
          flag = 1;
          in.get(c);
        }
        c2 = c;
        if(in.eof()) c2 = 'x';

        if(c1 == c2 && c2 == 'x'){
           c2 = 'q';
           // cout<<"c1 "<<c1<<" c2 "<<c2<<endl;
           out<<encrypt_util(c1,c2,flag);
           // cout<<"JUMP\n";
           goto nextc;
        }
        else if(c1 == c2 && c2 != 'x'){
           c2 = 'x';
           // cout<<"c1 "<<c1<<" c2 "<<c2<<endl;
           out<<encrypt_util(c1,c2,flag);
           // cout<<"JUMP\n";
           goto nextc;
        }
        else{
        out<<encrypt_util(c1,c2,flag);
        if(in.eof()) break;
      }
      }
  }
  in.close();
  out.close();
}
string decrypt_util(char c1, char c2, bool flag){
  string res = "";
  int i1,j1,i2,j2;
  find(c1,i1,j1);
  // cout<<"i1: "<<i1<<" j1: "<<j1<<" c1: "<<c1<<endl;
  find(c2,i2,j2);
  // cout<<"i2 "<<i2<<" j2 "<<j2<<" c2: "<<c2<<" flag: "<<flag<<endl;

  if(i1 == i2){ // same row
    res += key[i1][--j1 % 5] - 'A' + 'a';
    if(flag) res += " ";
    res += key[i2][--j2 % 5] - 'A' + 'a';
  }
  else if(j1 == j2){ // same column
    res += key[--i1 % 5][j1] - 'A' + 'a';
    if(flag) res += " ";
    res += key[--i2 % 5][j2] - 'A' + 'a';
  }
  else{
    res += key[i1][j2] - 'A' + 'a';
    if(flag) res += " ";
    res += key[i2][j1] - 'A' + 'a';
  }
  return res;
}
void decrypt(){
  fstream outf, in;
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
  outf.open(outfile, fstream::in | fstream::out | fstream::trunc);

  char c1,c2,c;
  in >> std::noskipws;
  // encrypt_util(out,in);
  bool flag = false;
  string output = "";
  while(in.get(c)){
    flag = false;

    if(c == '\n' || c == '\r')
      output+='\n';
    else if(c == ' ')
      output+= ' ';
    else
      {
        c1 = c;
        re:
        in.get(c);
        if(in.eof()) break;
        if(c == '\n'){
          flag = 1;
          goto re;
        }
        else if(c == ' '){
          flag = 1;
          goto re;
        }
        else{
        c2 = c;
        if(c2 > 'Z' && c2 < 'A') goto re;
        output+=decrypt_util(c1,c2,flag);
        }
      }
  }
  in.close();
  // outf.close();
  // outf.open(outfile);
  // outf<<output[;
  // outf.close();
  cout<<output<<endl;
  for (int i = 0; i < output.length()-1; i++) {
    outf<<output[i];
  }
  outf.close();

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
