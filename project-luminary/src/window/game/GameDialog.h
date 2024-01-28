#ifndef PROJECT_LUMINARY_GAMEDIALOG_H
#define PROJECT_LUMINARY_GAMEDIALOG_H


#include "../ReturnableWindow.h"
#include "../../Game.h"

class GameDialog : public ReturnableWindow {
private:
    bool m_faded;
    std::string m_text;
    Game* m_game;
public:
    GameDialog(std::string text, Game *game);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEDIALOG_H
