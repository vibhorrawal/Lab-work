#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void sphere(int x_centre, int y_centre, int r);
void func(){
  int t,T = 5;
  float x = 50, y = 50; // r = 40
  for (t = 0; t < T; t++) {
    x+= 20*t;
    y += 10*t*t;
    sphere(x,y, 10);
  }
  for (t=1; t < T; t++) {
    x+= 20*t;
    y+= -50 + 10*t*t;
    sphere(x,y, 10);

  }
}
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a Circle "<<endl;
  initgraph(&gd, &gm, NULL);
  int x,y,r;
  // cin>>x>>y>>r;
  // sphere(200,200,100);
  func();
  getch();
  return 0;
}
void draw_points(int x, int y, int x_centre, int y_centre)
{
    putpixel(x + x_centre ,-y + y_centre,WHITE);
    putpixel(y + x_centre ,x + y_centre,WHITE);
    putpixel(-y + x_centre ,x + y_centre,WHITE);

    putpixel(x + x_centre,y + y_centre,WHITE);
    putpixel(-x + x_centre,y + y_centre,WHITE);
    putpixel(x + x_centre,-y + y_centre,WHITE);
    putpixel(-x + x_centre,-y + y_centre,WHITE);

    putpixel(y + x_centre, x + y_centre,WHITE);
    putpixel(-y + x_centre, x + y_centre,WHITE);
    putpixel(y + x_centre, -x + y_centre,WHITE);
    putpixel(-y + x_centre, -x + y_centre,WHITE);
}

void sphere(int x_centre, int y_centre, int r)
{
    //First Point
    int x = 0, y = r;
    putpixel(x + x_centre, y + y_centre,WHITE);
    putpixel(y + y_centre, x + x_centre,WHITE);
    putpixel(x + x_centre, -y + y_centre,WHITE);
    putpixel(-y + y_centre, x + x_centre,WHITE);
    int p = 1 - r;
    while(x++ <= y)
    {
        if(p < 0)
        {
            draw_points(x, y, x_centre, y_centre);
            p += 2*x + 1;
        }
        else
        {
            y--;
            draw_points(x, y, x_centre, y_centre);
            p += 2*x + 1 - 2*y;
        }
    }

    for(float phi = -1.57; phi<=0; phi += 0.1)
    {
        for(float theta = -3.14; theta<=3.14; theta += 0.2)
        {
            x = r * cos(phi) * cos(theta);
            y = r * cos(phi) * sin(theta);
            draw_points(0, y, x_centre, y_centre);
            p = 1 - r;
            while(x++ <= y)
            {
                if (p < 0)
                {
                    p += 2*x + 1;
                    draw_points(x, y, x_centre, y_centre);
                }
                else
                {
                    y--;
                    p += 2*x + 1 - 2*y;
                    draw_points(x, y, x_centre, y_centre);
                }
            }
        }
    }
}
