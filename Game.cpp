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
                                        "Game", sf::Style::Titlebar | sf::Style::Close);
}


std::vector<Shapes> &Game::vectorShapes() {


    int rectHeightMax = WINDOW_HEIGHT; // Максимальная высота прямоугольника
    int numRectangles = WIDOW_WIDTH / rectWidth; // Количество прямоугольников

    srand(static_cast<unsigned int>(time(nullptr)));

    // Очищаем вектор перед добавлением новых прямоугольников
    shapes.clear();

    // Создаем и добавляем прямоугольники в вектор
    for (int i = 0; i < numRectangles; ++i) {
        int rectHeight = rand() % (rectHeightMax - rectHeightMin + 1) + rectHeightMin; // Случайная высота
        float xpos = i * rectWidth; // X-положение прямоугольника
        float ypos = WINDOW_HEIGHT - rectHeight; // Y-положение прямоугольника (нижний край экрана)

        sf::Color color(rand() % 256, rand() % 256, rand() % 256); // Случайный цвет

        // Создаем объекты Shapes и добавляем их в вектор
        Shapes shape(xpos, ypos, color, sf::Vector2f(rectWidth, rectHeight));

        shapes.push_back(shape);
    }

    return shapes; // Возвращаем ссылку на вектор

}


void Game::quickSort(std::vector<Shapes> &shapes) {
    if (shapes.empty())
    {
        throw "ERROR";
    }
    for (auto iter = shapes.begin(); iter != shapes.end(); ++iter) {
       iter->shape.getSize().y; // Получаем размер текущего прямоугольника
    }
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
        bool swapped = false; // Флаг для определения, были ли обмены на данном проходе

        for (int j = 0; j < n - i - 1; ++j) {
            // Сравниваем высоты текущего и следующего элементов
            float height1 = shapes[j].shape.getSize().y;
            float height2 = shapes[j + 1].shape.getSize().y;

            if (height1 > height2) {
                // Если текущий элемент больше следующего, меняем их местами
                std::swap(shapes[j], shapes[j + 1]);
                swapped = true; // Устанавливаем флаг, что был обмен
                std::cout << "CHECK RUN SORT LOOPS" << std::endl;
            }
        }

        // После завершения внутреннего цикла проверяем, были ли обмены
        if (!swapped) {
            break; // Если не было обменов, массив уже отсортирован, выходим из внешнего цикла
        }

        for (auto& shape : shapes) {
            shape.updatePosition();
        }

        // Добавьте отладочный вывод здесь
       // std::cout << "Bubble Sort Iteration " << i << std::endl;
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
                    this->vectorShapes(); // Вызываем сортировку

                }
                if (this->ev.key.code == sf::Keyboard::R) {
                    this->bubbleSort(shapes); // Вызываем сортировку
                    this->render(); // Обновляем экран после сортировки
                }
                break;
        }
    }
}

const bool Game::running() {
    return window->isOpen();
}
void Game::update() {
    this->poolEvents();
}

void Game::render() {
    this->window->clear(sf::Color(0,0,0,0));

    for (auto& shape : this->shapes) {
        // Обновляем позицию каждого прямоугольника
        shape.render(*window); // Рисуем прямоугольник
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














