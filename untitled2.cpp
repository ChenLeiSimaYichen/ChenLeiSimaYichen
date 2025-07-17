#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e2+5;
int n,m,x;
vector<int> ve[M],h;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("1.in","r",stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		h.push_back(x);
		ve[i].push_back(x);
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<m;j++){
			cin >> x;
			ve[j].push_back(x);
		}
	}
	for (int i=0;i<m;i++){
		sort(ve[i].begin(),ve[i].end());
	}
	int sum = 0;
	for (int i=1;i<m;i++){
		int b=lower_bound(ve[i].begin(),ve[i].end(),h[i])-ve[i].begin();
		sum+=b+1;
	}
	cout << sum;
	return 0;
}
