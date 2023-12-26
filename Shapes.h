//
// Created by snake0x8 on 9/21/23.
//

#ifndef SFML_GAME_SHAPES_H
#define SFML_GAME_SHAPES_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <algorithm>

class Shapes {

public:
     Shapes(float xpos , float ypos, sf::Color color, sf::Vector2f size);
    ~Shapes();

    void initVariables();

    void update();
    void render(sf::RenderTarget &target);

    sf::RectangleShape shape;

    void updatePosition();
private:

};


#endif //SFML_GAME_SHAPES_H
