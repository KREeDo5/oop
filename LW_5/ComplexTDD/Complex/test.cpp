#define CATCH_CONFIG_MAIN
#include "D:/Repos/VOLGATECH_WORK/OOP/LW_5/ComplexTDD/catch2/catch.hpp"

TEST_CASE("����������� ����� ����� ���������������� � �������� � ����", "[complex_class]")
{
	SECTION("������������� c �������.����������")
	{	
		Complex complex(3, 4);													 //3 + 4i

		REQUIRE(complex.Re() == 3.0);											 //������� �������������� ����� ������������ �����
		REQUIRE(complex.Im() == 4.0);											 //���������� ������ ����� ������������ �����

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re())); //���������� �������� ������������ �����

		REQUIRE(complex.GetMagnitude() == 5.0);									 //���������� ������ ������������ �����
	}

	SECTION("������������� c �����.����������")
	{
		Complex complex(-3, -4);

		REQUIRE(complex.Re() == -3.0);
		REQUIRE(complex.Im() ==- 4.0);

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re()));

		REQUIRE(complex.GetMagnitude() == 5.0);
	}

	SECTION("������������� c ���������� ����������")
	{
		Complex complex(3, -4);

		REQUIRE(complex.Re() == 3.0);
		REQUIRE(complex.Im() == -4.0);

		REQUIRE(complex.GetArgument() == std::tan(complex.Im() / complex.Re()));

		REQUIRE(complex.GetMagnitude() == 5.0);

	}

}
