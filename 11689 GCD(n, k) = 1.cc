#include <iostream>
#include <vector>

using namespace std;

long long N, ans=1;
vector<pair<long long,long long> > prime;
bool isupdate;

int main(){
	scanf("%lld",&N);
	
	prime.push_back({1,1});
	while(N>1){
		isupdate = false;
		for(long long i=2; i*i<=N; i++){
			if(N%i == 0){
				isupdate = true;
				if(prime.back().first == i) prime.back().second++;
				else prime.push_back({i,1});
				N /= i;
				break;
			}
		}
		
		if(!isupdate){
			if(prime.back().first == N) prime.back().second++;
			else prime.push_back({N,1});
			N /= N;
		}
	}
	
	vector<pair<long long,long long> >::iterator it;
	for(it= ++prime.begin(); it<prime.end(); it++){
		long long tmp = (*it).first-1;
		for(int i=1; i<(*it).second; i++) tmp *= (*it).first;
		
		ans *= tmp;
	}
	
	printf("%lld",ans);
	return 0;
}