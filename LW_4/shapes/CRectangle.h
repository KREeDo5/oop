#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

const std::string TYPE_RECTANGLE = "type: rectangle";
const std::string WIDTH = "width: ";
const std::string HEIGHT = "height: ";
const std::string LEFT_TOP = "left top: ";
const int ACCURACY_RECTANGLE = 2;

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor): 
		m_leftTop(leftTop),
		m_width(width),
		m_height(height),
		m_outlineColor(outlineColor),
		m_fillColor(fillColor) {}

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};