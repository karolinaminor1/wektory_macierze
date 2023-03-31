#pragma once

/*konstruktor z parametrami domyœlnymi - nDim = 2, nElem = 0
* konstruktor kopiuj¹cy
* operator =
* destruktor (zwalnia pamiec0
* getDim() //zwraca rozmiar (inline)
* operatory we/wy
* operatory: + (v1+v2)
*			 + (v+x)
*			 += (v+v)
*		     += (v+x)
*			 -  (v1-v2) //friend
*			 -  (v-x)   //fd
*			 -= (v-=v)
*			-= (v-=x)
*			- unarny (-v) //fr
*			* ilocczyn skalarny (v1*v2) //fr
*			mnozenie liczba razy wektor
*			* (v*x)
*			*= (v*=x)
* 
*			[] (po prawej str znaku podst)
*			[] (po lewej str znaku podstawienia)
*			== if(v1==v2)        //fd          //double x= x[2]
*			!= if( v1!=v2)	     //fd		   // x[3]=2
*
*			operator rzutowania typu na double*
*			(jak metoda klasy zwracamy referencje oprcz op wejscia wyjscia)
*           (jak friend to zwracamy const vector)
*
*			prywatne metody :
*          inline createVec( (UINT)int nDim ) //typedef unsigned int UINT
*          inline copy Vec(const Vector& v) wkoipiowuje do *this wspolrzedne v
*		inline getDim()
*
* prywatne skladowe:
* 
* double m_pCoord //dynamiczna tablica
* int m_nDim      //rozmar wektora
*
* -----------------------------------------------------------------------------------------------------------------------------------------
* 
* cVecexept( USINT errCode = VERROR) { m_Err=errCode}
* const char* showreason();
* 
* private:
* USINT m_err;
* 
* 
* 
* inline const char* showreas
* 
* -----------mATRIX------------------
* prywatne
rozmiar m_nRow;
tablica wektorow m_pCoord;

publiczne:
konstruktor z iloscia wierszy(nRow=2) ile kolumn(nCol=2) wartosc inicjujaca 0
konstr kopiujacy 
destruktor virtualny

public: rozmiar vektora
GetRowNo() GetColNo() inline;
//wyswietlanie/pobieranie wspolrzednych
operator we/wy;
//oba indeksowania 
operator rzutowania na Vector*
operator porownania == oraz !=
operator podstawienia(dla konstr kopiujacego)
//mnozenie macierzy ze sprawdzeniem ilosci kolumn i wierszy (wyjatek) 3 petle
mnozenie macierzy przez wektor (wyjatek) (iloczyn skalarny)

prywatna
void CopyMatrix(const CMatrix& m); //inline

* 
* 
* 
* 
* 
* 
* 
* 
* 
*/



