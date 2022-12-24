// AI : DFS

// Y tuong : 	Don gian la di theo tung node con
//				Khong co thi quay lai
//				Gap dich thi in ra, den het ma khong gap thi khong thay

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int n, be, en, ans[maxn];
vector<int> ke[maxn];
ifstream inp("AI_Search_2.INP");
bool check[maxn];

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

void dfs(int t){
	check[t] = true;
	if (t == en) {
		in();
		exit(0);
	}
	for (auto x : ke[t]) {
		if (!check[x]) {
			ans[x] = t;
			dfs(x);
		}
	}
}

signed main(){
	cout << "Nhap so dinh: "; inp >> n;
	nhap();
	memset(check, false, sizeof(check) * sizeof(bool));
	cout << "\nNhap dinh xuat phat: "; cin >> be;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	dfs(be);
	if (!check[en]){
		cout << "Khong ton tai duong di!\n";
	}
}
