#pragma once
#include "Object/SpoonText.h"
#include <SFML/Graphics/Text.hpp>

class SfmlText : public SpoonText
{
public:
	
	SfmlText(SWidget* parent) : SpoonText(parent) { SetString("TextBlock"); };

	SfmlText(SWidget* parent, std::string text) : SpoonText(parent, text) { SetString(text); };

	virtual std::string GetString() const override;

	virtual void SetString(const std::string& text) override;

	virtual FColor GetColor() const override;

	virtual void SetColor(const FColor& color) override;

	virtual unsigned int GetTextSize() const override;

	virtual void SetTextSize(unsigned int size) override;


protected:
	sf::Text CurrentText;

};