// Implement Scan Line Fill Algorithm with delay

#include <graphics.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
  
    int poly[] = {
        200,150,
        300,100,
        400,200,
        350,300,
        250,300,
        200,150
    };

    int n = 5;

    drawpoly(n + 1, poly);

    int ymin = poly[1];
    int ymax = poly[1];

    for(int i = 1; i < n * 2; i += 2)
    {
        if(poly[i] < ymin)
            ymin = poly[i];

        if(poly[i] > ymax)
            ymax = poly[i];
    }

    for(int y = ymin; y <= ymax; y++)
    {
        int interx[20];
        int count = 0;

        // Find intersections
        for(int i = 0; i < n; i++)
        {
            int x1 = poly[2 * i];
            int y1 = poly[2 * i + 1];

            int x2 = poly[2 * ((i + 1) % n)];
            int y2 = poly[2 * ((i + 1) % n) + 1];

            if(y1 == y2)
                continue;

            if(y >= min(y1, y2) && y < max(y1, y2))
            {
                int x = x1 + (float)(y - y1) * (x2 - x1) / (y2 - y1);

                interx[count] = x;
                count++;
            }
        }

        // Sort intersections
        for(int i = 0; i < count - 1; i++)
        {
            for(int j = i + 1; j < count; j++)
            {
                if(interx[i] > interx[j])
                {
                    int temp = interx[i];
                    interx[i] = interx[j];
                    interx[j] = temp;
                }
            }
        }

        // Fill polygon
        for(int i = 0; i < count; i += 2)
        {
            setcolor(YELLOW);

            line(interx[i], y, interx[i + 1], y);

            delay(20); 
        }
    }

    getch();
    closegraph();

    return 0;
}
