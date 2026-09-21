
#include "Fixed.hpp"

Fixed::Fixed(): rawBits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
	if (this != &other)
		this->rawBits = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {

}

int Fixed::getRawBits( void ) const {
	return rawBits;
}

void Fixed::setRawBits( int const raw ) {
	this->rawBits = raw;
}
