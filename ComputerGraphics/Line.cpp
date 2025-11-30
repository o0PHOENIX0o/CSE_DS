
// g++ Line.cpp -o Line.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && Line.exe

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include <iostream>


void PlotPoint(int x,int y,int color);
void DDAline(int x1,int x2,int y1,int y2);
void Brasenham_Vertical_line(int x1,int y1,int x2,int y2);
void Brasenham_Horizontal_line(int x1,int y1,int x2,int y2);
void Brasenham_line(int x1,int y1,int x2,int y2);






int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

    // int x= 100, y = -50;

    // DDAline(0,0, x, y);
    // Brasenham_line(0,0,x,y);


    PlotPoint(0, 0, 2);
    // PlotPoint(x, y, 3);
    
    

    while (!kbhit()) {
        if (GetAsyncKeyState(VK_LBUTTON)){  // Check if the left button is clicked
            int x =  mousex(), y =  mousey();


            printf("%d, %d\n", x,y);
            // Brasenham_line(getmaxx()/2, getmaxy()/2, x, y);
            DDAline(getmaxx()/2, getmaxy()/2 ,x,y);
            // putpixel(x,y,BLUE);
            // putpixel(x+1,y,BLUE);
            // putpixel(x-1,y,BLUE);
            // putpixel(x,y+1,BLUE);
            // putpixel(x,y-1,BLUE);
            
            delay(5);            
        }
    }
    getch();
    closegraph();

    return 0;
}


void PlotPoint(int x,int y,int color){
    int maxX = getmaxx();
    int maxY = getmaxy(); 
    putpixel((maxX/2 + x)    , (maxY/2 - y)    , color);
    putpixel((maxX/2 + x) + 1, (maxY/2 - y)    , color);
    putpixel((maxX/2 + x)    , (maxY/2 - y) + 1, color);
    putpixel((maxX/2 + x) - 1, (maxY/2 - y)    , color);
    putpixel((maxX/2 + x) - 1, (maxY/2 - y) + 1, color);
}


void DDAline(int x1,int y1,int x2,int y2){

    // x1 = getmaxx()/2 + x1;
    // y1 = getmaxy()/2 - y1;

    // x2 = getmaxx()/2 + x2;
    // y2 = getmaxy()/2 - y2;

    // printf("(x = %d, y = %d) \n(x = %d, y = %d)\n\n", x1, y1, x2, y2);

    int dx = x2-x1, dy = y2-y1;
    int step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // printf("step = %d\n", step);
    
    float xinc = (step != 0) ? (float)dx / (float)step : 0.0;
    float yinc = (step != 0) ? (float)dy / (float)step : 1.0;
    
    // printf("xinc = %f, yinc = %f", xinc, yinc);
    
    for(int i = 0; i < step; i++){
        x1 += xinc;
        y1 += yinc;
        // if (i % 10 < 5) { // Creates a dashed effect
            putpixel(x1, y1, RED);
        // }
    }
    
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}





void Brasenham_line(int x1,int y1,int x2,int y2){
    // x1 = getmaxx()/2 + x1;
    // y1 = getmaxy()/2 - y1;

    // x2 = getmaxx()/2 + x2;
    // y2 = getmaxy()/2 - y2;
    
    if(abs(x2 - x1) < abs(y2 - y1)){// for vertical lines
        Brasenham_Vertical_line(x1,y1,x2,y2);
    }else{
        Brasenham_Horizontal_line(x1,y1,x2,y2);
    }
    
}





void Brasenham_Vertical_line(int x1,int y1,int x2,int y2){
    if(y1 > y2){ // for dx < 0
        swap(&x1, &x2);
        swap(&y1, &y2);
    }

    int dx = x2-x1, dy = y2-y1;
    int dir = (dx > 0) ? 1 : -1; // for m < 0
    dx *= dir;
    
    int p = 2*dx - dy;
    while(y1 <= y2){
        putpixel(x1,y1,RED);
        y1++;
        if(p <= 0) p = p + 2*dx;
        else {
            x1 += dir;
            p = p + 2*dx -2*dy;
        }
    }
}

void Brasenham_Horizontal_line(int x1,int y1,int x2,int y2){
    if(x1 > x2){ // for dx < 0
        swap(&x1, &x2);
        swap(&y1, &y2);
    }

    int dx = x2-x1, dy = y2-y1;
    int dir = (dy > 0) ? 1 : -1; // for m < 0
    dy *= dir;
    
    int p = 2*dy - dx;
    while(x1 <= x2){
        putpixel(x1,y1,RED);
        x1++;
        if(p <= 0) p = p +2*dy;
        else {
            y1 += dir;
            p = p + 2*dy -2*dx;
        }
    }
}
