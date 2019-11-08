#pragma once
#include <array>
#include <initializer_list>
#include <stdexcept>
#include "Vector.h"

//[|:Column]
//[-:Row]

//imcomplete...

template <class T,std::size_t Row_,std::size_t Column_>
class Matrix {
public:
	Matrix() {}
	Matrix(const std::initializer_list<Vector<T,Column_>>& IL){
		auto itA = IL.begin();
		auto itB = m.begin();
		for (; itA != IL.end() && itB != m.end(); itA++, itB++) {
			*itB = *itA;
		}
	
	}

	T InnerProduct(const Matrix& In)const {
		T R(0);
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R += m[i][j] * In[i][j];
			}
		}

		return R;
	}	   
	std::size_t Row()const {
		return Row_;
	}
	std::size_t Column()const {
		return Column_;
	}

public:	
	const Vector<T, Row_>& operator [](std::size_t In)const {
		return m[In];
	}
	Vector<T, Row_>& operator [](std::size_t In) {
		return m[In];
	}
	template<class U>
	Matrix operator +(const U& In) const{
		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R[i][j] = m[i][j] + In;
			}
		}

		return R;
	}
	Matrix operator +(const Matrix& In) const {
		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R[i][j] = m[i][j] + In[i][j];
			}
		}
		return R;
	}
	template<class U>
	Matrix operator -(const U& In) const{
		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R[i][j] = m[i][j] - In;
			}
		}

		return R;
	}
	Matrix operator -(const Matrix& In) const {
		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R[i][j] = m[i][j] - In[i][j];
			}
		}
		return R;
	}
	template<class U>
	Matrix operator *(const U& In) const{
		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R[i][j] = m[i][j] * In;
			}
		}

		return R;
	}
	template<std::size_t Ro,std::size_t Co>
	Matrix operator *(const Matrix<T,Ro,Co>& In) const{
		if (In.Column() != Row()) { throw std::logic_error(); }

		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < In.Row(); j++) {
				for (std::size_t k = 0; k < Row_; k++) {
					R[i][j] += m[i][k] * In[k][j];
				}
			}
		}
		return R;
	}
	
	template<class U>
	Matrix operator /(const U& In) const{
		Matrix R;
		for (std::size_t i = 0; i < Column_; i++) {
			for (std::size_t j = 0; j < Row_; j++) {
				R[i][j] = m[i][j] / In;
			}
		}

		return R;
	}
	
protected:
	std::array<Vector<T, Row_>, Column_> m;
};
