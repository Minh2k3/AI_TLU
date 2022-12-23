// AI : Best First Search

// Y tuong :	Tuong tu nhu cac thuat toan truoc
//				Nhung khi duyet Open can sap xep lai theo h(u)

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
ifstream	inp("AI_Search_4.INP");
int n, be, en, ans[maxn] = {0};
pair<int, vector<int> > node[maxn];
bool check[maxn] = {false};
vector<int> open;

void nhap(){
	for (int i = 1; i <= n; ++i) {
		cout << "Nhap gia tri cua node: "; inp >> node[i].first;
		vector<int> res;
		cout << "Nhap cac node ke voi node " << i << ": ";
		while(true){
			int x; inp >> x; 
			if (x == 0) break;
			res.push_back(x);
		}
		node[i].second = res;
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

bool cmp(int t1, int t2){
	return node[t1].first < node[t2].first;
}

void bfs(int t){
	if (t == en) {
		in();
		return;
	}
	for (auto x : node[t].second) {
		if (!check[x]) {
			open.push_back(x);
			ans[x] = t;
			check[x] = true;
		}
	}
	sort(open.begin(), open.end(), cmp);
	cout << "Xet tai node " << t << ": ";
	for (auto x : open) {
		cout << x << " ";
	}
	cout << "\n";
	if (open.size() == 0) {
		cout << "Khong ton tai duong di!\n";
	}
	else {
		int x = open[0];
		open.erase(open.begin());
		bfs(x);
	}
}

int main(){
	cout << "Nhap so node: "; inp >> n;	// n <= 100
	nhap();
	cout << "\nNhap diem bat dau: "; cin >> be;
	cout << "Nhap diem ket thuc: "; cin >> en;
	check[be] = true;
	bfs(be);
}

// Kiem tra gia tri tai node va cac node ke voi node hien tai
//	for (int i = 1; i <= n; ++i) {
//		cout << node[i].first << " ";
//		for (auto x : node[i].second) {
//			cout << x << " ";
//		}
//		cout << "\n";
//	}
