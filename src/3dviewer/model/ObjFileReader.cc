#include "ObjFileReader.h"

#include <vector>

namespace ogzaitsev {

ObjFileReader::ObjFileReader(const string& filename) {
  this->file = ifstream(filename);
}

ObjFileReader::~ObjFileReader() {
  if (file.is_open()) file.close();
}

bool ObjFileReader::setFileName(const string& filename) {
  file.open(filename);
  return file.is_open();
}

bool ObjFileReader::validate() {
  if (file.peek() == std::ifstream::traits_type::eof()) {
    return false;  // empty file
  }
  return true;
}

void ObjFileReader::dataInfo(int& pointNumber, int& faceNumber,
                             int& indexArrayLength) {
  pointNumber = 0;
  faceNumber = 0;
  indexArrayLength = 0;
  string strline;
  if (!file.good()) return;
  while (file.good()) {
    getline(file, strline);
    if (strline.length() > 2 && strline.at(0) == 'v' && strline.at(1) == ' ') {
      ++pointNumber;
    }
    if (strline.length() > 2 && strline.at(0) == 'f' && strline.at(1) == ' ') {
      indexArrayLength += indicesOnFace(strline) * 2;
      ++faceNumber;
    }
  }
  file.clear();
  file.seekg(0);
}

int ObjFileReader::indicesOnFace(string& line) {
  size_t len = line.length();
  int result = 0;
  for (size_t i = 0; i < len; ++i) {
    if (isdigit(line.at(i))) {
      ++result;
      extractIndex(line, i);
    }
  }
  return result;
}

void ObjFileReader::fillDataArrays(shared_ptr<int[]> indexArray,
                                   shared_ptr<double[]> pointArray) {
  string strline;
  int i = 0;
  int p = 0;
  if (!file.good()) return;
  while (file.good()) {
    getline(file, strline);
    if (strline.length() > 2 && strline.at(0) == 'v' && strline.at(1) == ' ') {
      parseVertex(strline, pointArray, p);
    }
    if (strline.length() > 2 && strline.at(0) == 'f' && strline.at(1) == ' ') {
      parseFace(strline, indexArray, i);
    }
  }
  file.clear();
  file.seekg(0);
}

void ObjFileReader::parseVertex(string line, shared_ptr<double[]> pointArray,
                                int& pointArrayIndex) {
  size_t len = line.length();
  for (size_t i = 0; i < len; ++i) {
    if (isdigit(line.at(i)) || line.at(i) == '-') {
      size_t numlen = 0;
      pointArray[pointArrayIndex] = stod(line.substr(i), &numlen);
      i += numlen;
      ++pointArrayIndex;
    }
  }
}

void ObjFileReader::parseFace(string line, shared_ptr<int[]> indexArray,
                              int& indexArrayIndex) {
  size_t len = line.length();
  vector<int> indices;
  for (size_t i = 0; i < len; ++i) {
    if (isdigit(line.at(i))) {
      indices.push_back(extractIndex(line, i));
    }
  }
  int i = 0;
  while (i < static_cast<int>(indices.size())) {
    indexArray[indexArrayIndex++] = indices[i++];
    if (i < static_cast<int>(indices.size()))
      indexArray[indexArrayIndex++] = indices[i];
    else
      indexArray[indexArrayIndex++] = indices[0];
  }
}

int ObjFileReader::extractIndex(string& str, size_t& i) {
  size_t numlen;
  int result = stoi(str.substr(i), &numlen);  // get index
  i += numlen;
  if (i < str.length() && str.at(i) == '/') {  // skip all unnessesary data
    if (isdigit(str.at(++i))) {
      stoi(str.substr(i), &numlen);
      i += numlen;
    }
    if (i < str.length() && str.at(i) == '/') {
      if (isdigit(str.at(++i))) {
        stoi(str.substr(i), &numlen);
        i += numlen;
      }
    }
  }
  return result;
}

}  // namespace s21
