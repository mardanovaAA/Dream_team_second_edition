#include "Automaton.h"

Cell& Automaton::getAt(int x, int y){
    return field[x][y];
}

void Automaton::setAt(int x, int y, Cell &cell) {
    field[x][y] = cell;
}

void Automaton::setAt(Cell &cell) {
    field[cell.x][cell.y] = cell;
}

void Automaton::update(Rules rules) {
    Vector2D<Cell> temp(field.get_width(), field.get_height(), Cell());
    rules.bind_automaton(*this);
    for(int i = 0; i < field.get_width(); ++i) {
        for (int j = 0; j < field.get_height(); ++j) {
            temp[field[i][j].x][field[i][j].y].state = rules.new_state(field[i][j]);
        }
    }

    for(int i = 0; i < field.get_width(); ++i) {
        for (int j = 0; j < field.get_height(); ++j) {
            field[i][j].state = temp[field[i][j].x][field[i][j].y].state;
        }
    }
}

void Automaton::setFrom(Vector2D<int> cells) {
    Vector2D<Cell> temp(cells.get_width(), cells.get_height(), Cell(0, 0, 0));
    field = temp;
    for (int i = 0; i < cells.get_width(); ++i) {
        for (int j = 0; j < cells.get_height(); ++j) {
            field[i][j] = Cell(i, j, cells[i][j]);
        }
    }
}

