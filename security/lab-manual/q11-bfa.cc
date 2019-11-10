#include<iostream>
#include<fstream>
#include<math.h>
#include <vector>

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

void predicting_best_phrase(string outfile){
  fstream out;
  out.open(outfile);

  vector<string> a;
    while(!out.eof())
    {
        string in;
        getline(out, in);
        a.push_back(in);
    }

  vector<string> common;
  ifstream com("common_words.txt");
  if(!com){
     cout<<"Error opening common_words.txt\nExiting..\n";
     exit(0);
  }
  while(!com.eof()){
     string in;
     getline(com, in);
     common.push_back(in);
  }

  vector<string> token;
  split(token, a);

  vector<string> res;
  for(int i = 0; i < token.size(); i++)
      for(int j = 0; j < common.size(); j++)
          if(token[i].compare(common[j]) == 0)
              res.push_back(token[i]);

  cout<<"10 most predicted words are\n";
  int k = res.size();
  for(int i = 0; i < min(k, 10); i++)
    cout<<res[i]<<"\n";
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

  char c;
  // in.unsetf(std::ios_base::skipws);
  // in >> std::noskipws;
  // int i = 0;
  string a;
  while(!in.eof()){
      getline(in, a);
  // a>>in;
  cout << "Input: "<<a << endl;
  for(int j = 1; j <= 26; j++){
    for(int i = 0; i < a.length(); i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i] -= 1 % 26;
            if(a[i] < 'A')
                a[i] = a[i]-'A'+'Z'+1;
            // a[i] = tolower(a[i]);
            cout<<" a[i]: "<<a[i];
        }cout<<endl;
    }
    for (int i = 0; i < a.size(); i++) {
      out<<char(tolower(a[i]));
    }
    out<<endl;
    cout<<endl;
  }
}
    // caesarKeyGen(file, ofile, i);
    in.close();
    out.close();
  predicting_best_phrase(outfile);
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
