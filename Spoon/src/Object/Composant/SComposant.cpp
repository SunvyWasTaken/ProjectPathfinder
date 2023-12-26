
#include "SComposant.h"
#include <snpch.h>

SComposant::SComposant(SComposant* owner) : 
	SObject(),
	Owner(owner)
{}

SComposant::~SComposant()
{}

