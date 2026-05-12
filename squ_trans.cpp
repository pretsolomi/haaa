// translation of square using rectangle()
#include <graphics.h>
#include <iostream>
using namespace std;

int main() {

    int tx, ty;

    cout << "Enter translation values: ";
    cin >> tx >> ty;

    initwindow(800,600);

    // Original square
    setcolor(WHITE);
    outtextxy(10,10,"WHITE = Original");
    rectangle(200,200,300,300);

    delay(1000);

    // Translated square
    setcolor(YELLOW);
    outtextxy(10,30,"YELLOW = New");

    rectangle(
        200 + tx,
        200 + ty,
        300 + tx,
        300 + ty
    );

    getch();
    closegraph();
}
