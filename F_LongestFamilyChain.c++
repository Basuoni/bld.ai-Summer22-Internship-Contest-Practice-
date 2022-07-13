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
map<int, string> in;
int memo[(int)1e4 + 5];
map<string, int> index;
int countPerant(map<string, vector<int>>& tree, string it, int k = 1)
{
	if (tree[it].size() == 0)
		return k;
	if (memo[index[it]] != -1)
		return k + memo[index[it]];
	int res = 0;
	for (int i : tree[it])
	{
		int x;
		x = countPerant(tree, in[i], k + 1);
		res = max(res, x);
	}
	memo[index[it]] = res - k;
	return res;
}
void mainTestCase(int numberTest)
{
	map<string, vector<int>> tree;
	int n;
	cin >> n;
	forn(i, 1, n + 1)
	{
		string it;
		cin >> it;
		index[it] = i;
		in[i] = it;
		tree[it] = vector<int>();
	}
	for (pair<string, int> it : index)
	{
		for (int i = 0; i < it.first.size(); i++)
		{
			string temp = it.first;
			temp.erase(i, 1);
			if (index.find(temp) != index.end())
			{
				tree[temp].push_back(it.second);
			}
		}
	}
	int ans = -1;
	for (pair<string, vector<int>> it : tree)
	{
		int x = countPerant(tree, it.first);
		ans = max(ans, x);
	}
	cout << ans << endl;
}
int main()
{
	memset(memo, -1, sizeof memo);
	Fast;
	int t;
	t = 1;
	// cin >> t;
	forn(i, 0, t)
		mainTestCase(i + 1);
	return 0;
} 
