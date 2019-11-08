#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void cuboid(int x1, int y1, int z1, int x2, int y2, int z2);
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a line, input x1,y1,x2,y2: "<<endl;
  initgraph(&gd, &gm, NULL);
  int x1,y1,x2,y2,x3,y3,x4,y4;
  // cin>>x1>>y1>>x2>>y2;
  x1=100,y1=100,x2=250,y2=200;
  cuboid(x1,y1,0,x2,y2,10);
  getch();
  return 0;
}
void floodfill(int x, int y){
  int color = getpixel(x,y);
  if(color)
    return;
  putpixel(x,y,WHITE);

  floodfill(x+1,y);
  floodfill(x,y+1);
  floodfill(x-1,y);
  floodfill(x,y-1);
}
void rectangle(int x1, int y1, int x2, int y2){
  line(x1,y1,x2,y1);
  line(x2,y1,x2,y2);
  line(x1,y1,x1,y2);
  line(x1,y2,x2,y2);
  floodfill(x1+1,y1+1);
}
void cuboid(int x1, int y1, int z1, int x2, int y2, int z2){
  int d = z2 - z1;
  while (d--) {
    rectangle(x1+d,y1+d,x2+d,y2+d);

  }
}
