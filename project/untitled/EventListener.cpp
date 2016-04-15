#include "EventListener.h"
#include "Game.h"

WindowEventListener::WindowEventListener()

{
    Game::RegisterEventListener(this);
}

WindowEventListener::~WindowEventListener()
{
    Game::UnRegisterEventListener(this);
}

