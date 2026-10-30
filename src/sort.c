#include <stdio.h>
#define NMAX 10

int input(int *arr);
void sort(int *arr);
void output(int *arr);

int main() {
    int data[NMAX];

    if (!input(data)) {
        printf("n/a");
        return 0;
    }

    sort(data);
    output(data);

    return 0;
}

int input(int *arr) {
    int ok = 1;
    for (int i = 0; i < NMAX && ok; i++) {
        long long val;
        if (scanf("%lld", &val) != 1) {
            ok = 0;
        } else if (val < -2147483648LL || val > 2147483647LL) {
            ok = 0;
        } else {
            arr[i] = (int)val;
        }
    }
    if (ok) {
        char c;
        while ((c = getchar()) == ' ' || c == '\t') {
            // пропускаем
        }
        if (c != '\n' && c != EOF) {
            ok = 0;
        }
    }
    return ok;
}

void sort(int *arr) {
    for (int i = 0; i < NMAX - 1; i++) {
        for (int j = 0; j < NMAX - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void output(int *arr) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d", arr[i]);
        if (i < NMAX - 1) printf(" ");
    }
}