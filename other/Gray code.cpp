
int DecimaltoGray(int x){
	return x^(x>>1);
}

int GraytoDecimal(int n){
	int x=n;
	while(x>>=1){
		n^=x;
	}
	return n;
}
