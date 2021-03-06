#pragma once

#include "Command.h"

class MoveRight : public Command
{
public:
	MoveRight() : Command()
	{
		name = "right";
		type = ECT_RIGHT;
	}

	~MoveRight()
	{

	}

	void run(Character * player, bool flag, irr::u32 time)
	{
		player->setInputState(EIS_RIGHT, flag, time);
	}
};