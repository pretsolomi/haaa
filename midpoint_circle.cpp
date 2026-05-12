//4 midpoint circle algorithm
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void drawCirclePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y)
    {
        drawCirclePoints(xc, yc, x, y);

        if (p < 0)
            p = p + 2 * x + 3;
        else
        {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main()
{
    int xc, yc, r;

    cout << "Enter origin (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    initwindow(1000, 1000, "Midpoint Circle");
	   		line(0, yc, getmaxx(), yc);
    		line(xc, 0, xc, getmaxy());
    	midpointCircle(xc, yc, r);

    char text[50];
    sprintf(text, "Origin (%d,%d)", xc, yc);
    outtextxy(xc + 10, yc + 10, text);

    getch();
    closegraph();
    return 0;
}
