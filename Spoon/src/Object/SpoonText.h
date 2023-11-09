#pragma once

#include "SWidget.h"

class SPOON_API SpoonText : public SWidget
{
public:
	
	SpoonText(SWidget* parent) : SWidget(parent) {};

	SpoonText(SWidget* parent, std::string text) : SWidget(parent) {};

	virtual ~SpoonText() {};

	static SpoonText* Create(SWidget* parent = nullptr);

	virtual std::string GetString() const = 0;

	virtual void SetString(const std::string& text) = 0;

	virtual FColor GetColor() const = 0;

	virtual void SetColor(const FColor& color) = 0;

	virtual unsigned int GetTextSize() const = 0;

	virtual void SetTextSize(unsigned int size) = 0;

};