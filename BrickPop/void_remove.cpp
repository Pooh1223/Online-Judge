void remove(){
	int temp[10];
	for(int i=9;i>=0;i--){
		for(int h=0;h<10;h++){
			if(a[i][h]==0){
				for(int k=i-1;k>=0;k--){
					temp[k]=a[k][h];	
				}
				for(int n=i-1;n>=0;n--){
					a[n+1]=temp[n];	
				}
			}
		}
	}
	for(int i=8;i>=0;i--){
		if((a[0][i]==0)&&(a[1][i]==0)&&(a[2][i]==0)&&(a[3][i]==0)&&(a[4][i]==0)&&(a[5][i]==0)&&(a[6][i]==0)&&(a[7][i]==0)&&(a[8][i]==0)&&(a[9][i]==0)){
			for(int k=0;k<10;k++){
				a[k][i+1]==a[k][i];
			}
    	}
	}
	
}
