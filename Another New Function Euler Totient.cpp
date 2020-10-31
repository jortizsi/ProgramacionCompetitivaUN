#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <iterator>
#include <cmath>

using namespace std;


int DP_PhiEuler[ 2000001] = {0};
int DP_PhiDepthEuler[ 2000001] = {0};


/*
Este ejercicio usa a totient function de euler para calcular depth of phi de forma eficiente.
Adicionalmente se usa un arreglo tipo programacion dinamica para evitar el recalculo de operaciones.
*/

//*********************************************************************************************
//Funcion para obtener factores primos adaptada fde geeksforgeeks
set <int, greater <int> > FactoresPrimos(int n)
{
    set <int, greater <int> > factores;

    while (n % 2 == 0)
    {
        factores.insert(2);
        n = n/2;
    }


    for (int i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            factores.insert(i);
            n = n/i;
        }
    }


    if (n > 2){
        factores.insert(n);
    }
    return factores;
}

//***************************************************************************************

int Phi(int n){
    //cout<<"_______________________"<<"\n";
    //cout<<"calculando "<<n<<"\n";

    if(DP_PhiEuler[n]>0){
        return DP_PhiEuler[n];
    }else{

    set <int, greater <int> > FP = FactoresPrimos(n);
    set <int, greater <int> > :: iterator itr;
    long double productos = 1;

    for (itr = FP.begin(); itr != FP.end(); ++itr)
    {
        productos *= (long double)1.0 -( (long double)1.0 /((long double)*itr) );
        //cout<<"en lista "<<*itr<<"\n";
    }
    //cout<<"productos "<<productos<<"\n";
    productos *= n;
    //cout<<"productos *n "<<productos<<"\n";
    DP_PhiEuler[n] = round(productos);
    return DP_PhiEuler[n];
    }
    //cout<<"_______________________"<<"\n";
}



int depthPhi(int n){
    if(DP_PhiDepthEuler[n]>0){
        return DP_PhiDepthEuler[n];
    }else{
    int solucion = 0;
    int actual = n;
    while(actual !=1){
            actual = Phi(actual);
            solucion++;
        }

    DP_PhiDepthEuler[n] = solucion;
    return DP_PhiDepthEuler[n];
    }
}



int sumaDepth(int inicio,int fin){
    int acumulador = 0;
    for(int i = inicio;i<=fin;i++){
        acumulador += depthPhi(i);
    }
    return acumulador;
}






int main()
{


    int casos;
    cin>>casos;
    int inicio,fin;


    for(int i =0; i<casos;i++){
        cin>>inicio>>fin;
        //cout<<sumaDepth(inicio, fin)<<"\n";
        cout<<sumaDepth(inicio, fin)<<"\n";
    }



}
