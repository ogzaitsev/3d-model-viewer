#include "MoveStrategy.h"

namespace ogzaitsev {
    
void MoveStrategy::Trasform3DObject(std::shared_ptr<Data3D> data, double moveValue, transform_t type) {
    int shift = 0 + type;  // Genius solution. So proud
    for (int i = 0; i < data.get()->getPointArrayLength(); i += 3) {
        data.get()->getPointArray()[i + shift] += moveValue;
    }
}

} // namespace s21
