#include <iostream>
#include <cmath> 
using namespace std;

int soma = 0; 

void somaDeQuadrados(int *V, int n, int nq, int aux);
void imprimir(int *V);

void somaDeQuadrados(int *V, int n, int nq, int aux){
	if(soma <= n){
		if(soma == n)	
			imprimir(V);	
		else{
			for(int i = aux; i >= 1 && nq >= 0; i--){
				V[nq] = i ;	
				soma += pow(i,2);	
				nq--;	
				somaDeQuadrados(V, n, nq, i);
				nq++;	
				soma-= pow(i,2);	
				V[nq] = 0;	
			}
		}
	}
}
void imprimir(int *V){
	cout<<"{";		
	for(int i = 0; i<=3 ; i++) 
		cout<<V[i]<<" ";		
	cout<<"} ";
}
int main(){
	int V[4]= {0,0,0,0};
	int nq = 3; 
	int n;
	cin>>n;
	int aux = sqrt(n);	
	somaDeQuadrados(V,n,nq, aux);
	return 0;
}
