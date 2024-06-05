#include "D:/Repos/VOLGATECH_WORK/OOP/catch2/catch.hpp"
#include "../shapes/Shapes.h"
#include <sstream>
#include <float.h>
#include <math.h>

TEST_CASE("Тестирование классов фигур")
{
	setlocale(LC_ALL, "Russian");

	SECTION("Создание линии 5 6 9 1 00FF00")
	{
		CLineSegment line = CLineSegment(CPoint(5, 6), CPoint(9, 1), 16724991);
		REQUIRE(line.GetArea() == 0);
		REQUIRE(fabs(line.GetPerimeter() - 6.4031242374) < DBL_EPSILON);
		REQUIRE(line.GetStartPoint() == CPoint(5, 6));
		REQUIRE(line.GetEndPoint() == CPoint(9, 1));
		REQUIRE(line.GetOutlineColor() == 16724991);
		REQUIRE(line.ToString() == "type: line segment\nleft start point: (5.00, 6.00)\nend point: (9.00, 1.00)\nlength: 6.40\noutline color : ff33ff\n");
	}

	SECTION("Создание круга 0 0 15 00FF33FF EEFFBBFF")
	{
		CCircle circle = CCircle(CPoint(0, 0), 15, 16724991, 4009737215);
		REQUIRE(circle.GetCenter() == CPoint(0, 0));
		REQUIRE(circle.GetRadius() == 15.00);
		REQUIRE(fabs(circle.GetArea() - 706.8583470577) < DBL_EPSILON);
		REQUIRE(circle.GetPerimeter() == 6.4031242374);
		REQUIRE(circle.GetOutlineColor() == 16724991);
		REQUIRE(circle.GetFillColor() == 4009737215);
		REQUIRE(circle.ToString() == "type: circle\ncenter: (0.00, 0.00)\nradius: 15.00\narea: 706.86\nperimeter: 94.25\noutline color: ff33ff\nfill color: eeffbbff\n");
	}

	SECTION("Создание прямоугольника 5 -6 10 10 00FF33FF EEFFBBFF")
	{
		CRectangle rectangle = CRectangle(CPoint(5, -6), 10, 10, 16724991, 4009737215);
		REQUIRE(rectangle.GetArea() == 100.00);
		REQUIRE(rectangle.GetPerimeter() == 40.00);
		REQUIRE(rectangle.GetHeight() == 10);
		REQUIRE(rectangle.GetWidth() == 10);
		REQUIRE(rectangle.GetLeftTop() == CPoint(5, -6));
		REQUIRE(rectangle.GetRightBottom() == CPoint(rectangle.GetLeftTop().x + rectangle.GetWidth(), rectangle.GetLeftTop().y + rectangle.GetHeight()));
		REQUIRE(rectangle.GetOutlineColor() == 16724991);
		REQUIRE(rectangle.GetFillColor() == 4009737215);
		REQUIRE(rectangle.ToString() == "type: rectangle\nleft top: (5.00, -6.00)\nwidth: 10.00\nheight: 10.00\narea: 100.00\nperimeter: 40.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}

	SECTION("Создание треугольника 0 0 3 4 6 0 00FF33FF EEFFBBFF")
	{
		CTriangle triangle = CTriangle(CPoint(0, 0), CPoint(3, 4), CPoint(6, 0), 16724991, 4009737215);
		REQUIRE(triangle.GetArea() == 12.00);
		REQUIRE(triangle.GetPerimeter() == 16.00);
		REQUIRE(triangle.GetVertex1() == CPoint(0, 0));
		REQUIRE(triangle.GetVertex2() == CPoint(3, 4));
		REQUIRE(triangle.GetVertex3() == CPoint(6, 0));
		REQUIRE(triangle.GetOutlineColor() == 16724991);
		REQUIRE(triangle.GetFillColor() == 4009737215);
		REQUIRE(triangle.ToString() == "type: triangle\nvertex 1: (0.00, 0.00)\nvertex 2: (3.00, 4.00)\nvertex 3: (6.00, 0.00)\narea: 12.00\nperimeter: 16.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}
}

TEST_CASE("ReadShapeData считывает данные из istream и сохраняет объект.")
{
	setlocale(LC_ALL, "Russian");

	Shapes shapes;
	std::ostringstream oss;

	SECTION("Обработка данных с недопустимым типом фигуры")
	{
		std::istringstream iss("table 0 0 3 4 00FF00FF");
		REQUIRE(!shapes.ReadShapeData(iss));
	}

	SECTION("Обработка данных о линии")
	{
		std::istringstream iss("line 0 0 3 4 00FF00FF");
		REQUIRE(shapes.ReadShapeData(iss));
	}

	SECTION("Обработка некорректных данных о линии")
	{
		std::istringstream iss("line 0 0 3");
		REQUIRE(!shapes.ReadShapeData(iss));
	}

	SECTION("Обработка данных треугольника")
	{
		std::istringstream iss("triangle 0 0 3 4 6 0 00FF00FF EEFFAAFF");
		REQUIRE(shapes.ReadShapeData(iss));
	}

	SECTION("Обработка данных прямоугольника")
	{
		std::istringstream iss("rectangle 0 10 20 10 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
	}

	SECTION("Обработка данных круга")
	{
		std::istringstream iss("circle 10 10 20 22AA33FF CCFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
	}
}

TEST_CASE("FindMaxAreaShape ищет фигуру максимальной площади.")
{
	setlocale(LC_ALL, "Russian");

	Shapes shapes;
	std::ostringstream oss;

	SECTION("Если нет фигур")
	{
		shapes.PrintMaxAreaShapeInfo(oss);
		REQUIRE(oss.str() == "Failed to print shape data.\n");
	}

	SECTION("Если есть одна фигура")
	{
		std::istringstream iss("rectangle 0 10 20 10 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
		shapes.PrintMaxAreaShapeInfo(oss);
		REQUIRE(oss.str() == "type: rectangle\nleft top: (0.00, 10.00)\nwidth: 20.00\nheight: 10.00\narea: 200.00\nperimeter: 60.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}

	SECTION("Находит прямоугольник максимальной площади: площадь первого прямоугольника = 50, второго = 100, третьего = 15")
	{
		std::istringstream iss("rectangle 1 3 10 5 00FF33FF EEFFBBFF\nrectangle 5 -6 10 10 00FF33FF EEFFBBFF\nrectangle -7 4 1 15 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
		shapes.PrintMaxAreaShapeInfo(oss);
		REQUIRE(oss.str() == "type: rectangle\nleft top: (5.00, -6.00)\nwidth: 10.00\nheight: 10.00\narea: 100.00\nperimeter: 40.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}

	SECTION("Находит круг максимальной площади среди других типов фигур: площадь прямоугольника = 50, треугольника = 12, круга = 706,86.")
	{
		std::istringstream iss("rectangle 1 3 10 5 00FF33FF EEFFBBFF\ntriangle 0 0 3 4 6 0 00FF33FF EEFFBBFF\ncircle 0 0 15 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
		shapes.PrintMaxAreaShapeInfo(oss);
		REQUIRE(oss.str() == "type: circle\ncenter: (0.00, 0.00)\nradius: 15.00\narea: 706.86\nperimeter: 94.25\noutline color: ff33ff\nfill color: eeffbbff\n");
	}
}

TEST_CASE("FindMinPerimeterShape находит фигуру с минимальным периметром")
{
	setlocale(LC_ALL, "Russian");

	Shapes shapes;
	std::ostringstream oss;

	SECTION("Если нет фигур")
	{
		shapes.PrintMinPerimeterShapeInfo(oss);
		REQUIRE(oss.str() == "Failed to print shape data.\n");
	}

	SECTION("Если есть одна форма")
	{
		std::istringstream iss("rectangle 0 10 20 10 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
		shapes.PrintMinPerimeterShapeInfo(oss);
		REQUIRE(oss.str() == "type: rectangle\nleft top: (0.00, 10.00)\nwidth: 20.00\nheight: 10.00\narea: 200.00\nperimeter: 60.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}

	SECTION("Находит минимальный периметр прямоугольника: периметр первого прямоугольника = 30, второго = 40, третьего = 32.")
	{
		std::istringstream iss("rectangle 1 3 10 5 00FF33FF EEFFBBFF\nrectangle 5 -6 10 10 00FF33FF EEFFBBFF\nrectangle -7 4 1 15 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
		shapes.PrintMinPerimeterShapeInfo(oss);
		REQUIRE(oss.str() == "type: rectangle\nleft top: (1.00, 3.00)\nwidth: 10.00\nheight: 5.00\narea: 50.00\nperimeter: 30.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}

	SECTION("Находит треугольник с минимальным периметром среди других типов фигур: периметр прямоугольника = 30, второго = 16, круга = 94,25.")
	{
		std::istringstream iss("rectangle 1 3 10 5 00FF33FF EEFFBBFF\ntriangle 0 0 3 4 6 0 00FF33FF EEFFBBFF\ncircle 0 0 15 00FF33FF EEFFBBFF");
		REQUIRE(shapes.ReadShapeData(iss));
		shapes.PrintMinPerimeterShapeInfo(oss);
		REQUIRE(oss.str() == "type: triangle\nvertex 1: (0.00, 0.00)\nvertex 2: (3.00, 4.00)\nvertex 3: (6.00, 0.00)\narea: 12.00\nperimeter: 16.00\noutline color: ff33ff\nfill color: eeffbbff\n");
	}
}