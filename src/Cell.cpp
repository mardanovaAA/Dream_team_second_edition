#include "cell.h"

Cell::Cell(int _x, int _y, int _state){
    x = _x; y = _y; state = _state;
};

Cell::Cell(){
    x = y = state = 0;
}

/*Cell& Cell::operator= (const Cell &cel){
    if (this == &cel){
        return *this;
    }
    this->x = cel.x;
    this->y = cel.y;
    this->state = cel.state;
    return *this;
};*/