#include "Matrix.h"

Matrix::Matrix( int nRow, int nCol, int nElem ) {
	try {
		createMatrix( nRow, nCol );
	}
	catch( MatrixException e ) {
		cerr << e.getReason();
		return;
	}
	
	for( int i = 0; i < nRow; i++ ) {
		m_pCoord[i] = Vector( nCol, nElem );
	}

}



Matrix::~Matrix() {
	if( m_pCoord ) {
		delete[] m_pCoord;
	}
}


Matrix::Matrix( const Matrix& m ) {
	m_pCoord = NULL;
	m_nRow = 0;
	*this = m;
}


Matrix& Matrix::operator = ( const Matrix& m ) {

	if( GetRowNo() != m.GetRowNo() || GetColNo() != m.GetColNo() ) {
		
		if( m_pCoord ) {
			delete[] m_pCoord;
		}

		try {
			createMatrix(m.GetRowNo(), m.GetColNo());
		}
		catch( MatrixException e ) {
			cerr << e.getReason();
			return *this;
		}
		
	}

	CopyMatrix(m);
	return *this;
}


/*---------------------------GETTERY---------------------------*/


inline int Matrix::GetVecDim() const {
	if( !m_pCoord ) return 0;
	return this->m_pCoord->getDim();
}


inline int Matrix::GetRowNo() const {
	if( !m_pCoord ) return 0;
	return this->m_nRow;
}


inline int Matrix::GetColNo() const{
	if( !m_pCoord ) return 0;
	return this->GetVecDim();

}


const Matrix operator *( const Matrix& m1, const Matrix& m2 ) {  //mnozenie macierzy
	
	if( m1.GetColNo() != m2.GetRowNo() ) {
		throw MatrixException( INCOMPATIBLE_SIZES );
	}

	Matrix res = Matrix( m1.GetRowNo(), m2.GetColNo(), 0 );

	for( int i = 0; i < m1.GetRowNo(); i++ ) {
		Vector* pV = ( Vector* )m1;
		for( int j = 0; j < m2.GetColNo(); j++ ) {
			double x = 0;
			double* v = ( double* )*pV++;
			for( int k = 0; k < m1.GetColNo(); k++ ) {
				x += *v++ * m2[k][j];
			}
			res[i][j] = x;
		
		}
	}

	return res;
}


const Matrix operator *( const Matrix& m, const Vector& v ) {  //mnozenie macierzy przez wektor
	Matrix res = m;
	
	if( m.GetColNo() != v.getDim() ) {
		throw MatrixException(INCOMPATIBLE_SIZES);
	}
	
	for( int i = 0; i < m.GetRowNo(); i++ ) {
		for( int j = 0; j < v.getDim(); j++ ) {
			res[i][j] = res[i][j] * v[j];
		}
	}
	
	return res;
}



istream& operator >> ( istream& in, Matrix& m ) {
		double x;
		for( int i = 0; i < m.GetRowNo(); i++ ) {
			for( int j = 0; j < m.GetVecDim(); j++ ) {
				in >> x; ( m.m_pCoord[i] )[j] = x;
			}
		}
		return in;
}



ostream& operator << ( ostream& out, const Matrix& m ) {
	for( int i = 0; i < m.GetRowNo(); i++ ) {
		for( int j = 0; j < m.GetVecDim(); j++ ) {
			out <<  ( m.m_pCoord[i] )[j];
			out << "\t";
		}
		out << "\n";
	}
	return out;
}



Vector& Matrix::operator [] ( int iv ) {
	if( iv >= this->GetRowNo() ) {
		throw VectorException( INDEX_OUT_OF_RANGE );
	}
	return m_pCoord[iv];
}



const Vector& Matrix::operator [] ( int iv ) const {
	if( iv >= this->GetRowNo() ) {
		throw VectorException( INDEX_OUT_OF_RANGE );
	}
	return m_pCoord[iv];
}



bool operator !=( const Matrix& m1, const Matrix& m2 ) {
	if( m1.GetRowNo() != m2.GetRowNo() ) return true;
	if( m1.GetColNo() != m2.GetColNo() ) return true;

	for( int i = 0; i < m1.GetRowNo(); i++ ) {
		if( m1.m_pCoord[i] != m2.m_pCoord[i] ) return true;
	}
	return false;
}



bool operator ==( const Matrix& m1, const Matrix& m2 ) {
	if( m1 != m2 ) return false;
	else return true;
}