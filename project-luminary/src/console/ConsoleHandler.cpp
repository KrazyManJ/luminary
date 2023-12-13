#include <iostream>
#include <conio.h>
#include "ConsoleHandler.h"

ConsoleHandler::KeyEvent::KeyEvent(unsigned int key, bool arrowEscaped) {
    m_key = key;
    m_arrowEscaped = arrowEscaped;
}

unsigned int ConsoleHandler::KeyEvent::getKey() const {
    return m_key;
}

bool ConsoleHandler::KeyEvent::isArrowEscaped() const {
    return m_arrowEscaped;
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
                                         CharColorTarget target) {
    std::string targetVal = (target == CharColorTarget::FOREGROUND) ? "38" : "48";
    return "\033[" + targetVal + ";2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) +
           "m";
}

std::string ConsoleHandler::getColorChar(unsigned int hex, CharColorTarget target) {
    return getColorChar(((hex >> 16) & 0xFF), ((hex >> 8) & 0xFF), (hex & 0xFF), target);
}

std::string ConsoleHandler::getFormatChar(ConsoleFormatType type) {
    return "\033[" + std::to_string(type) + "m";
}
