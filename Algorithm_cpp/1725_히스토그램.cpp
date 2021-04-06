#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
int main_1725() {
	int n;

	scanf("%d", &n);
	stack<pair<int, int>> st;
	ll ans = 0;

	for (int i = 0; i <= n; ++i) {
		int height;

		if (i < n)
			scanf("%d", &height);
		else
			height = -1;
		int left = i;
		while (!st.empty() && st.top().second > height) {
			ans = max(ans, ((ll)i - st.top().first) * st.top().second);
			left = st.top().first;
			st.pop();
		}
		st.push(make_pair(left, height));
	}
	printf("%lld\n", ans);
	return 0;
}