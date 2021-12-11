#include "AutomatonView.h"

AutomatonView::AutomatonView(Automaton &_automaton) {
    automaton = &_automaton;
}

void AutomatonView::bind(Automaton &_automaton) {
    automaton = &_automaton;
}

void AutomatonView::draw_cell(RenderTarget &target, Vector2i index) const {
    Vector2f temp(cell_size, cell_size);
    sf::RectangleShape rect(temp);

    Vector2f real_position;
    real_position = position + Vector2f(index) * float(cell_size + 2 * cell_margin);
    rect.setPosition(real_position);

    switch (automaton->getAt(index.x,index.y).state) {
        case 0: rect.setFillColor(sf::Color::Black); break;
        case 1: rect.setFillColor(sf::Color::White); break;
        default: rect.setFillColor(sf::Color::Yellow); break;
    }

    target.draw(rect);
}

void AutomatonView::draw(RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < automaton->field.get_width(); ++i) {
        for (int j = 0; j < automaton->field.get_height(); ++j) {
            draw_cell(target, Vector2i(automaton->field[i][j].x, automaton->field[i][j].y));
        }
    }
}

void AutomatonView::setPosition(Vector2f pos) {
    position = pos;
}

Vector2f AutomatonView::getSize() const {
    auto temp1 = automaton->field.get_width() * (cell_size + 2 * cell_margin);
    auto temp2 = automaton->field.get_height() * (cell_size + 2 * cell_margin);
    return Vector2f(temp1,temp2);
}

void AutomatonView::centerAt(Vector2f pos) {
    position = pos - getSize()/2.f;
}