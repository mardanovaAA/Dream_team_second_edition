#include "App.h"

App::App() {

    resolution = RESOLUTION;
    window.create(sf::VideoMode(resolution.x, resolution.y), "Life-like cellular automaton", sf::Style::Default);
    window.setFramerateLimit(60);

    automatonView.cell_size = CELL_SIZE;
    automatonView.cell_margin = CELL_MARGIN;

}

void App::before_loop() {
    Vector2D<int> cells(WIDTH, HEIGHT, 0);

    cells[5][4] = cells[6][5] = cells[4][6] = cells[5][6] = cells[6][6] = 1;

    automaton.setFrom(cells);
    automatonView.bind(automaton);
    automatonView.centerAt(Vector2f(window.getSize())/2.f);

    rules.set_weighter([](int state, int index){
        return state;
    });

    rules.set_processor([](int weight, int state){
        if( weight == 3 )
            return 1;
        if( weight == 2 and state == 1 )
            return 1;
        return 0;
    });
}

void App::on_loop() {
    window.clear(sf::Color::Black);
    window.draw(automatonView);
    window.display();
}

void App::on_event(sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Space){
            automaton.update(rules);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            Cell current_cell(event.mouseButton.x / CELL_SIZE, event.mouseButton.y / CELL_SIZE,
                 automaton.getAt(event.mouseButton.x/CELL_SIZE, event.mouseButton.y/CELL_SIZE).state ? 0 : 1);
            automaton.setAt(current_cell);
        }
    }
}

void App::run() {
    before_loop();
    while (window.isOpen()){
        on_loop();

        sf::Event event{};
        while (window.pollEvent(event)) {
            on_event(event);
        }
    }
}