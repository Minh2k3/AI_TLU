// AI : Min-Max

// Y tuong : Xay dung mot cau truc node
//			 Moi node chua gia tri cua node, so con cua node,
//			 quan li cac con cua node
//			 Dpt khi tim gia tri cua mot node bat ki la O(n)
//			 Khi xay dung de quy den node la roi di dan len

#include <bits/stdc++.h>
using namespace std;

#define each(x, a) 	   		for (auto x : a)
#define SortA(ar,s)    		sort(ar, ar + s)
#define SortD(ar,s)   	 	sort(ar, ar + s, greater<int>())
#define FOR(i,x,y)			for (int i = x; i < y; ++i)
#define FOR_(i,x,y)			for (int i = y; i > x; --i)
#define nl        			'\n'
#define precision(x)      	cout << fixed << setprecision(x)
#define nel               	cout << nl
#define all(v)		   		v.begin(), v.end()

#define pb(x)             push_back(x)
#define is(x)			  insert(x)
#define min3(a,b,c)       min(a, min(b, c))
#define max3(a,b,c)       max(a, max(b, c))
#define mina(arr, n)	  *min_element(arr, arr + n)
#define maxa(arr, n)	  *max_element(arr, arr + n)
#define minv(v)			  *min_element(all(v))
#define maxv(v)			  *max_element(all(v))

typedef long long int ll;
typedef unsigned long long int llu;
const ll MOD = (ll)1e9+7;
const int MAXN = (int)200003;
const ll INF = (ll)1e18;

// Khai bao cac bien, hang su dung toan cuc
ifstream inp("Ai_Search_8.INP");

struct node {
	ll elem, numOfSon;
	vector<node> son;	
};

// Phan khai bao ham
void build(node &t, ll depth){
	cout << "Nhap so node con: "; inp >> t.numOfSon;
	if (t.numOfSon) {
		FOR(i,0,t.numOfSon) {
			node x;
			build(x, depth + 1);
			t.son.pb(x);
		}
		if (depth & 1) {
			t.elem = INF;
			each(son,t.son) {
				t.elem = min(t.elem, son.elem);
			}
		}
		else {
			t.elem = -INF;
			each(son, t.son) {
				t.elem = max(t.elem, son.elem);
			}
		}
	}
	else {
		cout << "Nhap gia tri tai node: "; inp >> t.elem;
	}
}

// Chuong trinh chinh
int main(){
	// Mac dinh nut goc la MAX
	node root;
	build(root, 0);
	cout << "\n\nGia tri tai goc la: " << root.elem << nl;
}

/*

'########:'########:::::'###::::'##::: ##::::'##::::'##:'####:'##::: ##:'##::::'##:
... ##..:: ##.... ##:::'## ##::: ###:: ##:::: ###::'###:. ##:: ###:: ##: ##:::: ##:
::: ##:::: ##:::: ##::'##:. ##:: ####: ##:::: ####'####:: ##:: ####: ##: ##:::: ##:
::: ##:::: ########::'##:::. ##: ## ## ##:::: ## ### ##:: ##:: ## ## ##: #########:
::: ##:::: ##.. ##::: #########: ##. ####:::: ##. #: ##:: ##:: ##. ####: ##.... ##:
::: ##:::: ##::. ##:: ##.... ##: ##:. ###:::: ##:.:: ##:: ##:: ##:. ###: ##:::: ##:
::: ##:::: ##:::. ##: ##:::: ##: ##::. ##:::: ##:::: ##:'####: ##::. ##: ##:::: ##:
:::..:::::..:::::..::..:::::..::..::::..:::::..:::::..::....::..::::..::..:::::..::

*/
