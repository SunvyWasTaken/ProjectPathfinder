#include "SfmlText.h"

std::string SfmlText::GetString() const
{
	return CurrentText.getString();
}

void SfmlText::SetString(const std::string& text)
{
	CurrentText.setString(text);
}

FColor SfmlText::GetColor() const
{
	FColor color = FColor(CurrentText.getColor().r, CurrentText.getColor().g, CurrentText.getColor().b, CurrentText.getColor().a);
	return color;
}

void SfmlText::SetColor(const FColor& color)
{
	CurrentText.setColor(sf::Color(color.R, color.G, color.B, color.A));
}

unsigned int SfmlText::GetTextSize() const
{
	return CurrentText.getCharacterSize();
}

void SfmlText::SetTextSize(unsigned int size)
{
	CurrentText.setCharacterSize(size);
}
