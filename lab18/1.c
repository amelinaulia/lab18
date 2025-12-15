#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>



struct point {
    float x;
    float y;
    char name;
};

typedef struct point Point;


void put_point(Point z) {
    printf("point %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}


float dist(Point z, Point w) {
    return sqrtf((w.x - z.x) * (w.x - z.x) +
        (w.y - z.y) * (w.y - z.y));
}


Point middle(Point a, Point b) {
    Point m;
    m.x = (a.x + b.x) / 2.0f;
    m.y = (a.y + b.y) / 2.0f;
    m.name = 'M';
    return m;
}


int quarter(Point p) {
    if (p.x > 0 && p.y > 0) return 1;
    if (p.x < 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y < 0) return 3;
    if (p.x > 0 && p.y < 0) return 4;
    return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");
    Point a, b;

    printf("Введите точку A: имя x y\n");
    scanf(" %c %f %f", &a.name, &a.x, &a.y);

    printf("Введите точку B: имя x y\n");
    scanf(" %c %f %f", &b.name, &b.x, &b.y);

    printf("\n--- Введенные точки ---\n");
    put_point(a);
    put_point(b);

    printf("\nРасстояние AB = %.3f\n", dist(a, b));

    Point m = middle(a, b);
    printf("Середина отрезка AB:\n");
    put_point(m);

    printf("\nЧетверти:\n");
    printf("Точка %c => четверть %d\n", a.name, quarter(a));
    printf("Точка %c => четверть %d\n", b.name, quarter(b));

    return 0;
}

