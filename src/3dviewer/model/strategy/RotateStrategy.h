#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_ROTATESTRATEGY_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_ROTATESTRATEGY_H_

#include "TransformStrategy.h"

namespace ogzaitsev {

//! Strategy for rotating object
class RotateStrategy : public TransformStrategy {
    public:
        static const transform_t xAxes = 0;
        static const transform_t yAxes = 1;
        static const transform_t zAxes = 2;

        void Trasform3DObject(std::shared_ptr<Data3D> data, double angle, transform_t type);
};

}  // namespace s21



#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_ROTATESTRATEGY_H_