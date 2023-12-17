#include "DataBuilder.h"

namespace ogzaitsev {

DataBuilder::~DataBuilder() {}

DataBuilder& DataBuilder::setFile(const std::string& filename) {
  this->filename = filename;
  ObjFileReader fileReader;
  fileReader.setFileName(filename);
  if (!fileReader.validate()) {
    this->filename = "";
    throw std::runtime_error("File is corrupted or empty");
  }
  return *this;
}

DataBuilder& DataBuilder::setData() {
  if (filename.empty()) return *this;
  int faceNumber, pointNumber, indexArrayLength;
  ObjFileReader fileReader(filename);
  fileReader.dataInfo(pointNumber, faceNumber, indexArrayLength);
  shared_ptr<int[]> indexArray(new int[indexArrayLength]);
  shared_ptr<double[]> pointArray(new double[pointNumber * 3]);
  fileReader.fillDataArrays(indexArray, pointArray);
  for (int i = 0; i < indexArrayLength; ++i) --indexArray[i];
  this->data = make_shared<Data3D>(pointNumber, faceNumber, indexArrayLength,
                                   indexArray, pointArray);
  return *this;
}

std::shared_ptr<Data3D> DataBuilder::getData() { return this->data; }

DataBuilder& DataBuilder::reset() {
  this->filename = "";
  this->data = nullptr;
  return *this;
}

}  // namespace s21
