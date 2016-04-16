#ifndef MAPCREATOR_H
#define MAPCREATOR_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace sf;
//---------------------паттерн Строитель----------

//класс карты
class Map {
public:
    Map(String filename)
        : File(filename)
    {
    }
    Map() {}

    Sprite sprite_out;
    void setFilename(String filename) { File = filename; }
    void setHeight(int height) { HEIGHT_MAP = height; }
    void setWidth(int width) { WIDTH_MAP = width; }
    void textureWork()
    {
        image.loadFromFile(File); //загружаем файл для карты
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }

private:
    int HEIGHT_MAP; //размер карты высота
    int WIDTH_MAP; //размер карты ширина
    String File; //файл с картинками для создания текстуры
    Image image;
    Texture texture;
};

//базовый класс строителя
class MapBuilder {
protected:
    std::shared_ptr<Map> mymap;

public:
    MapBuilder(String filename) { temp1 = filename; }
    void createNewMapProduct() { mymap.reset(new Map(temp1)); }
    std::shared_ptr<Map> GetMap() { return mymap; }

    virtual void buildParams() = 0;
    virtual void buildTexture() = 0;

    //private:
    String temp1;
};

//Строитель обычной карты
class UsualMapBuilder : public MapBuilder {
public:
    UsualMapBuilder()
        : MapBuilder("maps/map.png")
    {
    }
    virtual void buildParams()
    {
        mymap->setHeight(700);
        mymap->setWidth(700);
    }
    virtual void buildTexture()
    {
        sf::String TileMap[25] = {
            "                                        ",
            "0000000000000000                       0",
            "  s  s         0                      0",
            "               0                        0",
            "  s            0               00      0",
            "               0               00       0",
            "   s      000000                       0",
            "          0                             0",
            "      00000                            0",
            "    s 0                                0",
            "      00000000000                                 0",
            "                0                      0",
            "          s     0                      0",
            "    s           0s                     0",
            "000000000000    0 s                     0",
            "           0    00000                      0",
            "           0        0                0",
            "           0000000000                0",
            "                                       0",
            "                                      0",
             "                                      0",
            "                                       0",
            "0                                      0",
            "0                                      0",
            "0000000000000000000000000000000000000000",
        };
        mymap->textureWork();

        sf::RenderWindow window2(sf::VideoMode(800, 600), "lol");
        sf::Event event;
        sf::Image image;
        sf::Sprite sprite;
        sf::Texture texture;
        image.loadFromFile("maps/map.png"); //загружаем файл для карты
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        //sprite.setTexture(texture);
        while (window2.isOpen()) {
            while (window2.pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window2.close();
                }
            }
            for (int i = 0; i < 25; i++)
                for (int j = 0; j < 40; j++) {

                    if (TileMap[i][j] == ' ')
                        mymap->sprite_out.setTextureRect(IntRect(0, 0, 32, 32));
                    if (TileMap[i][j] == 's')
                        mymap->sprite_out.setTextureRect(IntRect(32, 0, 32, 32)); //если встретили символ s, то рисуем 2й квадратик
                    if (TileMap[i][j] == '0')
                        mymap->sprite_out.setTextureRect(IntRect(64, 0, 32, 32)); //если встретили символ 0, то рисуем 3й квадратик

                    mymap->sprite_out.setPosition(j * 32, i * 32);
                    window2.draw(mymap->sprite_out);

                }

            window2.display();
        }
    }
};

//директор
class Waiter {
private:
    MapBuilder* mapBuilder;

public:
    Waiter()
        : mapBuilder(NULL)
    {
    }
    ~Waiter() {}

    void SetMapBuilder(MapBuilder* b) { mapBuilder = b; }
    std::shared_ptr<Map> GetMap() { return mapBuilder->GetMap(); }
    void ConstructPizza()
    {
        mapBuilder->createNewMapProduct();
        mapBuilder->buildParams();
        mapBuilder->buildTexture();
    }
};

#endif // MAPCREATOR_H
