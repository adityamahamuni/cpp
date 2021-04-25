#include"Polynomial.h"

template <class T>
std::istream& operator >> (std::istream& is, Polynomial<T>& p) {
	int i = 0;

	std::cout << "Number of terms : ";
	std::cin >> p.n;

	p->terms = new Term<T>[p.n * sizeof(Term<T>)];

	std::cout << "\nEnter Terms : \n";
	for (i = 0; i < p.n; i++)
		std::cin << p->terms[i].coeff << p->terms[i].exp;

	return is;
}

template <class T>
std::ostream& operator << (std::ostream& os, const Polynomial<T> p) {
	int i = 0;

	for (i = 0; i < p.n; i++)
		std::cout << p.terms[i].coeff << "^" << p.terms[i].exp;
	std::cout << std::endl;

	return os;
}

template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T> p) {

	int i = 0, j = 0, k = 0;
	Polynomial<T>* sum;
	sum = new Polynomial<T>[sizeof(Polynomial)];
	sum->terms = new Term<T>[(n + p->n) * sizeof(Term)];

	while (i < n && j < p->n) {
		if (terms[i].exp > p.terms[j].exp)
			sum->terms[k++] = terms[i++];
		else if (terms[i].exp < p.terms[j].exp)
			sum->terms[k++] = p.terms[j++];
		else {
			sum->terms[k].exp = terms[i].exp;
			sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
		}
	}

	for (; i < n; i++)
		sum->terms[k++] = terms;
	for (; j < p.n; j++)
		sum->terms[k++] = p.terms;

	sum->n = k;

	return sum;
}