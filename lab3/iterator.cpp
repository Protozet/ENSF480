// iterator.cpp
// ENSF 480 - Fall 2019 - Lab 3, Ex A
// M. Moussavi: Sept 26, 2018
#include <iostream>
#include <assert.h>
#include <string>
#include <string.h>
#include "mystring2.h"

using namespace std;

template <class T>
class Vector{
public:
	class VectIter{
		friend class Vector<T>;

	private:
		Vector<T> *v; // points to a vector object of type T
		int index;	// represents the subscript number of the vector's
					  // array.
	public:
		VectIter(Vector<T> &x);

		T operator++(); // same as ++x
		//PROMISES: increments the iterator's indes and return the
		//          value of the element at the index position. If
		//          index exceeds the size of the array it will
		//          be set to zero. Which means it will be circulated
		//          back to the first element of the vector.

		T operator++(int); //same as x++
		// PRIMISES: returns the value of the element at the index
		//           position, then increments the index. If
		//           index exceeds the size of the array it will
		//           be set to zero. Which means it will be circulated
		//           back to the first element of the vector.

		T operator--(); //same as --X
		// PROMISES: decrements the iterator index, and return the
		//           the value of the element at the index. If
		//           index is less than zero it will be set to the
		//           last element in the aray. Which means it will be
		//           circulated to the last element of the vector.

		T operator--(int);
		// PRIMISES: returns the value of the element at the index
		//           position, then decrements the index. If
		//           index is less than zero it will be set to the
		//           last element in the aray. Which means it will be
		//           circulated to the last element of the vector.

		T operator*();
		// PRIMISES: returns the value of the element at the current
		//           index position.
	};

	Vector(int sz);
	~Vector();

	int &operator[](int i);
	// PRIMISES: returns existing value in the ith element of
	//           array or sets a new value to  the ith element in
	//           array.

	void ascending_sort();
	// PRIMISES: sorts the vector values in ascending order.

private:
	T *array;			 // points to the first element of an array of T
	int size;			 // size of array
	void swap(T &, T &); // swaps the values of two elements in array
};

template<>
class Vector<const char*>{
	private:
	int size;
	const char** array;

	public:
	Vector(int sz);
	~Vector();
	void ascending_sort();
	void swap(const char*  &a, const char* &b);
	const char*& operator[](int i){
		return array[i];
	}
	
	// const char*& operator =(const char* rhs){

	// }
	class VectIter{
		friend class Vector<const char*>;
		private:
		Vector<const char*> *v; // points to a vector object of type T
		int index;	

		public:
		VectIter(Vector<const char*> &x){
			v = &x;
			index = 0;
		}
		const char* operator++(){      //++x
			index++;
			if(index >= v->size)
				index = 0;
			return v->array[index];
		}
		const char* operator++(int){	//x++
			const char* res = v->array[index];
			index++;
			if(index >= v->size)
				index = 0;
			return res;
		}
		const char* operator--(){		//--x
			index--;
			if(index < 0)
				index = 0;
			return v->array[index];
		}
		const char* operator--(int){	//x--
			const char* res = v->array[index];
			index--;
			if(index < 0)
				index = 0;
			return res;
		}
		const char* operator*(){
			return v->array[index];
		}
	};
};

template<>
class Vector<Mystring>{
	private:
	int size;
	Mystring *array;

	public:
	Vector(int sz);
	~Vector();
	friend ostream& operator << (ostream &out, const Mystring &c);

	void ascending_sort();
	void swap(Mystring  &a, Mystring &b);
	Mystring &operator[](int i){
		return array[i];
	}
	class VectIter{
		friend class Vector<Mystring>;
		private:
		Vector<Mystring> *v; // points to a vector object of type T
		int index;	

		public:
		VectIter(Vector<Mystring> &x){
			v = &x;
			index = 0;
			Vector::size = 5;
		}
		Mystring operator++(){      //++x
			index++;
			if(index >= v->size)
				index = 0;
			return v->array[index];
		}
		Mystring operator++(int){	//x++
			Mystring res = v->array[index];
			index++;
			if(index >= v->size)
				index = 0;
			return res;
		}
		Mystring operator--(){		//--x
			index--;
			if(index < 0)
				index = v->size - 1;
			return v->array[index];
		}
		Mystring operator--(int){	//x--
			Mystring res = v->array[index];
			index--;
			if(index < 0)
				index =  v->size - 1;
			return res;
		}
		Mystring operator*(){
			return v->array[index];
		}
	};
};

// ostream& operator << (ostream &out, const Mystring &c){
// 	out << c.c_str();
// 	return out;
// }

Vector<Mystring>::Vector(int sz){
	size = sz;
	array = new Mystring[size];
	assert(array != nullptr);
	//// strcpy(array, sz);
}
Vector<Mystring>::~Vector(){
	// for(int i = 0; i < size; i++){
	// 	Mystring* yuh = array[0];
	// 	delete [] yuh;
	// }
	delete [] array;
	array = NULL;
}
Vector<const char*>::Vector(int sz){
	size = sz;
	array = new const char*[size];
	assert(array != nullptr);
	//// strcpy(array, sz);
}
Vector<const char*>::~Vector(){
	// for(int i = 0; i < size; i++){
	// 	delete [] array[i];
	// }
	delete [] array;
	array = NULL;
}

void Vector<const char*>::ascending_sort(){
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (strcmp(array[i], array[j]) > 0)	//array[i] > array[j]
				swap(array[i], array[j]);
}
void Vector<Mystring>::ascending_sort(){
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i].isGreater(array[j]))	//array[i] > array[j]
				swap(array[i], array[j]);
}

template <class T>
T Vector<T>::VectIter::operator++()
{ // same as ++x
	index++;
	if (index >= v->size)
	{
		index = 0;
	}
	return v->array[index];
}

template <class T>
T Vector<T>::VectIter::operator++(int)
{ // same as x++
	int result = v->array[index];
	index++;
	if (index >= v->size)
	{
		index = 0;
	}
	return result;
}
template <class T>
T Vector<T>::VectIter::operator--()
{ //same as --X
	index--;
	if (index < 0)
	{
		index = v->size - 1;
	}
	return v->array[index];
}
template <class T>
T Vector<T>::VectIter::operator--(int)
{ //same as X--
	int result = v->array[index];
	index--;
	if (index < 0)
	{
		index = v->size - 1;
	}
	return result;
}
template <class T>
T Vector<T>::VectIter::operator*()
{
	return v->array[index];
}

template <class T> //TODO prob have to do specialization here
void Vector<T>::ascending_sort()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i] > array[j])
				swap(array[i], array[j]);
}

template <class T>
void Vector<T>::swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// template <>
void Vector<Mystring>::swap(Mystring &a, Mystring &b){
	Mystring tmp = a;
	a = b;
	b = tmp;
}
void Vector<const char*>::swap(const char* &a, const char* &b){
	const char* tmp = a;
	a = b;
	b = tmp;
}

template <class T>
Vector<T>::VectIter::VectIter(Vector<T> &x)
{
	v = &x;
	index = 0;
}

template <class T>
Vector<T>::Vector(int sz)
{
	size = sz;
	array = new T[sz];
	assert(array != NULL);
}

template <class T>
Vector<T>::~Vector()
{
	delete[] array;
	array = NULL;
}

template <class T>
int &Vector<T>::operator[](int i)
{
	return array[i];
}

int main()
{

	Vector<int> x(3);
	x[0] = 999;
	x[1] = -77;
	x[2] = 88;

	Vector<int>::VectIter iter(x);

	cout << "\n\nThe first element of vector x contains: " << *iter;

	// the code between the  #if 0 and #endif is ignored by
	// compiler. If you change it to #if 1, it will be compiled

#if 1
	cout << "\nTesting an <int> Vector: " << endl;;
	
	cout << "\n\nTesting sort";
	x.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iter++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iter;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iter;	
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iter--;
	
	cout << endl;
	
	cout << "Testing a <Mystring> Vector: " << endl;
	Vector<Mystring> y(3);
	y[0] = "Bar";
	y[1] = "Foo";
	y[2] = "All";;
	
	Vector<Mystring>::VectIter iters(y);
	
	cout << "\n\nTesting sort";
	y.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iters++;
	// cout << endl << y;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iters;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iters;
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iters--;
	
	cout << endl; cout << "Testing a <char *> Vector: " << endl;
	Vector<const char*> z(3);
	z[0] = "Orange";
	z[1] = "Pear";
	z[2] = "Apple";
	// creating copy of z called iterchar
	Vector<const char*>::VectIter iterchar(z);
	
	cout << "\n\nTesting sort";
	z.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iterchar++;

#endif
	cout << "\nPrgram Terminated Successfully." << endl;

	return 0;
}
