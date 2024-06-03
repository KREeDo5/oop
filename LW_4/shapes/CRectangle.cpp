#include "CRectangle.h"
#include <sstream>
#include <iomanip>

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

std::string CRectangle::ToString() const
{
	std::ostringstream oss;

	oss << std::setprecision(ACCURACY) << std::fixed;

	oss << TYPE << std::endl
		<< LEFT_TOP << OPEN_BRACKET << m_leftTop.x << COMMA << m_leftTop.y << CLOSE_BRACKET << std::endl
		<< WIDTH << m_width << std::endl
		<< HEIGHT << m_height << std::endl
		<< AREA << GetArea() << std::endl
		<< PERIMETER << GetPerimeter() << std::endl
		<< OUTLINE_COLOR << std::hex << GetOutlineColor() << std::endl
		<< FILL_COLOR << std::hex << GetFillColor() << std::endl;

	return oss.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(m_leftTop.x + m_width, m_leftTop.y + m_height);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}