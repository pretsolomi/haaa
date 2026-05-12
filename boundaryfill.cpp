//5 boundary fill
#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

void boundaryFill(int x, int y, int fill_color, int boundary_color) {

    if (x < 0 || y < 0 || x > getmaxx() || y > getmaxy())
        return;

    int current = getpixel(x, y);


    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);

        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {

    initwindow(800, 600, "Boundary Fill Algorithm");

    setcolor(WHITE);

    int poly[10] = {200,150, 400,150, 400,300, 200,300, 200,150};

    drawpoly(5, poly);

    boundaryFill(250, 200, RED, WHITE);

    getch();
    closegraph();
    return 0;
}
