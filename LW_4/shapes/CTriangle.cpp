#include "CTriangle.h"
#include <sstream>
#include <iomanip>

double CTriangle::GetArea() const
{
	return HALF * abs(m_vertex[FIRST].x * (m_vertex[SECOND].y - m_vertex[THIRD].y)
		+ m_vertex[SECOND].x * (m_vertex[THIRD].y - m_vertex[FIRST].y) + m_vertex[THIRD].x * (m_vertex[FIRST].y - m_vertex[SECOND].y));
}

double CTriangle::GetPerimeter() const
{
	return hypot(m_vertex[FIRST].x - m_vertex[SECOND].x, m_vertex[FIRST].y - m_vertex[SECOND].y)
		+ hypot(m_vertex[SECOND].x - m_vertex[THIRD].x, m_vertex[SECOND].y - m_vertex[THIRD].y)
		+ hypot(m_vertex[FIRST].x - m_vertex[THIRD].x, m_vertex[FIRST].y - m_vertex[THIRD].y);
}

std::string CTriangle::ToString() const
{
	std::ostringstream oss;

	oss << std::setprecision(ACCURACY_TRIANGLE) << std::fixed;

	oss << TYPE_TRIANGLE << std::endl
		<< VERTEX_FIRST << OPEN_BRACKET << m_vertex[FIRST].x << COMMA << m_vertex[FIRST].y << CLOSE_BRACKET << std::endl
		<< VERTEX_SECOND << OPEN_BRACKET << m_vertex[SECOND].x << COMMA << m_vertex[SECOND].y << CLOSE_BRACKET << std::endl
		<< VERTEX_THIRD << OPEN_BRACKET << m_vertex[THIRD].x << COMMA << m_vertex[THIRD].y << CLOSE_BRACKET << std::endl
		<< AREA << GetArea() << std::endl
		<< PERIMETER << GetPerimeter() << std::endl
		<< OUTLINE_COLOR << std::hex << m_outlineColor << std::endl
		<< FILL_COLOR << std::hex << m_fillColor << std::endl;

	return oss.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex[FIRST];
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex[SECOND];
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex[THIRD];
}