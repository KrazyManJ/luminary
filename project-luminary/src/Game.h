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

    MapObject *getMapObjectInDirectionOfPlayer(MovementDirection direction);

    bool isPlayerMoveInMap(MovementDirection direction);

    void makePlayerMovement(MovementDirection direction);

    bool canAccessMapInDirection(MovementDirection direction);

    void switchMap(MovementDirection direction);

    Position posInDirection(Position position, MovementDirection direction);

public:
    static Game *debugGame();

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;

    ~Game() override;

    friend class GameCreator;

    Map *getCurrentMap();
};


#endif //PROJECT_LUMINARY_GAME_H
