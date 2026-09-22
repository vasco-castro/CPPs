
#include "Fixed.hpp"
#include <iostream>

static int	g_passed = 0;
static int	g_failed = 0;

static void check(bool condition, const std::string& label) {
	if (condition) {
		std::cout << "  [OK] " << label << std::endl;
		g_passed++;
	} else {
		std::cout << "  [KO] " << label << std::endl;
		g_failed++;
	}
}

static void section(const std::string& title) {
	std::cout << std::endl << "--- " << title << " ---" << std::endl;
}

static void subjectTest() {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}

static void testConstructors() {
	section("Constructors & conversions");

	check(Fixed().toFloat() == 0.0f, "default is 0");
	check(Fixed(42).toInt() == 42, "int 42 -> toInt 42");
	check(Fixed(-42).toInt() == -42, "int -42 -> toInt -42");
	check(Fixed(1.5f).toFloat() == 1.5f, "float 1.5 -> toFloat 1.5");
	check(Fixed(-1.5f).toFloat() == -1.5f, "float -1.5 -> toFloat -1.5");
	check(Fixed(1.9f).toInt() == 1, "float 1.9 -> toInt 1 (truncates)");
	check(Fixed(0.00390625f).toFloat() == 0.00390625f, "smallest step (1/256) is representable");

	Fixed original(3.25f);
	Fixed copy(original);
	check(copy == original, "copy constructor copies value");
}

static void testComparisons() {
	section("Comparison operators");

	Fixed a(1.5f);
	Fixed b(2);
	Fixed c(1.5f);

	check(a < b, "1.5 < 2");
	check(!(b < a), "!(2 < 1.5)");
	check(b > a, "2 > 1.5");
	check(!(a > b), "!(1.5 > 2)");
	check(a <= b && a <= c, "1.5 <= 2 and 1.5 <= 1.5");
	check(b >= a && a >= c, "2 >= 1.5 and 1.5 >= 1.5");
	check(a == c, "1.5 == 1.5");
	check(a != b, "1.5 != 2");
	check(!(a != c), "!(1.5 != 1.5)");
	check(Fixed(-1) < Fixed(0), "-1 < 0");
}

static void testArithmetic() {
	section("Arithmetic operators");

	check(Fixed(2) + Fixed(3) == Fixed(5), "2 + 3 == 5");
	check(Fixed(1.5f) + Fixed(-2.5f) == Fixed(-1), "1.5 + -2.5 == -1");
	check(Fixed(10) - Fixed(15) == Fixed(-5), "10 - 15 == -5");
	check(Fixed(2.5f) * Fixed(4) == Fixed(10), "2.5 * 4 == 10");
	check(Fixed(-3) * Fixed(-3) == Fixed(9), "-3 * -3 == 9");
	check(Fixed(-3) * Fixed(2) == Fixed(-6), "-3 * 2 == -6");
	// check(Fixed(7) / Fixed(3) == Fixed(2.33333333333333333333), "7 / 3 == 2.333333333333333333");
	check(Fixed(10) / Fixed(4) == Fixed(2.5f), "10 / 4 == 2.5");
	check(Fixed(-9) / Fixed(3) == Fixed(-3), "-9 / 3 == -3");
	check(Fixed(1) / Fixed(3) == Fixed(0.33203125f), "1 / 3 rounds to 85/256");

	Fixed chained = Fixed(1) + Fixed(2) * Fixed(3) - Fixed(4) / Fixed(2);
	check(chained == Fixed(5), "1 + 2 * 3 - 4 / 2 == 5 (precedence)");

	// Values whose raw bits exceed a float's 24-bit mantissa (> 65536.0).
	Fixed big(100000);
	Fixed epsilon(0.00390625f);
	// Compared as Fixed, not as float: near 100000 a float's step is 1/128,
	// so toFloat() cannot show a 1/256 difference even when rawBits is correct.
	check(big + epsilon > big, "100000 + 1/256 > 100000 (no precision loss)");
	check(big - epsilon != big, "100000 - 1/256 != 100000 (no precision loss)");
}

static void testIncrements() {
	section("Increment / decrement");

	Fixed a;
	Fixed epsilon(0.00390625f);

	check(++a == epsilon, "++0 returns 1/256");
	check(a == epsilon, "value after ++ is 1/256");

	Fixed old = a++;
	check(old == epsilon, "a++ returns the old value");
	check(a == epsilon + epsilon, "value after a++ is 2/256");

	check(--a == epsilon, "--a returns the new value");
	old = a--;
	check(old == epsilon, "a-- returns the old value");
	check(a == Fixed(), "value after a-- is 0");

	--a;
	check(a < Fixed(), "decrementing below 0 goes negative");

	Fixed b(1);
	++(++b);
	check(b == Fixed(1) + epsilon + epsilon, "++(++b) chains on the same object");
}

static void testMinMax() {
	section("min / max");

	Fixed a(1);
	Fixed b(2);

	check(&Fixed::min(a, b) == &a, "min(a, b) returns a reference to a");
	check(&Fixed::max(a, b) == &b, "max(a, b) returns a reference to b");

	Fixed::max(a, b) = Fixed(10);
	check(b == Fixed(10), "non-const max returns a modifiable reference");

	Fixed const c(3.5f);
	Fixed const d(-3.5f);
	check(&Fixed::min(c, d) == &d, "const min(c, d) returns d");
	check(&Fixed::max(c, d) == &c, "const max(c, d) returns c");

	Fixed const e(7);
	Fixed const f(7);
	check(Fixed::min(e, f) == e && Fixed::max(e, f) == f, "min/max with equal values");
}

int main( void ) {

	std::cout << "=== Subject test ===" << std::endl;
	subjectTest();

	testConstructors();
	testComparisons();
	testArithmetic();
	testIncrements();
	testMinMax();

	std::cout << std::endl << "=== " << g_passed << " passed, "
		<< g_failed << " failed ===" << std::endl;

	return g_failed != 0;
}
