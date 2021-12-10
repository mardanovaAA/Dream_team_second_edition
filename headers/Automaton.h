#ifndef LIFELIKE_CELLULAR_AUTOMATON_AUTOMATON_H
#define LIFELIKE_CELLULAR_AUTOMATON_AUTOMATON_H

#include "Cell.h"
#include "Rules.h"
#include "Vector2D.h"

class Rules;

using namespace std;


class Automaton{
public:
    Automaton(){};

    Vector2D<Cell> field;

    void setFrom(Vector2D<int> cells);

    Cell& getAt(int x, int y);
    void setAt(int x, int y, Cell& cell);
    void setAt(Cell& cell);

    void update(Rules rules);
};

#endif //LIFELIKE_CELLULAR_AUTOMATON_AUTOMATON_H
