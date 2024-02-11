#ifndef PROJECT_LUMINARY_CYCLER_H
#define PROJECT_LUMINARY_CYCLER_H


class Cycler {
private:
    unsigned int m_index;
    unsigned int m_max;
public:
    explicit Cycler(unsigned int maxIndex);

    void goUp();

    void goDown();

    unsigned int getIndex();

    void setMaxIndex(unsigned int newMaxIndex);
};


#endif //PROJECT_LUMINARY_CYCLER_H
