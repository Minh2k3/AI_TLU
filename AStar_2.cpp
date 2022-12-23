// AI : A*

// Y tuong : 	Hoan toan theo Pseudocode nhu slide

#include <bits/stdc++.h>
using namespace std;

#define pb			push_back
#define is			insert
#define each(x,a) 	for (auto x : a)

const int maxn = 101;
int n, be, en, ans[maxn] = {0};
ifstream	inp("AI_Search_6.INP");
pair<int, map<int, int> > node[maxn];
vector<int> open, g(maxn), f(maxn);

void nhap(){
	for (int i = 1; i <= n; ++i) {
		// Nhap gia tri cho h(u)
		cout << "Nhap gia tri tai dinh: "; inp >> node[i].first;
		// Nhap cac gia tri k(u,v)
		cout << "Nhap cac dinh ke va gia tri duong di den dinh:\n";
		while(1){
			int t1; inp >> t1;
			if (t1 == 0) break;
			else {
				int t2; inp >> t2;
				// t1 = u, t2 = v
				node[i].second.insert({t1, t2});
			}
		}
	}
}

void in(){
	cout << "Duong di la: " << en;
	int x = en;
	do {
		x = ans[x];
		cout << " <--- " << x;
	} while (x != be);
}

int inOpen(int u) {
	for (int i = 0; i <= open.size(); ++i){
		if (open[i] == u)
			return i;
	}
	return -1;
}

bool cmp(int t1, int t2) {
	return (f[t1] == f[t2] ? g[t1] < g[t2] : f[t1] < f[t2]);
}

void aStar() {
	open.pb(be);
	while(1) {
		if (open.empty()) {
			cout << "Khong ton tai duong di!\n";
			return;
		}
		int u = open[0];
		open.erase(open.begin());
		if (u == en) {
			in(); return;
		}
		each(x, node[u].second) {
			int v = x.first;
			int res1 = g[u] + x.second;
			int res2 = res1 + node[u].first;
			if (f[v]) {
				if (f[v] > res2 || (f[v] == res2 && res1 < g[v])) {
					f[v] = res2;
					g[v] = res1;
					ans[v] = u;
				}
			}
			else {
				f[v] = res2;
				g[v] = res1;
				ans[v] = u;
			}
			int idx = inOpen(v);
			if (idx != -1) {
				open.erase(open.begin() + idx);
			}
			open.pb(v);
			sort(open.begin(), open.end(), cmp);
		}
	}
}

int main(){
	cout << "Nhap vao so dinh: "; inp >> n;
	nhap();
	cout << "Nhap dinh bat dau: "; cin >> be;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	aStar();
}
