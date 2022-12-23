// AI: BFS

// Y tuong:		Su dung hang doi

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;	// MAX la 100 dinh
vector<int> ke[maxn];
int n, beg, en;
queue<int> duyet;
int ans[maxn];
ifstream inp("AI_Search_2.INP");
bool open[maxn] = {false};
vector<int> close;

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

bool inClose(int t) {
	for (auto x : close) {
		if (x == t) return true;
	}
	return false;
}

void bfs(){
	duyet.push(beg); 
	open[beg] = true;
	while(true) {
		if (duyet.empty())
			break;
		int res = duyet.front();
		duyet.pop();
		open[res] = false;
		close.push_back(res);
		if (res == en) 
			break;		
		for (auto x : ke[res]) {
			if (!inClose(x) && !open[x]) {
				duyet.push(x);
				open[x] = true;
				ans[x] = res;
			}
		}
	}
	cout << "OPEN: ";
	while(!duyet.empty()){
		cout << duyet.front() << " ";
		duyet.pop();
	}
	cout << "\nCLOSE: ";
	for (auto x : close) {
		cout << x << " ";
	}
	cout << "\n";
	if (close[close.size()-1]){
		in();
	}
	else
		cout << "Khong ton tai duong di!\n";
}

int main(){
	cout << "Nhap so dinh: "; inp >> n;
	nhap();
	cout << "Nhap dinh xuat phat: "; cin >> beg;
	cout << "Nhap dinh ket thuc: "; cin >> en;
	bfs();
}
