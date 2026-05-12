// Implement line shearing in X and Y
#include <graphics.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int shx, shy;

    cout << "Enter line coordinates: ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter X-shear factor: ";
    cin >> shx;

    cout << "Enter Y-shear factor: ";
    cin >> shy;

    initwindow(1000, 1000, "Line Shearing");

    // Original line
    setcolor(WHITE);
    outtextxy(10, 10, "Original Line");
    line(x1, y1, x2, y2);

    // X-axis shearing
    int new_x1 = x1 + shx * y1;
    int new_x2 = x2 + shx * y2;

    setcolor(RED);
    outtextxy(10, 30, "X-Sheared Line");
    line(new_x1, y1, new_x2, y2);

    // Y-axis shearing
    int new_y1 = y1 + shy * x1;
    int new_y2 = y2 + shy * x2;

    setcolor(GREEN);
    outtextxy(10, 50, "Y-Sheared Line");
    line(x1, new_y1, x2, new_y2);

    getch();
    closegraph();

    return 0;
}
