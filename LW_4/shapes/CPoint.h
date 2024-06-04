#pragma once

struct CPoint
{
public:
	CPoint(double x, double y): x(x), y(y) {}

	double x;
	double y;

	bool operator==(const CPoint& other) const;
};