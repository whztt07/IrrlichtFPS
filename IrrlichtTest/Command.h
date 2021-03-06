#pragma once

enum E_COMMAND_TYPE
{
	ECT_FORWARD = 0,
	ECT_BACKWARD,
	ECT_LEFT,
	ECT_RIGHT,
	ECT_ATTACK,
	ECT_ATTACK2,
	ECT_RELOAD,
	ECT_QUICKSWITCH,
	ECT_SWITCHPRIMARY,
	ECT_SWITCHSECONDARY,
	ECT_SWITCHKNIFE,
	ECT_JUMP,
	ECT_CROUCH,
	ECT_WALK,
	E_COMMAND_TYPE_COUNT
};

class Command
{
public:

	Command() { }
	virtual ~Command() { }

	virtual void run(class Character * player, bool flag, irr::u32 time) = 0;

	const irr::core::stringc& getName() const { return name; }

	E_COMMAND_TYPE getType() { return type; }

protected:

	irr::core::stringc name;

	E_COMMAND_TYPE type;

private:

	static Command * commands[E_COMMAND_TYPE_COUNT];

public:

	static void initCommands();

	static void cleanupCommands();

	static Command * getCommand(irr::core::stringc name);
	static Command * getCommand(E_COMMAND_TYPE type) { return commands[type]; }
};