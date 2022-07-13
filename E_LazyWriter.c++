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
const int N = 1e5 + 5, Mod = 1e9 + 7;
int arr[N];
int n, k;
bool check(ll m)
{
    long long ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += arr[i] / m + (arr[i] % m != 0);
        if (ret > k)
            return 0;
    }
    return 1;
}
int binarySearch(int MX)
{
    int first = 1,
        last = MX,
        position = 1e9;
    while (first <= last)
    {
        ll middle = (first + last) / 2;
        bool isTrue = check(middle);
        if (isTrue)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return first;
}
void mainTestCase(int numberTest)
{

    cin >> n >> k;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    cout << binarySearch(mx) << endl;
}
int main()
{
    Fast;
    int t;
    t = 1;
    // cin >> t;
    forn(i, 0, t)
        mainTestCase(i + 1);
    return 0;
}
