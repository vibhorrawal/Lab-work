#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int key[100] = {0};
int key_size = 1;
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

  in.close();
  in.open(infile);
  in >> std::noskipws;

  // finding no of rows
  number_of_rail = ceil(charsize / float(key_size));
  char fence[number_of_rail][key_size];
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      fence[i][j] = 'X';
    }
  }
  // char c;
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      in.get(c);
      fence[i][j] = c;
    }
  }

    for (int i = 0; i < key_size; i++) {
      int j;
      for (j = 0; j < key_size; j++) {
        if(i == key[j])
          break;
      }
      for (int k = 0; k < number_of_rail; k++) {
        if(fence[k][j] == ' ') out<<fence[k][j];
        else if(fence[k][j] == '\n') out<<fence[k][j];
        else
        out<<char(fence[k][j] - 'a' + 'A');
      }
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
    // if((c <= 'z' && c >= 'a') || c == ' ')
    charsize++;
  }
  in.close();
  in.open(infile);
  in >> std::noskipws;
  // cout<<"ENTER NUMBER OF FENCES: ";
  // cin>>number_of_rail;
   number_of_rail = ceil(charsize / float(key_size));

  char fence[number_of_rail][key_size];
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      fence[i][j] = 'X';
    }
  }
  // cout<<number_of_rail;
  // int count = 0;
  // while(in.get(c)){
  //   if((c <= 'z' && c >= 'a') || c == ' ')
  //   fence[count %number_of_rail][count / number_of_rail] = c;
  //   count++;
  // }
  for (int i = 0; i < key_size; i++) {
    int j = 0;
    for (j = 0; j < key_size; j++) {
      if(i == key[j])
        break;
    }
    for (int k = 0; k < number_of_rail; k++) {
      char c;
      in.get(c);
      fence[k][j] = c;
    }
  }
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      if(fence[i][j] == ' ') out<<fence[i][j];
      else if(fence[i][j] == '\n') out<<fence[i][j];
      else
      out<<char(fence[i][j] - 'A' + 'a');
      // cout<<char(fence[i][j] - 'A' + 'a');
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
void multiple_encrypt(){
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
  int rounds;

  reround:
  cout<<"HOW MANY ROUNDS DO YOU WANT(>0)?\n";
  cin>>rounds;
  if(rounds < 1) goto reround;
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
  // cout<<"ENTER NUMBER OF FENCES: ";
  // cin>>number_of_rail;
  number_of_rail = ceil(charsize / float(key_size));
  char fence[number_of_rail][key_size];
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      fence[i][j] = 'X';
    }
  }
  // char c;
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      in.get(c);
      fence[i][j] = c;
    }
  }
  string outstring;
    for (int i = 0; i < key_size; i++) {
      int j;
      for (j = 0; j < key_size; j++) {
        if(i == key[j])
          break;
      }
      for (int k = 0; k < number_of_rail; k++) {
        if(fence[k][j] == ' ') outstring += char(fence[k][j]);
        else if(fence[k][j] == '\n') outstring += char(fence[k][j]);
        else
        outstring += char(fence[k][j] - 'a' + 'A');
      }
    }
  rounds--;
  while(rounds--){
    int tc = 0;
    for (int i = 0; i < number_of_rail; i++) {
      for (int j = 0; j < key_size; j++) {
        c = outstring[tc++];
        fence[i][j] = c;
      }
    }
    string temps;
    for (int i = 0; i < key_size; i++) {
      int j;
      for (j = 0; j < key_size; j++) {
        if(i == key[j])
          break;
      }
      for (int k = 0; k < number_of_rail; k++) {
        if(fence[k][j] == ' ') temps += fence[k][j];
        else if(fence[k][j] == '\n') temps += fence[k][j];
        else
        temps += char(fence[k][j]);
      }
    }
    outstring = temps;
  }
  out<<outstring;
  in.close();
  out.close();
}
void multiple_decrypt(){
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
  int rounds;
  reround:
  cout<<"HOW MANY ROUNDS DO YOU WANT(>0)?\n";
  cin>>rounds;
  if(rounds < 1) goto reround;
  char c;
  int charsize = 0;
  while(in.get(c)){
    // if((c <= 'z' && c >= 'a') || c == ' ')
    charsize++;
  }
  in.close();
  in.open(infile);
  in >> std::noskipws;
  // cout<<"ENTER NUMBER OF FENCES: ";
  // cin>>number_of_rail;
   number_of_rail = ceil(charsize / float(key_size));

  char fence[number_of_rail][key_size];
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      fence[i][j] = 'X';
    }
  }
  // cout<<number_of_rail;
  // int count = 0;
  // while(in.get(c)){
  //   if((c <= 'z' && c >= 'a') || c == ' ')
  //   fence[count %number_of_rail][count / number_of_rail] = c;
  //   count++;
  // }
  for (int i = 0; i < key_size; i++) {
    int j = 0;
    for (j = 0; j < key_size; j++) {
      if(i == key[j])
        break;
    }
    for (int k = 0; k < number_of_rail; k++) {
      char c;
      in.get(c);
      fence[k][j] = c;
    }
  }
  string outstring;
  for (int i = 0; i < number_of_rail; i++) {
    for (int j = 0; j < key_size; j++) {
      if(fence[i][j] == ' ') outstring += fence[i][j];
      else if(fence[i][j] == '\n') outstring += fence[i][j];
      else
      outstring += char(fence[i][j] - 'A' + 'a');
      // cout<<char(fence[i][j] - 'A' + 'a');
    }
  }
  rounds--;
  while(rounds--){
    int tc = 0;
    for (int i = 0; i < key_size; i++) {
      int j = 0;
      for (j = 0; j < key_size; j++) {
        if(i == key[j])
          break;
      }
      for (int k = 0; k < number_of_rail; k++) {
        char c = outstring[tc++];
        // in.get(c);
        fence[k][j] = c;
      }
    }
    string temps;

    for (int i = 0; i < number_of_rail; i++) {
      for (int j = 0; j < key_size; j++) {
        if(fence[i][j] == ' ') temps += fence[i][j];
        else if(fence[i][j] == '\n') temps += fence[i][j];
        else
        temps += char(fence[i][j]);
        // cout<<char(fence[i][j] - 'A' + 'a');
      }
    }
    outstring = temps;
  }
  out<<outstring;
  in.close();
  out.close();
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY\n(4) GENERATE KEY\n(5) SHOW KEY\n(6) MULTIPLE ENCRYPTION\n(7) MULTIPLE DECRYPTION\n(8) EXIT \n\nchoice: ";
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
      multiple_encrypt();
    else if(choice == 7)
      multiple_decrypt();
    else if(choice == 8)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
