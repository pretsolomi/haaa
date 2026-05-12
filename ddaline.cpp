//practical 1 draw line using dda
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int myAbs(int n) {
    return (n > 0) ? n : -n;
}

void dda(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = (myAbs(dx) > myAbs(dy)) ? myAbs(dx) : myAbs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x0;
    float y = y0;

    char str[50]; // for displaying text
	
	  /*sprintf(str, "(%d,%d)", x0, y0);
        outtextxy(x0 + 5, y0, str);
        */
        
    for (int i = 0; i <= steps; i++) {
        int xi = (int)x;
        int yi = (int)y;

        // Plot pixel
        putpixel(xi, yi, WHITE);

        // Console output
       // cout << "(" << xi << "," << yi << ")" << endl;
  /*
        // Display on screen near the point
        sprintf(str, "(%d,%d)", xi, yi);
        outtextxy(xi + 5, yi, str);
		*/

		delay(10);
        x += xInc;
        y += yInc;
    }
}

int main() {
    int x0, y0, x1, y1;

    cout << "Enter x0 y0: ";
    cin >> x0 >> y0;

    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;

    initwindow(1000, 1000, "DDA Line with Points");

    dda(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}
