#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
void generate_rand(){
  srand(time(0));
  int a,b;
  a = rand() % 999 + 1;
  b = rand() % 999 + 1;

}
void filesave(string outputfile){
  fstream out;
  srand(time(0));
  int a,b;

  out.open(outputfile, fstream::in | fstream::out | fstream::trunc);
  for (int i = 0; i < 100; i++) {
    a = rand() % 999 + 1;
    b = rand() % 999 + 1;
    out<<a<<','<<b<<'\n';
    // out<<" gcd: "<<gcd(a,b)<<endl;
  }

}
int gcd2(int a, int b)
{
    int res;
    if(a>b){
      res = a-1;
    }
    else{
      res = b - 1;
    }

      while(res > 1){
        if(a%res == 0 && b % res == 0)
          return res;
        res--;
      }
return 1;
}
void calcgcd(){
  string infile, outfile;
  fstream in, out;
  cout<<"Enter filename: ";
  cin>>infile;
  cout<<"Enter filename to save result: ";
  cin>>outfile;

  out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  // in.open(infile, fstream::in | fstream::out | fstream::trunc);
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }

  char c;
  // in >> std::noskipws;
  int tc = 100;
  while(tc--){
    in.get(c);
    int num = 0;
    while(c != ','){
      num = num * 10;
      num = num + c - '0';
      in.get(c);
    }
    // cout<<num<<','<<endl;

    in.get(c);
    int num2 = 0;
    while(c != '\n'){
      num2 = num2 * 10;
      num2 = num2 + c - '0';
      in.get(c);
    }

    // cout<<num2<<','<<endl;

    int res = gcd(num,num2);
    out<<res<<endl;
  }
  in.close();
  out.close();
}
void calcgcd2(){
  string infile, outfile;
  fstream in, out;
  cout<<"Enter filename: ";
  cin>>infile;
  cout<<"Enter filename to save result: ";
  cin>>outfile;

  out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  // in.open(infile, fstream::in | fstream::out | fstream::trunc);
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }

  char c;
  // in >> std::noskipws;
  int tc = 100;
  while(tc--){
    in.get(c);
    int num = 0;
    while(c != ','){
      num = num * 10;
      num = num + c - '0';
      in.get(c);
    }
    // cout<<num<<','<<endl;

    in.get(c);
    int num2 = 0;
    while(c != '\n'){
      num2 = num2 * 10;
      num2 = num2 + c - '0';
      in.get(c);
    }

    // cout<<num2<<','<<endl;

    int res = gcd2(num,num2);
    out<<res<<endl;
  }
  in.close();
  out.close();
}
int main(int argc, char const *argv[]){
  // calcgcd();
  while(1){
  cout<<"**** MENU ****\n\n1) Generate file\n2) GCD\n3) GCD non recursive\n4) EXIT\n";
  int choice;
  cin>>choice;
  if(choice == 1){
    cout<<"Enter filename: ";
    string s;
    cin>>s;
    filesave(s);
  }
  else if(choice == 2){
    calcgcd();
  }
  else if(choice == 3){
    calcgcd2();
  }
  else if(choice == 4)
    break;
  else cout<<"Wrong choice!\n";
}
  return 0;
}
