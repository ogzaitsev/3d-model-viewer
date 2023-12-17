#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_DATABUILDER_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_DATABUILDER_H_

#include "Data3D.h"
#include "ObjFileReader.h"

namespace ogzaitsev {

//! Builder for Data3D objects
/*!
 * Builder is a creational design pattern that lets you construct complex
 * objects step by step. The pattern organizes object construction into a set of
 * steps To create an object, you execute a series of these steps on a builder
 * object.
 */
class DataBuilder {
 private:
  shared_ptr<Data3D> data;
  std::string filename = "";

 public:
  DataBuilder& setFile(const string& filename);
  DataBuilder& setData();
  shared_ptr<Data3D> getData();
  //! The reset method clears the object being built.
  DataBuilder& reset();
  DataBuilder() : data(nullptr) {}
  ~DataBuilder();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_DATABUILDER_H_
