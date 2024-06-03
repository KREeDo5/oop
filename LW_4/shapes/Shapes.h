#pragma once
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <iostream>
#include <vector>
#include <map>
#include <memory>

const std::string LINE = "line";
const std::string TRIANGLE = "triangle";
const std::string RECTANGLE = "rectangle";
const std::string CIRCLE = "circle";
const std::string ERROR_PRINT_MAX_AREA = "ERROR print max area";
const std::string ERROR_PRINT_MIN_PERIMETER = "ERROR print min perimeter";

class Shapes
{
public:
	enum class ShapeType
	{
		CLineSegment,
		CTriangle,
		CRectangle,
		CCircle
	};

	bool ReadShapeData(std::istream& input);
	void PrintMaxAreaShapeInfo(std::ostream& output) const;
	void PrintMinPerimeterShapeInfo(std::ostream& output) const;

private:
	std::shared_ptr<IShape> FindMaxAreaShape() const;
	std::shared_ptr<IShape> FindMinPerimeterShape() const;

	bool ReadLineSegmentData(std::istream& input);
	bool ReadTriangleData(std::istream& input);
	bool ReadRectangleData(std::istream& input);
	bool ReadCircleData(std::istream& input);

	std::vector<std::shared_ptr<IShape>> m_shapes;
};