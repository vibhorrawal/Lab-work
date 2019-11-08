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
  // getch();
  return 0;
}
void drawLine(int x1, int y1, int x2, int y2){
  if(x1>x2){
    swap(x1,x2);
    swap(y1,y2);
  }
  int dx = x2 - x1;
  int dy = y2 - y1;

  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  // calculating increment in x and y
  float xInc = dx / (float) steps;
  float yInc = dy / (float) steps;

  float x = x1, y = y1;

  for (int i = 0; i < steps; i++) {
    putpixel(x,y,7);
    x += xInc;
    y += yInc;
  }
}
