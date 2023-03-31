#include "Vector.h"

Vector::~Vector() {
	if( m_pCoord )
	  delete[] m_pCoord;
}

Vector::Vector( int nSize, int nElem ) { 
	
	try {
		createVec(nSize);
	}
	catch(VectorException e) {
		cerr << e.getReason();
		return;
	}
	for( int i = 0; i < nSize; i++ ) {
		m_pCoord[ i ] = nElem;
	}
}

Vector::Vector( const Vector& v ) {   
	m_pCoord = NULL;
	m_nDim = 0;
	*this = v;
}


Vector& Vector::operator = ( const Vector& v ) {   
	
	if( getDim() != v.getDim() ) {
		if( m_pCoord ) delete[] m_pCoord;
		try {
			createVec( v.getDim() );
		}
		catch( VectorException e ) {
			cerr << e.getReason();
			return *this;
		}
	}
	copyVec( v );
	return *this;

}


const Vector operator + ( const Vector& v1, const Vector& v2 ) {           
	Vector res(v1);
	return res += v2;
	
	
}


const Vector operator + ( const Vector& v, double x ) {						
	Vector res(v);
	return res += x;
}


const Vector operator + ( double x, const Vector& v ) {						
	return v + x;
}


Vector& Vector::operator +=( const Vector& v ) {							
	if( getDim() != v.getDim() ) {
		throw VectorException(INCOMPATIBLE_SIZES);
	}

	for( int i = 0; i < getDim(); i++ ) {
		m_pCoord[i] += v.m_pCoord[i];
	}
	return *this;

}



Vector& Vector::operator += ( double x ) {					

	for( int i = 0; i < getDim(); i++ ) {
		m_pCoord[i] += x;
	}
	return *this;
}



const Vector operator - ( const Vector& v1, const Vector& v2 ) {				
	Vector res( v1 );
	return res -= v2;
}



const Vector operator - ( const Vector& v, double x ) {                   
	Vector res( v );
	return res -= x;
}



Vector& Vector::operator -= ( const Vector& v ) {					
	if( getDim() != v.getDim() ) {
		throw VectorException(INCOMPATIBLE_SIZES);											//W
	
	}

	for( int i = 0; i < getDim(); i++ ) {
		m_pCoord[i] -= v.m_pCoord[i];
	}
	return *this;
}



Vector& Vector::operator -= ( double x ) {					

	for( int i = 0; i < getDim(); i++ ) {
		m_pCoord[i] -= x;
	}
	return *this;
}



const Vector operator - ( const Vector& v ) {				

	 return v*double(-1);
}



Vector& Vector::operator *= ( double x ) {						

	for( int i = 0; i < this->getDim(); i++ ) {
		this->m_pCoord[i] *= x;
	}
	return *this;
}



const Vector operator * ( double x, const Vector& v ) {					
	//Vector res( v );
	return v * x;
}



const Vector operator *( const Vector& v, double x ) {					
	Vector res(v);
	return res *= x;
}



double operator * ( const Vector& v1, const Vector& v2 ) {  //iloczyn skalarny			

	if( v1.getDim() != v2.getDim() ) {
		throw VectorException( INCOMPATIBLE_SIZES );														
		return 0;
	}
	double res = 0;
	for( int i = 0; i < v1.getDim(); i++ ) {
		res += v1.m_pCoord[i] * v2.m_pCoord[i];
	}

	return res;
}



const double& Vector::operator [] ( int ix )const {	
	if( ix  >=  this->m_nDim ) {
		throw VectorException( INDEX_OUT_OF_RANGE );
	}
	return this->m_pCoord[ix];
}



double& Vector::operator [] ( int ix ) {	
	if( ix  >=  this->m_nDim ) {
		throw VectorException( INDEX_OUT_OF_RANGE );
	}

	return this->m_pCoord[ix];
}



bool operator != ( const Vector& v1, const Vector& v2 ) {					
	return !( v1==v2); 
}



bool operator == ( const Vector& v1, const Vector& v2 ) {					
	if( v1.getDim() != v2.getDim() ) {
		return false;
	}

	for( int i = 0; i < v1.getDim(); i++ ) {
		if( v1.m_pCoord[i] != v2.m_pCoord[i] ) return false;
	}

	return true;
}



istream& operator >> ( istream& in, Vector& v ) {					
	double x;
	for( int i = 0; i < v.getDim(); i++ ) {
		in >> x; v.m_pCoord[i] = x;
	}
	return in;
}



ostream& operator << ( ostream& out, const Vector& v ) {
	out << "[";
	for(int i = 0; i < v.getDim(); i++) {
		out << v.m_pCoord[i];
		(i != v.getDim() - 1) ? out << "," : out << "";
		
	}
	out << "]";
	return out;
}