#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#pragma warning (disable:4996)

void n1(float* x, float* y) {//83%
    float temp_x = *x;
    *x = *x * 0.86 + *y * 0.03;
    *y = temp_x * -0.03 + *y * 0.86 + 1.5;
}

void n2(float* x, float* y) {//8%
    float temp_x = *x;
    *x = *x * 0.2 + *y * -0.25;
    *y = temp_x * 0.23 + *y * 0.21 + 1.5;
}

void n3(float* x, float* y) {//8%
    float temp_x = *x;
    *x = *x * -0.15 + *y * 0.27;
    *y = temp_x * 0.26 + *y * 0.25 + 0.45;
}

void n4(float* x, float* y) {//1%
    *x = 0;
    *y = *y * 0.17;
}

int main() {
    initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

    float x = 0;
    float y = 0;

    for (int i = 0; i < 50000; i++) {
        int choice = rand() % 100 + 1;

        if (choice >= 1 && choice <= 83) {
            n1(&x, &y);
        }
        else if (choice >= 84 && choice <= 91) {
            n2(&x, &y);
        }
        else if (choice >= 92 && choice <= 99) {
            n3(&x, &y);
        }
        else if (choice == 100) {
            n4(&x, &y);
        }
        putpixel(x * 85+ getmaxx() / 2, getmaxy() - y * 75 - 80, YELLOW);
    }
    getch();
    closegraph();
    return 0;
}