#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int t, x, y, z, n, k, flag;
	int a[50], b[50], c[50];
	vector<int> v1, v2, v3;
	cin >> t;
	for (int zz = 1; zz <= t; zz++) {
		v1.push_back(0);
		v2.push_back(0);
		v3.push_back(0);
		cin >> x >> y >> z;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				v1.push_back(a[i] + v1[j]);
			}
			k = v1.size();
		}
		k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				v2.push_back(b[i] + v2[j]);
			}
			k = v2.size();
		}
		k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				v3.push_back(c[i] + v3[j]);
			}
			k = v3.size();
		}
		flag = 0;
		for (int i = 0; i < k; i++) {
			if (v1[i] == x && v2[i] == y && v3[i] == z)
				flag = 1;
		}
		cout << "Case #" << zz << ": ";
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
		v1.clear();
		v2.clear();
		v3.clear();
	}
	return 0;
}