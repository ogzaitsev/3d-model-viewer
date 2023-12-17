#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_TRANSFORMSTRATEGY_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_TRANSFORMSTRATEGY_H_

#include "../Data3D.h"

namespace ogzaitsev {

//! Strategy interface
/*!
 * The strategy interface declares operations common to all
 * supported versions of transformation algorithm. The context uses this
 * interface to call the algorithm defined by the concrete
 * strategies.
*/
class TransformStrategy {
    public:
        using transform_t = int;
 
        virtual ~TransformStrategy() = default;
        virtual void Trasform3DObject(std::shared_ptr<Data3D> data, double value, transform_t type) = 0;
};

} // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_STRATEGY_TRANSFORMSTRATEGY_H_