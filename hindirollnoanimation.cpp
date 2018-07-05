#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

struct vertex
{
    float x;
    float y;
    float z;
};

int nseg = 9;
vertex signlist[50][10] = {
                            {{100, 290, 0}, {110, 280, 0}, {-50, 50, 0}, {50, 0, 0}},
                            {{110, 280, 0}, {100, 320, 0}, {30, 50, 0}, {100, 50, 0}},
                            {{140, 250, 0}, {170, 250, 0}, {0, 80, 0}, {0, -80, 0}},
                            {{170, 250, 0}, {155, 290, 0}, {0, 80, 0}, {-40, 0, 0}},
                            {{155, 290, 0}, {180, 290, 0}, {-30, -30, 0}, {50, 50, 0}},
                            {{200, 230, 0}, {220, 230, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{220, 230, 0}, {250, 230, 0}, {-20, 70, 0}, {40, -40, 0}},
                            {{270, 190, 0}, {290, 190, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{290, 190, 0}, {320, 190, 0}, {-20, 70, 0}, {40, -40, 0}},
                          };

vertex poly[20] = {{400,150,0}, {400,350,0}, {100,350,0}};
int n = 3;

void draw_poly(vertex vlist[], int n)
{
    for (int i=0; i<n; i++)
        line(vlist[i].x, vlist[i].y, vlist[(i+1)%n].x, vlist[(i+1)%n].y);
}

void hermite(vertex p0, vertex p3, vertex r0, vertex r3, int xc, int yc)
{
    float x, y, z;
    for (float t=0; t<=1; t=t+0.001)
    {
        float e = 2*t*t*t - 3*t*t + 1;
        float f = -2*t*t*t + 3*t*t;
        float g = t*t*t - 2*t*t + t;
        float h = t*t*t - t*t;

        x = e*p0.x + f*p3.x + g*r0.x + h*r3.x;
        y = e*p0.y + f*p3.y + g*r0.y + h*r3.y;

        putpixel(x+xc, y+yc, WHITE);
    }
}


void signanimater(vertex signlist[][10], int nseg)
{
	for (int i=0; i<nseg; i++)
	{
		hermite(signlist[i][0], signlist[i][1], signlist[i][2], signlist[i][3], 0, 0);
	}
	draw_poly(poly,n);

	int xd;
	int yd;
	int type = 0;

while(true)
{
	if (type==0)
    {
    vertex temp[50][20];
    xd=10;
    yd=-10;
    while(true)
    {

		cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<2; k++)
                {
                    float x = signlist[i][k].x;
                    float y = signlist[i][k].y;
                    temp[i][k].x += xd;
                    temp[i][k].y +=yd;
                }
			}
				for (int i=0; i<nseg; i++)
	            {
		            hermite(signlist[i][0], signlist[i][1], signlist[i][2], signlist[i][3], xd, yd);
                }
	            draw_poly(poly,n);
				xd+=10;
				yd+=-10;
				if (xd >130)
                {
                    type=1;
                    break;
                }
				delay(50);
    }
    }

    if (type==1)
    {
        vertex temp[50][10] = {
                            {{420, 130, 0}, {430, 120, 0}, {-50, 50, 0}, {50, 0, 0}},
                            {{430, 120, 0}, {420, 160, 0}, {30, 50, 0}, {100, 50, 0}},
                            {{410, 170, 0}, {440, 170, 0}, {0, 80, 0}, {0, -80, 0}},
                            {{440, 170, 0}, {430, 210, 0}, {0, 80, 0}, {-40, 0, 0}},
                            {{430, 210, 0}, {460, 210, 0}, {-30, -30, 0}, {50, 50, 0}},
                            {{410, 230, 0}, {430, 230, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{430, 230, 0}, {460, 230, 0}, {-20, 70, 0}, {40, -40, 0}},
                            {{410, 270, 0}, {430, 270, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{430, 270, 0}, {460, 270, 0}, {-20, 70, 0}, {40, -40, 0}},
                          };
    xd=0;
    yd=0;
    while(true)
    {

		cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<2; k++)
                {
                    temp[i][k].x += xd;
                    temp[i][k].y +=yd;
                }
			}
				for (int i=0; i<nseg; i++)
	            {
		            hermite(temp[i][0], temp[i][1], temp[i][2], temp[i][3], 0, 0);
                }
	            draw_poly(poly,n);
				xd+=0;
				yd+=10;
                if (yd >40)
                {
                    type=2;
                    break;
                }
				delay(50);
    }
    }

    if (type==2)
    {
        vertex temp[50][10] = {
                            {{420, 370, 0}, {430, 360, 0}, {-50, 50, 0}, {50, 0, 0}},
                            {{430, 360, 0}, {420, 410, 0}, {30, 50, 0}, {100, 50, 0}},
                            {{350, 370, 0}, {380, 370, 0}, {0, 80, 0}, {0, -80, 0}},
                            {{380, 370, 0}, {370, 410, 0}, {0, 80, 0}, {-40, 0, 0}},
                            {{370, 410, 0}, {400, 410, 0}, {-30, -30, 0}, {50, 50, 0}},
                            {{280, 380, 0}, {300, 380, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{300, 380, 0}, {330, 380, 0}, {-20, 70, 0}, {40, -40, 0}},
                            {{230, 380, 0}, {250, 380, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{250, 380, 0}, {270, 380, 0}, {-20, 70, 0}, {40, -40, 0}},
                          };
    xd=0;
    yd=0;
    while(true)
    {

		cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<2; k++)
                {
                    temp[i][k].x += xd;
                    temp[i][k].y +=yd;
                }
			}
				for (int i=0; i<nseg; i++)
	            {
		            hermite(temp[i][0], temp[i][1], temp[i][2], temp[i][3], 0, 0);
                }
	            draw_poly(poly,n);
				xd+=-10;
				yd+=0;

                if (xd < -75)
                {
                    type=0;
                    break;
                }
				delay(50);
    }
    }
}
}

void signanimatel(vertex signlist[][10], int nseg)
{
	int xd;
	int yd;
	int type = 0;

while(true)
{
	if (type==0)
    {
    vertex temp[50][10] = {
                            {{200, 190, 0}, {210, 180, 0}, {-50, 50, 0}, {50, 0, 0}},
                            {{210, 180, 0}, {200, 220, 0}, {30, 50, 0}, {100, 50, 0}},
                            {{240, 150, 0}, {270, 150, 0}, {0, 80, 0}, {0, -80, 0}},
                            {{270, 150, 0}, {255, 190, 0}, {0, 80, 0}, {-40, 0, 0}},
                            {{255, 190, 0}, {280, 190, 0}, {-30, -30, 0}, {50, 50, 0}},
                            {{300, 130, 0}, {320, 130, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{320, 130, 0}, {350, 130, 0}, {-20, 70, 0}, {40, -40, 0}},
                            {{370, 90, 0}, {390, 90, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{390, 90, 0}, {420, 90, 0}, {-20, 70, 0}, {40, -40, 0}},
                          };
    xd=-10;
    yd=10;
    while(true)
    {

		cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<2; k++)
                {
                    temp[i][k].x += xd;
                    temp[i][k].y +=yd;
                }
			}
				for (int i=0; i<nseg; i++)
	            {
		            hermite(temp[i][0], temp[i][1], temp[i][2], temp[i][3], xd, yd);
                }
	            draw_poly(poly,n);
				xd+=-10;
				yd+=10;
				if (xd < -50)
                {
                    type=1;
                    break;
                }
				delay(50);
    }
    }

    if (type==2)
    {
        vertex temp[50][10] = {
                            {{420, 230, 0}, {430, 220, 0}, {-50, 50, 0}, {50, 0, 0}},
                            {{430, 220, 0}, {420, 260, 0}, {30, 50, 0}, {100, 50, 0}},
                            {{410, 270, 0}, {440, 270, 0}, {0, 80, 0}, {0, -80, 0}},
                            {{440, 270, 0}, {430, 310, 0}, {0, 80, 0}, {-40, 0, 0}},
                            {{430, 310, 0}, {460, 310, 0}, {-30, -30, 0}, {50, 50, 0}},
                            {{410, 330, 0}, {430, 330, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{430, 330, 0}, {460, 330, 0}, {-20, 70, 0}, {40, -40, 0}},
                            {{410, 370, 0}, {430, 370, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{430, 370, 0}, {460, 370, 0}, {-20, 70, 0}, {40, -40, 0}},
                          };
    xd=0;
    yd=0;
    while(true)
    {

		cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<2; k++)
                {
                    temp[i][k].x += xd;
                    temp[i][k].y +=yd;
                }
			}
				for (int i=0; i<nseg; i++)
	            {
		            hermite(temp[i][0], temp[i][1], temp[i][2], temp[i][3], 0, 0);
                }
	            draw_poly(poly,n);
				xd+=0;
				yd+=-10;
                if (yd < -60)
                {
                    type=0;
                    break;
                }
				delay(50);
    }
    }

    if (type==1)
    {
        vertex temp[50][10] = {
                            {{220, 370, 0}, {230, 360, 0}, {-50, 50, 0}, {50, 0, 0}},
                            {{230, 360, 0}, {220, 410, 0}, {30, 50, 0}, {100, 50, 0}},
                            {{150, 370, 0}, {180, 370, 0}, {0, 80, 0}, {0, -80, 0}},
                            {{180, 370, 0}, {170, 410, 0}, {0, 80, 0}, {-40, 0, 0}},
                            {{170, 410, 0}, {200, 410, 0}, {-30, -30, 0}, {50, 50, 0}},
                            {{80, 380, 0}, {100, 380, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{100, 380, 0}, {130, 380, 0}, {-20, 70, 0}, {40, -40, 0}},
                            {{30, 380, 0}, {50, 380, 0}, {10, 0, 0}, {10, 0, 0}},
                            {{50, 380, 0}, {70, 380, 0}, {-20, 70, 0}, {40, -40, 0}},
                          };
    xd=0;
    yd=0;
    while(true)
    {

		cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<2; k++)
                {
                    temp[i][k].x += xd;
                    temp[i][k].y +=yd;
                }
			}
				for (int i=0; i<nseg; i++)
	            {
		            hermite(temp[i][0], temp[i][1], temp[i][2], temp[i][3], 0, 0);
                }
	            draw_poly(poly,n);
				xd+=10;
				yd+=0;

                if (xd > 60)
                {
                    type=2;
                    break;
                }
				delay(50);
    }
    }
}
}

int main()
{
    int gd=DETECT, gm=0;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    char ch;
    cout<<"Press r to rotate right and l to rotate left"<<endl;
    cin>>ch;
    if (ch == 'r')
    signanimater(signlist, nseg);
    if (ch == 'l')
    signanimatel(signlist, nseg);

    getch();
    closegraph();
    return 0;
}

