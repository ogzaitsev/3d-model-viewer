#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_DATA3D_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_DATA3D_H_

#include <memory>

namespace ogzaitsev {

//! An Object for storing .obj file data and metadata
class Data3D {
 private:
  int pointNumber;
  int faceNumber;

  int indexArrayLength;
  std::shared_ptr<int[]> indexArray;
  int pointArrayLength;
  std::shared_ptr<double[]> pointArray;

 public:
  Data3D(int pointNumber, int faceNumber, int indexArrayLength,
         std::shared_ptr<int[]> indexArray,
         std::shared_ptr<double[]> pointArray)
      : pointNumber(pointNumber),
        faceNumber(faceNumber),
        indexArrayLength(indexArrayLength),
        indexArray(indexArray),
        pointArrayLength(pointNumber * 3),
        pointArray(pointArray) {}
  ~Data3D() {}

  std::shared_ptr<int[]> getIndexArray() { return indexArray; }
  std::shared_ptr<double[]> getPointArray() { return pointArray; }
  int getIndexArrayLength() { return indexArrayLength; }
  int getPointArrayLength() { return pointArrayLength; }
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_DATA3D_H_
