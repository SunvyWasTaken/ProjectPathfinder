#include <snpch.h>
#include "SWidget.h"
#include "Spoon/Events/SpoonEvent.h"
#include "Spoon/Events/MouseEvent.h"
#include "Composant/SComposant.h"

void SWidget::OnEvent(SpoonEvent& event)
{
	for (auto composant : ComposantList)
	{
		composant->OnEvent(event);
	}
}

void SWidget::OnUpdate()
{
	for (auto composant : ComposantList)
	{
		composant->OnUpdate();
	}
}

void SWidget::Render(Window* window)
{}

void SWidget::AddComposant(SComposant* compo)
{
	ComposantList.push_back(compo);
}

