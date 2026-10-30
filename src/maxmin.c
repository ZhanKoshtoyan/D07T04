#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Найди максимальную и минимальную вероятности. */
int main() {
    const int SIDE_VALUE = 2147483647;
    const int INT_MIN = -SIDE_VALUE - 1;
    const int INT_MAX = SIDE_VALUE;
    long long input_x, input_y, input_z;
    int return_bool = 0;
    char end_char = '\0';

    // 1. Проверка на корректность ввода;
    if (scanf("%lld %lld %lld%c", &input_x, &input_y, &input_z, &end_char) != 4 ||
        (end_char != '\n' && end_char != ' ' && end_char != '\t')) {
        printf("n/a");
        return_bool = 1;
    }

    // 2. Проверка на граничные условия для int;
    if (((input_x < INT_MIN || input_x > INT_MAX) || (input_y < INT_MIN || input_y > INT_MAX) ||
         (input_z < INT_MIN || input_z > INT_MAX)) &&
        return_bool == 0) {
        printf("n/a");
        return_bool = 1;
    }

    // 3. Привидение переменных к типу int;
    int x = (int)input_x;
    int y = (int)input_y;
    int z = (int)input_z;

    // 4. Расчет и запись значений max и min;
    int max, min;
    if (return_bool == 0) {
        maxmin(x, y, z, &max, &min);
        printf("%d %d", max, min);
    }

    return return_bool;
}

/* Эту функцию нужно сохранить! (Твой ИИ) */
/* Но ошибки и баги необходимо исправить. */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = prob1;
    *min = prob1;

    if (prob2 > *max) {
        *max = prob2;
    }
    if (prob2 < *min) {
        *min = prob2;
    }
    if (prob3 > *max) {
        *max = prob3;
    }
    if (prob3 < *min) {
        *min = prob3;
    }
}