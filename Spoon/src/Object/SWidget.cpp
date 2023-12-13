#include <snpch.h>
#include "SWidget.h"
#include "Spoon/Events/SpoonEvent.h"
#include "Spoon/Events/MouseEvent.h"

void SWidget::OnEvent(SpoonEvent& event)
{
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(SWidget::OnMouseEvent));
}

bool SWidget::OnMouseEvent(MouseMovedEvent& mouseMoved)
{
	return false;
}
