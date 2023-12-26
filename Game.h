//
// Created by snake0x8 on 9/19/23.
//

#ifndef SFML_GAME_GAME_H
#define SFML_GAME_GAME_H

#include "Shapes.h"

class Game {
public:

    Game();
    ~Game();

    //Functions
    void poolEvents();
    void update();
    void render();

    const bool running();

private:
    sf::RenderWindow* window;
    std::vector<Shapes> shapes;
    sf::Event ev;

    const int WIDOW_WIDTH = 1000, WINDOW_HEIGHT = 500;

    const int rectWidth = 50; // Фиксированная ширина прямоугольника
    const int rectHeightMin = 50; // Минимальная высота прямоугольника

    std::vector<Shapes>& vectorShapes();
    void quickSort(std::vector<Shapes> &shapes);
    void bubbleSort(std::vector<Shapes> &shapes);
    void updateShapePositions();
    void initVariables();
    void initWindow();
};


#endif //SFML_GAME_GAME_H
