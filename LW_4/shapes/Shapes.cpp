#include "Shapes.h"
#include <optional>
#include <sstream>
#include <iomanip>
#include <algorithm>

const std::map<std::string, Shapes::ShapeType> mapStringToShapeType =
{
	{ 
		LINE,
		Shapes::ShapeType::CLineSegment
	},
	{ 
		TRIANGLE,
		Shapes::ShapeType::CTriangle
	},
	{ 
		RECTANGLE,
		Shapes::ShapeType::CRectangle
	},
	{ 
		CIRCLE,
		Shapes::ShapeType::CCircle
	}
};

bool Shapes::ReadShapeData(std::istream& input)
{
	std::string inputStr, shapeTypeStr;
	std::stringstream iss;
	std::optional<ShapeType> shapeType;

	while (std::getline(input, inputStr))
	{
		iss.clear();
		iss << inputStr;
		iss >> shapeTypeStr;
		shapeType.reset();

		auto it = mapStringToShapeType.find(shapeTypeStr);
		if (it != mapStringToShapeType.end())
		{
			shapeType = it->second;
		}

		if (!shapeType.has_value())
		{
			return false;
		}

		switch (*shapeType)
		{
		case ShapeType::CLineSegment:
			if (!ReadLineSegmentData(iss))
			{
				return false;
			}
			break;

		case ShapeType::CTriangle:
			if (!ReadTriangleData(iss))
			{
				return false;
			}
			break;

		case ShapeType::CRectangle:
			if (!ReadRectangleData(iss))
			{
				return false;
			}
			break;

		case ShapeType::CCircle:
			if (!ReadCircleData(iss))
			{
				return false;
			}
			break;

		default:
			return false;
		}
	}

	return true;
}

void Shapes::PrintMaxAreaShapeInfo(std::ostream& output) const
{
	if (auto maxAreaShapePtr = FindMaxAreaShape())
	{
		output << maxAreaShapePtr->ToString();
	}
	else
	{
		output << ERROR_PRINT_MAX_AREA << std::endl;
	}
}

void Shapes::PrintMinPerimeterShapeInfo(std::ostream& output) const
{
	if (auto minPerimeterShapePtr = FindMinPerimeterShape())
	{
		output << minPerimeterShapePtr->ToString();
	}
	else
	{
		output << ERROR_PRINT_MIN_PERIMETER << std::endl;
	}
}

std::shared_ptr<IShape> Shapes::FindMaxAreaShape() const
{
	if (m_shapes.empty())
	{
		return {};
	}

	std::shared_ptr<IShape> maxAreaShape = m_shapes[0];

	double maxArea = m_shapes[0]->GetArea();
	double area;
	for (size_t i = 1; i < m_shapes.size(); ++i)
	{
		if ((area = m_shapes[i]->GetArea()) > maxArea)
		{
			maxArea = area;
			maxAreaShape = m_shapes[i];
		}
	}
	return maxAreaShape;
}

std::shared_ptr<IShape> Shapes::FindMinPerimeterShape() const
{
	if (m_shapes.empty())
	{
		return {};
	}

	std::shared_ptr<IShape> minPerimeterShape = m_shapes[0];

	double minPerimeter = m_shapes[0]->GetPerimeter();
	double perimeter;
	for (size_t i = 1; i < m_shapes.size(); ++i)
	{
		if ((perimeter = m_shapes[i]->GetPerimeter()) < minPerimeter)
		{
			minPerimeter = perimeter;
			minPerimeterShape = m_shapes[i];
		}
	}

	return minPerimeterShape;
}

bool Shapes::ReadLineSegmentData(std::istream& input)
{
	double startX, startY, endX, endY;
	uint32_t outlineColor;

	if (input >> startX >> startY >> endX >> endY >> std::hex >> outlineColor)
	{
		m_shapes.push_back(
			std::make_shared<CLineSegment>(
				CPoint(
					startX,
					startY
				), 
				CPoint(
					endX, 
					endY
				), 
				outlineColor
			)
		);
		return true;
	}

	return false;
}

bool Shapes::ReadTriangleData(std::istream& input)
{
	double vertex1X, vertex1Y, vertex2X, vertex2Y, vertex3X, vertex3Y;
	uint32_t outlineColor, fillColor;

	if (input >> vertex1X >> vertex1Y >> vertex2X >> vertex2Y >> vertex3X >> vertex3Y >> std::hex >> outlineColor >> std::hex >> fillColor)
	{
		m_shapes.push_back(std::make_shared<CTriangle>(
			CPoint(
				vertex1X, 
				vertex1Y
			), 
			CPoint(
				vertex2X, 
				vertex2Y
			), 
			CPoint(
				vertex3X, 
				vertex3Y
			), 
			outlineColor, 
			fillColor)
		);
		return true;
	}

	return false;
}

bool Shapes::ReadRectangleData(std::istream& input)
{
	double leftTopX, leftTopY, width, height;
	uint32_t outlineColor, fillColor;

	if (input >> leftTopX >> leftTopY >> width >> height >> std::hex >> outlineColor >> std::hex >> fillColor)
	{
		m_shapes.push_back(
			std::make_shared<CRectangle>(
				CPoint(
					leftTopX, 
					leftTopY
				), 
				width,
				height, 
				outlineColor, 
				fillColor
			)
		);
		return true;
	}

	return false;
}

bool Shapes::ReadCircleData(std::istream& input)
{
	double centerX, centerY, radius;
	uint32_t outlineColor, fillColor;

	if (input >> centerX >> centerY >> radius >> std::hex >> outlineColor >> std::hex >> fillColor)
	{
		m_shapes.push_back(
			std::make_shared<CCircle>(
				CPoint(
					centerX, 
					centerY
				), 
				radius, 
				outlineColor, 
				fillColor
			)
		);
		return true;
	}

	return false;
}