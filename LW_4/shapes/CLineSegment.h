#pragma once
#include "IShape.h"
#include "CPoint.h"

const std::string TYPE = "type: line segment";
const int ACCURACY = 2;
const double ZERO_AREA = 0.0;

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor):
		m_startPoint(startPoint), 
		m_endPoint(endPoint), 
		m_outlineColor(outlineColor) {}

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor;
};