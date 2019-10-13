#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

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

  // floodfill(x+1,y+1);
}
void fill_F_scaling(int x, int y, int z){

  int sc[4][4] = {{2,0,0,0},{0,1,0,0},{0,0,2,0},{0,0,0,1}}; //scaling matrix
  int pt[4] = {x,y,z,0}; // on z axis
  int ans[4] = {0};
  int sum;

  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  int x_ = ans[0], y_ = ans[1];

  // line(x,y,x+100,y);
  pt[0] = x+100;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  // cout << "x_: "<<x_<<" ans[0]: "<<ans[0]<< endl;
  int x100 = ans[0];
  line(x_,y_,x100,y_);

  // line(x,y,x,y+200);
  pt[1] = y + 200;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  // cout << "x_: "<<x_<<" ans[1]: "<<ans[1]<< endl;
  int y200 = ans[1];
  line(x_,y_,x_,y200);

  // line(x,200+y,x+40,200+y);
  pt[0] = x + 40;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  int x40 = ans[0];
  line(x_,y200,x40,y200);

  // line(x+100,y,x+100,y+40);
  pt[1] = y + 40;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  int y40 = ans[1];
  line(x100,y_,x100,y40);

  // line(x+80,y+80,x+80,y+120);
  pt[0] = x+80, pt[1] = y+80;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  int x80 = ans[0], y80 = ans[1];

  pt[1] = y + 120;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  int y120 = ans[1];
  line(x80,y80,x80,y120);

  // line(x+40,y+40,x+100,y+40);
  line(x40,y40,x100,y40);

  // line(x+40,y+80,x+80,y+80);
  line(x40,y80,x80,y80);

  // line(x+40,y+120,x+80,y+120);
  line(x40,y120,x80,y120);

  // line(x+40,y+40,x+40,y+80);
  line(x40,y40,x40,y80);

  // line(x+40,y+120,x+40, y+200);
  line(x40,y120,x40,y200);

  // floodfill(x+1,y+1);
}
void fill_F_rotation_z(int x, int y, int z, float th){
  float sc[4][4] = {{cos(th),-sin(th),0,0},{sin(th),cos(th),0,0},{0,0,1,0},{0,0,0,1}}; //rotation matrix
  float pt[4] = {x,y,z,0};
  float ans[4] = {0};
  float sum;
  cout<<"sin(th): "<<sin(th)<<endl;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  float x_ = ans[0], y_ = ans[1];

  // line(x,y,x+100,y);
  pt[0] = x+100, pt[1] = y;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  cout << "x_: "<<x_<<" ans[0]: "<<ans[0]<< endl;
  float x100 = ans[0];
  float yfor100 = ans[1];
  line(x_,y_,ans[0],ans[1]);

  // line(x,y,x,y+200);
  pt[0] = x, pt[1] = y + 200;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  // cout << "x_: "<<x_<<" ans[1]: "<<ans[1]<< endl;
  float y200 = ans[1];
  line(x_,y_,ans[0],ans[1]);

  // line(x,200+y,x+40,200+y);
  pt[0] = x + 40,pt[1] = y+200;
  x_ = ans[0],y_ = ans[1];
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  float x40 = ans[0];
  line(x_,y_,ans[0],ans[1]);

  // line(x+100,y,x+100,y+40);
  pt[0] = x + 100,pt[1] = y + 40;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  float y40 = ans[1];
  float xfor40 = ans[0];
  line(x100,yfor100,ans[0],ans[1]);

  // line(x+80,y+80,x+80,y+120);
  pt[0] = x+80, pt[1] = y+80;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  float x80 = ans[0], yfor80 = ans[1];

  pt[1] = y + 120;
  for (int i = 0; i < 4; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += sc[i][j] * pt[j];
    }
    ans[i] = sum;
  }
  float y120 = ans[1];
  line(x80,yfor80,ans[0],ans[1]);

  // line(x+40,y+40,x+100,y+40);
  // line(xfor40,y40,x100,y40);

  // line(x+40,y+80,x+80,y+80);
  // line(x40,y80,x80,y80);

  // line(x+40,y+120,x+80,y+120);
  // line(x40,y120,x80,y120);

  // line(x+40,y+40,x+40,y+80);
  // line(x40,y40,x40,y80);

  // line(x+40,y+120,x+40, y+200);
  // line(x40,y120,x40,y200);
}
int main(){
  int gd = DETECT, gm;
  cout<<"Creating..."<<endl;
  initgraph(&gd, &gm, NULL);
  fill_F(0,0);
  fill_F_rotation_z(300,100,0,0.5);
  getch();
  closegraph();
}
