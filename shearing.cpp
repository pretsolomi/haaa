//9e implement code to make line shearing  in x and y
#include <graphics.h>
#include <iostream>
#include<conio.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int shx, shy;

    cout << "Enter the endpoints of the line:\n";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter shear factor along X-axis: ";
    cin >> shx;

    initwindow(800, 600, "Line Shearing");

    setcolor(WHITE);
    outtextxy(10, 10, "WHITE: Before Shearing");
    line(x1, y1, x2, y2);

    setcolor(RED);
    outtextxy(10, 30, "RED: After Shearing along X-axis");

    // Apply shear (X-axis)
    int new_x1 = x1 + shx * y1;
    int new_x2 = x2 + shx * y2;


    line(new_x1, y1, new_x2, y2);

    cout << "Enter shear factor along Y-axis: ";
    cin >> shy;

	char msg1[] = "WHITE: Before Shearing";
	char msg2[] = "RED: After Shearing along X-axis";
    setcolor(WHITE);
    outtextxy(10, 10, msg1);
    line(x1, y1, x2, y2);

    setcolor(RED);
    outtextxy(10, 30, msg2);

    // Apply shear (Y-axis)
    int new_y1 = y1 + shy * x1;
    int new_y2 = y2 + shy * x2;

    line(x1, new_y1, x2, new_y2);

    getch();
    closegraph();

    return 0;
}
