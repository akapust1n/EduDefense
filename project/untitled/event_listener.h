#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class WindowEventListener
{
    void OnEvent(const sf::Event& Event);
};

#endif // EVENT_LISTENER_H
