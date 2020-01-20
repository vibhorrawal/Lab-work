#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

// code from stack overflow
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main(int argc, char const *argv[]){
  ifstream code;
  string fname;

  cout<<"Analysing " << argv[1] << " ..."<<endl;
  if(argv[1] == ""){
    cout<<"Enter file name: ";
    cin>>fname;
    code.open(fname);
  }
  else code.open(argv[1]);

  string soup;
  // delimit with these
  string symbols[] = { "+", "-", "(", "{", "}", ")", "*", "/", "<", ">", "%", ";", "=", "=="};
  int tokenCounter = 0;
  while(!code.eof()){
      getline(code,soup);
      cout<<soup<<endl;

      // delimit with #
      for (int i = 0; i < sizeof(symbols) / sizeof(symbols[0]); i++) {
        // cout<<symbols[i]<<endl;
        replaceAll(soup, symbols[i], "#");
      }

      // cout<<soup<<endl;

      // now after delimiting I need to remove adjacent #s
      // replaceAll(soup, "##", "#");
      // cout<<soup<<endl;

      while(true){
        // if(find(soup.begin(), soup.end(), "##") == soup.end()) break;
        size_t found = soup.find("##");
        if(found == string::npos) break;

        replaceAll(soup, "##", "#");
      }
      while(true){
        // if(find(soup.begin(), soup.end(), "##") == soup.end()) break;
        size_t found = soup.find("  ");
        if(found == string::npos) break;

        replaceAll(soup, "  ", " ");
      }
      // cout<< soup<<endl;
      tokenCounter += count(soup.begin(), soup.end(), '#') ;//+ count(soup.begin(), soup.end(), ' ');
  }
  cout<<"\n\n No of tokens found: "<<tokenCounter*2+1<<endl;
  return 0;
}
