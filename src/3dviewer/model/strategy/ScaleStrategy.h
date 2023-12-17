#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_SCALESTRATEGY_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_SCALESTRATEGY_H_

#include "TransformStrategy.h"

namespace ogzaitsev {

//! Strategy for scaling object
class ScaleStrategy : public TransformStrategy {
    public:
        static const transform_t zoomIn = 1;
        static const transform_t zoomOut = 2;

        virtual void Trasform3DObject(std::shared_ptr<Data3D> data, double ratio, transform_t type);
};

}  // namespace s21



#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_SCALESTRATEGY_H_