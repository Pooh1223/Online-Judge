int kmp(string s1,string s2){
	if(s2.length() > s1.length()) return 0;
	int cnt = 0;
	f[0] = -1;
	int p = -1;
	//////// failure function
	for(int i = 1;s2[i];++i){
		if(s2[i] == s2[p]) f[i] = f[p];
		while(p != -1 && s2[p + 1] != s2[i]) p = f[p];
	 	if(s2[p + 1] == s2[i]) p++;
		f[i] = p;
	}
	////////
	/////////// KMP
	p = -1;
	for(int i = 0;s1[i];++i){
		while(p != -1 && s2[p + 1] != s1[i]) p = f[p];
		if(s2[p + 1] == s1[i]) p++;
		if(!s2[p + 1]){
			cnt++;
			p = f[p];
		}
	}
	return cnt;
}