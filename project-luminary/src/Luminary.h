//
// Created by KrazyManJ on 22.11.2023.
//

#ifndef PROJECT_LUMINARY_LUMINARY_H
#define PROJECT_LUMINARY_LUMINARY_H


class Luminary {
private:
    static bool s_run;
public:
    static void initialize();
    static void startLoop();
    static void exit();
};


#endif //PROJECT_LUMINARY_LUMINARY_H
