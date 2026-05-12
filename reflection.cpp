//9c implement code in c++ to make line reflection in x and y
#include <graphics.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    int x1, y1, x2, y2;

    // Create window (width, height, title)
    initwindow(800, 600, "Line Reflection");

    cout << "Enter x coordinate of line 1: ";
    cin >> x1;

    cout << "Enter y coordinate of line 1: ";
    cin >> y1;

    cout << "Enter x coordinate of line 2: ";
    cin >> x2;

    cout << "Enter y coordinate of line 2: ";
    cin >> y2;

    cleardevice();

    // Draw axes (center of screen)
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2);

    // Original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Reflection in X-axis
    setcolor(YELLOW);
    line(x1, getmaxy() - y1, x2, getmaxy() - y2);

    // Reflection in Y-axis
    setcolor(WHITE);
    line(getmaxx() - x1, y1, getmaxx() - x2, y2);

    getch();
    closegraph();

    return 0;
}
