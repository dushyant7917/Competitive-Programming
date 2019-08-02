#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

char ans[MX + 1];
int n, x;

bool dfs(int n, long long l = 0, long long r = 0) {
	if (n == 0) return l == r;
	if (n == x) return dfs(n - 1, l, r);

	if (l < r) {
		ans[n - 1] = '0';
		if (dfs(n - 1, l + n, r)) return true;

		ans[n - 1] = '1';
		if (dfs(n - 1, l, r + n)) return true;
	}
	else {
		ans[n - 1] = '1';
		if (dfs(n - 1, l, r + n)) return true;

		ans[n - 1] = '0';
		if (dfs(n - 1, l + n, r)) return true;
	}

	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &x, &n);

		long long sum = n * (n + 1ll) / 2 - x;
		if (sum % 2 == 1 || dfs(n) == false) {
			printf("impossible\n");
			continue;
		}

		ans[n] = 0;
		ans[x - 1] = '2';
		printf("%s\n", ans);
	}

	return 0;
}
