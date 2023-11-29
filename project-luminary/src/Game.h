#ifndef PROJECT_LUMINARY_GAME_H
#define PROJECT_LUMINARY_GAME_H


#include <vector>
#include "window/Window.h"
#include "map/Map.h"
#include "player/Player.h"

class Game : public Window {
private:
    std::vector<std::vector<Map *>> m_mapMatrix;
    Position m_currentMapPos;
    Player *m_player;
public:
    static Game *debugGame();

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;

    ~Game() override;

    friend class GameCreator;
};


#endif //PROJECT_LUMINARY_GAME_H
