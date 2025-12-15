#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define SIZE 3

struct employee {
    char lastname[20];    // Фамилия
    char name[20];        // Имя
    char surname[20];     // Отчество
    char position[20];    // Должность
    float salary;         // Зарплата
    int birth_day;        // День рождения
    int birth_month;      // Месяц рождения
    int birth_year;       // Год рождения
};
typedef struct employee employee;

int main()
{
setlocale(LC_ALL, "RUS");
 struct employee employees[SIZE];
 printf("=== Ввод данных о сотрудниках ===\n\n");

  for (int i = 0; i < SIZE; i++) {
      printf("Сотрудник №%d:\n", i + 1);
      printf("  Фамилия: ");
      scanf("%19s", employees[i].lastname);
      printf("  Имя: ");
      scanf("%19s", employees[i].name);
      printf("  Отчество: ");
      scanf("%19s", employees[i].surname);
      printf("  Должность: ");
      scanf("%19s", employees[i].position);
      printf("  Зарплата: ");
      scanf("%f", &employees[i].salary);
      printf("  Дата рождения (день месяц год): ");
      scanf("%d %d %d",
            &employees[i].birth_day,
            &employees[i].birth_month,
            &employees[i].birth_year);

      printf("\n");
    }

    printf("\n=== Сотрудники, родившиеся в мае ===\n\n");

    int found = 0;  
    for (int i = 0; i < SIZE; i++) {
        if (employees[i].birth_month == 5) {  // 5 - месяц май
            printf("Сотрудник #%d:\n", i + 1);
            printf("  Фамилия:    %s\n", employees[i].lastname);
            printf("  Имя:        %s\n", employees[i].name);
            printf("  Отчество:   %s\n", employees[i].surname);
            printf("  Должность:  %s\n", employees[i].position);
            printf("  Зарплата:   %.2f\n", employees[i].salary);
            printf("  Дата рождения: %02d.%02d.%d\n",
            employees[i].birth_day,
            employees[i].birth_month,
            employees[i].birth_year);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Сотрудников, родившихся в мае, не найдено.\n");
    }
    return 0;
}
