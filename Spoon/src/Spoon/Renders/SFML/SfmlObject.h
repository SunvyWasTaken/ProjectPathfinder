#pragma once
#include "Spoon/Core/ObjectRender.h"

namespace sf { class RectangleShape; }

class SfmlRender : public ObjectRender
{
public:
	
	SfmlRender();

	virtual ~SfmlRender() { delete shape; };

	void SpoonDraw(class Window* windowRef) override;

	void Init() override;

private:

	sf::RectangleShape* shape;

};
