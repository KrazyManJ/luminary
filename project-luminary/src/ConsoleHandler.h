#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"

#ifndef PROJECT_LUMINARY_CONSOLEHANDLER_H
#define PROJECT_LUMINARY_CONSOLEHANDLER_H

#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_RIGHT 77
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_E 101

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

#pragma clang diagnostic pop