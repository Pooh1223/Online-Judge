#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin >> a;
	cin >> b;
	int lena = a.length();
	int lenb = b.length();
	//if(lena < lenb) swap(a,b);
	reverse(a.begin(),a.end());
	cout << a << "\n";
	reverse(b.begin(),b.end());
	cout << b << "\n";
	int next = 0;
	for(int i = 0;i < lenb;++i){
		int num = 0;
		num += (a[i] - '0') + (b[i] - '0') + next;
		cout << i << " : " << num << "\n";
		next = 0;
		if(num >= 10){
			num -= 10;
			++next;
		}
		a[i] = (char)(num + '0');
		cout << a[i] << "\n";
	}
	for(int i = lenb;i < lena;++i){
		int num = 0;
		num = (a[i] - '0') + next;
		next = 0;
		if(num >= 10){
			num -= 10;
			++next;
		}
		a[i] = (char)(num + '0');
	}
	if(next > 0) a += (char)(next + '0');
	reverse(a.begin(),a.end());
	cout << a;
	return 0;
}