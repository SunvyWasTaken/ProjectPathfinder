#pragma once
#include "GridSquare.h"
class PortalSquare :
    public GridSquare
{
public:
    PortalSquare() : p_PortalDestination(nullptr), GridSquare() {};

    GridSquare* p_PortalDestination;
};

