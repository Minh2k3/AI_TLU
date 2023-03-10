// AI : BFS

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int n, be, en, depth;
vector<int> ke[maxn];
ifstream inp("AI_Search_2.INP");
bool check[maxn];
int ans[maxn];

void nhap(){
	for (int i = 1; i <= n; ++i){
		cout << "Nhap cac dinh ke voi dinh " 
		<< i << ": ";
		while(true){int x; inp >> x; if (x > 0) ke[i].push_back(x); else break;}	// Nhap so 0 de dung
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

void bfs(int t){
	check[t] = true;
	if (t == en) {
		in();
		exit(0);
	}
	for (auto x : ke[t]) {
		if (!check[x]) {
			ans[x] = t;
			bfs(x);
		}
	}
}

signed main(){
	cout << "Nhap so dinh: "; inp >> n;
	nhap();
	memset(check, false, sizeof(check) * sizeof(bool));
	cout << "Nhap dinh xuat phat: "; cin >> be;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	bfs(be);
	if (!check[en]){
		cout << "Khong ton tai duong di!\n";
	}
}
