#include <bits/stdc++.h>
using namespace std;

long long coin(int N, long long val[], long long str[]){
	if (N==0){
	     return 0;
	}
	if (N==1){
	     return val[1];
	} 
    else{
		long long tmp1, tmp2;
		if (str[N-1] == -1){
			tmp1 = coin(N-1, val, str);
			str[N-1] = tmp1;
		}
		else{
		     tmp1 = str[N-1];
		}
		if (str[N-2] == -1){
			tmp2 = coin(N-2, val, str);
			str[N-2] = tmp2;
		}
		else{
		     tmp2 = str[N-2];
		}
		return max(val[N] + tmp2, tmp1);
	}
}

int main(){
    long long N;
	cin>>N;
	long long value[N+1], str[N+1];
	for (int i=1; i<=N; i++){
		cin >> value[i];
		str[i] = -1;
	}
	str[0] = 0;
	str[1] = value[1];
	cout << coin(N, value, str);
}