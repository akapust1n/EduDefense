#ifndef MAPCREATOR_H
#define MAPCREATOR_H
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <fstream>
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
    Texture texture;
    void setFilename(String filename) { File = filename; }
    void setHeight(int height) { HEIGHT_MAP = height; }
    void setWidth(int width) { WIDTH_MAP = width; }
    void textureWork()
    {
        image.loadFromFile(File); //загружаем файл для карты
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite.setTexture(texture); //заливаем текстуру спрайтом
    }

private:
    int HEIGHT_MAP; //размер карты высота
    int WIDTH_MAP; //размер карты ширина
    String File;
    Image image;
    Sprite sprite;
    enum MapStates { //я ещё не придумал зачем это нужно, но в теории поможет при считывании файла
        Way,
        BadWay,
        BuildingArea,
        UnBuildingArea
    };
};

//базовый класс строителя
class MapBuilder {
protected:
    std::shared_ptr<Map> mymap;

public:
    MapBuilder(String filename) { temp = filename; }
    void createNewMapProduct() { mymap.reset(new Map(temp)); }
    std::shared_ptr<Map> GetMap() { return mymap; }

    virtual void buildParams() = 0;
    virtual void buildTexture() = 0;

private:
    String temp;
};

//Строитель обычной карты
class UsualMapBuilder : public MapBuilder {
public:
    virtual void buildParams()
    {
        mymap->setHeight(700);
        mymap->setWidth(700);
    }
    virtual void buildTexture()
    {
        mymap->textureWork();
        //ВРЕМЕННОЕ РЕШЕНИЕ
        std::vector<std::string> temp;
        std::string line;
          std::ifstream myfile ("maps/level1.txt");
          if (myfile.is_open())
          {
            while ( myfile.good() )
            {
              getline (myfile,line);
              temp.push_back(line);
            }
            myfile.close();
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
    }
};

#endif // MAPCREATOR_H
