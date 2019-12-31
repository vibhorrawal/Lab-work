#include<iostream>
#include<fstream>
#include<math.h>
#include <vector>
#include<algorithm>
#define vi vector<int>
#define ll long long int
using namespace std;

ll powerMod(ll t, ll e, int N){
  if(e==1) return t;
  return (t*powerMod(t,e-1,N) % N) % N;
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
bool checkPrimeRoot(vi v, int q)
{
    for(int i = 0; i < q-1; i++)
        if(v[i] != i+1)
            return false;
    return true;
}

int primeRoot(int q){
  for (int i = 1; i < q; i++) {
    vi v;
    for (int j = 1; j < q; j++) {
        v.push_back(powerMod(i,j,q));
    }
    sort(v.begin(),v.end());
    if(checkPrimeRoot(v,q)) return i;
  }
}
void keyGeneration(){
  vi primeList = generatePrime(100);
  int q = primeList[rand() % 100];
  int alpha = primeRoot(q);
  int Xa = 2 + (rand() % (q-1));
  int Xb = 2 + (rand() % (q-1));
  int Ya = powerMod(alpha, Xa, q) % q;
  int Yb = powerMod(alpha, Xb, q) % q;
  int Ka = powerMod(Yb, Xa, q) % q;
  int Kb = powerMod(Ya, Xb, q) % q;
  cout << "q: "<<q<<"\nalpha: "<<alpha<<"\nXa: "<<Xa<<"\nXb: "<<Xb<<"\nYa: "
  <<Ya<<"\nYb: "<<Yb<<"\nKa: "<<Ka<<"\nKb: "<<Kb<< endl;
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) Generate key\n(2) EXIT\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      keyGeneration();
    else if(choice == 2)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
