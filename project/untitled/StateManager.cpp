#include "StateManager.h"
//#include "GameState.h"
//#include "Exception.h"
#include "Logfile.h"


StateManager::StateManager()
{
   // m_CurrentGamestate = NULL;
}

StateManager::~StateManager()
{
  //  m_CurrentGamestate = NULL;
    for (std::map<std::string, Gamestate*>::iterator It = m_States.begin(); It != m_States.end(); ++It)
    {
        delete It->second;
    }
    m_States.clear();
}

void StateManager::AddGamestate( const std::string Name, Gamestate* Gamestate )
{
    m_States[Name] = Gamestate;
}
/*
void StateManager::ChangeGamestate( const std::string Name, void* InitializationData )
{
    // Alten Gamestate beenden
    if (m_CurrentGamestate)
    {
        m_CurrentGamestate->Exit();
    }

    // Neuen Gamestate suchen
    std::map<std::string, Gamestate*>::iterator It = m_States.find(Name);
    if(It != m_States.end())
    {
        // Neunen Gamestate setzen
        m_CurrentGamestate = It->second;
    }
    else
    {
        // Gamestate nicht gefunden!
        THROW_EXCEPTION("Der Ganestate " + Name + " konnte nicht gefunden werden")
    }

    // Neuen Gamestate initialisieren
    m_CurrentGamestate->Init(InitializationData);
}
*/
void StateManager::Update()
{
    #ifdef _DEBUG
    if (m_CurrentGamestate == NULL)
    {
        Logfile::GetInstance() << Warning << "Es ist kein Gamestate gesetzt!" << NewLine;
        return;
    }
    #endif
    //m_CurrentGamestate->Update();
}

void StateManager::Draw()
{
    #ifdef _DEBUG
    if (m_CurrentGamestate == NULL)
    {
        Logfile::GetInstance() << Warning << "Es ist kein Gamestate gesetzt!" << NewLine;
        return;
    }
    #endif
    //m_CurrentGamestate->Draw();
}

void StateManager::HandleEvent( const sf::Event& Event )
{
    #ifdef _DEBUG
    if (m_CurrentGamestate == NULL)
    {
        Logfile::GetInstance() << Warning << "Es ist kein Gamestate gesetzt!" << NewLine;
        return;
    }
    #endif
    //m_CurrentGamestate->HandleEvent(Event);
}
