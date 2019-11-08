#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void drawLine(int x1, int y1, int x2, int y2);
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a line, input x1,y1,x2,y2: "<<endl;
  initgraph(&gd, &gm, NULL);
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  // x1 = 1,x2 = 0, y1 = 3, y2 = 4;
  putpixel(x1,y1,RED);
  putpixel(x2,y2,RED);
  drawLine(x1,y1,x2,y2);
  getch();
  return 0;
}
void drawLine(int x1, int y1, int x2, int y2){
  int dx, dy, p, x, y;
  dx = abs(x2 - x1);
  dy = abs(y2 - y1);

  if(abs(dx) > abs(dy)){
    if(x1>x2){
      swap(x1,x2);
      swap(y1,y2);
    }
    x = x1;
    y = y1;
    p = 2 * dy - dx;
    while(x<x2){
      putpixel(x,y,7);
      if (p >= 0) {
        (y2>y1) ? y++ : y--;
        p += 2 * (dy - dx);
      }
      else{
        p += 2 * dy;
      }
      x++;
    }
  }
  else{
    if(y1>y2){
      swap(x1,x2);
      swap(y1,y2);
    }
    x = x1;
    y = y1;
    p = 2 * dx - dy;

    while(y<y2){
      putpixel(x,y,7);
      if (p >= 0) {
        (x2>x1) ? x++ : x--;
        p += 2 * (dx - dy);
      }
      else{
        p += 2 * dx;
      }
      y++;
    }
  }
}
