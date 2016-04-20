#ifndef MAPCREATOR_H
#define MAPCREATOR_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "exceptions.h"

using namespace sf;
//---------------------паттерн Строитель----------

//класс карты
class Map {
  public:
    Map(String filename) : textureFilename(filename) {}
    Map() {}

    Sprite sprite_out;
    void setFilename(String filename) { textureFilename = filename; }
    void setHeight(int height) { HEIGHT_MAP = height; }
    void setWidth(int width) { WIDTH_MAP = width; }
    void textureWork() {
        image.loadFromFile(textureFilename); //загружаем файл для карты
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }
    int getleft_margin() { return left_margin; }
    int getright_margin() { return right_margin; }
    int gettop_margin() { return top_margin; }
    int getbot_margin() { return bot_margin; }
    int getheight() { return HEIGHT_MAP; }
    int getwidth() { return WIDTH_MAP; }
    std::string getMapStr() { return mapStr; }
    void setMapStr(std::string mapStr) { this->mapStr = mapStr; }

  private:
    int HEIGHT_MAP; //размер карты высота
    int WIDTH_MAP;  //размер карты ширина
    int top_margin = 0;
    int left_margin = 0;
    int bot_margin = 10;   //  пока не используетс
    int right_margin = 10; //пока не используется
    String textureFilename; //файл с картинками для создания текстуры
    Image image;
    Texture texture;
    std::string mapStr;
};

//базовый класс строителя
class MapBuilder {
  protected:
    std::shared_ptr<Map> mymap;
    String textureFilename;
    std::string mapFilename;

  public:
    MapBuilder(String textureFilename, std::string mapFileName) {
        this->textureFilename = textureFilename;
        this->mapFilename = mapFileName;
    }
    void createNewMapProduct() { mymap.reset(new Map(textureFilename)); }
    std::shared_ptr<Map> GetMap() { return mymap; }

    virtual void loadMapFromFile() = 0;
    virtual void buildTexture() = 0;
};

//Строитель обычной карты
class UsualMapBuilder : public MapBuilder {
  public:
    UsualMapBuilder(RenderWindow &window, String mapsname, std::string mapFilename)
        : MapBuilder(mapsname, mapFilename) {
        window2 = &window;
    }

    virtual void loadMapFromFile() {
        std::ifstream fin(mapFilename);
        if (!fin.is_open()) throw(file_load_error());
        size_t height, width;
        fin >> height;
        fin >> width;
        mymap->setHeight(height);
        mymap->setWidth(width);
        std::string buf;
        std::string mapStr;
        for (size_t i = 0; i < height; i++) {
            fin >> buf;
            mapStr += buf;
        }
        mymap->setMapStr(mapStr);
    }

    virtual void buildTexture() {
        mymap->textureWork();
        loadMapFromFile();
        for (int i = 0; i < mymap->getheight(); i++)
            for (int j = 0; j < mymap->getwidth(); j++) {
                switch (mymap->getMapStr().at(i * mymap->getwidth() + j)) {
                case '+':
                    mymap->sprite_out.setTextureRect(IntRect(0, 0, 60, 60));
                    break;
                case 's':
                    if (i % 2 != 0 || j > 7) {
                        mymap->sprite_out.setTextureRect(IntRect(60, 0, 60, 60));
                    } else {
                        mymap->sprite_out.setTextureRect(IntRect(180, 0, 60, 60));
                    }
                    break;
                case '0':
                    mymap->sprite_out.setTextureRect(IntRect( 120, 0, 60, 60));
                    break;
                default:
                    // заливаем пустым участком
                    mymap->sprite_out.setTextureRect(IntRect(0, 0, 60, 60));
                    break;
                }
                mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                              mymap->gettop_margin() + i * 60);
              //  window2->draw(mymap->sprite_out);
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
        mapBuilder->buildTexture();
    }
};

#endif // MAPCREATOR_H
