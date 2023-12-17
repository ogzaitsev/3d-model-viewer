#include <gtest/gtest.h>

#include <cmath>

#include "../3dviewer/model/DataBuilder.h"
#include "../3dviewer/model/TransformContext.h"

TEST(transformations, move_x) {
  double shift = 1.0;
  ogzaitsev::DataBuilder builder;
  std::shared_ptr<ogzaitsev::Data3D> data =
      builder.setFile("../obj/tetrahedron.obj").setData().getData();
  ogzaitsev::TransformContext transformer(std::make_unique<ogzaitsev::MoveStrategy>());
  transformer.transform(data, shift, ogzaitsev::MoveStrategy::xAxes);
  EXPECT_EQ(data.get()->getPointArray()[0], 2);
  EXPECT_EQ(data.get()->getPointArray()[1], 0);
  EXPECT_EQ(data.get()->getPointArray()[2], 0);
  EXPECT_EQ(data.get()->getPointArray()[3], 1);
  EXPECT_EQ(data.get()->getPointArray()[4], 1);
  EXPECT_EQ(data.get()->getPointArray()[5], 0);
  EXPECT_EQ(data.get()->getPointArray()[6], 1);
  EXPECT_EQ(data.get()->getPointArray()[7], 0);
  EXPECT_EQ(data.get()->getPointArray()[8], 1);
  EXPECT_EQ(data.get()->getPointArray()[9], 1);
  EXPECT_EQ(data.get()->getPointArray()[10], 0);
  EXPECT_EQ(data.get()->getPointArray()[11], 0);
}

TEST(transformations, move_y) {
  double shift = 1.0;
  ogzaitsev::DataBuilder builder;
  std::shared_ptr<ogzaitsev::Data3D> data =
      builder.setFile("../obj/tetrahedron.obj").setData().getData();
  ogzaitsev::TransformContext transformer(std::make_unique<ogzaitsev::MoveStrategy>());
  transformer.transform(data, shift, ogzaitsev::MoveStrategy::yAxes);
  EXPECT_EQ(data.get()->getPointArray()[0], 1);
  EXPECT_EQ(data.get()->getPointArray()[1], 1);
  EXPECT_EQ(data.get()->getPointArray()[2], 0);
  EXPECT_EQ(data.get()->getPointArray()[3], 0);
  EXPECT_EQ(data.get()->getPointArray()[4], 2);
  EXPECT_EQ(data.get()->getPointArray()[5], 0);
  EXPECT_EQ(data.get()->getPointArray()[6], 0);
  EXPECT_EQ(data.get()->getPointArray()[7], 1);
  EXPECT_EQ(data.get()->getPointArray()[8], 1);
  EXPECT_EQ(data.get()->getPointArray()[9], 0);
  EXPECT_EQ(data.get()->getPointArray()[10], 1);
  EXPECT_EQ(data.get()->getPointArray()[11], 0);
}

TEST(transformations, move_z) {
  double shift = 1.0;
  ogzaitsev::DataBuilder builder;
  std::shared_ptr<ogzaitsev::Data3D> data =
      builder.setFile("../obj/tetrahedron.obj").setData().getData();
  ogzaitsev::TransformContext transformer(std::make_unique<ogzaitsev::MoveStrategy>());
  transformer.transform(data, shift, ogzaitsev::MoveStrategy::zAxes);
  EXPECT_EQ(data.get()->getPointArray()[0], 1);
  EXPECT_EQ(data.get()->getPointArray()[1], 0);
  EXPECT_EQ(data.get()->getPointArray()[2], 1);
  EXPECT_EQ(data.get()->getPointArray()[3], 0);
  EXPECT_EQ(data.get()->getPointArray()[4], 1);
  EXPECT_EQ(data.get()->getPointArray()[5], 1);
  EXPECT_EQ(data.get()->getPointArray()[6], 0);
  EXPECT_EQ(data.get()->getPointArray()[7], 0);
  EXPECT_EQ(data.get()->getPointArray()[8], 2);
  EXPECT_EQ(data.get()->getPointArray()[9], 0);
  EXPECT_EQ(data.get()->getPointArray()[10], 0);
  EXPECT_EQ(data.get()->getPointArray()[11], 1);
}

TEST(transformations, zoom_in) {
  double ratio = 2;
  ogzaitsev::DataBuilder builder;
  std::shared_ptr<ogzaitsev::Data3D> data =
      builder.setFile("../obj/tetrahedron.obj").setData().getData();
  ogzaitsev::TransformContext transformer(std::make_unique<ogzaitsev::ScaleStrategy>());
  transformer.transform(data, ratio, ogzaitsev::ScaleStrategy::zoomIn);
  EXPECT_EQ(data.get()->getPointArray()[0], 2);
  EXPECT_EQ(data.get()->getPointArray()[1], 0);
  EXPECT_EQ(data.get()->getPointArray()[2], 0);
  EXPECT_EQ(data.get()->getPointArray()[3], 0);
  EXPECT_EQ(data.get()->getPointArray()[4], 2);
  EXPECT_EQ(data.get()->getPointArray()[5], 0);
  EXPECT_EQ(data.get()->getPointArray()[6], 0);
  EXPECT_EQ(data.get()->getPointArray()[7], 0);
  EXPECT_EQ(data.get()->getPointArray()[8], 2);
  EXPECT_EQ(data.get()->getPointArray()[9], 0);
  EXPECT_EQ(data.get()->getPointArray()[10], 0);
  EXPECT_EQ(data.get()->getPointArray()[11], 0);
}

TEST(transformations, zoom_out) {
  double ratio = 2;
  ogzaitsev::DataBuilder builder;
  std::shared_ptr<ogzaitsev::Data3D> data =
      builder.setFile("../obj/tetrahedron.obj").setData().getData();
  ogzaitsev::TransformContext transformer(std::make_unique<ogzaitsev::RotateStrategy>());
  transformer.setStrategy(std::make_unique<ogzaitsev::ScaleStrategy>());
  transformer.transform(data, ratio, ogzaitsev::ScaleStrategy::zoomOut);
  EXPECT_EQ(data.get()->getPointArray()[0], 1.0 / ratio);
  EXPECT_EQ(data.get()->getPointArray()[1], 0);
  EXPECT_EQ(data.get()->getPointArray()[2], 0);
  EXPECT_EQ(data.get()->getPointArray()[3], 0);
  EXPECT_EQ(data.get()->getPointArray()[4], 1.0 / ratio);
  EXPECT_EQ(data.get()->getPointArray()[5], 0);
  EXPECT_EQ(data.get()->getPointArray()[6], 0);
  EXPECT_EQ(data.get()->getPointArray()[7], 0);
  EXPECT_EQ(data.get()->getPointArray()[8], 1.0 / ratio);
  EXPECT_EQ(data.get()->getPointArray()[9], 0);
  EXPECT_EQ(data.get()->getPointArray()[10], 0);
  EXPECT_EQ(data.get()->getPointArray()[11], 0);
  builder.reset();
}

TEST(transformations, rotate_x) {
  double angle = 1.5708;
  ogzaitsev::DataBuilder builder;
  std::shared_ptr<ogzaitsev::Data3D> data =
      builder.setFile("../obj/tetrahedron.obj").setData().getData();
  ogzaitsev::TransformContext transformer(std::make_unique<ogzaitsev::RotateStrategy>());
  transformer.transform(data, angle, ogzaitsev::RotateStrategy::xAxes);
  EXPECT_TRUE(std::fabs(data.get()->getPointArray()[0] - 1) < 0.000001);
  EXPECT_TRUE(std::fabs(data.get()->getPointArray()[1] - 0) < 0.000001);
  EXPECT_TRUE(std::fabs(data.get()->getPointArray()[2] - 0) < 0.000001);
  EXPECT_TRUE(std::fabs(data.get()->getPointArray()[3] - 0) < 0.000001);
  EXPECT_TRUE(std::fabs(data.get()->getPointArray()[4] - (-0.00000367321)) <
              0.000001);
  EXPECT_TRUE(std::fabs(data.get()->getPointArray()[7] - (-1)) < 0.000001);
}