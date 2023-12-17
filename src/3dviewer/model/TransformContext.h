#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_OBJECTSTRANSFORMER_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_OBJECTSTRANSFORMER_H_

#include "Data3D.h"
#include "strategy/MoveStrategy.h"
#include "strategy/RotateStrategy.h"
#include "strategy/ScaleStrategy.h"
#include "strategy/TransformStrategy.h"

namespace ogzaitsev {

//! Context for transforming Data3D objects
/*! The context maintains a reference to one of the strategy
 * objects. The context doesn't know the concrete class of a
 * strategy. It should work with all strategies via the
 * strategy interface.
 */
class TransformContext {
 private:
  std::unique_ptr<TransformStrategy> strategy;

 public:
  //! Usually the context accepts a strategy through the constructor
  TransformContext(std::unique_ptr<TransformStrategy>&& strategy);
  ~TransformContext() = default;

  //! the context also provides a setter so that the strategy can be switched
  void setStrategy(std::unique_ptr<TransformStrategy>&& strategy);

  void transform(std::shared_ptr<Data3D> data, double value,
                 TransformStrategy::transform_t type);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_OBJECTSTRANSFORMER_H_