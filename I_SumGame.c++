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

void mainTestCase(int numberTest)
{
    ll A, B;
    cin >> A >> B;
    if(A>B) swap(A,B);
    ll ans1 = (A * (A - 1)) / 2;
    ll ans2 = (B * (B + 1)) / 2;
// 999999999  888888888
   // cout << ans1 << " " << ans2 <<" "<<(ans2 - ans1)<<  endl;
    if ((ans2 - ans1) & 1)
        cout << "Hoss" << endl;
    else
        cout << "Nasser" << endl;
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
