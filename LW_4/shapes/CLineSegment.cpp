#include "CLineSegment.h"
#include <sstream>
#include <iomanip>

double CLineSegment::GetArea() const
{	
	double zero = ZERO_AREA;
	return zero;
}

//длина линии
double CLineSegment::GetPerimeter() const
{
	return hypot(m_endPoint.x - m_startPoint.x, m_endPoint.y - m_startPoint.y);
}

std::string CLineSegment::ToString() const
{
	std::ostringstream oss;

	oss << std::setprecision(ACCURACY) << std::fixed;

	oss << TYPE << std::endl
		<< START_POINT << OPEN_BRACKET << m_startPoint.x << COMMA << m_startPoint.y << CLOSE_BRACKET << std::endl
		<< END_POINT << OPEN_BRACKET << m_endPoint.x << COMMA << m_endPoint.y << CLOSE_BRACKET << std::endl
		<< LENGTH << GetPerimeter() << std::endl
		<< OUTLINE_COLOR << std::hex << m_outlineColor << std::endl;

	return oss.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}