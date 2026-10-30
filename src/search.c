#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int find_first(int *a, int n, double mean_v, double sigma);

int main() {
    int n, data[NMAX];

    if (!input(data, &n)) {
        printf("n/a");
        return 0;
    }

    double m = mean(data, n);
    double var = variance(data, n);
    double sigma = sqrt(var);

    int result = find_first(data, n, m, sigma);
    printf("%d", result);

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

int find_first(int *a, int n, double mean_v, double sigma) {
    double upper = mean_v + 3.0 * sigma;
    int result = 0;
    int found = 0;
    for (int i = 0; i < n && !found; i++) {
        int val = a[i];
        if (val != 0 && val % 2 == 0 && (double)val >= mean_v && (double)val <= upper) {
            result = val;
            found = 1;
        }
    }
    return result;
}