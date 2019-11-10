#include<iostream>
#include<fstream>
#include<math.h>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
#define mi map<int, int>
#define vs vector<string>
using namespace std;


void print(vector<string> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<"\n";
}

void split(vector<string> &token, vector<string> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        string word = "";
        for (auto x : a[i])
        {
            if (x == ' ')
            {
                token.push_back(word);
                word = "";
            }
            else
                word = word + x;
        }
        token.push_back(word);
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
void decrypt(){
  fstream out;
  string infile, outfile;
  cout<<"ENTER FILE TO DECRYPT: ";
  cin>>infile;
  // in.open(infile);
  ifstream in(infile.c_str());
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
  cin>>outfile;
  out.open(outfile, fstream::in | fstream::out | fstream::trunc);

  vs a;
  while(!in.eof())
  {
      string inp;
      getline(in, inp);
      a.push_back(inp);
  }
  vs token;
  split(token, a);

  mi m;
  char dict[] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'R','H', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W', 'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};

  for(int i = 0; i < token.size(); i++)
        for(int j = 0; j < token[i].size(); j++)
            m[toupper(token[i][j])-'A']++;

    vector<pair<int, int> > mpcopy(m.begin(), m.end());
    sort(mpcopy.begin(), mpcopy.end(), compare);

    in.close();
    in.open(infile);
    string l;
    while(!in.eof())
    {
      cout << "message" << endl;
        getline(in, l);
        for(int i = 0; i < l.size(); i++)
        {
            if(isalpha(l[i]))
            {
                for(int j = 0; j < 26; j++)
                {
                    if(l[i] == char(mpcopy[j].first + 'A'))
                    {
                        l[i] = tolower(dict[j]);
                        out<<char(l[i]);
                    }
                }
            }
            else
                out<<char(l[i]);
        }
    }
  out<<endl;

    in.close();
    out.close();
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) DECRYPT FILE\n(2) EXIT\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      decrypt();
    else if(choice == 2)
      return 0;
    else
    cout<<"WRONG INPUT!!\n";
  }
  return 0;
}
