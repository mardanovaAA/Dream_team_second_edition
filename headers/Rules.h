#ifndef LIFELIKE_CELLULAR_AUTOMATON_RULES_H
#define LIFELIKE_CELLULAR_AUTOMATON_RULES_H

#include <functional>
#include <utility>

class Automaton;
#include "Automaton.h"

class Rules{
protected:
    Automaton* _automaton = nullptr;

    int moore_size = 1;

    std::function<int(int, int)> weighter;

    std::function<int(int, int)> processor;

    void apply_to_neighbors(Cell& cell, const std::function<void(Cell,int)>& func );

public:

    Rules() = default;
    void set_processor(const std::function<int(int, int)>& _processor){
        processor = _processor;
    }
    void set_weighter(const std::function<int(int, int)>& _weighter){
        weighter = _weighter;
    }

    Rules( int _moore_size, const std::function<int(int, int)>& _weighter, const std::function<int(int, int)>& _processor){
        moore_size = _moore_size;
        set_processor(_processor); set_weighter(_weighter);
    }

    void bind_automaton(Automaton& automaton);

    int new_state(Cell& cell);
};

#endif //LIFELIKE_CELLULAR_AUTOMATON_RULES_H
