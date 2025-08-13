#include <stdio.h>

int main(void)
{
    int n;
	const int mod = 12345;
    const int min = 1, max = 10000;

    printf("Введіть довжину послідовності в діапазоні від %d до %d не включно: ", min, max);
    if (scanf("%d", &n) != 1) {
        printf("\nНекоректні дані\n");
        return 1;
    }

	if (n <= min || n >= max) {
		printf("\nДовжина послідовності не входить у діапазон\n");
		return 1;
	}

    int dp[n + 1][3];

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = dp[i - 1][0] % mod;
        dp[i][2] = dp[i - 1][1] % mod;
    }

    int result = (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
    printf("\nКількість допустимих послідовностей: %d\n", result);

    return 0;
}
