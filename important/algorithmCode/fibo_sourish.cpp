#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000010
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second
 
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll> > matrix;
 
const ll mod = 10000007;
int m = 2;
 
matrix mult(matrix A, matrix B) {
	matrix X(m + 1, vector<ll>(m + 1));
	rep(i, m) rep(j, m) rep(k, m)
		X[i][j] = (X[i][j] + A[i][k] * B[k][j]) % mod;
	return X;
}
matrix pow(matrix A, int p) {
	if (p == 1)
		return A;
	if (p & 1)
		return mult(A, pow(A, p - 1));
	matrix B = pow(A, p / 2);
	return mult(B, B);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t, n;
	ll res;
	cin >> t;
	while (t--) {
		cin >> n;
		matrix M(m + 1, vector<ll>(m + 1));
		M[0][0] = 1; M[0][1] = 2;
		M[1][0] = 1; M[1][1] = 0;
		vector<ll> F(m + 1);
		F[0] = 5;
		F[1] = 1;
		res = 0;
		if (n == 1) cout << "1\n";
		else if (n == 2) cout << "5\n";
		else {
			M = pow(M, n - 2);
			rep(i, m)
				res = (res + M[0][i] * F[i]) % mod;
			cout << res << endl;
		}
	}
	return 0;
} 