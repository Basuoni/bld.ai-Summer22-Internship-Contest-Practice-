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
	int n;
	cin>> n;
	vector<int> A(n);
	vector<int> cash;
	forn(i,0,n) cin>>A[i];
	
	forn(i,0,n){
		if(cash.size()!= 0){
			if(cash[cash.size()- 1] == A[i]){
				cash.pop_back();
			}
			else
				cash.push_back(A[i]);
		}else cash.push_back(A[i]);
	}
	cout<< cash.size() <<endl;
	for(int it : cash) cout<< it <<" ";
	
}
int main()
{
	// freopen("", "r", stdin);
	// freopen("", "w", stdout);
	Fast;
	int t;
	t = 1;
	//cin >> t;
	forn(i, 0, t)
		mainTestCase(i + 1);
	return 0;
}
