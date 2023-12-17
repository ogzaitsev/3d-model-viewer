#include "TransformContext.h"

namespace ogzaitsev {

TransformContext::TransformContext(
    std::unique_ptr<TransformStrategy>&& strategy)
    : strategy(std::move(strategy)) {}

void TransformContext::transform(std::shared_ptr<Data3D> data, double value,
                                 TransformStrategy::transform_t type) {
  strategy->Trasform3DObject(data, value, type);
}

void TransformContext::setStrategy(
    std::unique_ptr<TransformStrategy>&& strategy) {
  this->strategy = std::move(strategy);
}

}  // namespace s21
