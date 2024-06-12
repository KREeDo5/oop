#pragma once

#include <iostream>

class Complex
{
	public:
		Complex(double real = 0, double image = 0);
		Complex(const Complex& complex);
		Complex(Complex&& complex) noexcept;

		double Re() const;
		double Im() const;
		double GetMagnitude() const;
		double GetArgument() const;

		Complex operator+() const;
		Complex operator-() const;

		friend Complex operator+(
			const Complex& left,
			const Complex& right
		);
		friend Complex operator-(
			const Complex& left,
			const Complex& right
		);
		friend Complex operator*(
			const Complex& left,
			const Complex& right
		);
		friend Complex operator/(
			const Complex& left,
			const Complex& right
		);

		friend Complex& operator+=(
			Complex& left,
			const Complex& right
		);
		friend Complex& operator-=(
			Complex& left,
			const Complex& right
		);
		friend Complex& operator*=(
			Complex& left,
			const Complex& right
		);
		friend Complex& operator/=(
			Complex& left,
			const Complex& right
		);

		friend bool operator==(
			const Complex& left,
			const Complex& right
		);
		friend bool operator!=(
			const Complex& left,
			const Complex& right
		);

		friend std::ostream& operator<<(
			std::ostream& out,
			const Complex& complex
		);
		friend std::istream& operator>>(
			std::istream& in,
			Complex& complex
		);

	private:
		double m_real;
		double m_image;
};
