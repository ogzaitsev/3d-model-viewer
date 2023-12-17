#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_OBJFILEREADER_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_OBJFILEREADER_H_

#include <fstream>
#include <memory>
#include <string>

using namespace std;

namespace ogzaitsev {

//! A class for interacting with .obj files
class ObjFileReader {
 private:
  ifstream file;

 public:
  bool setFileName(const string& filename);
  bool validate();

  void dataInfo(int& pointNumber, int& faceNumber, int& indexArrayLength);
  void fillDataArrays(shared_ptr<int[]> indexArray,
                      shared_ptr<double[]> pointArray);

  ObjFileReader() : file() {}
  ObjFileReader(const string& filename);
  ~ObjFileReader();

 private:
  int indicesOnFace(string& str);
  int extractIndex(string& str, size_t& i);
  void parseVertex(string line, shared_ptr<double[]> pointArray,
                   int& pointArrayIndex);
  void parseFace(string line, shared_ptr<int[]> indexArray,
                 int& indexArrayIndex);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_OBJFILEREADER_H_