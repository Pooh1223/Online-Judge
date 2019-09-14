#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll pa,pb,na,nb;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll sum = 1;
	
	int n;
	cin >> n;
	int last;
	for(int i = 0;i < n;++i){
		cin >> na >> nb;
		if(!i){
			pa = na;
			pb = nb;
			if(min(na,nb)) sum += min(na,nb);
			last = min(na,nb);
		} else {
			if(na || nb){
				if(nb < pa || na < pb){
					pa = na;
					pb = nb;
					continue;
				} else {
					if(na > nb){
						if(pa >= pb){
							sum += nb - pa + (int)(last != pa);
							last = nb;
						} else {
							sum += nb - pb + (int)(last != pb);
							last = nb;
						}
					} else if(na >= pb){
						if(pa >= pb){
							sum += na - pa + (int)(last != pa);
							last = na;
						} else {
							sum += na - pb + (int)(last != pb);
							last = na;
						}
					} else if(nb > na){
						if(pb >= pa){
							sum += na - pb + (int)(last != pb);
							last = na;
						} else {
							sum += na - pa + (int)(last != pa);
							last = na;
						}
					} else if(nb >= pa){
						if(pb >= pa){
							sum += nb - pb + (int)(last != pb);
							last = nb;
						} else {
							sum += nb - pa + (int)(last != pa);
							last = nb;
						}	
					} 
				}
				pa = na;
				pb = nb;
			}
		}
	}

	cout << sum << "\n";
	
	return 0;
}