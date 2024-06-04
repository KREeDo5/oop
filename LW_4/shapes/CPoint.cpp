#include "CPoint.h"
#include <sstream>

bool CPoint::operator==(const CPoint& other) const
{
	return (this->x == other.x) && (this->y == other.y);
}
