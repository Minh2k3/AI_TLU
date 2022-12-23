// AI : DLS

// Y tuong :	Phat trien tu DFS
//				nhung them do sau toi da co the
//				Khoi tao do sau tai goc la 0
//				Khi duyet toi dinh con thi cap nhat do sau cong 1
//				Neu vuot qua do sau toi da thi tro ve
//				Luc nao gap dich thi in

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int n, be, en, maxDepth;
vector<int> ke[maxn];
ifstream inp("AI_Search_3.INP");
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
	cout << "\nNhap dinh xuat phat: "; cin >> be;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	cout << "Nhap do sau: "; cin >> maxDepth;
//	int depth = 0;
	dls(be, 0);
	if (!check[en]){
		cout << "Khong ton tai duong di!\n";
	}
}
