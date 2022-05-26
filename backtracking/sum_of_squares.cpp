#include <iostream>
#include <cmath> 
using namespace std;

int sum = 0; 

void sum_of_squares(int *V, int n, int nq, int assistant);
void show(int *V);

int main(){
	int V[4]= {0,0,0,0};
	int nq = 3; 
	int n;
	cin>>n;
	int aux = sqrt(n);	
	sum_of_squares(V,n,nq, aux);
	return 0;
}

void sum_of_squares(int *V, int n, int nq, int assistant){
	if(sum <= n){
		if(sum == n)	
			show(V);	
		else{
			for(int i = assistant; i >= 1 && nq >= 0; i--){
				V[nq] = i ;	
				sum += pow(i,2);	
				nq--;	
				sum_of_squares(V, n, nq, i);
				nq++;	
				sum -= pow(i,2);	
				V[nq] = 0;	
			}
		}
	}
}

void show(int *V){
	cout<<"{";		
	for(int i = 0; i<=3 ; i++) 
		cout<<V[i]<<" ";		
	cout<<"} ";
}


