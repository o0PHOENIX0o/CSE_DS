//  g++ MCA.cpp -o MCA.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && MCA.exe 

#include <stdio.h>
#include <graphics.h>
#include <conio.h>


#define color 2

void drawCircle(int xc, int yc, int r);
void putPixels(int xc, int yc, int x, int y);

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int xc = getmaxx() / 2, yc = getmaxy() / 2;
    // int xc = 200, yc = 250;

    int r = 14;
    drawCircle(xc, yc, r);
    // drawCircle(xc, yc + r, r);
    // drawCircle(xc, yc - r, r);
    // drawCircle(xc + r, yc, r);
    // drawCircle(xc - r, yc, r);

    // float rCos = r*0.7071, rSin = r*0.7071;
    // drawCircle(xc + rCos, yc + rSin, r);
    // drawCircle(xc - rCos, yc + rSin, r);
    // drawCircle(xc + rCos, yc - rSin, r);
    // drawCircle(xc - rCos, yc - rSin, r);
    
    getch();
    closegraph();

    return 0;
}

void putPixels(int xc, int yc, int x, int y){
    putpixel(xc + x, yc + y, color);
    putpixel(xc + y, yc + x, color);

    putpixel(xc - x, yc + y, color);
    putpixel(xc + y, yc - x, color);

    putpixel(xc + x, yc - y, color);
    putpixel(xc - y, yc + x, color);

    putpixel(xc - x, yc - y, color);
    putpixel(xc - y, yc - x, color);
}

void drawCircle(int xc, int yc, int r){
    int x= 0, y = r;
    int p = 1.25-r;

    while(x <= y){
        printf("%d, %d, %d\n", x, y, p);
        putPixels(xc, yc, x, y);
        if(p < 0) p += 2*x+3;
        else{
            p += 2*(x-y) + 5;
            y--;
        }
        x++;
    }
}