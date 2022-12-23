// AI : Branch-and-Bound

#include <bits/stdc++.h>
using namespace std;

#define pb			push_back
#define is			insert
#define each(x,a) 	for (auto x : a)
#define For(i,x,y)	for (int i = x; i < y; ++i)

const int maxn = 101;
int n, be, en, minf = (int)1e9, ans[maxn] = {0};
ifstream	inp("AI_Search_6.INP");
pair<int, map<int, int> > node[maxn];
vector<int> open, g(maxn), f(maxn);
bool check = false;

void nhap(){
	for (int i = 1; i <= n; ++i) {
		// Nhap gia tri cho h(u)
		cout << "Nhap gia tri tai dinh: "; inp >> node[i].first;
		// Nhap cac gia tri k(u,v)
		cout << "Nhap cac dinh ke va gia tri duong di den dinh:\n";
		while(1){
			int t1; inp >> t1;
			if (t1 == 0) break;
			int t2; inp >> t2;
			// t1 = u, t2 = v
			node[i].second.insert({t1, t2});
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
	cout << "\n";
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

void bab() {
	open.pb(be);
	while(1) {
		Here:
		if (open.empty()) {
			if (check) {
				in(); 
				cout << "Gia tri f[u]: \n";
				For(i,1,n+1) cout << f[i] << " ";
				cout << "\n";
				return;
			}
			cout << "Khong ton tai duong di!\n";
			return;
		}
		int u = open[0];
		open.erase(open.begin());
		cout << "Xet tai node " << u << " truoc: ";
		each(x,open) cout << x << " ";
		cout << "\n";
		if (u == en) {
			if (f[u] < minf) {
				minf = f[u];
				check = true;
				goto Here;
				//continue;
			}
		}
		if (f[u] >= minf) {
			goto Here;
		}
		vector<int> L;
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
			L.pb(v);
			int idx = inOpen(v);
			if (idx != -1) {
				open.erase(open.begin() + idx);
			}
		}
		sort(L.begin(), L.end(), cmp);
		open.insert(open.begin(), L.begin(), L.end());
		cout << "Xet tai node " << u << " sau: ";
		each(x,open) cout << x << " ";
		cout << "\n";
	}
}

int main(){
	cout << "Nhap vao so dinh: "; inp >> n;
	nhap();
	cout << "Nhap dinh bat dau: "; cin >> be;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	bab();
}
