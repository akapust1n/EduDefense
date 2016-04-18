#ifndef GAMEMENU_H
#define GAMEMENU_H
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
class GameMenu {
  public:
    GameMenu(String filename) : File(filename) {}
    GameMenu() {}

    Sprite sprite_out;
    void setFilename(String filename) { File = filename; }
    void setHeight(int height) { HEIGHT_MENU = height; }
    void setWidth(int width) { WIDTH_MENU = width; }
    void textureWork() {
        image.loadFromFile(File); //загружаем файл для меню
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }

    void towersIconsWork() {
        image.loadFromFile("images/GUI/towers.png");
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }

    void statsIconsWork() {
        image.loadFromFile("images/GUI/stats1.png");
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }

    void playIconsWork() {
        image.loadFromFile("images/GUI/play.png");
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_out.setTexture(texture); //заливаем текстуру спрайтом
    }

    int getleft_margin() { return left_margin; }
    int getright_margin() { return right_margin; }
    int gettop_margin() { return top_margin; }
    int getbot_margin() { return bot_margin; }
    int getheight() { return HEIGHT_MENU; }
    int getwidth() { return WIDTH_MENU; }

  private:
    int HEIGHT_MENU; //высота меню
    int WIDTH_MENU;  //ширина меню
    int top_margin = 0;
    int left_margin = 0;
    int bot_margin = 10;   //  пока не используетс
    int right_margin = 10; //пока не используется
    String File; //файл с картинками для создания текстуры
    Image image;
    Texture texture;
};

//базовый класс строителя
class GameMenuBuilder {
  protected:
    std::shared_ptr<GameMenu> mymenu;
    String temp1;

  public:
    GameMenuBuilder(String filename) { temp1 = filename; }
    void createNewGameMenuProduct() { mymenu.reset(new GameMenu(temp1)); }
    std::shared_ptr<GameMenu> GetGameMenu() { return mymenu; }

    virtual void buildParams() = 0;
    virtual void buildTexture() = 0;
};

//Строитель обычной карты
class UsualGameMenuBuilder : public GameMenuBuilder {
  public:
    UsualGameMenuBuilder(RenderWindow &window, String mapsname)
        : GameMenuBuilder(mapsname) {
        window2 = &window;
    }

    virtual void buildParams() {
        mymenu->setHeight(11);
        mymenu->setWidth(13);
    }

    virtual void buildTexture() {
        mymenu->textureWork();

        for (int i = 0; i < 500; i += 240) {
            mymenu->sprite_out.setTextureRect(IntRect(0, 0, 240, 240));
            mymenu->sprite_out.setPosition(780, i);
            window2->draw(mymenu->sprite_out);
        }

        mymenu->towersIconsWork();

        mymenu->sprite_out.setTextureRect(IntRect(0, 0, 100, 100));
        mymenu->sprite_out.setPosition(792, 136);
        window2->draw(mymenu->sprite_out);

        mymenu->sprite_out.setTextureRect(IntRect(101, 0, 100, 100));
        mymenu->sprite_out.setPosition(908, 136);
        window2->draw(mymenu->sprite_out);

        mymenu->sprite_out.setTextureRect(IntRect(203, 0, 100, 100));
        mymenu->sprite_out.setPosition(792, 279);
        window2->draw(mymenu->sprite_out);

        mymenu->sprite_out.setTextureRect(IntRect(305, 0, 100, 100));
        mymenu->sprite_out.setPosition(908, 279);
        window2->draw(mymenu->sprite_out);

        mymenu->statsIconsWork();

        mymenu->sprite_out.setTextureRect(IntRect(0, 0, 35, 35));
        mymenu->sprite_out.setPosition(786, 3);
        window2->draw(mymenu->sprite_out);

        mymenu->sprite_out.setTextureRect(IntRect(70, 0, 35, 35));
        mymenu->sprite_out.setPosition(978, 3);
        window2->draw(mymenu->sprite_out);

        mymenu->sprite_out.setTextureRect(IntRect(36, 0, 35, 35));
        mymenu->sprite_out.setPosition(786, 46);
        window2->draw(mymenu->sprite_out);

        mymenu->sprite_out.setTextureRect(IntRect(70, 0, 35, 35));
        mymenu->sprite_out.setPosition(978, 46);
        window2->draw(mymenu->sprite_out);

        mymenu->playIconsWork();

        mymenu->sprite_out.setTextureRect(IntRect(0, 0, 221, 130));
        mymenu->sprite_out.setPosition(790, 527);
        window2->draw(mymenu->sprite_out);

        window2->display();
    }

  private:
    RenderWindow *window2;
};

//директор
class WaiterMenu {
  private:
    GameMenuBuilder *menuBuilder;

  public:
    WaiterMenu() : menuBuilder(NULL) {}
    ~WaiterMenu() {}

    void SetGameMenuBuilder(GameMenuBuilder *b) { menuBuilder = b; }
    std::shared_ptr<GameMenu> GetGameMenu() { return menuBuilder->GetGameMenu(); }
    void ConstructGameMenu() {
        menuBuilder->createNewGameMenuProduct();
        menuBuilder->buildParams();
        menuBuilder->buildTexture();
    }
};

#endif // GAMEMENU_H
