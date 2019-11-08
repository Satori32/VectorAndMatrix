#pragma once

#include <initializer_list>
#include <array>
#include <cstdint>
#include <algorithm>
#include <cmath>

//https://rikeilabo.com/vector-formula-list

template<class T,std::size_t N>
class Vector {
public:
	Vector() {}
	Vector(const std::initializer_list<T>& IL) {
		//if (IL.size() > N)return;
		auto itA = IL.begin();
		auto itB = v.begin();
		for (; itA != IL.end() && itB != v.end(); itA++, itB++) {
			*itB = *itA;
		}
	}

	T Norm() const{
		T R(0);
		for (std::size_t i = 0; i < N; i++) {
			R += v[i] * v[i];
		}
		return std::sqrt(R);
	}
	T Norm2() const{
		T R(0);
		for (std::size_t i = 0; i < N; i++) {
			R = R+(v[i] * v[i]);
		}
		return R;
	}
	T Area(const Vector& B)const {
		T N2 = Norm2() * B.Norm2();
		T I2 = InnerProduct(B);
		I2 *= I2;

		return 0.5 * std::sqrt(N - I2);
	}

	T InnerProduct(const Vector<T,N>& B)const {
		T R(0);
		for (std::size_t i = 0; i < N; i++) {
			R += v[i] * B[i];
		}
		return R;
	}

	T Theta(const Vector<T, N>& B)const {//cos theta.Theta(0 <-> 180).
		return this->InnerProduct(B) / (((*this).Norm()) * B.Norm());
	}

	bool IsParallel(const Vector<T, N>& B) const{
		if (Volume(B) == 0)return false;
		T V = InnerProduct(B);
		T No = std::abs(this->Norm() * B.Norm());
		return  V==No;
	}
	bool IsVertical(const Vector<T, N>& B) const{
		if (Volume(B) == 0)return false;


		T V = InnerProduct(B);		
		return  V==0;
	}
	T R(const Vector<T, N>& C) const{
		return (*this - C).Norm();
	}
	
	T Volume(const Vector& B) const{
		Vector<T, N> C = B - (*this);
		return C.Norm();
	}

	std::size_t Size() const{
		return N;
	}
public:
	typename std::array<T, N>::iterator begin() {
		return v.begin();
	}
	typename std::array<T, N>::const_iterator begin() const{
		return v.cbegin();
	}
	typename std::array<T, N>::iterator end() {
		return v.end();
	}
	typename std::array<T, N>::const_iterator end() const{
		return v.cend();
	}
public:
	const T& operator [](const std::size_t& In)const {
		return v[In];
	}
	T& operator [](const std::size_t& In){
		return v[In];
	}


	Vector<T,N> operator +(const Vector<T,N>& In)const{
		Vector<T, N> R;
		for (std::size_t i = 0; i < N; i++) {
			R[i] = v[i] + In[i];
		}
		return R;
 	}
	Vector<T,N> operator -(const Vector<T,N>& In)const{
		Vector<T, N> R;
		for (std::size_t i = 0; i < N; i++) {
			R[i] = v[i] - In[i];
		}
		return R;
 	}
	template<class U>
	Vector<T,N> operator *(const U& In)const{
		Vector<T, N> R;
		for (std::size_t i = 0; i < N; i++) {
			R[i] = v[i] * In;
		}
		return R;
 	}
	template<class U>
	Vector<T,N> operator /(const U& In)const{
		Vector<T, N> R;
		for (std::size_t i = 0; i < N; i++) {
			R[i] = v[i] / In;
		}
		return R;
 	}
public:
	static Vector<T, N> CenterOfGravity(const Vector<T, N>& A, const Vector<T, N>& B, const Vector<T, N>& C) {
		return (A + B + C) / 3;
	}
	static Vector<T, N> OuterDividingPoint(const Vector<T, N>& A, const T& n, const Vector<T, N>& B, const T& m) {
		return ((-n * A) + (m * B)) / (m - n);
	}
	static Vector<T, N> InternalDividingPoint(const Vector<T, N>& A, const T& n, const Vector<T, N>& B, const T& m) {
		return ((n * A) + (m * B)) / (m + n);
	}
protected:
	std::array<T, N> v = {0,};
};