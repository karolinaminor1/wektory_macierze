#pragma once
#include <iostream>
using namespace std;

typedef unsigned short int USINT;

#define VECERROR 0
#define ALLOCATION_ERROR 1
#define INCOMPATIBLE_SIZES 2
#define INDEX_OUT_OF_RANGE 3


class VectorException {
public:
	VectorException(USINT errorCode = VECERROR) { m_Error = errorCode; }
	const char* getReason();

private:
	USINT m_Error;  
};

inline const char* VectorException::getReason()
{
	switch(m_Error)
	{
	case ALLOCATION_ERROR: return "Allocation error!\n";
	case INCOMPATIBLE_SIZES: return "Incompatible sizes!\n";
	case INDEX_OUT_OF_RANGE: return "Index out of range!\n";
	default: return "Vector error!\n";


	}
}

class Vector
{

public:
	Vector(int nSize = 2, int nElem = 0);
	Vector(const Vector& v);

	virtual ~Vector(); //destruktor

	Vector& operator = (const Vector& v); //op podst


public:

	/*DODAWANIE*/
	friend const Vector operator + (const Vector&, const Vector&); 
	friend const Vector operator + (const Vector&, double); 
	friend const Vector operator + (double, const Vector&);

	Vector& operator +=(const Vector&);
	Vector& operator +=(double);


	/*ODEJMOWANIE*/
	friend const Vector operator - (const Vector&, const Vector&); 
	friend const Vector operator - (const Vector&, double); 

	Vector& operator -= (const Vector&);
	Vector& operator -= (double);

	friend const Vector operator - (const Vector&); //-unarny


	/*ILOCZYNY*/
	Vector& operator *= (double);
	friend const Vector operator *(double, const Vector&);
	friend const Vector operator *(const Vector&, double);  

	friend double operator *(const Vector&, const Vector&); //iloczyn skalarny



	operator double* () const { return m_pCoord; }  //operator rzutowania


	/*INDEKSOWANIE*/
	double& operator [](int ix);						             //po lewej od =
	const double& operator[](int ix) const;					         //po prawej od =

	/*POROWNANIE*/
	friend bool operator !=( const Vector&, const Vector& ); 
	friend bool operator ==( const Vector&, const Vector& );


	friend istream& operator >> (istream& in, Vector&);
	friend ostream& operator << (ostream& out, const Vector&);

	//inline int getDim() const; 
   
	inline void createVec(USINT nDim);
	inline void copyVec(const Vector& v);

	inline int getDim() const;

private:
	double* m_pCoord; 
	int m_nDim;
};


inline void Vector::createVec(USINT nDim) {
	
	if(nDim < 2) nDim = 2;
	m_nDim = nDim;
	
		m_pCoord = new( nothrow ) double[nDim];
		if( !m_pCoord ) throw VectorException( ALLOCATION_ERROR );
}

inline int Vector::getDim() const {
	return m_nDim;
}

inline void Vector::copyVec( const Vector& v ) {
	memcpy( m_pCoord, ( double* )v, m_nDim * sizeof(double) );
}
