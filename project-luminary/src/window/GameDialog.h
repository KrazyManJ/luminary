#ifndef PROJECT_LUMINARY_GAMEDIALOG_H
#define PROJECT_LUMINARY_GAMEDIALOG_H


#include "ReturnableWindow.h"

class GameDialog : public ReturnableWindow {
private:
    bool m_faded;
    std::string m_text;
public:
    GameDialog(std::string text, Window *prevWindow);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEDIALOG_H
