//
// Created by akhtyamovpavel on 5/1/20.
//

#include <boost/filesystem.hpp>
#include "TreeTestCase.h"
#include "Tree.h"

boost::filesystem::path TreeTestCase::path_to_tmp_dir_;

void TreeTestCase::SetUpTestCase() {
  path_to_tmp_dir_ = boost::filesystem::temp_directory_path()  / boost::filesystem::unique_path();
  if (!boost::filesystem::exists(path_to_tmp_dir_)) {
    boost::filesystem::create_directory(path_to_tmp_dir_);
  }
}

void TreeTestCase::TearDownTestCase() {
  if (boost::filesystem::exists(path_to_tmp_dir_)) {
    boost::filesystem::remove_all(path_to_tmp_dir_);
  }
}

void TreeTestCase::SetUp() {
  empty_dir_path_ = path_to_tmp_dir_ / boost::filesystem::unique_path();
  test_file_path_ = path_to_tmp_dir_ / boost::filesystem::unique_path();

  boost::filesystem::create_directory(empty_dir_path_);

  boost::filesystem::ofstream file(test_file_path_);
  file << "test_data";
  file.close();
}

void TreeTestCase::TearDown() {
  if (boost::filesystem::exists(empty_dir_path_)) {
    boost::filesystem::remove_all(empty_dir_path_);
  }

  if (boost::filesystem::exists(test_file_path_)) {
    boost::filesystem::remove(test_file_path_);
  }
}

TEST_F(TreeTestCase, PathDoesntExist) {
  EXPECT_THROW(GetTree((path_to_tmp_dir_ / boost::filesystem::unique_path()).string(), true), std::invalid_argument);
}

TEST_F(TreeTestCase, NotDir) {
  EXPECT_THROW(GetTree(test_file_path_.string(), true), std::invalid_argument);
}

TEST_F(TreeTestCase, OnlyDirs) {
  auto res = GetTree(path_to_tmp_dir_.string(), true);
  EXPECT_EQ(res.children.size(), 1);
}

TEST_F(TreeTestCase, AllFiles) {
  auto res = GetTree(path_to_tmp_dir_.string(), false);
  EXPECT_EQ(res.children.size(), 2);
}

TEST_F(TreeTestCase, FilterDirsEmptyDir) {
  FilterEmptyNodes(GetTree(path_to_tmp_dir_.string(), false), path_to_tmp_dir_);
  EXPECT_FALSE(boost::filesystem::exists(empty_dir_path_));
}

TEST_F(TreeTestCase, FilterDirsNotEmptyDir) {
  FilterEmptyNodes(GetTree(path_to_tmp_dir_.string(), false), path_to_tmp_dir_);
  EXPECT_TRUE(boost::filesystem::exists(path_to_tmp_dir_));
}

TEST_F(TreeTestCase, FilterDirsFile) {
  FilterEmptyNodes(GetTree(path_to_tmp_dir_.string(), false), path_to_tmp_dir_);
  EXPECT_TRUE(boost::filesystem::exists(test_file_path_));
}

TEST_F(TreeTestCase, EqualNodes) {
  EXPECT_EQ(GetTree(path_to_tmp_dir_.string(), true) == GetTree(path_to_tmp_dir_.string(), true), true);
}

TEST_F(TreeTestCase, AbsolutelyDifferentNodes) {
  FileNode first_node = {"test1", false, {FileNode{"ch1", false, {}}}};
  FileNode second_node = {"test12", false, {FileNode{"ch2", false, {}}}};

  EXPECT_FALSE(first_node == second_node);
}

TEST_F(TreeTestCase, NodesWithSameNameAndDifferentParams) {
  FileNode first_node = {"test", false, {}};
  FileNode second_node = {"test", true, {}};

  EXPECT_FALSE(first_node == second_node);
}

TEST_F(TreeTestCase, NodesWithSameNameAndDifferentChilds) {
  FileNode first_node = {"test", true, {FileNode{"test2", false, {}}}};
  FileNode second_node = {"test", true, {FileNode{"test3", false, {}}}};

  EXPECT_FALSE(first_node == second_node);
}