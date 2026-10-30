#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int data[NMAX];
    int length;

    input(data, &length);

    if (length <= 0 || length > NMAX) {
        printf("n/a");
        return 0;
    }

    int has_even = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] % 2 == 0 && data[i] != 0) {
            has_even = 1;
            break;
        }
    }
    if (!has_even) {
        printf("n/a");
        return 0;
    }

    int sum = sum_numbers(data, length);
    int numbers[NMAX];
    int count = find_numbers(data, length, sum, numbers);

    printf("%d\n", sum);
    if (count > 0) {
        output(numbers, count);
    }

    return 0;
}

void input(int *buffer, int *length) {
    long long temp_len;
    char c;
    int ok = 1;

    if (scanf("%lld%c", &temp_len, &c) != 2 || (c != '\n' && c != ' ' && c != '\t')) {
        ok = 0;
    } else if (temp_len <= 0 || temp_len > NMAX) {
        ok = 0;
    } else {
        *length = (int)temp_len;
        for (int i = 0; i < *length && ok; i++) {
            long long val;
            if (scanf("%lld", &val) != 1) {
                ok = 0;
            } else if (val < -2147483648LL || val > 2147483647LL) {
                ok = 0;
            } else {
                buffer[i] = (int)val;
            }
        }
        if (ok) {
            while ((c = getchar()) == ' ' || c == '\t') {
                // пропускаем
            }
            if (c != '\n' && c != EOF) {
                ok = 0;
            }
        }
    }
    if (!ok) {
        *length = -1;  // сигнал ошибки
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) printf(" ");
    }
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0 && buffer[i] != 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count++] = buffer[i];
        }
    }
    return count;
}