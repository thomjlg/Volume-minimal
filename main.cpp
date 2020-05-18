#include<iostream>
#include"fct.h"
#include<math.h>
using namespace std;

int main() {
	unsigned long long int Vmin;
	lLh vol;
	cout << "Entrez la valeur du volume minimal que vous souhaitez : ";
	cin >> Vmin;
	
	vol = Surface_min(Vmin);
	cout << "Pour un volume minimal de "<<Vmin<<", on a un parallelepipede rectangle de longueur " << vol.L << ", de largeur " << vol.l << " et de hauteur " << vol.h << "." << endl;
	cout << "On a un volume de " << vol.L*vol.l*vol.h << endl;
	cout << "On a une surface de " << 2 * (vol.L*vol.l + vol.L*vol.h + vol.l*vol.h) << endl;
	system("pause");
	return 0;
}
