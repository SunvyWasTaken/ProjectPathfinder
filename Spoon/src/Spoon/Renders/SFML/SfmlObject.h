#pragma once
#include "Spoon/Core/ObjectRender.h"

namespace sf { class RectangleShape; }

class SfmlRender : public ObjectRender
{
public:
	
	SfmlRender(FVector2D* loc, FVector2D* size, FColor* color);

	virtual ~SfmlRender() { delete shape; };

	void SpoonDraw(class Window* windowRef) override;

private:

	sf::RectangleShape* shape;

};
