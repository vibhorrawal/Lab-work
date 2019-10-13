#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int a = 3,b = 3;
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
      int ch =  a*(c-'a') + b;
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
  int a_inv,flag;
  for (int i = 0; i < 26; i++)
   {
       flag = (a * i) % 26;

       //Check if (a*i)%26 == 1,
               //then i will be the multiplicative inverse of a
       if (flag == 1)
       {
           a_inv = i;
       }
   }
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
        int ch = (a_inv * ((c - 'A') - b)) % 26 + 'a';
        out<<char(ch);
      }
  }
  in.close();
  out.close();
}
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
void generate_key(){
  srand(time(0));

  for (int i = 0; i < 10; i++) {
    if(i==2)
    a = rand() % 26;
    rand() % 26;
  }
  // a = rand();
  while(gcd(a,26) != 1){
    a = rand() % 26;
  }
  cout<<"a is "<<a<<endl;
  cout<<"ENTER A USABLE b (<26): ";
  cin>>b;
  cout<<endl;
}
void show_key(){
  cout << "a is : "<<a<<endl<<"b is : " <<b<< endl<<endl;
}
void input_key(){
  cout<<"ENTER a: ";
  cin>>a;
  cout<<"ENTER b: ";
  cin>>b;
  cout<<endl;
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) GENERATE KEY \n(4) SHOW KEY\n(5) INPUT KEY\n(6) EXIT\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      generate_key();
    else if(choice == 4)
      show_key();
    else if(choice == 5)
      input_key();
    else if(choice == 6)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
