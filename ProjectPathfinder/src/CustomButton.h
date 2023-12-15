#pragma once
#include "Spoon.h"

class CustomNode;

class CustomButton :
    public SButton
{
public:
    CustomButton(SComposant* owner = nullptr);

    void OnPressed() override;

    CustomNode* p_node;
};

