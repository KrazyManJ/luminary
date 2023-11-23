#define K_ESC 27

#ifndef PROJECT_LUMINARY_CONSOLEHANDLER_H
#define PROJECT_LUMINARY_CONSOLEHANDLER_H


#include <string>
#include "structs/Position.h"

class ConsoleHandler {
public:
    class KeyEvent {
    private:
        unsigned int m_key;
        bool m_arrowEscaped;

        KeyEvent(unsigned int key, bool arrowEscaped);

        /**
         * Makes it accessible to ConsoleHandler
         */
        friend class ConsoleHandler;

    public:

        unsigned int getKey();

        bool isArrowEscaped();
    };

    enum ConsoleFormatType {
        RESET, ITALIC, BLINKING, INVERTED, UNDERLINE, STRIKETHROUGH
    };
    enum CharColorTarget {
        BACKGROUND, FOREGROUND
    };

    static void setCursorPosition(unsigned short x, unsigned short y);

    static void setCursorPosition(Position position);

    static void setConsoleTitle(std::string title);

    static void disableCursorVisibility();

    static void clear();

    static KeyEvent *handleKeyboardInput();

    static std::string getColorChar(unsigned char r, unsigned char g, unsigned char b, CharColorTarget target);

    static std::string getColorChar(unsigned int hex, CharColorTarget target);

    static std::string getFormatChar(ConsoleFormatType type);
};


#endif //PROJECT_LUMINARY_CONSOLEHANDLER_H
