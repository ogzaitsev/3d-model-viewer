#include "RotateStrategy.h"
#include <cmath>

namespace ogzaitsev {
    
void RotateStrategy::Trasform3DObject(std::shared_ptr<Data3D> data, double angle, transform_t type) {
    int shift_m = (type == 0) ? 1 : 0;
    int shift_k = (type == 2) ? 1 : 2;  // genius solution. Im proud!
    for (int i = 0; i < data.get()->getPointArrayLength(); i += 3) {
        double value_m = data.get()->getPointArray()[i + shift_m];
        double value_k = data.get()->getPointArray()[i + shift_k];
        data.get()->getPointArray()[i + shift_m] = (std::cos(angle) * value_m) - (std::sin(angle) * value_k);
        data.get()->getPointArray()[i + shift_k] = (std::sin(angle) * value_m) + (std::cos(angle) * value_k);
    }
}

} // namespace s21
