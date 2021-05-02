//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>

class TreeTestCase : public ::testing::Test {
 public:
//  static void SetUpTestCase();
//  static void TearDownTestCase();
 protected:
  void SetUp() final;
//  void TearDown() final;

  static boost::filesystem::path path_to_tmp_dir_;
  boost::filesystem::path empty_dir_path_;
  boost::filesystem::path test_file_path_;
};

class FilterTestCase: public ::testing::Test {
protected:
 void SetUp() override;
};

class FileNodeEqualTestCase: public ::testing::Test {
 protected:
};


