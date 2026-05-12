// rotation of a square using drawpoly()

#include <graphics.h>
#include <iostream>
#include <math.h>

using namespace std;

void rotateSquare(int cx, int cy, int w, int h, int angle)
{
    double theta = angle * M_PI / 180.0;

    int dx = w / 2;
    int dy = h / 2;

    // Original points relative to center
    int x[4] = {-dx, dx, dx, -dx};
    int y[4] = {-dy, -dy, dy, dy};

    int points[10];

    // Rotate points
    for(int i = 0; i < 4; i++)
    {
        int rx = cx + (x[i] * cos(theta) - y[i] * sin(theta));
        int ry = cy + (x[i] * sin(theta) + y[i] * cos(theta));

        points[2*i] = rx;
        points[2*i + 1] = ry;
    }

    // Repeat first point to close polygon
    points[8] = points[0];
    points[9] = points[1];

    // Draw square
    drawpoly(5, points);
}

int main()
{
    int angle;
    int cx = 250, cy = 250;
    int w = 100, h = 100;

    cout << "Enter angle: ";
    cin >> angle;

    initwindow(1000, 1000, "SQUARE ROTATION");

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
