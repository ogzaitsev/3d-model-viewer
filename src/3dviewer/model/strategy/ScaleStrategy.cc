#include "ScaleStrategy.h"
#include <cmath>

namespace ogzaitsev {
    
void ScaleStrategy::Trasform3DObject(std::shared_ptr<Data3D> data, double ratio, transform_t type) {
    if (type == zoomIn)
        for (int i = 0; i < data.get()->getPointArrayLength(); ++i)
            data.get()->getPointArray()[i] *= ratio;
    else if (type == zoomOut)
        for (int i = 0; i < data.get()->getPointArrayLength(); ++i)
            data.get()->getPointArray()[i] /= ratio;
}

} // namespace s21