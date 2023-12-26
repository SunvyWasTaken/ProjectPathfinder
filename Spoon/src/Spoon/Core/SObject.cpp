#include "SObject.h"
#include "Level.h"

SObject::SObject() : ObjectTransform()
{
}

SObject::~SObject()
{
}

FVector2D SObject::GetLocation() const
{
	return ObjectTransform.Location;
}

void SObject::SetLocation(const FVector2D& loc)
{
	std::mutex _mutex;
	_mutex.lock();
	ObjectTransform.Location = loc;
	_mutex.unlock();
}

FVector2D SObject::GetSize() const
{
	return ObjectTransform.Size;
}

void SObject::SetSize(const FVector2D& size)
{
	ObjectTransform.Size = size;
}

FTransform SObject::GetTransform() const
{
	return ObjectTransform;
}

void SObject::SetTransform(const FTransform& transform)
{
	ObjectTransform = transform;
}

bool SObject::IsInBound(const FVector2D& _loc)
{
	FVector2D truc = GetLocation() + GetSize();
	if (_loc.X <= truc.X && _loc.X >= GetLocation().X && _loc.Y <= truc.Y && _loc.Y >= GetLocation().Y)
	{
#ifdef DEBUG
		std::cout << "Object coord : " << truc << " , curseur loc : " << _loc << std::endl;
#endif // DEBUG

		return true;
	}
	return false;
}
