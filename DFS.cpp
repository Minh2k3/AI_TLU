// AI : DFS

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;	// MAX la 100 dinh
vector<int> ke[maxn];
int n, beg, en;
unordered_set<int> open;
int ans[maxn];
ifstream inp("AI_Search_2.INP");
bool open[maxn] = {false};

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
	} while (x != beg);
}

bool cmp(int a1, int a2) {
	return a1 > a2;
}

void dfs(){
	open.insert
	while(true) {
		if (duyet.empty) {
			break;
		}
		int res = duyet.top();
		duyet.pop();
		if (res == en) {
			in(); return;
		}
//		sort(ke[res].begin(), ke[res].end(), cmp);
		for (auto x : ke[res]){
			duyet.push(x);
			ans[x] = res;
		}
	}
	cout << "Khong ton tai duong di!";
}

int main(){
	cout << "Nhap so dinh: "; inp >> n;
	nhap();
	cout << "Nhap dinh xuat phat: "; cin >> beg;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	dfs();
}
