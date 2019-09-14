void rec(int n,int dx,int dy,int x,int y){
	if(n == 2){
		if(x == dx && y == dy) Report(dx,dy - 1,dx - 1,dy,dx - 1,dy - 1);
		else if(x == dx - 1 && y == dy) Report(dx,dy,dx,dy - 1,dx - 1,dy - 1);
		else if(x == dx && y == dy - 1) Report(dx,dy,dx - 1,dy,dx - 1,dy - 1);
		else if(x == dx - 1 && y == dy - 1) Report(dx,dy,dx - 1,dy,dx,dy - 1);
		return;
	}
	if(x <= dx - n / 2 && y <= dy - n / 2){
		Report(dx - n / 2,dy - n / 2 + 1,dx - n / 2 + 1,dy - n / 2,dx - n / 2 + 1,dy - n / 2 + 1);
		rec(n / 2,dx - n / 2,dy - n / 2,x,y);
		rec(n / 2,dx - n / 2,dy,dx - n / 2,dy - n / 2 + 1);
		rec(n / 2,dx,dy - n / 2,dx - n / 2 + 1,dy - n / 2);
		rec(n / 2,dx,dy,dx - n / 2 + 1,dy - n / 2 + 1);
	}
	else if(x <= dx - n / 2 && y > dy - n / 2){
		Report(dx - n / 2,dy - n / 2,dx - n / 2 + 1,dy - n / 2,dx - n / 2 + 1,dy - n / 2 + 1);
		rec(n / 2,dx - n / 2,dy - n / 2,dx - n / 2,dy - n / 2);
		rec(n / 2,dx - n / 2,dy,x,y);
		rec(n / 2,dx,dy - n / 2,dx - n / 2 + 1,dy - n / 2);
		rec(n / 2,dx,dy,dx - n / 2 + 1,dy - n / 2 + 1);
	}
	else if(x > dx - n / 2 && y <= dy - n / 2){
		Report(dx - n / 2,dy - n / 2,dx - n / 2,dy - n / 2 + 1,dx - n / 2 + 1,dy - n / 2 + 1);
		rec(n / 2,dx - n / 2,dy - n / 2,dx - n / 2,dy - n / 2);
		rec(n / 2,dx - n / 2,dy,dx - n / 2,dy - n / 2 + 1);
		rec(n / 2,dx,dy - n / 2,x,y);
		rec(n / 2,dx,dy,dx - n / 2 + 1,dy - n / 2 + 1);
	}
	else {
		Report(dx - n / 2,dy - n / 2,dx - n / 2,dy - n / 2 + 1,dx - n / 2 + 1,dy - n / 2);
		rec(n / 2,dx - n / 2,dy - n / 2,dx - n / 2,dy - n / 2);
		rec(n / 2,dx - n / 2,dy,dx - n / 2,dy - n / 2 + 1);
		rec(n / 2,dx,dy - n / 2,dx - n / 2 + 1,dy - n / 2);
		rec(n / 2,dx,dy,x,y);
	}
}
void solve(int N,int X,int Y){
	rec(N,N,N,X,Y);
}