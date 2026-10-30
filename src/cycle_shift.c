#include <stdio.h>
#define NMAX 10

int input(int *arr, int *n, int *shift);
void cyclic_shift(int *arr, int n, int shift);
void output(int *arr, int n);

int main() {
    int arr[NMAX];
    int n, shift;

    if (!input(arr, &n, &shift)) {
        printf("n/a");
        return 0;
    }

    cyclic_shift(arr, n, shift);
    output(arr, n);

    return 0;
}

int input(int *arr, int *n, int *shift) {
    long long temp_n, temp_shift;
    char c;
    int ok = 1;

    if (scanf("%lld%c", &temp_n, &c) != 2 || (c != '\n' && c != ' ' && c != '\t')) {
        ok = 0;
    } else if (temp_n <= 0 || temp_n > NMAX) {
        ok = 0;
    } else {
        *n = (int)temp_n;
        for (int i = 0; i < *n && ok; i++) {
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
            if (scanf("%lld", &temp_shift) != 1) {
                ok = 0;
            } else if (temp_shift < -2147483648LL || temp_shift > 2147483647LL) {
                ok = 0;
            } else {
                *shift = (int)temp_shift;
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
    return ok;
}

void cyclic_shift(int *arr, int n, int shift) {
    shift %= n;
    if (shift < 0) shift += n;
    if (shift != 0) {
        int temp[NMAX];
        for (int i = 0; i < shift; i++) {
            temp[i] = arr[i];
        }
        for (int i = shift; i < n; i++) {
            arr[i - shift] = arr[i];
        }
        for (int i = 0; i < shift; i++) {
            arr[n - shift + i] = temp[i];
        }
    }
    // если shift == 0, функция ничего не делает (один выход)
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
}