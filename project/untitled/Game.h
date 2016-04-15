#ifndef Game_h__
#define Game_h__

#include "EventListener.h"
#include "Logfile.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <deque>


using namespace std;
struct GameOverStruct {
    bool PlayerWin;
    int Wave;
};

class Game {
private:
    static list<WindowEventListener*> m_EventListener;
    static deque<WindowEventListener*> m_EventListener2;

public:
    Game();
    //	~Game(){};

    void Run();

    void Exit()
    {
        m_Exit = true;
    }

    sf::RenderWindow& GetWindow()
    {
        return m_Window;
    }

    static void RegisterEventListener(WindowEventListener* EventListener)
    {
        WindowEventListener* zz=0;
        m_EventListener.push_back(zz);
        m_EventListener.push_back(EventListener);
        m_EventListener2.push_back(zz);
    }
    static void UnRegisterEventListener(WindowEventListener* EventListener)
    {
        m_EventListener.remove(EventListener);
    }

private:
    // Gibt an ob das Programm beendet werden soll
    bool m_Exit;

    // Fenster auf das gerendert wird
    sf::RenderWindow m_Window;

    // Statemanager
    StateManager m_StateManager;

    // Standart View
    sf::View m_View;
};
#endif // Game_h__
