#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input_number(int *buffer, int *length);
void print_number(int *buffer, int length);

int main() {
    int num1[LEN], num2[LEN];
    int len1, len2;

    if (!input_number(num1, &len1) || !input_number(num2, &len2)) {
        printf("n/a");
        return 0;
    }

    int sum_result[LEN + 1];
    int sum_len;
    sum(num1, len1, num2, len2, sum_result, &sum_len);
    print_number(sum_result, sum_len);
    printf("\n");

    int sub_result[LEN];
    int sub_len;
    if (sub(num1, len1, num2, len2, sub_result, &sub_len)) {
        print_number(sub_result, sub_len);
    } else {
        printf("n/a");
    }

    return 0;
}

// Чтение одного числа: сначала длина, затем цифры
int input_number(int *buffer, int *length) {
    long long temp_len;
    char c;
    int ok = 1;

    if (scanf("%lld%c", &temp_len, &c) != 2 || (c != '\n' && c != ' ' && c != '\t')) {
        ok = 0;
    } else if (temp_len <= 0 || temp_len > LEN) {
        ok = 0;
    } else {
        *length = (int)temp_len;
        for (int i = 0; i < *length && ok; i++) {
            long long digit;
            if (scanf("%lld", &digit) != 1) {
                ok = 0;
            } else if (digit < 0 || digit > 9) {
                ok = 0;
            } else {
                buffer[i] = (int)digit;
            }
        }
        // Проверка лишних символов (необязательно, но оставим)
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

// Вывод массива цифр через пробел, без завершающего перевода строки
void print_number(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
}

// Сложение двух чисел (прямой порядок: старший разряд в начале)
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int i = len1 - 1;
    int j = len2 - 1;
    int carry = 0;
    int pos = 0;
    int temp[LEN + 1];  // временный массив для обратного порядка

    // Складываем, начиная с младших разрядов
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? buff1[i] : 0;
        int digit2 = (j >= 0) ? buff2[j] : 0;
        int sum_digit = digit1 + digit2 + carry;
        temp[pos] = sum_digit % 10;
        carry = sum_digit / 10;
        pos++;
        if (i >= 0) i--;
        if (j >= 0) j--;
    }
    // Теперь temp содержит цифры в обратном порядке (младшие в начале)
    *result_length = pos;
    for (int k = 0; k < pos; k++) {
        result[k] = temp[pos - 1 - k];  // переворачиваем в прямой порядок
    }
}

// Вычитание двух чисел (прямой порядок), возвращает 1 если успешно, иначе 0
int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    // Сравниваем числа: если buff2 > buff1, то вычитание невозможно
    int cmp = 0;  // 0 - равны, 1 - buff1 > buff2, -1 - buff1 < buff2
    if (len1 > len2)
        cmp = 1;
    else if (len1 < len2)
        cmp = -1;
    else {
        for (int i = 0; i < len1 && cmp == 0; i++) {
            if (buff1[i] > buff2[i])
                cmp = 1;
            else if (buff1[i] < buff2[i])
                cmp = -1;
        }
    }
    if (cmp < 0) {
        return 0;  // вычитаемое больше уменьшаемого
    }

    // Выполняем вычитание
    int i = len1 - 1;
    int j = len2 - 1;
    int borrow = 0;
    int pos = 0;
    int temp[LEN];

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? buff1[i] : 0;
        int digit2 = (j >= 0) ? buff2[j] : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp[pos] = diff;
        pos++;
        if (i >= 0) i--;
        if (j >= 0) j--;
    }
    // Убираем ведущие нули (но оставляем хотя бы один разряд)
    while (pos > 1 && temp[pos - 1] == 0) {
        pos--;
    }
    *result_length = pos;
    for (int k = 0; k < pos; k++) {
        result[k] = temp[pos - 1 - k];
    }
    return 1;
}