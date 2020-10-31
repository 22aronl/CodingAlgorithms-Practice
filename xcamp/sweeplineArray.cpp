#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define INF 10000000
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	priority_queue<pair<pair<int,int>, pair<int, int>>> pq;
	vector<pair<pair<int, int>, pair<int, int>>> vectors;
	int n, m;
	cin >> n >> m;
	int a, b, c, d;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		pq.push(mp(mp(a, b), mp(c, d)));
	}

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		pq.push(mp(mp(a, b), mp(c, -1)));
	}

	int total = 0;
	while(!pq.empty())
	{
		pair<pair<int, int>, pair<int, int>> p;
		if(p.s.s == -1)
		{
			for(pair<pair<int, int>, pair<int, int>> q : vectors)
			{
				if(q.f.f <= p.f.f && q.s.f >= p.f.f && p.f.s >= q.f.s && p.s.f <= q.f.s)
					total++;
			}
		}
		else
		{
			for(auto it = vectors.begin(); it != vectors.end(); ++it)
			{
				pair<pair<int, int>, pair<int, int>> q = *it;
				if(q.s.s < p.f.f)
					vectors.erase(it);
			}
			vectors.push_back(p);
		}
		
	}

	cout << total << endl;

}