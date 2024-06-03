#pragma once
#include <string>

const std::string START_POINT = "start point: ";
const std::string END_POINT = "end point: ";
const std::string LENGTH = "length: ";
const std::string OUTLINE_COLOR = "outline color: ";
const std::string AREA = "area: ";
const std::string PERIMETER = "perimeter: ";
const std::string OPEN_BRACKET = "(";
const std::string CLOSE_BRACKET = ")";
const std::string COMMA = ", ";

class IShape
{
public:
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
};
