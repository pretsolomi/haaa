//bresham line drawing 
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;

// LOW SLOPE
void plotLineLow(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int y = y0;

    for (int x = x0; x <= x1; x++) {
        putpixel(x, y, WHITE);

        if (D > 0) {
            y = y + yi;
            D = D + 2 * (dy - dx);
        } else {
            D = D + 2 * dy;
        }
    }
}

// HIGH SLOPE
void plotLineHigh(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;
    int x = x0;

    for (int y = y0; y <= y1; y++) {
        putpixel(x, y, WHITE);

        if (D > 0) {
            x = x + xi;
            D = D + 2 * (dx - dy);
        } else {
            D = D + 2 * dx;
        }
    }
}

// GENERAL FUNCTION
void plotLine(int x0, int y0, int x1, int y1) {
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1)
            plotLineLow(x1, y1, x0, y0);
        else
            plotLineLow(x0, y0, x1, y1);
    } else {
        if (y0 > y1)
            plotLineHigh(x1, y1, x0, y0);
        else
            plotLineHigh(x0, y0, x1, y1);
    }
}

int main() {

    int x0, y0, x1, y1;
    char str[20];

    cout << "Enter starting coordinate (x0 y0): ";
    cin >> x0 >> y0;

    cout << "Enter ending coordinate (x1 y1): ";
    cin >> x1 >> y1;

    initwindow(1000, 1000, "Breshemham line drawing");
    //sprintf(str, "(%d,%d)", x0, y0);
	//outtextxy(x0 + 5, y0, str);
    plotLine(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}
