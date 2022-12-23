// AI : Hill Climbing

// Y tuong : 	Tuong tu Best First Search va Beam
//				Nhung voi moi dinh dang duyet thi chen vao danh sach L
//				Sap xep lai L theo h(u) roi chen vao dau Open

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

void hc(int t){
	if (t == en) {
		in();
		return;
	}
	vector<int> L;
	for (auto x : node[t].second) {
		if (!check[x]) {
			L.push_back(x);
			ans[x] = t;
			check[x] = true;
		}
	}
	sort(L.begin(), L.end(), cmp);
	open.insert(open.begin(), L.begin(), L.end());
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
		hc(x);
	}
}

int main(){
	cout << "Nhap so node: "; inp >> n;	// n <= 100
	nhap();
	cout << "\nNhap diem bat dau: "; cin >> be;
	cout << "Nhap diem ket thuc: "; cin >> en;
	check[be] = true;
	hc(be);
}

// Kiem tra gia tri tai node va cac node ke voi node hien tai
//	for (int i = 1; i <= n; ++i) {
//		cout << node[i].first << " ";
//		for (auto x : node[i].second) {
//			cout << x << " ";
//		}
//		cout << "\n";
//	}
