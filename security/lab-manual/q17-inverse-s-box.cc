#include <bits/stdc++.h>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

bitset<8> additionOverGF(bitset<8> a,bitset<8> b)
{
    return a^b;
}

bitset<8> multiplicationOverGF(bitset<8> a_,bitset<8> b_)
{
  bitset<8> p(string("00000000"));
  bitset<8> a = a_;
  bitset<8> b = b_;
  bitset<8> irreducible(string("00011011"));
  while (a != 0 && b != 0) {
    if (b[0] & 1) /* if b is odd, then add the corresponding a to p (final product = sum of all a's corresponding to odd b's) */
        p ^= a; /* since we're in GF(2^m), addition is an XOR */

    if (a[7] & 1) /* GF modulo: if a >= 128, then it will overflow when shifted left, so reduce */
        a = (a << 1) ^ irreducible; /* XOR with the primitive polynomial x^8 + x^4 + x^3 + x + 1 (0b1_0001_1011) – you can change it but it must be irreducible */
    else
        a <<= 1; /* equivalent to a*2 */
    b >>= 1; /* equivalent to b // 2 */
  }
  return p;
}

bitset<8> multiplicativeInverseOverGF(bitset<8> a)
{
    bitset<8> remainder(1);
    bitset<8> result(0);
    for(int i=0;i<255;i++)
    {
        bitset<8> q(i);
        if(multiplicationOverGF(a,q)==remainder)
        {
            result=q;
            return result;
        }
    }
    return result;
}

void print(bitset<8> sBox[16][16]){
  for(int i=0;i<16;i++)
  {
      for(int j=0;j<16;j++)
      {
          cout<<hex<<sBox[i][j].to_ulong()<<"\t";
      }
      cout<<endl;
  }
}

int main()
{
    bitset<8> sBox[16][16];
    bitset<8> initial(0);
    for(int i=0;i<256;i++)
    {
        sBox[i/16][i%16]=initial;
        for(int j=0;j<8;j++)
        {
            if(initial[j]==0)
            {
                initial[j]=1;
                break;
            }
            else
            {
                initial[j]=0;
            }
        }
    }
    cout << "Initial inv S Box is:" << endl;
    print(sBox);

    bitset<8> inv_sBox[16][16];
    inv_sBox[0][0]=sBox[0][0];
    bitset<8> d(string("00000101"));

    for(int i=0;i<256;i++)
    {
        for(int j=0;j<8;j++)
        {
            inv_sBox[i/16][i%16][j] = sBox[i/16][i%16][(j+2)%8]^
            sBox[i/16][i%16][(j+5)%8]^
            sBox[i/16][i%16][(j+7)%8]^d[j];
        }
    }
    cout << "\n\nMultiplicative Inverse inv S Box is:" << endl;
    print(inv_sBox);

    for(int i=0;i<256;i++)
    {
        sBox[i/16][i%16]=multiplicativeInverseOverGF(inv_sBox[i/16][i%16]);
    }


    cout << "\n\nFinal inv S Box is:" << endl;
    print(sBox);

}
