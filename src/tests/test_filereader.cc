#include <gtest/gtest.h>

#include "../3dviewer/model/ObjFileReader.h"

TEST(file_opening, construct_validate) {
  ogzaitsev::ObjFileReader reader("../../src/obj/cube.obj");
  EXPECT_TRUE(reader.validate());
}

TEST(file_opening, set_name) {
  ogzaitsev::ObjFileReader reader;
  reader.setFileName("../../src/obj/cube.obj");
  EXPECT_TRUE(reader.validate());
}

TEST(file_opening, fail_validate) {
  ogzaitsev::ObjFileReader reader;
  reader.setFileName("../../src/obj/empty.obj");
  EXPECT_FALSE(reader.validate());
}

TEST(file_opening, no_file) {
  ogzaitsev::ObjFileReader reader;
  EXPECT_FALSE(reader.setFileName("../../src/obj/nosuch.obj"));
  EXPECT_FALSE(reader.validate());
}

TEST(file_parsing, parse_values) {
  ogzaitsev::ObjFileReader reader("../../src/obj/tetrahedron.obj");
  int v, f, flen;
  EXPECT_TRUE(reader.validate());
  reader.dataInfo(v, f, flen);
  EXPECT_EQ(v, 4);
  EXPECT_EQ(f, 4);
  EXPECT_EQ(flen, 24);
}

TEST(file_parsing, parse_values2) {
  ogzaitsev::ObjFileReader reader("../../src/obj/cube.obj");
  int v, f, flen;
  EXPECT_TRUE(reader.validate());
  reader.dataInfo(v, f, flen);
  EXPECT_EQ(v, 8);
  EXPECT_EQ(f, 12);
  EXPECT_EQ(flen, 72);
}

TEST(file_parsing, parse_wireframe_data) {
  ogzaitsev::ObjFileReader reader("../../src/obj/cube.obj");
  int v, f, flen;
  reader.dataInfo(v, f, flen);
  shared_ptr<int[]> indexArray(new int[flen]);
  shared_ptr<double[]> pointArray(new double[v * 3]);
  reader.fillDataArrays(indexArray, pointArray);
  EXPECT_EQ(pointArray[0], 0);
  EXPECT_EQ(pointArray[5], 1);
  EXPECT_EQ(pointArray[6], 0);
  EXPECT_EQ(pointArray[7], 1);
  EXPECT_EQ(pointArray[8], 0);
  EXPECT_EQ(pointArray[9], 0);
  EXPECT_EQ(pointArray[10], 1);
  EXPECT_EQ(pointArray[11], 1);
  EXPECT_EQ(pointArray[21], 1);
  EXPECT_EQ(pointArray[22], 1);
  EXPECT_EQ(pointArray[23], 1);
  EXPECT_EQ(indexArray[0], 1);
  EXPECT_EQ(indexArray[1], 7);
  EXPECT_EQ(indexArray[2], 7);
  EXPECT_EQ(indexArray[3], 5);
  EXPECT_EQ(indexArray[4], 5);
  EXPECT_EQ(indexArray[5], 1);
  EXPECT_EQ(indexArray[6], 1);
  EXPECT_EQ(indexArray[7], 3);
  EXPECT_EQ(indexArray[8], 3);
  EXPECT_EQ(indexArray[9], 7);
  EXPECT_EQ(indexArray[10], 7);
  EXPECT_EQ(indexArray[11], 1);
  EXPECT_EQ(indexArray[66], 2);
  EXPECT_EQ(indexArray[67], 8);
  EXPECT_EQ(indexArray[68], 8);
  EXPECT_EQ(indexArray[69], 4);
  EXPECT_EQ(indexArray[70], 4);
  EXPECT_EQ(indexArray[71], 2);
}
