#ifndef PROJECT_LUMINARY_GAME_H
#define PROJECT_LUMINARY_GAME_H


#include <vector>
#include "window/Window.h"
#include "map/Map.h"
#include "player/Player.h"
#include "map/Torch.h"
#include "structs/GamePosition.h"

class Game : public Window {
private:
    std::vector<std::vector<Map *>> m_mapMatrix;
    Position m_currentMapPos;
    Player *m_player;
    std::vector<Torch*> m_torchesOrder;
    GamePosition m_endPosition;

    MapObject *getMapObjectInDirectionOfPlayer(MovementDirection direction);

    bool isPlayerMoveInMap(MovementDirection direction);

    void makePlayerMovement(MovementDirection direction);

    bool canAccessMapInDirection(MovementDirection direction);

    void switchMap(MovementDirection direction);

    Position posInDirection(Position position, MovementDirection direction);

    void end();

    explicit Game(GamePosition playerStartPosition);
public:

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;

    ~Game() override;

    Player* getPlayer();

    friend class GameCreator;
    friend class DebugGame;

    Map *getCurrentMap();

    bool lightUpTorch(Torch* torch);

    bool areAllTorchesLitUp();

    GamePosition getEndingPosition();

    void teleportPlayer(GamePosition position);

    std::vector<std::vector<Map *>> getMapMatrix();

    int getWidth();
};


#endif //PROJECT_LUMINARY_GAME_H
