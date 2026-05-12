//triangle
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>   // for abs()

// DDA Line Drawing Function
void dda(int x0, int y0, int x1, int y1) {

    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Edge case: single point
    if (steps == 0) {
        putpixel(x0, y0, WHITE);
        return;
    }

    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel((int)x, (int)y, WHITE);
        x += xinc;
        y += yinc;
    }
}

int main() {


    initwindow(800, 600, "Triangle using DDA");

    // Predefined triangle vertices
    int x1 = 10,  y1 = 10;
    int x2 = 10,  y2 = 200;
    int x3 = 100, y3 = 200;

    // Draw triangle
    dda(x1, y1, x2, y2);
    dda(x2, y2, x3, y3);
    dda(x3, y3, x1, y1);

    getch();
    closegraph();

    return 0;
}
