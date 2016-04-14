#ifndef Game_h__
#define Game_h__


#include <SFML/Graphics.hpp>
struct GameOverStruct
{
	bool PlayerWin;
	int Wave;
};

class Game
{
public:
	Game();
	~Game(){};

	void Run();

	void Exit()
	{
		m_Exit = true;
	}

	sf::RenderWindow& GetWindow()
	{
		return m_Window;
	}

/*	static void RegisterEventListener(WindowEventListener* EventListener)
	{
		m_EventListener.push_back(EventListener);
	}
	static void UnRegisterEventListener(WindowEventListener* EventListener)
	{
		m_EventListener.remove(EventListener);
        }*/
private:

	// Gibt an ob das Programm beendet werden soll
	bool m_Exit;

	// Fenster auf das gerendert wird
	sf::RenderWindow m_Window;

	// Statemanager
//	StateManager m_StateManager;

	// Standart View
	sf::View m_View;

        //static std::list<WindowEventListener*> m_EventListener;
};
#endif // Game_h__
