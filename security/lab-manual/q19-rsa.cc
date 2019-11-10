#include<iostream>
#include<fstream>
#include<math.h>
#include <vector>
#include<algorithm>
#define vi vector<int>
#define ll long long int
#define ppi pair<pair<int, int>, int>
using namespace std;

ll powerMod(ll t, ll e, int N){
  if(e==1) return t;
  return (t*powerMod(t,e-1,N) % N) % N;
}
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

bool isPrime(int a)
{
    if (a == 2)
        return true;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}

vi generatePrime(int n)
{
    vector<int> v;
    int i = 2;
    while(v.size() != n)
    {
        if(isPrime(i))
            v.push_back(i);
        i++;
    }
    return v;
}
vi gen_eList(int phi){
  vi v;
  for (int i = 1; i < phi; i++) {
    if(gcd(i,phi) == 1) v.push_back(i);
  }
  return v;
}
int calculate_d(int phi, int e){
  for (int i = 1; i < phi; i++) {
    if((e * i) % phi == 1) return i;
  }
}
ppi keyGeneration(){
  vi v = generatePrime(100);
  int p = v[rand() % 100];
  int q = v[rand() % 100];
  int n = p * q;
  int phi = (p-1) * (q-1);
  vi eList = gen_eList(phi);
  int e = eList[rand() % eList.size()];
  int d = calculate_d(phi, e);
  cout << "e: "<<e<<"\nd: "<<d<<"\nn: "<<n << endl;
  return make_pair(make_pair(e,d),n);
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
  ppi k = keyGeneration();

  // char c;
  // in >> std::noskipws;
  int flag = 0;
  while(!in.eof())
  {
      string a;
      in>>a;
      // cout<<a<<endl;
      if(a == " " || a == "\n" || a == "\r") continue;
      int b = stoi(a); //cout << b << endl;
      ll c = powerMod(b, k.first.first, k.second) % k.second;
      if (flag == false)
      {
          out<<c;
          flag = true;
      }
      else
          out<<" "<<c;
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
  int e,d,n;
  cout<<"Input e:";cin>>e;
  cout<<"Input d:";cin>>d;
  cout<<"Input n:";cin>>n;

  char c;
  while(!in.eof())
      {
          string a;
          in>>a;
          int b = stoi(a);
          ll c = powerMod(b, d, n) % n;
          out<<c<<" ";
      }

}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) Generate key\n(2) Encrypt File\n(3) Decrypt File\n(4) Exit\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      keyGeneration();
    else if(choice == 2)
      encrypt();
    else if(choice== 3)
      decrypt();
    else if(choice == 4)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
