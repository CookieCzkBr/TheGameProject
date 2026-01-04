#include "Game.h"

int main()
{
	GameConfig debugMode;
	debugMode.showConsoleLog = true;
	debugMode.appTitle = "Game Title";

	Game app(debugMode);
	app.run();
	return 0;
}