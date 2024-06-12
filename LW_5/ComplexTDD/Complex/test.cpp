#define CATCH_CONFIG_MAIN
#include "D:/Repos/VOLGATECH_WORK/OOP/LW_5/ComplexTDD/catch2/catch.hpp"

TEST_CASE("����������� ����� ����� ���������������� � �������� � ����")
{
	setlocale(LC_ALL, "Russian");

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
	setlocale(LC_ALL, "Russian");

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
	setlocale(LC_ALL, "Russian");

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



TEST_CASE("2.1) �������� ���� ����������� �����")
{
	setlocale(LC_ALL, "Russian");

	SECTION("�������� ���� ������������� ����������� �����")
	{
		Complex complex1(12, 34);
		Complex complex2(56, 78);

		auto complexResult = complex1 - complex2;

		REQUIRE(complexResult.Re() == -44.0);
		REQUIRE(complexResult.Im() == -44.0);
	}

	SECTION("�������� ���� ������������� ����������� �����")
	{
		Complex complex1(-12, -34);
		Complex complex2(-56, -78);

		auto complexResult = complex1 - complex2;

		REQUIRE(complexResult.Re() == 44.0);
		REQUIRE(complexResult.Im() == 44.0);
	}
}

TEST_CASE("2.2) �������� ������������ ����� � ���������������")
{
	setlocale(LC_ALL, "Russian");

	SECTION("�������� � ������������� �������������� ������")
	{
		Complex complex(12, -34);
		double real = 56.0;

		auto complexResult = complex - real;

		REQUIRE(complexResult.Re() == -44.0);
		REQUIRE(complexResult.Im() == -34.0);
	}

	SECTION("�������� � ������������� �������������� ������")
	{
		Complex complex(12, -34);
		double real = -56.0;

		auto complexResult = complex - real;

		REQUIRE(complexResult.Re() == 68.0);
		REQUIRE(complexResult.Im() == -34.0);
	}
}

TEST_CASE("3.1) ��������� ����������� �����")
{
	SECTION("��������� ���� ������������� ����������� �����")
	{
		Complex complex1(1, 2);
		Complex complex2(3, 4);

		auto complexResult = complex1 * complex2;

		REQUIRE(complexResult.Re() == -5.0);
		REQUIRE(complexResult.Im() == 10.0);
	}

	SECTION("��������� ���� ������������� ����������� �����")
	{
		Complex complex1(-1, -2);
		Complex complex2(-3, -4);

		auto complexResult = complex1 * complex2;

		REQUIRE(complexResult.Re() == -5.0);
		REQUIRE(complexResult.Im() == 10.0);
	}
}

TEST_CASE("3.2) ��������� ������������ ����� � ���������������")
{
	SECTION("��������� �� ������������� ��������������")
	{
		Complex complex(1, -2);
		double real = 3.0;

		auto complexResult = complex * real;

		REQUIRE(complexResult.Re() == 3.0);
		REQUIRE(complexResult.Im() == -6.0);
	}

	SECTION("��������� �� ������������� ��������������")
	{
		Complex complex(1, -2);
		double real = -3.0;

		auto complexResult = complex * real;

		REQUIRE(complexResult.Re() == -3.0);
		REQUIRE(complexResult.Im() == 6.0);
	}
}


TEST_CASE("4.1) ������� ���� ����������� �����")
{
	SECTION("������� ������������� �����������")
	{
		Complex complex1(2, 4);
		Complex complex2(8, 24);

		auto complexResult = complex1 / complex2;

		REQUIRE(complexResult.Re() == 0.175);
		REQUIRE(complexResult.Im() == -0.025);
	}

	SECTION("������� ������������� �����������")
	{
		Complex complex1(-2, -4);
		Complex complex2(-8, -24);

		auto complexResult = complex1 / complex2;

		REQUIRE(complexResult.Re() == 0.175);
		REQUIRE(complexResult.Im() == -0.025);
	}
}

TEST_CASE("4.2) ������� ������������ ����� � ���������������")
{
	SECTION("������� �� ������������� ��������������")
	{
		Complex complex(12, -6);
		double real = 4.0;

		auto complexResult = complex / real;

		REQUIRE(complexResult.Re() == 3.0);
		REQUIRE(complexResult.Im() == -1.5);
	}

	SECTION("������� �� ������������� ��������������")
	{
		Complex complex(12, -6);
		double real = -4.0;

		auto complexResult = complex / real;

		REQUIRE(complexResult.Re() == -3.0);
		REQUIRE(complexResult.Im() == 1.5);
	}
}


TEST_CASE("5) ������� + � -")
{
	SECTION("������� +")
	{
		Complex complex(1, 2);

		REQUIRE((+complex).Re() == complex.Re());
		REQUIRE((+complex).Im() == complex.Im());
	}

	SECTION("������� -")
	{
		Complex complex(1, 2);

		REQUIRE((-complex).Re() == -(complex.Re()));
		REQUIRE((-complex).Im() == -(complex.Im()));
	}
}


TEST_CASE("6-9) ����������� ����� ���������� ����� ������������ ����� � ��������������� ����������� �����")
{
	SECTION("+= ����������� �����")
	{
		Complex complex1(12, -34);
		Complex complex2(-56, 78);

		Complex& complexCopy = complex1;

		complex1 += complex2;

		REQUIRE(complex1.Re() == -44.0);
		REQUIRE(complex1.Im() == 44.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex1)); //�������� ��� complexCopy � complex ����� ���� � ��� �� ����� � ������, ��� complexCopy �������� ������� �� ������ complex.
	}

	SECTION("+= ������������ � ��������������� �����")
	{
		Complex complex(12, -34);
		double real = 56.0;

		Complex& complexCopy = complex;

		complex += real;

		REQUIRE(complex.Re() == 68.0);
		REQUIRE(complex.Im() == -34.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex));
	}

	SECTION("-= ���� ����������� �����")
	{
		Complex complex1(12, -34);
		Complex complex2(-56, 78);

		Complex& complexCopy = complex1;

		complex1 -= complex2;

		REQUIRE(complex1.Re() == 68.0);
		REQUIRE(complex1.Im() == -112.0);

		REQUIRE(std::addressof(complexCopy) == std::addressof(complex1));
	}

	SECTION("-= ������������ � ��������������� �����")
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
