#include <stdio.h>

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    long long arr[3] = {a, b, c};

    // sederhana: sorting 3 elemen manual
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                long long tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    long long p = arr[0], q = arr[1], r = arr[2];
    long long d1 = q - p;
    long long d2 = r - q;

    long long result = (d1 < d2) ? d1 : d2;
    printf("%lld\n", result);

    return 0;
}