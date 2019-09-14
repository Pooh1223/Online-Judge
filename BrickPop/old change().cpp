void change(){
	int xx = rl / 2;
	int yy = ud;
	int i = a[yy][xx];
	//up,right,down,left
	char ch;
	while(cin >> ch){
		if(ch == x){
			while(a[yy][xx] != 0){
				a[yy][xx] = 0;
				if((yy == 0 || yy == 9) || (xx == 0 || xx == 9)){//situation 1 + 2
					if(yy == 0 && xx == 0){//left-top corner
						if(a[yy][xx] == a[yy][xx + 1]){//right
							xx++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy + 1][xx]){//down
							yy++;
							a[yy][xx] == 0;
							change();
						}
					}
					else if(yy == 0 && xx == 9){//right-top corner
						if(a[yy][xx] == a[yy + 1][xx]){//down
							yy++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx - 1]){//left
							xx--;
							a[yy][xx] = 0;
							change();
						}
					}
					else if(yy == 9 && xx == 0){//left-bottom corner
						if(a[yy][xx] == a[yy - 1][xx]){//up
							yy--;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx + 1]){//right
							xx++;
							a[yy][xx] = 0;
							change();
						}
					}
					else if(yy == 9 && xx == 9){//right-bottom corner
						if(a[yy][xx] == a[yy + 1][xx]){//up
							yy++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx - 1]){//left
							xx--;
							a[yy][xx] = 0;
							change();
						}
					}
					else if(yy == 0/* && (xx > 0 && xx < 9)*/){//top side
						if(a[yy][xx] == a[yy][xx + 1]){//right
							xx++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy - 1][xx]){//down
							yy--;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx - 1]){//left
							xx--;
							a[yy][xx] = 0;
							change();
						}
					}
					else if(yy == 9/* && (xx > 0 && xx < 9)*/){//bottom side
						if(a[yy][xx] == a[yy + 1][xx]){//up
							yy++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx + 1]){//right
							xx++;
							a[yy][xx] = 0;
							change(); 
						}
						if(a[yy][xx] == a[yy][xx - 1]){//left
							xx--;
							a[yy][xx] = 0;
							change();
						}
					}
					else if(xx == 0/* && (yy > 0 && yy < 9)*/){//left side
						if(a[yy][xx] == a[yy + 1][xx]){//up
							yy++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx + 1]){//right
							xx++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy - 1][xx]){//down
							yy--;
							a[yy][xx] = 0;
							change();
						}
					}
					else if(xx == 9/* && (yy > 0 && yy < 9)*/){//right side 
						if(a[yy][xx] == a[yy + 1][xx]){//up
							yy++;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy - 1][xx]){//down
							yy--;
							a[yy][xx] = 0;
							change();
						}
						if(a[yy][xx] == a[yy][xx - 1]){//left
							xx--;
							a[yy][xx] = 0;
							change();
						}
					}
				}
				else if((yy > 0 && yy < 9) && (xx > 0 && xx < 9)){//situation 3
					if(a[yy][xx] == a[yy + 1][xx]){//up
						yy++;
						a[yy][xx] = 0;
						change();
					}
					if(a[yy][xx] == a[yy][xx + 1]){//right
						xx++;
						a[yy][xx] = 0;
						change();
					}
					if(a[yy][xx] == a[yy - 1][xx]){//down
						yy--;
						a[yy][xx] = 0;
						change();
					}
					if(a[yy][xx] == a[yy][xx - 1]){//left
						xx--;
						a[yy][xx] = 0;
						change();
					}
				}
				else{
					a[yy][xx] = i;
				}
			}
		}
	}
	redraw();
}
