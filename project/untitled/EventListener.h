
#ifndef EventListener_h__
#define EventListener_h__


#include <SFML/Window.hpp>

class WindowEventListener
{
public:
    WindowEventListener();
    virtual ~WindowEventListener();

    virtual void OnEvent(const sf::Event& Event) = 0;
};
#endif // EventListener_h__

