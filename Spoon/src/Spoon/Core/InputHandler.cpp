#include "InputHandler.h"

void InputHandler::BindInput(void* objRef, std::function<void()>& func)
{
	Truc tmpFollower(objRef, func);
	auto tmp = std::find(ListFollower.begin(), ListFollower.end(), tmpFollower);
	if (tmp == ListFollower.end())
		return;

	ListFollower.push_back(tmpFollower);
}

void InputHandler::MassSuicide()
{
	for (auto follower : ListFollower)
	{
		follower.first
	}
}
