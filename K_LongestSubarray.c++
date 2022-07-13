#include <bits/stdc++.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define forn(i, st, n) for (int i = st; i < n; i++)
#define ll long long
#define endl "\n"
#define endCase return
using namespace std;
const int N = 1e3 + 5, Mod = 1e9 + 7;
int getLongestSubarray(vector<ll> &a, map<ll, set<int>> &MP, int &k, int i)
{
	ll x = 0;
	if (i)
		x = a[i - 1];
	x += k;
	set<int> &cur = MP[x];
	if (cur.size() == 0)
		return -1;
	auto it = cur.end();
	it--;
	if (*it >= i)
		return *it;
	else
		return -1;
}
void mainTestCase(int numberTest)
{
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	map<ll, set<int>> MP;
	forn(i, 0, n)
	{
		cin >> a[i];
		if (i)
			a[i] += a[i - 1];
		MP[a[i]].insert(i);
	}
	int ans = 0;
	forn(i, 0, n)
	{
		int indx = getLongestSubarray(a, MP, k, i);
		if (indx == -1)
			continue;
		int len = indx - i + 1;
		ans = max(ans, len);
	}
	cout << ans << endl;
}
int main()
{
	Fast;
	int t;
	t = 1;
	forn(i, 0, t)
		mainTestCase(i + 1);
	return 0;
}

/*

7 5
1 10 2 3 8 -8 10
=> 47 5
1 10 2 3 8 -8 -10
=> 6
4 1
1 5 5 5
=> 1
4 1
5 5 5 5
=> 0


*/
