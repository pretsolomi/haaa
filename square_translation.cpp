//translation of a square with predefined vertices
#include <graphics.h>
#include <iostream>
using namespace std;

// Function to draw square using 4 points
void drawSquare(int x[], int y[]) {
    for(int i = 0; i < 4; i++) {
        line(x[i], y[i], x[(i+1)%4], y[(i+1)%4]);
    }
}

int main() {
    int tx, ty;

    // Predefined square vertices
    int x[4] = {200, 300, 300, 200};
    int y[4] = {200, 200, 300, 300};

    cout << "Enter translation values (tx ty): ";
    cin >> tx >> ty;

    // Initialize window
    initwindow(800, 600);

    // Draw original square
    setcolor(WHITE);
    outtextxy(10, 10, "Original Square");
    drawSquare(x, y);

    // Apply translation
    int x_new[4], y_new[4];
    for(int i = 0; i < 4; i++) {
        x_new[i] = x[i] + tx;
        y_new[i] = y[i] + ty;
    }

    // Draw translated square
    setcolor(YELLOW);
    outtextxy(10, 30, "Translated Square");
    drawSquare(x_new, y_new);

    getch();
    closegraph();
    return 0;
}
