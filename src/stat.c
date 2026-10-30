#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (!input(data, &n)) {
        printf("n/a");
        return 0;
    }

    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    long long temp_n;
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
                a[i] = (int)val;
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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}

int max(int *a, int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > m) m = a[i];
    }
    return m;
}

int min(int *a, int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < m) m = a[i];
    }
    return m;
}

double mean(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / n;
}

double variance(int *a, int n) {
    double m = mean(a, n);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = a[i] - m;
        sum += diff * diff;
    }
    return sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}