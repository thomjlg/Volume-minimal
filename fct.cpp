#include<iostream>
#include"fct.h" //pour inclure la déclaration de la fonction
#include<math.h> //pour utiliser la fonction pow(x, y)
using namespace std; // pour utiliser cin, cout et endl

lLh   Surface_min(unsigned long long int Vmin) { //définition de la fonction Surface_min
	lLh volume; //déclaration d'une variable lLh composée pour la retourner à la fin de la fonction
	float racine_volume; // variable réelle car on y affecte une racine cubique
	unsigned long long int valeur_racine; // variable entière pour la partie entière de la racine cubique
	unsigned long long int t; // variable entière pour l'intervalle de calcul pour trouver la surface min 
	unsigned long long int surface; // variable entière initialisée assez grande pour en trouver une plsu petite à la fin
	unsigned long long int r; // variable entière qui représentera volume.l dans la boucle for
	unsigned long long int q; // variable entière qui représentera volume.h dans la boucle for
	unsigned long long int i, j, k, a; // i,j et k servent à trouver les dimensions de l, L et h ; a représente un volume
	
	volume.l = 0; // initialisation de la largeur à 0 
	volume.L = 0; // initialisation de la longueur à 0
	volume.h = 0; // initialisation de la hauteur à 0
	
	surface = 0llu; //initialisation de la surface retournée à la fin
	racine_volume = pow(Vmin, 1.0 / 3); //racine cubique de Vmin (volume minimal)
	valeur_racine= floor(racine_volume); //partie entière de la racine cubique de Vmin
	cout << "La racine cubique du volume minimal " << Vmin << " est egale a : " << valeur_racine << endl; 
	//affichage de la racine cubique
	
	if (pow(valeur_racine, 3) == Vmin) { // 1er cas : si on a un cube parfait, alors on sort de la boucle directement
		volume.L = valeur_racine; // sans faire tous les calculs
		volume.l = valeur_racine; // lLh sont donc identiques
		volume.h = valeur_racine;
		cout << endl << "Cela correspond a un cube parfait !" << endl << endl;
	}
	else { //boucle si ce n'est pas un cube parfait
		if (valeur_racine < 1501) { // 1er cas : si la racine cubique < 1501
			volume.L = 1; // initailisation de la longueur, la largeur et la hauteur
			volume.l = 1;
			volume.h = 1;
			t = valeur_racine * 2; // intervalle de recherche de valeurs avec la racine cubique
			surface = pow(valeur_racine + 2, 3); // initialisation d'une surface grande pour trouver une plus petite après
		}
		else { // 2ème cas : pour les racines cubiques > 1500
			volume.L = valeur_racine - 1500; // on soustrait 1500 a la valeur de la racine cubique
			volume.l = valeur_racine - 1500; // et on initialise la Longueur, la largeur 
			volume.h = valeur_racine - 1500; // et la hauteur
			t = 3000; // intervalle de calculs pour trouver la surface minimale
			surface = (volume.L*volume.l + volume.L*volume.h + volume.l*volume.h)*(volume.L*volume.l + volume.L*volume.h + volume.l*volume.h)*(volume.L*volume.l + volume.L*volume.h + volume.l*volume.h);
			// ici, on donne a surface une valeur importante pour pouvoir trouver la plus petite valeur par la suite
		}
		r = volume.l; // initialisation de variables qui vont servir a trouver la surface min
		q = volume.h; // initialisation pour ne pas perdre la valeur precedement rentrée dans volume.l et volume.h
		// r et q seront modifiées dans les boucles for
		for (i = volume.L; i <= (volume.L + t); i = i + 1) { // pour i allant de volume.L a volume.L+t
			q = i;
			r = i;
			for (j = r; j <= (volume.l + t); j = j + 1) { // pour j allant de r à volume.l+t
				q = j;
				for (k = q; k <= (volume.h + t); k = k + 1) { // pour k allant de q à volume.h+t
					a = i*j*k; // calcul du volume avec tous les cas possibles suite aux 3 boucles for
					if (a >= Vmin) { // on regarde si le volume trouvé est plus grand que le volume minimal
						if ((2 * (i*j + i*k + j*k)) <= surface) { // si il est plus grand, on regarde si la surface trouvée
							volume.L = i; // est bien plus petite que celle initialisée au début
							volume.l = j; // si c'est le cas, on change la valeur de la longueur, de la largeur
							volume.h = k; // et de la hauteur
							surface = 2 * (i*j + i*k + j*k); // et on donne une nouvelle valeur à la surface à partir
							// des nouvelles valeurs de la longueur, de la hauteur et de la largeur
						}
					}
				}
			}
		} // on continue la boucle tant que le volume trouvé est plus grand que le volume minimal
	} // dès que le volume trouvé est plus petit, on affiche le dernier volume trouvé plus grand que le volume minimal
	return volume; // on retourne le type composé volume (lLh)
}
