#include "Game.h"
Game::Game() : m_Exit(false), m_Window(sf::VideoMode(800,600), "Tower Defence"), m_View(sf::FloatRect(0,0,800,600))
{
	//m_Window.SetFramerateLimit(1);
	m_Window.EnableKeyRepeat(false);

	// Gamestates zum Statemanager hinzufügen
	m_StateManager.AddGamestate("MainMenuState", new MainMenuState(m_Window, m_StateManager));
 	m_StateManager.AddGamestate("MainGameState", new MainGameState(m_Window, m_StateManager));
	m_StateManager.AddGamestate("GameOverState", new GameOverState(m_Window, m_StateManager));
 	


	m_StateManager.ChangeGamestate("MainMenuState", 0);

	m_Window.SetView(m_View);
}

void Game::Run()
{
	Logfile::GetInstance() << Info << "Gameloop wird betreten" << NewLine;
	while(m_Window.IsOpened() && !m_Exit)
	{
		// Window Events verarbeiten
		sf::Event Event;
		while(m_Window.GetEvent(Event))
		{
			m_StateManager.HandleEvent(Event);
			for_each(m_EventListener.begin(), m_EventListener.end(), std::bind2nd(std::mem_fun(&WindowEventListener::OnEvent), Event));
			if (Event.Type == sf::Event::Closed)
			{
				Exit();
			}
		}

		// Gamestate aktualisieren
		m_StateManager.Update();

		AudioManager::GetInstance().Update();

		// Fenster clearen
		m_Window.Clear(sf::Color(150,150,150));

		// Gamestate rendern
		m_StateManager.Draw();

		// Fenster anzeigen
		m_Window.Display();
	}
	Logfile::GetInstance() << Info << "Gameloop wurde verlassen" << NewLine;
}

std::list<WindowEventListener*> Game::m_EventListener;
