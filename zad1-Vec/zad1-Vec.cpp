
#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
   /* int nDim;
    cout << "Podaj wymiar wektora" << endl;
    cin >> nDim; Vector v = Vector(nDim, 0);
    cout << "Podaj wartosci wektora" << endl;
    cin >> v;
    cout << "Wczytany wektor:" << endl;
    cout << v << endl;
    Vector v2 = Vector(10, 1);

    cout << "wygenerowany wektor v2:" << endl;
    cout << v2 << endl;
    v2 = v;

  /* Vector v3 = v + v2;

    cout << "suma v + v2:" << endl;
    cout << v3 << endl;
    cout << "\n" << endl;



    v3 = v - v2;
    cout << "roznica v - v2:" << endl;
    cout << v3 << endl;
    cout << "\n" << endl;



    double a = v * v2;
    cout << "iloczyn skalarny v i v2" << endl;
    cout << a << endl;
    cout << "\n" << endl;



    bool b = (v == v2);
    cout << "wynik v==v2 " << endl;
    cout << b << endl;
    cout << "\n" << endl;



    b = (v != v2);
    cout << "wynik v!=v2 " << endl;
    cout << b << endl;
    cout << "\n" << endl;

    try {
        int b = v[5];
    }
    catch(VectorException e) {
        cerr << e.getReason();
    }*/
  

    int nRow;
    cout << "Podaj liczbe wierszy macierzy" << endl;
    cin >> nRow; 
    int nCol;
    cout << "Podaj liczbe kolumn macierzy" << endl; 
    cin >> nCol; 
    Matrix m = Matrix(nRow, nCol, 0);
    
    cout << "Podaj wartosci macierzy" << endl;
    cin >> m;

    cout << "wczytana macierz m :" << endl;
    cout << m << endl;

    Matrix m3 = Matrix(4, 4, 2);
    cout << "wygenerowana macierz m3:" << endl;
    cout << m3 << endl;
   
    Matrix m2;
    try {
        m2 = m * m3;
        cout << "m*m3:" << endl;
        cout << m2 << endl;
    }
    catch(MatrixException e) {
        cerr << e.getReason();
    }
    
    
    Vector v = Vector(4, 5);
    try {
        Matrix m4 = m * v;
        cout << "m*v :" << endl;
        cout << m4 << endl;
    }
    catch(MatrixException e) {
        cerr << e.getReason();
    }

   bool b = (m == m3);
    cout << "wynik m2==m3 " << endl;
    cout << b << endl;
    cout << "\n" << endl; 
  
   
    return 0;
}

