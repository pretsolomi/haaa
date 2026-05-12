//floodfill algorithm
#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// 4-connected Flood Fill
void floodFill(int x, int y, int old_color, int fill_color)
{
    // Boundary check
    if (x < 0 || y < 0 || x > getmaxx() || y > getmaxy())
        return;

    int current = getpixel(x, y);

    // Fill only if current pixel matches old color
    if (current == old_color)
    {
        putpixel(x, y, fill_color);

        floodFill(x + 1, y, old_color, fill_color);
        floodFill(x - 1, y, old_color, fill_color);
        floodFill(x, y + 1, old_color, fill_color);
        floodFill(x, y - 1, old_color, fill_color);
    }
}

int main()
{


    // Draw polygon (rectangle example)
    initwindow(1000, 1000, "FLOOD FILL ALGORITHM");
    rectangle(100, 100, 300, 300);

    // Start flood fill inside the polygon
      
    int seed_x = 150, seed_y = 150;
    int old_color = getpixel(seed_x, seed_y);

    floodFill(seed_x, seed_y, old_color, GREEN);

    getch();
    closegraph();
    return 0;
}
