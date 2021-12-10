#ifndef LIFELIKE_CELLULAR_AUTOMATON_AUTOMATONVIEW_H
#define LIFELIKE_CELLULAR_AUTOMATON_AUTOMATONVIEW_H

#include "Automaton.h"
#include <SFML/Graphics.hpp>

using sf::Vector2i, sf::Vector2f;
using sf::RenderTarget, sf::RenderStates;
using namespace std;

class AutomatonView: public sf::Drawable{
protected:
    Automaton* automaton = nullptr;

    Vector2f position;

    void draw_cell(RenderTarget &target, Vector2i index) const;


public:
    int cell_size;
    int cell_margin;

    AutomatonView() = default;
    AutomatonView(int size, int margin): cell_size(size), cell_margin(margin){}
    explicit AutomatonView(Automaton& _automaton);
    void bind(Automaton& _automaton);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    Vector2f getSize() const;
    void setPosition(Vector2f pos);
    void centerAt(Vector2f pos);
    void click(Vector2f pos);
};

#endif //LIFELIKE_CELLULAR_AUTOMATON_AUTOMATONVIEW_H
