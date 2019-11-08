#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void sphere(int x_centre, int y_centre, int r);
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a Circle "<<endl;
  initgraph(&gd, &gm, NULL);
  int x,y,r;
  // cin>>x>>y>>r;
  sphere(200,200,100);
  getch();
  return 0;
}
void plot_points(int x, int y, int x_centre, int y_centre)
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
            plot_points(x, y, x_centre, y_centre);
            p += 2*x + 1;
        }
        else
        {
            y--;
            plot_points(x, y, x_centre, y_centre);
            p += 2*x + 1 - 2*y;
        }
    }

    for(float phi = -1.57; phi<=0; phi += 0.1)
    {
        for(float theta = -3.14; theta<=3.14; theta += 0.2)
        {
            x = r * cos(phi) * cos(theta);
            y = r * cos(phi) * sin(theta);
            plot_points(0, y, x_centre, y_centre);
            p = 1 - r;
            while(x++ <= y)
            {
                if (p < 0)
                {
                    p += 2*x + 1;
                    plot_points(x, y, x_centre, y_centre);
                }
                else
                {
                    y--;
                    p += 2*x + 1 - 2*y;
                    plot_points(x, y, x_centre, y_centre);
                }
            }
        }
    }
}
