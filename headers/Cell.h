#ifndef LIFELIKE_CELLULAR_AUTOMATON_CELL_H
#define LIFELIKE_CELLULAR_AUTOMATON_CELL_H

struct Cell{
public:
    int state;
    int x;
    int y;

    Cell();

    Cell(int _x, int _y, int _state);

    //friend Cell& operator= (const Cell &cel);
};

#endif //LIFELIKE_CELLULAR_AUTOMATON_CELL_H
