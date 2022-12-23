#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;

#define Faster		ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define Sort(x)        sort(x.begin(), x.end())
#define SortR(x)       sort(x.begin(), x.end(), greater<int>())
#define Reverse(x)     reverse(x.begin(), x.end())
#define each(x, a) 	   for (auto x : a)
#define vii			   vector<int>
#define pii			   pair<int, int>
#define all(v)		   v.begin(), v.end()

#define Sum(A,n)       accumulate(A, A + n, 0)
#define SortA(ar,s)    sort(ar, ar + s)
#define SortD(ar,s)    sort(ar, ar + s, greater<int>())
#define maxa(A,n)      *max_element(A, A + n)
#define mina(A,n)      *min_element(A, A + n)
#define maxv(v)		   *max_element(all(v))
#define minv(v)		   *min_element(all(v))
#define gcd(a,b)       __gcd(a, b)
#define lcm(a,b)       (a * (b/gcd(a, b)))
#define sq(x)          (x) * (x)
#define mid(l,r)       (l + r / 2)
#define log(x,y)	   (log(x) / log(y))

#define min3(a,b,c)       min(a, min(b, c))
#define min4(a,b,c,d)     min(a, min(b, min(c, d)))
#define max3(a,b,c)       max(a, max(b, c))
#define max4(a,b,c,d)     max(a, max(b, max(c, d)))
#define pb(x)             push_back(x)
#define is(x)			  insert(x)

#define FOR(i,x,y)		for (int i = x; i <= y; i++)
#define FOR_(i,x,y)		for (int i = y; i >= x; i--)
#define For(i,s,e,d)	for (int i = s; i <= e; i+=d)
#define For_(i,s,e,d)	for (int i = s; i >= e; i-=d)
#define forcin(x,a)		each(&x,a) cin >> x

#define nl        		  '\n'
#define precision(x)      cout << fixed << setprecision(x)
#define nel               cout << nl
#define yes               cout << "YES\n"
#define no                cout << "NO\n"
#define yesre             yes; return
#define nore              no; return

#define readi(t)		int t; cin >> t
#define readll(t)		ll t; cin >> t
#define reads(t)		string t; cin >> t
#define readis(n, m)	readi(n); readi(m)
#define readlls(n, m)	readll(n); readll(m)

#define test(t)			readi(t); 		\
						while(t--){		\
							solve();	\
						}

typedef long long int ll;
typedef unsigned long long int llu;

const ll MOD = (ll)1e9+7;
const int MAXN = (int)200003;
const ll INF = (ll)1e18;

void solve(){
	vector<int> v = {2, 6, 9, 7, 4, 5, 8, 3, 1};
	int x = minv(v);
	cout << x;
}

int main(){
	Faster;
//	test(t);
	solve();
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
