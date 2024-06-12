#define CATCH_CONFIG_MAIN
#include "D:/Repos/VOLGATECH_WORK/OOP/LW_5/ComplexTDD/catch2/catch.hpp"

TEST_CASE("комплексные числа можно инициализировать и работать с ними", "[complex_class]")
{
	SECTION("инициализация c положит.значениями")
	{	
		Complex complex(3, 4);													 //3 + 4i

		REQUIRE(complex.Re() == 3.0);											 //возврат действительной части комплексного числа
		REQUIRE(complex.Im() == 4.0);											 //возвращает мнимую часть комплексного числа

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re())); //возвращает аргумент комплексного числа

		REQUIRE(complex.GetMagnitude() == 5.0);									 //возвращает модуль комплексного числа
	}

	SECTION("инициализация c отриц.значениями")
	{
		Complex complex(-3, -4);

		REQUIRE(complex.Re() == -3.0);
		REQUIRE(complex.Im() ==- 4.0);

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re()));

		REQUIRE(complex.GetMagnitude() == 5.0);
	}

	SECTION("инициализация c различными значениями")
	{
		Complex complex(3, -4);

		REQUIRE(complex.Re() == 3.0);
		REQUIRE(complex.Im() == -4.0);

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re()));

		REQUIRE(complex.GetMagnitude() == 5.0);

	}

}
