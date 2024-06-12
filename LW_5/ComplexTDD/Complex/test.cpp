#define CATCH_CONFIG_MAIN
#include "D:/Repos/VOLGATECH_WORK/OOP/LW_5/ComplexTDD/catch2/catch.hpp"

TEST_CASE("����������� ����� ����� ���������������� � �������� � ����")
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


TEST_CASE("1.1) ����� ����������� �����")
{
	SECTION("����� ���� ����������� ����� � �������������� �������")
	{
		Complex complex1(12, 34);
		Complex complex2(56, 78);

		auto complexResult = complex1 + complex2;

		REQUIRE(complexResult.Re() == 68.0);  // 12 + 56 = 68
		REQUIRE(complexResult.Im() == 112.0); // 34 + 78 = 112
	}


	SECTION("����� ���� ����������� ����� � �������������� �������")
	{
		Complex complex1(-12, -34);
		Complex complex2(-56, -78);

		auto complexResult = complex1 + complex2;

		REQUIRE(complexResult.Re() == -68.0);  // -12 - 56 = -68
		REQUIRE(complexResult.Im() == -112.0); // -34 - 78 = -112
	}

	SECTION("����� ���� ����������� ����� � ���������� �������")
	{
		Complex complex1(12, -34);
		Complex complex2(-56, 78);

		auto complexResult = complex1 + complex2;

		REQUIRE(complexResult.Re() == -44.0); // 12 - 56 = -(56 - 12) = -44 
		REQUIRE(complexResult.Im() == 44.0);  // -34 + 78 = 44
	}
}

TEST_CASE("1.2) ����� ������������ � ��������������� �����")
{
	SECTION("����� ������������ ����� � ������������� ��������������")
	{
		Complex complex(12, -34);
		double real = 56.0;

		auto complexResult = complex + real;

		REQUIRE(complexResult.Re() == 68.0);
		REQUIRE(complexResult.Im() == -34.0);
	}

	SECTION("����� ������������ ����� � ������������� ��������������")
	{
		Complex complex(12, -34);
		double real = -56.0;

		auto complexResult = complex + real;

		REQUIRE(complexResult.Re() == -44.0);
		REQUIRE(complexResult.Im() == -34.0);
	}
}
