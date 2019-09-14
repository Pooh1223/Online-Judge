#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& s){
    // ���o���P�_���S��
    if (s.size() == 0) return 0;
 
    // ����J�@�ӼƦr�A�K�o�y�� v.back() �X���C
    vector<int> v;
    v.push_back(s[0]);
 
    for (int i = 1; i < s.size(); ++i){
        int n = s[i];
        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }
    return v.size();
}

int main(){
	vector<int> num;
	int a,b;
	cin >> a;
	while(a--){
		cin >> b;
		num.push_back(b);
	}
	cout << LIS(num) << "\n";
	return 0;
}
