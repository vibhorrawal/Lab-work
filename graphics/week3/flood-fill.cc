// flood fill FRD
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void fill_F(int x, int y);
void fill_R(int x, int y);
void fill_D(int x, int y);
void floodfill(int x, int y);
void drawLine(int x1, int y1, int x2, int y2);
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Creating..."<<endl;
  initgraph(&gd, &gm, NULL);
  fill_F(0,0);
  fill_R(150,0);
  fill_D(300,0);
  getch();
  closegraph();
  return 0;
}

void fill_F(int x, int y){
  line(x,y,x+100,y);
  line(x,y,x,y+200);
  line(x,200+y,x+40,200+y);
  line(x+100,y,x+100,y+40);
  line(x+80,y+80,x+80,y+120);
  line(x+40,y+40,x+100,y+40);
  line(x+40,y+80,x+80,y+80);
  line(x+40,y+120,x+80,y+120);
  line(x+40,y+40,x+40,y+80);
  line(x+40,y+120,x+40, y+200);

  floodfill(x+1,y+1);
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

void fill_R(int x, int y){
  line(x,y,x,y+200);
  line(x+30,y,x+30,y+200);
  line(x,y,x+30,y);
  line(x,y+200,x+30,y+200);
  arc(x+30,y+50,-90,90,50);
  arc(x+30,y+50,-90,90,30);
  line(x+30,y+100,x+90,y+200);
  line(x+30,y+130,x+70,y+200);
  line(x+70,y+200,x+90,y+200);

  floodfill(x+1,y+1);
  floodfill(x+32,y+4);
  floodfill(x+32,y+110);
}

void fill_D(int x, int y){
  line(x,y,x,y+200);
  line(x+40,y,x+40,y+200);
  line(x,y,x+40,y);
  line(x,y+200,x+40,y+200);
  arc(x+40,y+100,-90,90,70);
  arc(x+40,y+100,-90,90,100);

  floodfill(x+1,y+1);
  floodfill(x+42,y+1);
}
