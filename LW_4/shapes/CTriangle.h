#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

const std::string TYPE = "type: triangle";
const std::string VERTEX_FIRST = "vertex 1: ";
const std::string VERTEX_SECOND = "vertex 2: ";
const std::string VERTEX_THIRD = "vertex 3: ";
const int FIRST = 0;
const int SECOND = 1;
const int THIRD = 2;
const int ACCURACY = 2;
const double HALF = 0.5;

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor):
		m_vertex{ vertex1, vertex2, vertex3 }, 
		m_outlineColor(outlineColor), 
		m_fillColor(fillColor) {}

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex[3];
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};