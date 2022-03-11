#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned int D1, D2;
	double CO1, RE1, DE1, CO2, RE2, CE, DE2, N, A, T, desconto1, desconto2;

	cin >> D1;

	cin >> CO1 >> RE1 >> DE1;

	cin >> D2;

	cin >> CO2 >> RE2  >> CE >> DE2;

	if(D1 < 20 && D1 >= 1 && D1 <= 24){
	    N = ( CO1 + (RE1 - (RE1 * 0.10) ) + (DE1 - (DE1 * 0.15) ) );
	}
	else if(D1 == 20 && D1 >= 1 && D1 <= 24){
	    N = ( (CO1 - (CO1 * 0.12) ) + (RE1 - (RE1 * 0.15) ) + (DE1 - (DE1 * 0.20) ) );
	}
	else if(D1 == 21 && D1 >= 1 && D1 <= 24){
	    N = ( (CO1 - (CO1 * 0.17) ) + (RE1 - (RE1 * 0.22) ) + (DE1 - (DE1 * 0.27) ) );
	}
	else if(D1 == 22 && D1 >= 1 && D1 <= 24){
	    N = ( (CO1 - (CO1 * 0.20) ) + (RE1 - (RE1 * 0.22) ) + (DE1 - (DE1 * 0.30) ) );
	}
	else if(D1 == 23 && D1 >= 1 && D1 <= 24){
	    N = ( (CO1 - (CO1 * 0.25) ) + (RE1 - (RE1 * 0.29) ) + (DE1 - (DE1 * 0.35) ) );
	}
	else if(D1 == 24 && D1 >= 1 && D1 <= 24){
	    N = ( (CO1 - (CO1 * 0.35) ) + (RE1 - (RE1 * 0.35) ) + (DE1 - (DE1 * 0.50) ) );
	}

	if(D2 == 25 && D2 >= 25 && D2 <= 31){
	    A = ( (CO2 - (CO2 * 0.15) ) + (RE2 - (RE2 * 0.13) ) + CE + (DE2 - (DE2 * 0.10) ) );
	}
	else if(D2 == 26 && D2 >= 25 && D2 <= 31){
	    A = ( (CO2 - (CO2 * 0.19) ) + (RE2 - (RE2 * 0.25) ) + (CE - (CE * 0.05) ) + (DE2 - (DE2 * 0.23) ) );
	}
	else if(D2 == 27 && D2 >= 25 && D2 <= 31){
	    A = ( (CO2 - (CO2 * 0.24) ) + (RE2 - (RE2 * 0.30) ) + (CE - (CE * 0.12) ) + (DE2 - (DE2 * 0.33) ) );
	}
	else if(D2 == 28 && D2 >= 25 && D2 <= 31){
	    A = ( (CO2 - (CO2 * 0.30) ) + (RE2 - (RE2 * 0.32) ) + (CE - (CE * 0.20) ) + (DE2 - (DE2 * 0.35) ) );
	}
	else if( (D2 == 29 && D2 >= 25 && D2 <= 31) || (D2 == 30) ){
	    A = ( (CO2 - (CO2 * 0.35) ) + (RE2 - (RE2 * 0.40) ) + (CE - (CE * 0.33) ) + (DE2 - (DE2 * 0.42) ) );
	}
	else if(D2 == 31 && D2 >= 25 && D2 <= 31){
	    A = ( (CO2 - (CO2 * 0.40) ) + (RE2 - (RE2 * 0.47) ) + (CE - (CE * 0.45) ) + (DE2 - (DE2 * 0.66) ) );
	}

	T = N + A;

	cout.precision(2);
	cout << fixed;
	cout << "Compras de natal: R$ " << N << ".\n";
	cout << "Compras de ano novo: R$ " << A << ".\n";
	cout << "Total das compras: R$ " << T << ".";


}

