#include "Game.h"
Game::Game() : m_Exit(false), m_Window(sf::VideoMode(800,600), "Tower Defence"), m_View(sf::FloatRect(0,0,800,600))
{

    m_Window.setFramerateLimit(1);

    m_Window.setKeyRepeatEnabled(false);
    //потом статистику
    //Gamestates zum Statemanager hinzufügen
    /*
    m_StateManager.AddGamestate("MainMenuState", new MainMenuState(m_Window, m_StateManager));
    m_StateManager.AddGamestate("MainGameState", new MainGameState(m_Window, m_StateManager));
    m_StateManager.AddGamestate("GameOverState", new GameOverState(m_Window, m_StateManager));


    m_StateManager.ChangeGamestate("MainMenuState", 0);
*/

    m_Window.setView(m_View);
}

void Game::Run()
{/*
    //Logfile::GetInstance() << Info << "Gameloop wird betreten" << NewLine;
    */
    //или isOpened???
    while(m_Window.isOpen() && !m_Exit)
	{
		// Window Events verarbeiten
		sf::Event Event;
        /*
        while( m_Window.pollEvent((Event)))
		{
			m_StateManager.HandleEvent(Event);

			for_each(m_EventListener.begin(), m_EventListener.end(), std::bind2nd(std::mem_fun(&WindowEventListener::OnEvent), Event));
            if (Event.type == sf::Event::Closed)
			{
				Exit();
			}
        }*/

		// Gamestate aktualisieren
        m_StateManager.Update();

       // AudioManager::getInstance().Update();

		// Fenster clearen
        //m_Window.Clear();
        m_Window.clear(sf::Color(150,150,150));

		// Gamestate rendern
		m_StateManager.Draw();

		// Fenster anzeigen
        //m_Window.Display();
        m_Window.display();
	}
   // Logfile::GetInstance() << Info << "Gameloop wurde verlassen" << NewLine;
}

//std::list<WindowEventListener*> Game::m_EventListener;
