
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): rawBits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
	rawBits = other.rawBits;
}

Fixed::Fixed(const int value) {
	rawBits = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	rawBits = roundf(value * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

bool Fixed::operator>(const Fixed& other) const {
	return (rawBits > other.rawBits);
}

bool Fixed::operator<(const Fixed& other) const {
	return (rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (rawBits <= other.rawBits);
}

bool Fixed::operator==(const Fixed& other) const {
	return (rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (rawBits != other.rawBits);
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	rawBits++;
	return temp;
}

Fixed& Fixed::operator--() {
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	rawBits--;
	return temp;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

int Fixed::toInt( void ) const {
	return rawBits >> fractionalBits;
}

float Fixed::toFloat( void ) const {
	return (float)rawBits / (1 <<fractionalBits);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
