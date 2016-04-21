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

    void textureCurveWork() {
        image.loadFromFile("maps/map_curve.png");
        texture.loadFromImage(image);
        sprite_out.setTexture(texture);
    }

    void backgroundWork() {
        image.loadFromFile("maps/way.jpg");
        texture.loadFromImage(image);
        sprite_out.setTexture(texture);
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
        mymap->backgroundWork();
        mymap->sprite_out.setTextureRect(IntRect(0, 0, 780, 660));
        mymap->sprite_out.setPosition(0, 0);
        window2->draw(mymap->sprite_out);

        mymap->textureWork();
        loadMapFromFile();
        for (int i = 0; i < mymap->getheight(); i++)
            for (int j = 0; j < mymap->getwidth(); j++) {
                switch (mymap->getMapStr().at(i * mymap->getwidth() + j)) {
                case 's':
                    if (i % 2 != 0 || j > 7) {
                        mymap->sprite_out.setTextureRect(IntRect(60, 0, 60, 60));
                    } else {
                        mymap->sprite_out.setTextureRect(IntRect(180, 0, 60, 60));
                    }
                    break;
                default:
                    // заливаем пустым участком
                    mymap->sprite_out.setTextureRect(IntRect(240, 0, 60, 60));
                    break;
                }
                mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                              mymap->gettop_margin() + i * 60);
                window2->draw(mymap->sprite_out);
            }
        buildCurveTexture();
        //window2->display();
    }

    virtual bool checker(std::shared_ptr<Map> mymap, int x_1, int y_1,
                         int x_2, int y_2, int x_3, int y_3, char c, char c_f) {
        if (x_1 < 0 or y_1 < 0 or x_1 >  mymap->getheight() - 1
                or y_1 >  mymap->getwidth() - 1 or
                x_2 < 0 or y_2 < 0 or x_2 >  mymap->getheight() - 1
                                or y_2 >  mymap->getwidth() - 1 or
                x_3 < 0 or y_3 < 0 or x_3 >  mymap->getheight() - 1
                                or y_3 >  mymap->getwidth() - 1)
            return false;
        if (mymap->getMapStr().at(x_1 * mymap->getwidth() + y_1) == c_f
                and mymap->getMapStr().at(x_2 * mymap->getwidth() + y_2) == c
                and mymap->getMapStr().at(x_3 * mymap->getwidth() + y_3) == c)
            return true;
        else
            return false;
    }

    virtual void buildCurveTexture() {
        mymap->textureCurveWork();
        loadMapFromFile();
        for (int i = 0; i < mymap->getheight(); i++)
            for (int j = 0; j < mymap->getwidth(); j++) {
                if (checker(mymap, i, j, i+1, j, i, j-1, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(0, 0, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j, i-1, j, i, j-1, '0', '0')){
                    mymap->sprite_out.setTextureRect(IntRect(60, 0, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j, i-1, j, i, j+1, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(120, 0, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j, i+1, j, i, j+1, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(182, 0, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }



                if (checker(mymap, i-1, j, i, j-1, i, j+1, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(0, 120, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i-1, j, i+1, j, i, j+1, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(60, 120, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j+1, i, j-1, i+1, j, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(120, 120, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i-1, j, i+1, j, i, j-1, '0', '0')) {
                    mymap->sprite_out.setTextureRect(IntRect(180, 120, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }


                if (checker(mymap, i, j, i-1, j, i, j+1, '0', '+')) {
                    mymap->sprite_out.setTextureRect(IntRect(0, 60, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j, i+1, j, i, j+1, '0', '+')){
                    mymap->sprite_out.setTextureRect(IntRect(60, 60, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j, i+1, j, i, j-1, '0', '+')) {
                    mymap->sprite_out.setTextureRect(IntRect(120, 60, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (checker(mymap, i, j, i-1, j, i, j-1, '0', '+')) {
                    mymap->sprite_out.setTextureRect(IntRect(180, 60, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }

                if (mymap->getMapStr().at(i * mymap->getwidth() + j) == '+') {
                    mymap->sprite_out.setTextureRect(IntRect(240, 60, 60, 60));
                    mymap->sprite_out.setPosition(mymap->getleft_margin() + j * 60,
                                                  mymap->gettop_margin() + i * 60);
                    window2->draw(mymap->sprite_out);
                    continue;
                }
            }
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
