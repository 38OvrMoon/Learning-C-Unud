//minimum operasi yang dibutuhkan supaya jumlah array jadi 0 adalah nilai absolut dari total jumlah array
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        sum += a;
    }

    long long result = sum < 0 ? -sum : sum;
    printf("%lld\n", result);

    return 0;
}