#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>
#include <iomanip>


double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	std::ostringstream oss;

	oss << std::setprecision(ACCURACY_CIRCLE) << std::fixed;

	oss << TYPE_CIRCLE << std::endl
		<< CENTER << OPEN_BRACKET << m_center.x << COMMA << m_center.y << CLOSE_BRACKET << std::endl
		<< RADIUS << m_radius << std::endl
		<< AREA << GetArea() << std::endl
		<< PERIMETER << GetPerimeter() << std::endl
		<< OUTLINE_COLOR << std::hex << GetOutlineColor() << std::endl
		<< FILL_COLOR << std::hex << GetFillColor() << std::endl;

	return oss.str();
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}