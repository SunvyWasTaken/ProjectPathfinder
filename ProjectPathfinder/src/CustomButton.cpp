#include "CustomButton.h"

#include "CustomNode.h"

CustomButton::CustomButton(SComposant* owner) : SButton(owner)
{
}

void CustomButton::OnPressed()
{
	p_node->CycleState();
}
