#pragma once
#include "Vector.h"

#define MERROR 0
#define ALLOCATION_ERROR 1
#define INCOMPATIBLE_SIZES 2
#define INDEX_OUT_OF_RANGE 3


class MatrixException {
public:
	MatrixException(USINT errorCode = MERROR) { m_Error = errorCode; }
	const char* getReason();

private:
	USINT m_Error;
};

inline const char* MatrixException::getReason()
{
	switch(m_Error)
	{
	case ALLOCATION_ERROR: return "Allocation error!\n";
	case INCOMPATIBLE_SIZES: return "Incompatible sizes!\n";
	case INDEX_OUT_OF_RANGE: return "Index out of range!\n";
	default: return "Matrix error!\n";


	}
}


class Matrix
{
public:
	Matrix( int nRow = 2, int nCol = 2, int nElem = 0 );
	Matrix( const Matrix& m );
	virtual ~Matrix();
	Matrix& operator = (const Matrix& v);

	inline int GetVecDim() const;
	inline int GetRowNo() const;
	inline int GetColNo() const;

	friend const Matrix operator * ( const Matrix&, const Matrix& ); //mnozenie macierzy
	friend const Matrix operator * ( const Matrix&, const Vector& );

	operator Vector* () const { return m_pCoord; }  //operator rzutowania


	Vector& operator [] ( int iv );
	const Vector& operator [] (int iv ) const;


	friend bool operator != ( const Matrix&, const Matrix& );
	friend bool operator == (const Matrix&, const Matrix& );

	friend istream& operator >> ( istream& in, Matrix& );
	friend ostream& operator << ( ostream& out, const Matrix& );
	

private:
	int m_nRow;
	Vector* m_pCoord;
	inline void CopyMatrix( const Matrix& m );
	inline void createMatrix( USINT nRow, USINT nCol );
};


inline void Matrix::CopyMatrix( const Matrix& m ) {

	for( int i = 0; i < m.GetRowNo(); i++ ) {
		memcpy( (double*)(m_pCoord[i]), ( double* )(m.m_pCoord[i]), m.GetVecDim() * sizeof(double) );
	}
}

inline void Matrix::createMatrix(USINT nRow, USINT nCol) {
	
	if(nRow < 2) nRow = 2;
	m_nRow = nRow;
	m_pCoord = new(nothrow) Vector[nRow];
	if(!m_pCoord) throw MatrixException(ALLOCATION_ERROR);
	
	for(int i = 0; i < nRow; i++) {
		m_pCoord[i] = Vector(nCol, 0);
	}
}
