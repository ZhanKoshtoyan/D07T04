#include <stdio.h>
#define NMAX 10

int input(int *arr, int *size_arr);
void output(int *arr, int size_arr);
void squaring(int *arr, int size_arr);
int read_size(long long *size, char *end_char);
int check_squaring(long long value, int int_max);
int has_trailing_invalid_character(void);

int main() {
    int size_arr, arr[NMAX];

    if (input(arr, &size_arr)) {
        squaring(arr, size_arr);
        output(arr, size_arr);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *arr, int *size_arr) {
    const int INT_MAX = 2147483647;
    const int INT_MIN = -INT_MAX - 1;
    int result = 1;
    long long ll_size_arr;
    char end_char = '\0';
    // Чтение размера;
    /*Проверка на корректность ввода размерности массива и
        что размер массива не <=0 и не больше NMAX*/
    if (!read_size(&ll_size_arr, &end_char) || (ll_size_arr <= 0 || ll_size_arr > NMAX)) {
        result = 0;
    } else {
        // Присваиваем размер;
        *size_arr = (int)ll_size_arr;
        // Чтение элементов;
        for (int i = 0; i < *size_arr; i++) {
            long long value;
            int input_element = scanf("%lld", &value);
            // int input_element = scanf("%lld%c", &value, &end_char);
            //  Проверка на, то что введено число в ячейку массива;
            if (input_element != 1) {
                result = 0;
            } else if (value < INT_MIN || value > INT_MAX) {
                result = 0;
            } else if (check_squaring(value, INT_MAX)) {
                result = 0;
            } else {
                arr[i] = (int)value;
            }
        }
        // Проверка на лишние символы после ввода всех чисел;
        if (result && has_trailing_invalid_character()) result = 0;
    }
    return result;
}

void squaring(int *arr, int size_arr) {
    for (int i = 0; i < size_arr; i++) {
        arr[i] *= arr[i];
    }
}

void output(int *arr, int size_arr) {
    for (int i = 0; i < size_arr; i++) {
        printf("%d", arr[i]);
        if (i < size_arr - 1) {
            printf(" ");
        }
    }
}

// Читает размер и проверяет символ после него
int read_size(long long *size, char *end_char) {
    int result = 0;
    result =
        scanf("%lld%c", size, end_char) == 2 && (*end_char == '\n' || *end_char == ' ' || *end_char == '\t');
    return result;
}

int check_squaring(long long value, int int_max) {
    int error = 0;
    long long square = value * value;
    if (square > int_max) {
        error = 1;
    }
    return error;
}

// Проверка на лишние символы после ввода всех чисел;
int has_trailing_invalid_character(void) {
    char end_char;
    int error = 0;
    int done = 0;

    while (scanf("%c", &end_char) == 1 && !done) {
        if (end_char == '\n') {
            done = 1;
        } else if (end_char != ' ' && end_char != '\t') {
            error = 1;
            done = 1;
        }
    }

    return error;
}
