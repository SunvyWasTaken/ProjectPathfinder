#pragma once
#include "Spoon/Core/ObjectRender.h"

namespace sf { class RectangleShape; }

class SfmlRender : public ObjectRender
{
public:
	
	SfmlRender(FVector2D* loc = nullptr, FVector2D* size = nullptr, FColor* color = nullptr);

	virtual ~SfmlRender() { delete shape; };

	void SpoonDraw(class Window* windowRef) override;

private:

	sf::RectangleShape* shape;

};
