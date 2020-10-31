#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <iterator>
#include <cmath>

using namespace std;


/*
La idea de solucion es distribuir a las personas que llegan en aquellas bancas que tienen el 
menor numero de personas .

una vez estas bancas se llenan al punto de que tienen tantas personas como el siguiente numero menor entonces se distribuyen personas en las bancas con el menor numero actual.
Se itera hasta que todas las personas se hayan sentado.
*/




int main()
{
    set <int> sentados;
    

    int solucion = -9; //numero para identificar errores en la solucion
    int minimo;
    int recangleWide[101] = {0};
    int PersonsOcurrence[10101];

    int bancas;
    int visitantes_nuevos;
    int n;


    cin>>bancas;
    cin>>visitantes_nuevos;

    for(int i =0;i<bancas;i++){
        cin>>n;
        PersonsOcurrence[n] += 1 ;
        sentados.insert(n);
    }


	int todos_los_visitantes = visitantes_nuevos;
	
    int limite_inferior;
    int limite_siguiente;

    bool seguir = true;

    limite_inferior =0;

    set <int> :: iterator itr;
    set <int> :: iterator Next;

    Next = sentados.begin();
    if(sentados.size()>1){
        Next++;
    }else{
        int mejor_disponibilidad = *sentados.begin();
        int personas_nuevas_por_banca = visitantes_nuevos / PersonsOcurrence[mejor_disponibilidad];
                int personas_extra_una_banca = visitantes_nuevos % PersonsOcurrence[mejor_disponibilidad];
                int sobran =0;
                if(personas_extra_una_banca>0){
                    sobran = 1;
                }
                solucion = mejor_disponibilidad + personas_nuevas_por_banca + sobran;
        seguir = false;
        //Next = itr;
    }


    for (itr = sentados.begin(); Next != sentados.end() && seguir ; ++itr)
    {
        int mejor_disponibilidad = *itr;
        int siguiente_mejor_disponibilidad = *Next;
        int campo_por_silla = siguiente_mejor_disponibilidad - mejor_disponibilidad;


        int personas_que_se_pueden_sentar = campo_por_silla * PersonsOcurrence[mejor_disponibilidad];


        //Si termino
        if(visitantes_nuevos <= personas_que_se_pueden_sentar){

                int personas_nuevas_por_banca = visitantes_nuevos / PersonsOcurrence[mejor_disponibilidad];
                int personas_extra_una_banca = visitantes_nuevos % PersonsOcurrence[mejor_disponibilidad];
                int sobran =0;
                if(personas_extra_una_banca>0){
                    sobran = 1;
                }
                solucion = mejor_disponibilidad + personas_nuevas_por_banca + sobran;
                //int bancas_a_usar_completas = (int)(visitantes_nuevos/campo_por_silla);
                //int extras = (int)(visitantes_nuevos % campo_por_silla);
                seguir = false;

        }else{

            visitantes_nuevos -= personas_que_se_pueden_sentar;

            PersonsOcurrence[siguiente_mejor_disponibilidad] += PersonsOcurrence[mejor_disponibilidad];


        }


        Next++;
        //productos *= (long double)1.0 -( (long double)1.0 /((long double)*itr) );
        //cout<<"en lista "<<*itr<<"\n";
    }

    if(solucion<0){
        int mejor_disponibilidad = *itr;
        int personas_nuevas_por_banca = visitantes_nuevos / PersonsOcurrence[mejor_disponibilidad];
                int personas_extra_una_banca = visitantes_nuevos % PersonsOcurrence[mejor_disponibilidad];
                int sobran =0;
                if(personas_extra_una_banca>0){
                    sobran = 1;
                }
                solucion = mejor_disponibilidad + personas_nuevas_por_banca + sobran;
        //seguir = false;
    }
    
    
    cout << max(solucion,*sentados.rbegin()) << " " <<(*sentados.rbegin() + todos_los_visitantes) ;

    return 0;
}
