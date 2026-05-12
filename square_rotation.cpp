//rotation of a square with predefined vertices
#include <graphics.h>
#include <iostream>
#include <math.h>

using namespace std;

void rotateSquare(int cx, int cy, int w, int h, int angle)
{
    double theta = angle * M_PI / 180.0;

    int dx = w / 2;
    int dy = h / 2;

    // Original points (relative to center)
    int x[4] = {-dx, dx, dx, -dx};
    int y[4] = {-dy, -dy, dy, dy};

    int rx[4], ry[4];

    // Rotate each point
    for(int i = 0; i < 4; i++)
    {
        rx[i] = cx + (x[i] * cos(theta) - y[i] * sin(theta));
        ry[i] = cy + (x[i] * sin(theta) + y[i] * cos(theta));
    }

    // Draw square
    for(int i = 0; i < 4; i++)
    {
        line(rx[i], ry[i], rx[(i+1)%4], ry[(i+1)%4]);
    }
}

int main()
{
    int angle;
    int cx = 250, cy = 250;
    int w = 100, h = 100;

    cout << "Enter angle: ";
    cin >> angle;

    initwindow(1000, 1000,"SQUARE ROTATION");

    // Original square
    setcolor(WHITE);
    outtextxy(10, 10, "WHITE = Original");
    rotateSquare(cx, cy, w, h, 0);

    // Rotated square
    setcolor(YELLOW);
    outtextxy(10, 30, "YELLOW = Rotated");
    rotateSquare(cx, cy, w, h, angle);

    getch();
    closegraph();
}
