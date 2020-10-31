#EJERCICIO 6 TEORIA DE NUMEROS

"""
______________________________________________________________________
ENUNCIADO


C. Line (Codeforces Beta Round #7)

time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A line on the plane is described by an equation Ax + By + C = 0. You are to 
find any point on this line, whose coordinates are integer numbers from  
- 5·1018 to 5·1018 inclusive, or to find out that such points do not exist.



Input
The first line contains three integers A, B and C 
( - 2·109 ≤ A, B, C ≤ 2·109) — corresponding coefficients of the line equation.
 It is guaranteed that A2 + B2 > 0.

Output
If the required point exists, output its coordinates, otherwise output -1.


Examples

    input
    2 5 3

    output
    6 -3

______________________________________________________________________
"""


#Lectura de las entradas
X,Y,C = map(int, input().split()) 



# La ecuacion es de la forma AX + BY = -C


#Algoritmo extendido de euclides
def gcdExt(a,b):
  prevx, x = 1, 0; prevy, y = 0, 1
  while b:
    q = a//b
    x, prevx = prevx - q*x, x
    y, prevy = prevy - q*y, y
    a, b = b, a % b
  return a, prevx, prevy

#Usamos el algoritmo extendido de euclides para hallar una solucion de la ecuacion si existe, si no se imprime -1
#Para esto hallamos el valor k que satisface   [ k * mcd = -c ], este k se usa para multiplicar las suluciones del gcdExt
#De esta forma hallamos la solucion de la ecuacion

#si -c no es divisible por gcd(a,b), la ecuacion no tiene solucion




mcd, x, y = gcdExt(X,Y)

c=C

if((-c) % mcd == 0):
  k = -c//mcd
  print(x*k,y*k)
else:
  print(-1)