#include "Cycler.h"

Cycler::Cycler(unsigned int maxIndex) {
    m_index = 0;
    m_max = maxIndex;
}

void Cycler::goUp() {
    m_index = (m_index < m_max) ? m_index+1 : 0;
}

void Cycler::goDown() {
    m_index = (m_index > 0) ? m_index-1 : m_max;
}

unsigned int Cycler::getIndex() {
    return m_index;
}
