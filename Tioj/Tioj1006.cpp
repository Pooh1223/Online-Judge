#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,b10[10];
ll numa,numb;
ll square(int a,int b){
	if(b == 0) return 1;
	if(b == 1) return a;
	if(b % 2 == 0) return square(a,b / 2) * square(a,b / 2);
	else return square(a,b / 2) * square(a,b / 2) * a;
}
string add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int lena = a.length();
	int lenb = b.length();
	int next = 0;
	for(int i = 0;i < lenb;++i){
		int num = 0;
		num += (a[i] - '0') + (b[i] - '0') + next;
		//cout << i << " : " << num << "\n";
		next = 0;
		if(num >= 10){
			num -= 10;
			++next;
		}
		a[i] = (char)(num + '0');
		//cout << a[i] << "\n";
	}
	//next = 0;
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
	return a; 
}
bool search(string a,string b){
	int lena = a.length();
	int lenb = b.length();
	if(lenb > lena) return 0;
	else if(lena > lenb) return 1;
	for(int i = 0;i < lena;++i){
		if(a[i] > b[i]) return 1;
		else if(b[i] > a[i]) return 0;
	}
}
int main(){
	cin >> a;
	cin >> b;
	int cnt = b.length() - 1,top = 0;
	for(int i = 1;i < 10;++i){
		if(i == 1) b10[i] = b;
		else {
			b10[i] = add(b10[i - 1],b10[1]);
			cout << b10[i] << "\n";
		}
	}
	while(1){
		bool bigger = 0;
		for(int i = 0;i <= cnt;++i){
			if(a[i] > b[i]){
				bigger = 1;
				break;
			} else if(a[i] < b[i]){
				break;
			}
		}
		if(!bigger) ++cnt;
		string ram;
		for(int i = top;i < cnt;++i) ram += a[i];
		int l = 1,r = 9;
		while(l < r){
			int m = (l + r) / 2;
			if(search(ram,b10[m])) r = m;
			else l = m + 1;
		}
		
	}
	return 0;
}