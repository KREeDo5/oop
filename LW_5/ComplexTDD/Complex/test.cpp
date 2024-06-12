#define CATCH_CONFIG_MAIN
#include "D:/Repos/VOLGATECH_WORK/OOP/LW_5/ComplexTDD/catch2/catch.hpp"

TEST_CASE("Комплексные числа можно инициализировать и работать с ними")
{
	setlocale(LC_ALL, "Russian");

	SECTION("Инициализация c положит.значениями")
	{	
		Complex complex(3, 4);													 //3 + 4i

		REQUIRE(complex.Re() == 3.0);											 //возврат действительной части комплексного числа
		REQUIRE(complex.Im() == 4.0);											 //возвращает мнимую часть комплексного числа

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re())); //возвращает аргумент комплексного числа

		REQUIRE(complex.GetMagnitude() == 5.0);									 //возвращает модуль комплексного числа
	}

	SECTION("Инициализация c отриц.значениями")
	{
		Complex complex(-3, -4);

		REQUIRE(complex.Re() == -3.0);
		REQUIRE(complex.Im() ==- 4.0);

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re()));

		REQUIRE(complex.GetMagnitude() == 5.0);
	}

	SECTION("Инициализация c различными значениями")
	{
		Complex complex(3, -4);

		REQUIRE(complex.Re() == 3.0);
		REQUIRE(complex.Im() == -4.0);

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re()));

		REQUIRE(complex.GetMagnitude() == 5.0);

	}

}


TEST_CASE("1.1) Сумма комплексных чисел")
{
	setlocale(LC_ALL, "Russian");

	SECTION("Сумма двух комплексных чисел с положительными знаками")
	{
		Complex complex1(12, 34);
		Complex complex2(56, 78);

		auto complexResult = complex1 + complex2;

		REQUIRE(complexResult.Re() == 68.0);  // 12 + 56 = 68
		REQUIRE(complexResult.Im() == 112.0); // 34 + 78 = 112
	}


	SECTION("Сумма двух комплексных чисел с отрицательными знаками")
	{
		Complex complex1(-12, -34);
		Complex complex2(-56, -78);

		auto complexResult = complex1 + complex2;

		REQUIRE(complexResult.Re() == -68.0);  // -12 - 56 = -68
		REQUIRE(complexResult.Im() == -112.0); // -34 - 78 = -112
	}

	SECTION("Сумма двух комплексных чисел с различными знаками")
	{
		Complex complex1(12, -34);
		Complex complex2(-56, 78);

		auto complexResult = complex1 + complex2;

		REQUIRE(complexResult.Re() == -44.0); // 12 - 56 = -(56 - 12) = -44 
		REQUIRE(complexResult.Im() == 44.0);  // -34 + 78 = 44
	}
}

TEST_CASE("1.2) Сумма комплексного и действительного числа")
{
	setlocale(LC_ALL, "Russian");

	SECTION("Сумма комплексного числа с положительным действительным")
	{
		Complex complex(12, -34);
		double real = 56.0;

		auto complexResult = complex + real;

		REQUIRE(complexResult.Re() == 68.0);
		REQUIRE(complexResult.Im() == -34.0);
	}

	SECTION("Сумма комплексного числа с отрицательным действительным")
	{
		Complex complex(12, -34);
		double real = -56.0;

		auto complexResult = complex + real;

		REQUIRE(complexResult.Re() == -44.0);
		REQUIRE(complexResult.Im() == -34.0);
	}
}



TEST_CASE("2.1) Разность двух комплексных чисел")
{
	setlocale(LC_ALL, "Russian");

	SECTION("разность двух положительных комплексных чисел")
	{
		Complex complex1(12, 34);
		Complex complex2(56, 78);

		auto complexResult = complex1 - complex2;

		REQUIRE(complexResult.Re() == -44.0);
		REQUIRE(complexResult.Im() == -44.0);
	}

	SECTION("разность двух отрицательных комплексных чисел")
	{
		Complex complex1(-12, -34);
		Complex complex2(-56, -78);

		auto complexResult = complex1 - complex2;

		REQUIRE(complexResult.Re() == 44.0);
		REQUIRE(complexResult.Im() == 44.0);
	}
}

TEST_CASE("2.2) Разность комплексного числа и действительного")
{
	setlocale(LC_ALL, "Russian");

	SECTION("разность с положительным действительным числом")
	{
		Complex complex(12, -34);
		double real = 56.0;

		auto complexResult = complex - real;

		REQUIRE(complexResult.Re() == -44.0);
		REQUIRE(complexResult.Im() == -34.0);
	}

	SECTION("разность с отрицательным действительным числом")
	{
		Complex complex(12, -34);
		double real = -56.0;

		auto complexResult = complex - real;

		REQUIRE(complexResult.Re() == 68.0);
		REQUIRE(complexResult.Im() == -34.0);
	}
}

TEST_CASE("3.1) Умножение комплексных чисел")
{
	SECTION("Умножение двух положительных комплексных чисел")
	{
		Complex complex1(1, 2);
		Complex complex2(3, 4);

		auto complexResult = complex1 * complex2;

		REQUIRE(complexResult.Re() == -5.0);
		REQUIRE(complexResult.Im() == 10.0);
	}

	SECTION("Умножение двух отрицательных комплексных чисел")
	{
		Complex complex1(-1, -2);
		Complex complex2(-3, -4);

		auto complexResult = complex1 * complex2;

		REQUIRE(complexResult.Re() == -5.0);
		REQUIRE(complexResult.Im() == 10.0);
	}
}

TEST_CASE("3.2) Умножение комплексного числа и действительного")
{
	SECTION("Умножение на положительное действительное")
	{
		Complex complex(1, -2);
		double real = 3.0;

		auto complexResult = complex * real;

		REQUIRE(complexResult.Re() == 3.0);
		REQUIRE(complexResult.Im() == -6.0);
	}

	SECTION("Умножение на отрицательное действительное")
	{
		Complex complex(1, -2);
		double real = -3.0;

		auto complexResult = complex * real;

		REQUIRE(complexResult.Re() == -3.0);
		REQUIRE(complexResult.Im() == 6.0);
	}
}


TEST_CASE("4.1) Деление двух комплексных чисел")
{
	SECTION("деление положительных комплексных")
	{
		Complex complex1(2, 4);
		Complex complex2(8, 24);

		auto complexResult = complex1 / complex2;

		REQUIRE(complexResult.Re() == 0.175);
		REQUIRE(complexResult.Im() == -0.025);
	}

	SECTION("деление отрицательных комплексных")
	{
		Complex complex1(-2, -4);
		Complex complex2(-8, -24);

		auto complexResult = complex1 / complex2;

		REQUIRE(complexResult.Re() == 0.175);
		REQUIRE(complexResult.Im() == -0.025);
	}
}

TEST_CASE("4.2) Деление комплексного числа и действительного")
{
	SECTION("Деление на положительное действительное")
	{
		Complex complex(12, -6);
		double real = 4.0;

		auto complexResult = complex / real;

		REQUIRE(complexResult.Re() == 3.0);
		REQUIRE(complexResult.Im() == -1.5);
	}

	SECTION("Деление на отрицательное действительное")
	{
		Complex complex(12, -6);
		double real = -4.0;

		auto complexResult = complex / real;

		REQUIRE(complexResult.Re() == -3.0);
		REQUIRE(complexResult.Im() == 1.5);
	}
}


TEST_CASE("5) Унарные + и -")
{
	SECTION("Унарный +")
	{
		Complex complex(1, 2);

		REQUIRE((+complex).Re() == complex.Re());
		REQUIRE((+complex).Im() == complex.Im());
	}

	SECTION("Унарный -")
	{
		Complex complex(1, 2);

		REQUIRE((-complex).Re() == -(complex.Re()));
		REQUIRE((-complex).Im() == -(complex.Im()));
	}
}


TEST_CASE("6-9) комплексные числа возвращают копию комплексного числа и противоположное комплексное число")
{
	SECTION("+= комплексных чисел")
	{
		Complex complex1(12, -34);
		Complex complex2(-56, 78);

		Complex& complexCopy = complex1;

		complex1 += complex2;

		REQUIRE(complex1.Re() == -44.0);
		REQUIRE(complex1.Im() == 44.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex1)); //Проверка что complexCopy и complex имеют один и тот же адрес в памяти, что complexCopy является ссылкой на объект complex.
	}

	SECTION("+= комплексного и действительного числа")
	{
		Complex complex(12, -34);
		double real = 56.0;

		Complex& complexCopy = complex;

		complex += real;

		REQUIRE(complex.Re() == 68.0);
		REQUIRE(complex.Im() == -34.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex));
	}

	SECTION("-= двух комплексных чисел")
	{
		Complex complex1(12, -34);
		Complex complex2(-56, 78);

		Complex& complexCopy = complex1;

		complex1 -= complex2;

		REQUIRE(complex1.Re() == 68.0);
		REQUIRE(complex1.Im() == -112.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex1));
	}

	SECTION("-= комплексного и действительного числа")
	{
		Complex complex(12, -34);
		double real = 56.0;

		Complex& complexCopy = complex;

		complex -= real;

		REQUIRE(complex.Re() == -44.0);
		REQUIRE(complex.Im() == -34.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex));
	}
}
