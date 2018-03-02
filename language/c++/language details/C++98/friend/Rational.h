/*
 * Rational.h
 *
 *  Created on: 2014-2-11
 *      Author: tli
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

template <typename T>
class Rational {
public:
	Rational(const T& number =0, const T& deno =1);
	const T numberator() const;
	const T denominator() const;
    friend const Rational<T> operator* (const Rational<T>& lhs, const Rational<T>& rhs) {
    	return doMutliply(lhs, rhs);
	}
private:
	T number_, denominator_;
};

template <typename T>
Rational<T>::Rational(const T& number, const T& deno)
: number_(number),denominator_(deno)
{
}

template <typename T>
const T Rational<T>::numberator() const
{
  return number_;
}

template <typename T>
const T Rational<T>::denominator() const
{
  return denominator();
}

template <typename T>
const Rational<T> doMutliply (const Rational<T>& lhs,
		                     const Rational<T>& rhs)
{
	return Rational<T>(lhs.numberator() * rhs.numberator(), rhs.denominator() * rhs.denominator());

}
#endif /* RATIONAL_H_ */
