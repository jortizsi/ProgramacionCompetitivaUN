#include <iostream>
#include <bits/stdc++.h>
using namespace std;

	
	
	/*
	ENUNCIADO

	B - QAQ CodeForces - 894A 



	"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters of length n. There is a great number of "QAQ" in the string (Diamond is so cute!).

 illustration by ?? https://twitter.com/nekoyaliu
Bort wants to know how many subsequences "QAQ" are in the string Diamond has given. Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.



Input
The only line contains a string of length n (1?=?n?=?100). It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.

Examples
Input
QAQAQYSYIOIWIN
Output
4
Input
QAQQQZZYNOIWIN
Output
3
Note
In the first example there are 4 subsequences "QAQ": "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN".
	*/
	
	
	
	
	/*
	Solucion
	este es un problema combinatorio.
	Se itera por todos las A's y se multilplican el numero de Q's a la izquierda por el de la derecha.
	*/



     int contar_Qs(string cadena){
        return count(cadena.begin(),cadena.end(),'Q');
     }


int main()
{


     string s;
     cin >> s;


     int Qsderecha = contar_Qs(s);
     int Qsizquierda = 0;
     int acumulador = 0;

     for(int i = 0; i<s.length();i++){

            if (s.at(i)=='Q'){
                    Qsizquierda++;
                    Qsderecha--;
            }else if(s.at(i)=='A'){
                acumulador = acumulador +  (Qsizquierda * Qsderecha);
            }


     }
     

     cout<<acumulador;

}
