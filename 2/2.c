#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define WIDTH 80
#define HEIGHT 10

void center_text(char* dest, const char* text) {
    int len = strlen(text);
    int inner_width = WIDTH - 2;
    int left = (inner_width - len) / 2;

    sprintf(dest, "*%*s%s%*s*",
        left, "",
        text,
        inner_width - left - len, "");
}

int main() {
    setlocale(LC_ALL, "RUS");
    struct tm* mytime;
    time_t t;
    t = time(NULL);
    mytime = localtime(&t);

    const char* weekday_names[] = {
        "Воскресенье", "Понедельник", "Вторник", "Среда",
        "Четверг", "Пятница", "Суббота"
    };

    char weekday[20];
    sprintf(weekday, "%s", weekday_names[mytime->tm_wday]);

    char time_str[40];
    sprintf(time_str,
        "Текущее время: %02d:%02d:%02d",
        mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    char weekday_str[40];
    sprintf(weekday_str,
        "День недели: %s",
        weekday);

    char line[WIDTH + 1];

    for (int i = 0; i < WIDTH; i++) printf("*");
    printf("\n");


    for (int i = 0; i < (HEIGHT - 4) / 2; i++) {
        printf("*%*s*\n", WIDTH - 2, "");
    }


    center_text(line, time_str);
    printf("%s\n", line);

    center_text(line, weekday_str);
    printf("%s\n", line);


    for (int i = 0; i < (HEIGHT - 4) / 2; i++) {
        printf("*%*s*\n", WIDTH - 2, "");
    }


    for (int i = 0; i < WIDTH; i++) printf("*");
    printf("\n");

    return 0;
}