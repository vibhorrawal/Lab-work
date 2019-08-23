#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    ifstream key;
    fstream fout;

    char e;

    int pf[26][2]={0};
    int c[26]={0};

    cout<<"Press E for encription or D for Decription:";
    cin>>e;

    cin.ignore();

    string key;
    cout<<"Enter file name of key:";
    cin>>key;

    key.open(key.c_str());

    string k="";
    string kw;
    while(key >> kw)
    {
        k+=kw;
    }

    key.close();

    int x=0;
    for(int i=0;i<k.length();i++)
    {
        if(c[k.at(i)-'a']==1)
        {
            continue;
        }

        pf[k.at(i)-'a'][0]=x/5;
        pf[k.at(i)-'a'][1]=x%5;

        c[k.at(i)-'a']=1;
        if(k.at(i)=='i')
            c[k.at(i)-'a'+1]=1;

        x++;
    }

    for(int i=0;i<26;i++)
    {
        if(i+'a'=='j')
            continue;

        if(c[i]==0)
        {
            pf[i][0]=x/5;
            pf[i][1]=x%5;
            x++;
        }
    }

    int arr[5][5];

    for(int i=0;i<26;i++)
    {
        if(i+'a'=='j')
            continue;

        arr[pf[i][0]][pf[i][1]]=i;
    }

    cin.ignore();

    string in;
    cout<<"Name of input file:";
    cin>>in;

    fin.open(in.c_str());

    cin.ignore();

    string out;
    cout<<"Name of output file:";
    cin>>out;

    //fout.open(out.c_str());

    remove(out.c_str());

    string s;

    string w;
    while(fin >> w)
    {
        s+=w;
    }

    fin.close();

    string o="";

    int a,b;
    int shift=1;

    if(e=='D')
        shift=-1;

    for(int i=0;i<s.length();i+=2)
    {
        a=s.at(i)-'a';

        if(i==s.length()-1)
            b='x'-'a';
        else
            b=s.at(i+1)-'a';

        if(a==b)
        {
            b='x'-'a';
            i--;
        }

        // cout<<(char)('a'+a)<<(char)('a'+b)<<endl;

        if(pf[a][0]==pf[b][0])
        {
            int row=pf[a][0];

            o+=(char)('a'+arr[row][(pf[a][1]+shift)%5]);
            o+=(char)('a'+arr[row][(pf[b][1]+shift)%5]);

            continue;
        }

        if(pf[a][1]==pf[b][1])
        {
            int col=pf[a][1];

            o+=(char)('a'+arr[(pf[a][0]+shift)%5][col]);
            o+=(char)('a'+arr[(pf[b][0]+shift)%5][col]);

            continue;
        }

        o+=(char)('a'+arr[pf[a][0]][pf[b][1]]);
        o+=(char)('a'+arr[pf[b][0]][pf[a][1]]);
    }


    fout.open(out.c_str(),ios::out | ios::trunc);

    fout<<o;

    fout.close();
}
