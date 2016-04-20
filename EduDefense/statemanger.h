#ifndef STATEMANGER_H
#define STATEMANGER_H

enum state{
    MenuMain,
    Levelchoose,
    LevelRun,
    Options,
    Stats,
    Quit,
    StayHere
};

class StateManager {
  public:
    StateManager():currentState(MenuMain){}
    state getcurrentState(){return currentState;}
    void setState(state newstate){currentState = newstate;}
private:
    state currentState;

};

#endif // STATEMANGER_H
