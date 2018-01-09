#ifndef CONFIG_H
#define CONFIG_H

/**
 * @brief The Config class
 *  configuration du jeu
 */
class Config
{
public:
    static const int WIDTH = 650;//largeur de la scene d'evolution des joueurs
    static const int HEIGHT = 650;//hauteur de la scene
    static const int CLOCK = 20;//temps pour un tour de jeu
    static const int SIZE_SNAKE = 7;//eppaisseur du trait pour les trace des serpents
    static const int COMPTEUR_PRINT = 5;//compteur pour ameliorer les performances graphiques tout en ayant un trace fluide
    static const int WALL_SIZE = 5;//epaisseur des bordure de la scene
    static const int SPACE_FROM_WALL = Config::WALL_SIZE + 50;//epaisseur ou aucun joueurs et bonus ne peuvent spawner

    //temps minimum et maximum pendant lequel le serpent laisse une trace avant de laisser un trou
    static const int TIC_PATH_MIN = 50;
    static const int TIC_PATH_MAX = 250;

    static const int TIC_HOLE = 25;//temps pendant lequel le serpent laisse eu trou

    static const int SIZE_BONUS = 20;//taille des bonus en px sur la scene
    static const int NBR_BONUS = 3;//nbr bonus effectif
    static const int SPAWN_BONUS = 400;//intervalle de temps pour faire spawn a bonus

};

#endif // CONFIG_H
