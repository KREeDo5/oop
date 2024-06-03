#pragma once
#include "IShape.h"

const std::string FILL_COLOR = "fill color: ";

class ISolidShape : public IShape
{
public:
	virtual ~ISolidShape() = default;

	virtual uint32_t GetFillColor() const = 0;
};
