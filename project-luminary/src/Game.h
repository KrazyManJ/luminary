#ifndef PROJECT_LUMINARY_GAME_H
#define PROJECT_LUMINARY_GAME_H


#include <vector>
#include "window/Window.h"
#include "map/Map.h"
#include "player/Player.h"
#include "map/Torch.h"

class Game : public Window {
private:
    std::vector<std::vector<Map *>> m_mapMatrix;
    Position m_currentMapPos;
    Player *m_player;
    std::vector<Torch*> m_torchesOrder;

    MapObject *getMapObjectInDirectionOfPlayer(MovementDirection direction);

    bool isPlayerMoveInMap(MovementDirection direction);

    void makePlayerMovement(MovementDirection direction);

    bool canAccessMapInDirection(MovementDirection direction);

    void switchMap(MovementDirection direction);

    Position posInDirection(Position position, MovementDirection direction);

public:

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;

    ~Game() override;

    Player* getPlayer();

    friend class GameCreator;
    friend class DebugGame;

    Map *getCurrentMap();
};


#endif //PROJECT_LUMINARY_GAME_H
