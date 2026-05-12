//liam barsky algorithm
#include <graphics.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    int xmin, ymin, xmax, ymax;
    int dx, dy;
    float t1 = 0.0, t2 = 1.0, t;
    int p[4], q[4];

    // Input window
    cout << "Enter xmin ymin: ";
    cin >> xmin >> ymin;

    cout << "Enter xmax ymax: ";
    cin >> xmax >> ymax;

    // Input line
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Initialize window
    initwindow(800, 600, "Liang-Barsky Line Clipping");
    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    dx = x2 - x1;
    dy = y2 - y1;

    // Define p and q
    p[0] = -dx; q[0] = x1 - xmin;
    p[1] = dx;  q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] = dy;  q[3] = ymax - y1;

    for (int i = 0; i < 4; i++) {

        if (p[i] == 0 && q[i] < 0) {
            cout << "Line is completely outside\n";
            getch();
            closegraph();
            return 0;
        }

        if (p[i] != 0) {
            t = (float)q[i] / p[i];

            if (p[i] < 0) {
                if (t > t1) t1 = t;
            } else {
                if (t < t2) t2 = t;
            }
        }
    }

    if (t1 > t2) {
        cout << "Line lies outside the window\n";
    } else {
        int xx1 = x1 + t1 * dx;
        int yy1 = y1 + t1 * dy;
        int xx2 = x1 + t2 * dx;
        int yy2 = y1 + t2 * dy;

        setcolor(YELLOW);
        line(xx1, yy1, xx2, yy2);
    }

    getch();
    closegraph();
    return 0;
}
