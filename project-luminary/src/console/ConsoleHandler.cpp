#include <iostream>
#include <conio.h>
#include "ConsoleHandler.h"

ConsoleHandler::KeyEvent::KeyEvent(unsigned int key, bool arrowEscaped) {
    this->m_key = key;
    this->m_arrowEscaped = arrowEscaped;
}

unsigned int ConsoleHandler::KeyEvent::getKey() {
    return this->m_key;
}

bool ConsoleHandler::KeyEvent::isArrowEscaped() {
    return this->m_arrowEscaped;
}

void ConsoleHandler::setCursorPosition(unsigned short x, unsigned short y) {
    std::cout << "\033[" + std::to_string(y) + ";" + std::to_string(x) + "H";
}

void ConsoleHandler::setCursorPosition(Position position) {
    ConsoleHandler::setCursorPosition(position.x, position.y);
}

void ConsoleHandler::setConsoleTitle(std::string title) {
    std::cout << "\033]0;" + title + "\007";
}

void ConsoleHandler::disableCursorVisibility() {
    std::cout << "\033[?25l";
}

void ConsoleHandler::clear() {
    std::cout << "\033[1J";
}

ConsoleHandler::KeyEvent *ConsoleHandler::handleKeyboardInput() {
    int key = getch();
    bool isArrowEscaped = false;
    if (key == 224) {
        key = getch();
        isArrowEscaped = true;
    }
    return new KeyEvent(key, isArrowEscaped);
}

std::string ConsoleHandler::getColorChar(unsigned char r, unsigned char g, unsigned char b,
                                         ConsoleHandler::CharColorTarget target) {
    std::string targetVal = (target == CharColorTarget::FOREGROUND) ? "38" : "48";
    return "\033[" + targetVal + ";2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) +
           "m";
}

std::string ConsoleHandler::getColorChar(unsigned int hex, ConsoleHandler::CharColorTarget target) {
    return getColorChar(((hex >> 16) & 0xFF), ((hex >> 8) & 0xFF), (hex & 0xFF), target);
}

std::string ConsoleHandler::getFormatChar(ConsoleHandler::ConsoleFormatType type) {
    int code;
    switch (type) {
        case RESET:
            code = 0;
            break;
        case ITALIC:
            code = 3;
            break;
        case INVERTED:
            code = 7;
            break;
        case BLINKING:
            code = 5;
            break;
        case UNDERLINE:
            code = 4;
            break;
        case STRIKETHROUGH:
            code = 9;
            break;
    }
    return "\033[" + std::to_string(code) + "m";
}
