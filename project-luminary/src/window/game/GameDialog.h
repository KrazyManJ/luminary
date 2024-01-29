#ifndef PROJECT_LUMINARY_GAMEDIALOG_H
#define PROJECT_LUMINARY_GAMEDIALOG_H


#include "../../Game.h"
#include "GameReturnableWindow.h"

class GameDialog : public GameReturnableWindow {
private:
    bool m_faded;
    std::string m_text;
    bool m_fullScreen;
    bool m_lower;

    void renderClassic();

    void renderFullScreen();
public:
    GameDialog(std::string text, Game *game, bool fullScreen = false);
    GameDialog(std::string text, Game *game, bool lower, bool fullScreen);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEDIALOG_H
