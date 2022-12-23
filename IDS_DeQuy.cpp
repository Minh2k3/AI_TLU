// AI : IDS

// Y tuong :	Ke thua tu DLS
//				Lap do sau toi da tang dan tu 0 den max

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int n, be, en, maxDepth;
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

void dls(int t, int depth){
	check[t] = true;
	if (t == en) {
		in();
		exit(0);
	}
	if (depth == maxDepth) {
		return;
	}
	for (auto x : ke[t]) {
		if (!check[x]) {
			ans[x] = t;
			dls(x, depth + 1);
		}
	}
}

signed main(){
	cout << "Nhap so dinh: "; inp >> n;
	nhap();
	memset(check, false, sizeof(check) * sizeof(bool));
	cout << "Nhap dinh xuat phat: "; cin >> be;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	cout << "Nhap do sau max: "; cin >> maxDepth;
//	int depth = 0;
	for (int i = 0; i <= maxDepth; ++i){
		dls(be, i);
	}
	if (!check[en]){
		cout << "Khong ton tai duong di!\n";
	}
}
