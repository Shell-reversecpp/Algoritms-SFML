//
// Created by snake0x8 on 9/19/23.
//

#include "Game.h"

Game::Game() {
    this->initVariables();
    this->vectorShapes();
    this->initWindow();

}

void Game::initVariables() {

}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(this->WIDOW_WIDTH, this->WINDOW_HEIGHT),
                                        "Algo", sf::Style::Titlebar | sf::Style::Close);
}


std::vector<Shapes> &Game::vectorShapes() {


    int rectHeightMax = WINDOW_HEIGHT;
    int numRectangles = WIDOW_WIDTH / rectWidth;
    srand(static_cast<unsigned int>(time(nullptr)));


    shapes.clear();


    for (int i = 0; i < numRectangles; ++i) {
        int rectHeight = rand() % (rectHeightMax - rectHeightMin + 1) + rectHeightMin;
        float xpos = i * rectWidth;
        float ypos = WINDOW_HEIGHT - rectHeight;

        sf::Color color(rand() % 256, rand() % 256, rand() % 256);


        Shapes shape(xpos, ypos, color, sf::Vector2f(rectWidth, rectHeight));

        shapes.push_back(shape);
    }

    return shapes;

}


void Game::quickSort(std::vector<Shapes>& shapes, int low, int high) {
    if (low < high) {

        auto partition = [&](std::vector<Shapes>& shapes, int low, int high) {
            float pivot = shapes[high].shape.getSize().y;
            int i = (low - 1);

            for (int j = low; j <= high - 1; j++) {
                if (shapes[j].shape.getSize().y < pivot) {
                    i++;
                    std::swap(shapes[i], shapes[j]);
                }
            }
            std::swap(shapes[i + 1], shapes[high]);
            return (i + 1);
        };

        int pi = partition(shapes, low, high);


        quickSort(shapes, low, pi - 1);
        quickSort(shapes, pi + 1, high);
    }
}

void Game::quickSort(std::vector<Shapes>& shapes) {
    if (shapes.empty()) {
        throw std::runtime_error("ERROR");
    }
    quickSort(shapes, 0, shapes.size() - 1);
    updateShapePositions();
}


void Game::updateShapePositions() {
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        float xpos = std::distance(shapes.begin(), it) * rectWidth;
        it->shape.setPosition(xpos, it->shape.getPosition().y);
    }

}

void Game::bubbleSort(std::vector<Shapes> &shapes) {
    int n = shapes.size();
    //std::cout << "CHECK RUN F" <<std::endl;

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {

            float height1 = shapes[j].shape.getSize().y;
            float height2 = shapes[j + 1].shape.getSize().y;

            if (height1 > height2) {

                std::swap(shapes[j], shapes[j + 1]);
                swapped = true;
                std::cout << "CHECK RUN SORT LOOPS" << std::endl;
            }
        }


        if (!swapped) {
            break;
        }

        for (auto& shape : shapes) {
            shape.updatePosition();
        }


        this->updateShapePositions();

    }
}


void Game::poolEvents() {


    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    window->close();
                if (this->ev.key.code == sf::Keyboard::G) {
                    this->vectorShapes();

                }
                if (this->ev.key.code == sf::Keyboard::R) {
                    this->bubbleSort(shapes);
                    this->render();
                }
                if (this->ev.key.code == sf::Keyboard::F) {
                    this->quickSort(shapes);
                    this->render();
                }
                break;
        }
    }
}

bool Game::running() {
    return window->isOpen();
}
void Game::update() {
    this->poolEvents();
}

void Game::render() {
    this->window->clear(sf::Color(0,0,0,0));

    for (auto& shape : this->shapes) {

        shape.render(*window);
    }
    /*
    for (auto i : this->shapes)
    {

        i.render(*window);
    }
*/

    this->window->display();
}

Game::~Game() {

    delete this->window;
}














