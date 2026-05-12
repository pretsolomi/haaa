// translation of square using drawpoly()
#include <graphics.h>
#include <iostream>
using namespace std;

int main() {

    int tx, ty;

    cout << "Enter translation values: ";
    cin >> tx >> ty;

    // Original square points
    int square[] = {
        200,200,
        300,200,
        300,300,
        200,300,
        200,200
    };

    initwindow(800,600);

    // Draw original square
    setcolor(WHITE);
    drawpoly(5, square);

    // Translated square
    int newSquare[10];

    for(int i=0; i<10; i+=2) {
        newSquare[i] = square[i] + tx;       // x
        newSquare[i+1] = square[i+1] + ty;  // y
    }

    setcolor(YELLOW);
    drawpoly(5, newSquare);

    getch();
    closegraph();
}
