#include <iostream>
#include "SLinkedlist.h"
using namespace std;
class PolyArray

{
public:
	PolyArray();
	PolyArray(double coeffArray[], int arraysize); // degree = arraysize -1;
	PolyArray(const PolyArray& poly);
	~PolyArray();
	double evaluate(const double& x) const;

private:
	double *coeff; // coefficients of polynomial function
	int n; // degree of polynomial function
};

PolyArray::PolyArray() { // default constructor
	n = 0;
	coeff = new double[n + 1]; // dynamically create an array of size 1
	coeff[0] = 0.0;
}
PolyArray::PolyArray(double coarray[],int arraysize)
{
	n = arraysize-1;
	coeff = new double[n+1]; // dynamically create an array of size 1
	for (int i = 0; i <= n; i++)
	{
		coeff[i] = coarray[i];
	}
}
PolyArray::~PolyArray() 
{
	delete[] coeff;
}
PolyArray::PolyArray(const PolyArray &poly)
{
	n = poly.n;
	coeff = new double[n+1];
	for (int y = 0; y < n; y++)
		coeff[y] = poly.coeff[y];
}
//solve the polynomial
double PolyArray::evaluate(const double& x) const

{
	double total = 0.0;
	for (int i = 0; i <= n; i++)
	{
		total += coeff[i] * pow(x, i);
	}
	return total;
}

class PolyTerm {

private:
	int _order;
	double _coeff;

public:
	void setOrder(int order) {
		_order = order;
	}
	void setCoeff(double coeff) {
		_coeff = coeff;
	}
	int getOrder() {
		return _order;
	}
	double getCoeff() {
		return _coeff;
	}
};
int main()
{
	// polynomial function y = 3.5*x^7 + 2.2 using array
	// this function is the same as 2.2*x^0 + 0*x^1 + 0*x^2 + 0*x^3 + 0*x^4 + 0*x^5 +
	//0 * x ^ 6 + 3.5*x ^ 7
	double coeffArray[8] = { 2.2, 0, 0, 0, 0, 0, 0, 3.5 };
	PolyArray polyArray(coeffArray, 8);
	cout << "Evaluate using arrays:" << endl;
	cout << polyArray.evaluate(1.0) << endl;
	cout << polyArray.evaluate(2.0) << endl;
	// polynomial function y = 3.5*x^7 + 2.2 using linked list
	PolyTerm seven;
		seven.setCoeff(3.5);
		seven.setOrder(7);
	PolyTerm six;
		six.setCoeff(0);
		six.setOrder(6);
	PolyTerm five;
		five.setCoeff(0);
		five.setOrder(5);
	PolyTerm four;
		four.setCoeff(0);
		four.setOrder(4);
	PolyTerm three;
		three.setCoeff(0);
		three.setOrder(3);
	PolyTerm two;
		two.setCoeff(0);
		two.setOrder(2);
	PolyTerm one;
		one.setCoeff(0);
		one.setOrder(1);
	PolyTerm zero;
		zero.setCoeff(2.2);
		zero.setOrder(0);
	SLinkedList<PolyTerm> polyLinkedList;
	//add terms to the linked list
	polyLinkedList.addFront(zero);
	polyLinkedList.addFront(two);
	polyLinkedList.addFront(three);
	polyLinkedList.addFront(four);
	polyLinkedList.addFront(five);
	polyLinkedList.addFront(six);
	polyLinkedList.addFront(seven);
	cout << "Evaluate using linked list:" << endl;
	//x=1
	cout << polyLinkedList.evaluate(1.0) <<endl;
	//x=2
	cout << polyLinkedList.evaluate(2.0) << endl;
	system("pause");
	return 0;
}
