#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <string>
#include <map>
#include <SFML/Window.hpp>

class Gamestate;

class StateManager
{
public:
    StateManager();

    ~StateManager();

    // Fgt einen Gamestate hinzu
    // Parameter 1: Name des Gamestate
    // Parameter 2: Zeiger auf eine Instanz des Gamestates (mit new erzeugt)
    void AddGamestate(const std::string Name, Gamestate* Gamestate);

    // Wechselt den Gamestate
    //void ChangeGamestate(const std::string Name, void* InitializationData = NULL);

    // Aktualisiert den aktuellen Gamestate
    void Update();

    // Malte den aktuellen Gamestate
    void Draw();

    void HandleEvent(const sf::Event& Event);

private:
    std::map<std::string, Gamestate*> m_States;
};

#endif // STATEMANAGER_H
