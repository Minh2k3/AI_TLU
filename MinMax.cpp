// AI : Min-Max

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
const int maxn = 101;	// Max so phan tu la 100
int n;
vector<int> f(maxn+1), val(maxn+1);
ifstream inp("Ai_Search_8.INP");
struct node {
	int elem, maxOfSon, minOfSon, numOfSon;
	vector<node> son;	
};


// Phan khai bao ham
void build() {
	cout << "Nhap so node con: "; inp >> t; 
}

void MaxVal(int u) {
	if (son[u].size() == 0) {
		val[u] = f[u];
	}
	else {
		MaxVal[u] = maxv(son[u]);
	}
}

void MinVal(int u) {
	if (son[u].size() == 0) {
		MinVal[u] = f[u];
	}
	else {
		MinVal[u] = minv(son[u]);
	}
}

// Chuong trinh chinh
int main(){
	// Mac dinh nut goc la MAX
	nhap();
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
