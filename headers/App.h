#ifndef LIFELIKE_CELLULAR_AUTOMATON_APP_H
#define LIFELIKE_CELLULAR_AUTOMATON_APP_H

#include <SFML/Graphics.hpp>
#include "iostream"

#include "Automaton.h"
#include "AutomatonView.h"
#include "Rules.h"
#include "Cell.h"
#include "Vector2D.h"

using sf::Vector2f;
using namespace std;

#define WIDTH 100
#define HEIGHT 50
#define CELL_SIZE 10
#define CELL_MARGIN 0

#define RESOLUTION Vector2f(WIDTH*(CELL_SIZE+2*CELL_MARGIN), HEIGHT*(CELL_SIZE+2*CELL_MARGIN))

class App {
    Vector2f resolution;
    sf::RenderWindow window;

    AutomatonView automatonView;
    Automaton automaton;
    Rules rules;
public:
    App();

    void run();

protected:
    void before_loop();
    void on_loop();
    void on_event(sf::Event& event);
};

#endif //LIFELIKE_CELLULAR_AUTOMATON_APP_H
