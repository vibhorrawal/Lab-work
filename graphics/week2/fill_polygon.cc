// polygon given is M shaped
#include<bits/stdc++.h>
#include<graphics.h>
#define mp make_pair
using namespace std;
void drawLine(int x1, int y1, int x2, int y2);
void scanLineAlgo();
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  scanLineAlgo();
  getch();
  return 0;
}
void scanLineAlgo() {
  // points are taken cw
  auto p1 = mp(2,300), p2 = mp(200,300), p3 = mp(200,2), p4 = mp(101,2), p5 = mp(2,2);
  int ymax = 300, ymin = 2; // next time make use of loop
  int y = ymin;
  float x1,x2;

  // std::vector< pair<int> , pair<int> > v;
  while(y <= ymax){
    x1 = 2 + (y-2) * 99.0 / 298.0;
    x2 = 200 - (y-2) * 99.0 / 298.0;
    // v.push_back(mp(2,x1),)
    drawLine(2,y,x1,y); drawLine(x2,y,200,y);
    y++;
  }
}
void drawLine(int x1, int y1, int x2, int y2){
  int x = x1, y = y1;
  int delX = abs(x2 - x1), delY = abs(y2 - y1);
  int p = 2 * delY - delX;
  int count = max(abs(x2 - x1), abs(y2 - y1));

  while(count--){
    if(p<0){
       putpixel(++x, y, WHITE);
       p = 2 * delY + p;
     }
    else {
      putpixel(++x, ++y, WHITE);
      p = 2 * delY - 2 * delX + p;
    }

  }
}
