//
// Created by snake0x8 on 9/21/23.
//

#include "Shapes.h"


Shapes::Shapes(float xpos, float ypos, sf::Color color, sf::Vector2f size) {
    this->shape.setPosition(xpos,ypos);
    this->shape.setSize(size);
    this->shape.setFillColor(color);

}

void Shapes::initVariables() {

}

void Shapes::update() {

}

void Shapes::render(sf::RenderTarget &target){
    target.draw(this->shape);
}

void Shapes::updatePosition() {
    this->shape.setPosition(this->shape.getPosition().x, this->shape.getPosition().y);
}



Shapes::~Shapes() = default;

