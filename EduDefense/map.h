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
    Map(String filename) : File(filename) {}
    Map() {}

    Sprite sprite_out;
    void setFilename(String filename) { File = filename; }
    void setHeight(int height) { HEIGHT_MAP = height; }
    void setWidth(int width) { WIDTH_MAP = width; }
    void textureWork() {
        image.loadFromFile(File); //загружаем файл для карты
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }
    int getleft_margin() { return left_margin; }
    int getright_margin() { return right_margin; }
    int gettop_margin() { return top_margin; }
    int getbot_margin() { return bot_margin; }
    int getheight() { return HEIGHT_MAP; }
    int getwidth() { return WIDTH_MAP; }

  private:
    int HEIGHT_MAP; //размер карты высота
    int WIDTH_MAP;  //размер карты ширина
    int top_margin = 6;
    int left_margin = 6;
    int bot_margin = 10;   //  пока не используетс
    int right_margin = 10; //пока не используется
    String File; //файл с картинками для создания текстуры
    Image image;
    Texture texture;
};

//базовый класс строителя
class MapBuilder {
  protected:
    std::shared_ptr<Map> mymap;
    String temp1;

  public:
    MapBuilder(String filename) { temp1 = filename; }
    void createNewMapProduct() { mymap.reset(new Map(temp1)); }
    std::shared_ptr<Map> GetMap() { return mymap; }

    virtual void buildParams() = 0;
    virtual void buildTexture() = 0;
};

//Строитель обычной карты
class UsualMapBuilder : public MapBuilder {
  public:
    UsualMapBuilder(RenderWindow &window, String mapsname)
        : MapBuilder(mapsname) {
        window2 = &window;
    }

    virtual void buildParams() {
        mymap->setHeight(21);
        mymap->setWidth(22);
    }

    virtual void buildTexture() {
        sf::String TileMap[21] = {
            "                      ",
            "0000000000000000      ",
            "  s  s         0      ",
            "               0      ",
            "  s            0      ",
            "               0      ",
            "   s      000000      ",
            "          0           ",
            "      00000           ",
            "    s 0               ",
            "      00000000000     ",
            "                0     ",
            "          s     0     ",
            "    s           0s    ",
            "000000000000    0 s   ",
            "           0  s 00000 ",
            "           0        0 ",
            "           0000000000 ",
            "                      ",
            "                      ",
            "                      ",
        };

        mymap->textureWork();

        for (int i = 0; i < mymap->getheight(); i++)
            for (int j = 0; j < mymap->getwidth(); j++) {

                if (TileMap[i][j] == ' ')
                    mymap->sprite_out.setTextureRect(IntRect(0, 0, 32, 32));
                if (TileMap[i][j] == 's')
                    mymap->sprite_out.setTextureRect(IntRect(
                        32, 0, 32,
                        32)); //если встретили символ s, то рисуем 2й квадратик
                if (TileMap[i][j] == '0')
                    mymap->sprite_out.setTextureRect(IntRect(
                        64, 0, 32,
                        32)); //если встретили символ 0, то рисуем 3й квадратик

                mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 32,
                                              mymap->gettop_margin() + i * 32);
                window2->draw(mymap->sprite_out);
            }
        window2->display();
    }

  private:
    RenderWindow *window2;
};

//директор
class Waiter {
  private:
    MapBuilder *mapBuilder;

  public:
    Waiter() : mapBuilder(NULL) {}
    ~Waiter() {}

    void SetMapBuilder(MapBuilder *b) { mapBuilder = b; }
    std::shared_ptr<Map> GetMap() { return mapBuilder->GetMap(); }
    void ConstructMap() {
        mapBuilder->createNewMapProduct();
        mapBuilder->buildParams();
        mapBuilder->buildTexture();
    }
};

#endif // MAPCREATOR_H
