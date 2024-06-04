#include "Shapes.h"
#include <iostream>
#include <vector>

const std::string MAX_AREA_SHAPE = "Max Area Shape";
const std::string MIN_PERIMETER_SHAPE = "Min Perimeter Shape";
const std::string ERROR_READ_DATA = "Failed to read data";

int main()
{
	Shapes shapes;

	if (!shapes.ReadShapeData(std::cin))
	{
		std::cout << ERROR_READ_DATA << std::endl;
		return 1;
	}

	std::cout << MAX_AREA_SHAPE << std::endl;
	shapes.PrintMaxAreaShapeInfo(std::cout);
	std::cout << MIN_PERIMETER_SHAPE << std::endl;
	shapes.PrintMinPerimeterShapeInfo(std::cout);

	return 0;
}