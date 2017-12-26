#ifndef CONFIG_H
#define CONFIG_H


class Config
{
public:
    static const int WIDTH = 500;
    static const int HEIGHT = 500;
    static const int CLOCK = 20;
    static const int SIZE_SNAKE = 7;
    static const int COMPTEUR_PRINT = 5;
    static const int WALL_SIZE = 5;
    static const int SPACE_FROM_WALL = Config::WALL_SIZE + 50;

    static const int TIC_PATH_MIN = 50;
    static const int TIC_PATH_MAX = 250;
    static const int TIC_HOLE = 20;

};

#endif // CONFIG_H
