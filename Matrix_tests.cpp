#include "Matrix.hpp"
#include "Matrix_test_helpers.hpp"
#include "unit_test_framework.hpp"


using namespace std;




// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic_one) {
Matrix *mat_one = new Matrix; // create a Matrix in dynamic memory


const int width_one = 3;
const int height_one = 5;
const int value_one = 42;
Matrix_init(mat_one, 3, 5);
Matrix_fill(mat_one, value_one);


for(int r = 0; r < height_one; ++r){
for(int c = 0; c < width_one; ++c){
ASSERT_EQUAL(*Matrix_at(mat_one, r, c), value_one);
}
}


delete mat_one; // delete the Matrix
}


// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.hpp as needed.




// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()


TEST(test_fill_basic_two) {
Matrix *mat = new Matrix; // create a Matrix in dynamic memory


const int width = 100;
const int height = 100;
const int value = 4;
Matrix_init(mat, 100, 100);
Matrix_fill(mat, value);


for(int r = 0; r < height; ++r){
for(int c = 0; c < width; ++c){
ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
}
}


delete mat; // delete the Matrix
}


TEST(test_fill_basic_three) {
Matrix *mat = new Matrix; // create a Matrix in dynamic memory


const int width = 1;
const int height = 1;
const int value = 0;
Matrix_init(mat, 1, 1);
Matrix_fill(mat, value);


for(int r = 0; r < height; ++r){
for(int c = 0; c < width; ++c){
ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
}
}


delete mat; // delete the Matrix
}


TEST(test_fill_basic_four) {
Matrix *mat = new Matrix; // create a Matrix in dynamic memory


const int width = 5;
const int height = 5;
const int value = 10;
Matrix_init(mat, width, height);
Matrix_fill(mat, value);


for(int r = 0; r < height; ++r){
for(int c = 0; c < width; ++c){
ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
}
}


delete mat; // delete the Matrix
}


TEST(test_fill_basic_five) {
Matrix *mat = new Matrix; // create a Matrix in dynamic memory


const int width = 1;
const int height = 1;
const int value = 7;
Matrix_init(mat, width, height);
Matrix_fill(mat, value);


// Check the single element in the matrix.
ASSERT_EQUAL(*Matrix_at(mat, 0, 0), value);


delete mat; // delete the Matrix
}












TEST(test_matrix_basic_one) {
Matrix *mat = new Matrix;
Matrix_init(mat, 5, 5);


int width = Matrix_width(mat);
int height = Matrix_height(mat);
ASSERT_EQUAL(width, 5);
ASSERT_EQUAL(height, 5);


Matrix_fill(mat, 0);


int *ptr = Matrix_at(mat, 2, 3);
ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
ASSERT_EQUAL(Matrix_column(mat, ptr), 3);
ASSERT_EQUAL(*ptr, 0);
*ptr = 42;


const int *cptr = Matrix_at(mat, 2, 3);
ASSERT_EQUAL(*cptr, 42);


Matrix_fill_border(mat, 2);
ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 2);
ASSERT_EQUAL(*Matrix_at(mat, 4, 4), 2);
ASSERT_EQUAL(*Matrix_at(mat, 0, 4), 2);
ASSERT_EQUAL(*Matrix_at(mat, 4, 0), 2);


ASSERT_EQUAL(Matrix_max(mat), 42);


delete mat;
}


TEST(test_matrix_basic_two) {
Matrix *mat = new Matrix;
Matrix_init(mat, 4, 4);


int width = Matrix_width(mat);
int height = Matrix_height(mat);
ASSERT_EQUAL(width, 4);
ASSERT_EQUAL(height, 4);


Matrix_fill(mat, 1);


int *ptr = Matrix_at(mat, 1, 2);
ASSERT_EQUAL(Matrix_row(mat, ptr), 1);
ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
ASSERT_EQUAL(*ptr, 1);
*ptr = 99;


const int *cptr = Matrix_at(mat, 1, 2);
ASSERT_EQUAL(*cptr, 99);


Matrix_fill_border(mat, 0);
ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 0);
ASSERT_EQUAL(Matrix_max(mat), 99);


delete mat;
}


TEST(test_matrix_edge_cases) {
Matrix *mat = new Matrix;
Matrix_init(mat, 1, 1);


int width = Matrix_width(mat);
int height = Matrix_height(mat);
ASSERT_EQUAL(width, 1);
ASSERT_EQUAL(height, 1);


Matrix_fill(mat, 5);
ASSERT_EQUAL(Matrix_max(mat), 5);
delete mat;
}


TEST(test_matrix_large_matrix) {
// Test with a large matrix and filling with a large value.
Matrix *mat = new Matrix;
Matrix_init(mat, 500, 500);


int width = Matrix_width(mat);
int height = Matrix_height(mat);
ASSERT_EQUAL(width, 500);
ASSERT_EQUAL(height, 500);


Matrix_fill(mat, 9999);
ASSERT_EQUAL(*Matrix_at(mat, 250, 250), 9999);


Matrix_fill_border(mat, 1111);
ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 1111);
ASSERT_EQUAL(Matrix_max(mat), 9999);
ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 500), 0);
ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 499, 0, 500), 0);
ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 400, 401, 500), 499);
ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 400, 0, 500), 0);
ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 499, 401, 500), 401);
ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 499), 1111);
ASSERT_EQUAL(Matrix_min_value_in_row(mat, 499, 0, 499), 1111);
ASSERT_EQUAL(Matrix_min_value_in_row(mat, 499, 400, 499), 1111);
ASSERT_EQUAL(Matrix_min_value_in_row(mat, 300, 0, 500), 1111);
ASSERT_EQUAL(Matrix_min_value_in_row(mat, 499, 401, 499), 1111);
ASSERT_EQUAL(Matrix_min_value_in_row(mat, 300, 401, 499), 9999);
ASSERT_EQUAL(Matrix_max(mat), 9999);


delete mat;
}

TEST(test_matrix_print_one) {
Matrix *mat = new Matrix;
Matrix_init(mat, 1, 1);


int width = Matrix_width(mat);
int height = Matrix_height(mat);


*Matrix_at(mat, height-1, width-1) = 42;
ostringstream expected;
expected << "1 1\n"
<< "42 \n";
ostringstream actual;
Matrix_print(mat, actual);
ASSERT_EQUAL(expected.str(), actual.str());


delete mat;
}


TEST(test_matrix_print_two) {
Matrix *mat = new Matrix;
Matrix_init(mat, 2, 2);


int width = Matrix_width(mat);
int height = Matrix_height(mat);


Matrix_fill(mat,0);
*Matrix_at(mat, height-1, width-1) = 42;
ostringstream expected;
expected << "2 2\n"
<< "0 0 \n"
<< "0 42 \n";
ostringstream actual;
Matrix_print(mat, actual);
ASSERT_EQUAL(expected.str(), actual.str());


delete mat;
}


TEST(test_matrix_print_three) {
Matrix *mat = new Matrix;
Matrix_init(mat, 3, 3);




Matrix_fill(mat,1);
Matrix_fill_border(mat, 42);
ostringstream expected;
expected << "3 3\n"
<< "42 42 42 \n"
<< "42 1 42 \n"
<< "42 42 42 \n";
ostringstream actual;
Matrix_print(mat, actual);
ASSERT_EQUAL(expected.str(), actual.str());


delete mat;
}

/*
TEST(test_matrix_print_large_matrix) {
Matrix *mat = new Matrix;
Matrix_init(mat, 3, 3);


int width = Matrix_width(mat);
int height = Matrix_height(mat);


for (int i = 0; i < width; i++) {
for (int j = 0; j < height; j++) {
*Matrix_at(mat, j, i) = i * 3 + j + 1;
}
}


ostringstream expected;
expected << "3 3\n"
<< "1 2 3 \n"
<< "4 5 6 \n"
<< "7 8 9 \n";
ostringstream actual;
Matrix_print(mat, actual);
ASSERT_EQUAL(expected.str(), actual.str());


delete mat;
}




TEST(test_matrix_print_row_vector) {
Matrix *mat = new Matrix;
Matrix_init(mat,1,5);


Matrix_fill(mat, 0);
*Matrix_at(mat,0,0) = 1;
*Matrix_at(mat,1,0) = 2;
*Matrix_at(mat,2,0) = 3;
*Matrix_at(mat,3,0) = 4;
*Matrix_at(mat,4,0) = 5;


ostringstream expected;


expected << "1 5\n"
<< "1 2 3 4 5 \n";
ostringstream actual;
Matrix_print(mat, actual);
ASSERT_EQUAL(expected.str(), actual.str());


delete mat;
}



TEST(test_matrix_print_column_vector) {
Matrix *mat = new Matrix;
Matrix_init(mat, 4, 1);


Matrix_fill(mat, 0);
*Matrix_at(mat, 0, 0) = 3;
*Matrix_at(mat, 0, 2) = 100;


ostringstream expected;
expected << "4 1\n"
<< "3 \n"
<< "0 \n"
<< "100 \n"
<< "0 \n";
ostringstream actual;
Matrix_print(mat, actual);
ASSERT_EQUAL(expected.str(), actual.str());


delete mat;
}
*/
TEST(test_innit) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 10, 10);
  ASSERT_EQUAL(Matrix_width(mat), 10);
  ASSERT_EQUAL(Matrix_height(mat), 10);

  delete mat;
}

TEST(test_row_column) {
  Matrix *mat = new Matrix;
  Matrix_init(mat,10, 10);
  *Matrix_at(mat, 5, 5) = 100;

  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 5, 5)), 5);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 9, 0)), 9);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 0, 9)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 5, 5)), 5);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 0)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 9, 9)), 9);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 9)), 9);

  delete mat;
}

TEST(test_min_column) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 10, 10);
  Matrix_fill(mat, 10);
  *Matrix_at(mat, 5, 5) = 100;
  
  *Matrix_at(mat, 4, 4) = 5;

  ASSERT_EQUAL(Matrix_max(mat), 100);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 4, 0, 8), 5);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 4, 0, 8), 4);

  delete mat;

}

TEST(test_min_column_two) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 10, 10);
  Matrix_fill(mat, 10);
  *Matrix_at(mat, 5, 5) = 5;
  *Matrix_at(mat, 5, 4) = 5;

  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 5, 0, 8), 5);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 5, 0, 8), 4);

  delete mat;

}

TEST(test_at) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 10, 10);
  Matrix_fill(mat, 10);
  
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, i, j), 10);
    }
  }
  delete mat;
}

TEST(test_at_2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 10, 10);
  Matrix_fill(mat, 10);
  
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 0, 0)), 0);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 2, 0)), 2);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 3, 3)), 3);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 4, 4)), 4);

  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 0)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 2)), 2);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 3, 3)), 3);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 4, 4)), 4);

  delete mat;
}

TEST(test_const_at) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 3);
  *Matrix_at(mat, 0, 0) = 1;
  *Matrix_at(mat, 0, 1) = 2;
  *Matrix_at(mat, 0, 2) = 3;
  *Matrix_at(mat, 1, 0) = 4;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 7;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 9;

  const Matrix *const_mat = mat;
  const int *value1 = Matrix_at(const_mat, 0, 0);
  const int *value2 = Matrix_at(const_mat, 0, 1);
  const int *value3 = Matrix_at(const_mat, 0, 2);
  const int *value4 = Matrix_at(const_mat, 1, 0);
  const int *value5 = Matrix_at(const_mat, 1, 1);
  const int *value6 = Matrix_at(const_mat, 1, 2);
  const int *value7 = Matrix_at(const_mat, 2, 0);
  const int *value8 = Matrix_at(const_mat, 2, 1);
  const int *value9 = Matrix_at(const_mat, 2, 2);
  ASSERT_EQUAL(*value1, 1);
  ASSERT_EQUAL(*value2, 2);
  ASSERT_EQUAL(*value3, 3);
  ASSERT_EQUAL(*value4, 4);
  ASSERT_EQUAL(*value5, 5);
  ASSERT_EQUAL(*value6, 6);
  ASSERT_EQUAL(*value7, 7);
  ASSERT_EQUAL(*value8, 8);
  ASSERT_EQUAL(*value9, 9);
    
  

  delete mat;

}

TEST(test_minimums) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 99);

  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 99);

  *Matrix_at(mat, 0, 0) = 0;

  Matrix_fill_border(mat, 100);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 100);

  int * ptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 100);
  ASSERT_EQUAL(Matrix_max(mat), 100);
  delete mat;
}

TEST(test_maximums) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, 99);

  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 99);
  ASSERT_EQUAL(*Matrix_at(mat, 499, 499), 99);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 499), 99);
  ASSERT_EQUAL(*Matrix_at(mat, 499, 0), 99);

  Matrix_fill(mat, 0);

  Matrix_fill_border(mat, 100);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 100);
  ASSERT_EQUAL(*Matrix_at(mat, 499, 499), 100);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 499), 100);
  ASSERT_EQUAL(*Matrix_at(mat, 499, 0), 100);
  ASSERT_EQUAL(*Matrix_at(mat, 300, 0), 100);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 300), 100);


  int * ptr = Matrix_at(mat, 499, 499);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 499);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 499);
  delete mat;
}

TEST(test_fill_4x6_matrix) {
  Matrix *mat = new Matrix;

  const int width = 6;
  const int height = 4;
  const int value = 77;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; 
}


TEST(test_print_2x3_matrix) {
  Matrix *mat = new Matrix; 

  Matrix_init(mat, 2, 3);

  delete mat; 

  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, 2, 2);

  *Matrix_at(mat2, 0, 0) = 55;
  *Matrix_at(mat2, 0, 1) = 22;
  *Matrix_at(mat2, 1, 0) = 11;
  *Matrix_at(mat2, 1, 1) = 33;

  ostringstream expected;
  expected << "2 2\n"
           << "55 22 \n"
           << "11 33 \n";
  ostringstream actual;
  Matrix_print(mat2, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat2;
}


TEST(test_width_5x2_matrix) {
  Matrix *mat = new Matrix; 

  const int value = 99;
  Matrix_init(mat, 5, 2);
  Matrix_fill(mat, value);

  ASSERT_EQUAL(Matrix_width(mat), 5);

  delete mat; 
}

TEST(test_height_3x7_matrix) {
  Matrix *mat = new Matrix; 

  const int value = 88;
  Matrix_init(mat, 3, 7);
  Matrix_fill(mat, value);

  ASSERT_EQUAL(Matrix_height(mat), 7);

  delete mat; 
}

TEST(test_fill_border_4x4_matrix) {
  Matrix *mat = new Matrix; 

  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 0);

  Matrix_fill_border( mat,  9);

  ostringstream expected;
  expected << "4 4\n" 
           << "9 9 9 9 \n"
           << "9 0 0 9 \n"
           << "9 0 0 9 \n"
           << "9 9 9 9 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat; 
}


TEST(test_fill_border_1x1_matrix) {
  Matrix *mat = new Matrix; 

  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 0);

  Matrix_fill_border( mat,  9);

  ostringstream expected;
  expected << "1 1\n" 
           << "9 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat; 
}

TEST(test_Matrix_init_2x3_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 2, 3);
   ASSERT_EQUAL(Matrix_width(mat), 2);
   ASSERT_EQUAL(Matrix_height(mat), 3);
   delete mat;
}

TEST(test_Matrix_print_2x2_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 2, 2);
   *(Matrix_at(mat, 0, 0)) = 7;
   *(Matrix_at(mat, 0, 1)) = 8;
   *(Matrix_at(mat, 1, 0)) = 9;
   *(Matrix_at(mat, 1, 1)) = 10;

   std::ostringstream os;
   Matrix_print(mat, os);
   ASSERT_EQUAL(os.str(), "2 2\n7 8 \n9 10 \n");

   delete mat;
}

TEST(test_Matrix_at_get_set_values) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 3, 2);
   Matrix_fill(mat, 5);
   ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 5);
   *Matrix_at(mat, 1, 1) = 11;
   ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 11);
   delete mat;
}

TEST(test_Matrix_row_column_of_element) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 3, 3);
   const int* ptr = Matrix_at(mat, 1, 2);
   ASSERT_EQUAL(Matrix_row(mat, ptr), 1);
   ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
   delete mat;
}

TEST(test_Matrix_fill_3x2_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 3, 2);
   Matrix_fill(mat, 6);
   ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 6);
   ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 6);
   delete mat;
}

TEST(test_Matrix_fill_border_3x3_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 3, 3);
   Matrix_fill(mat, 1);
   Matrix_fill_border(mat, 9);
   ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 9);
   ASSERT_EQUAL(*Matrix_at(mat, 2, 2), 9);
   ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 1);
   delete mat;
}

TEST(test_fill_1x1_matrix) {
  Matrix *mat = new Matrix; 

  const int width = 1;
  const int height = 1;
  const int value = 123;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; 
}

TEST(test_print_1x1_matrix) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);

  *Matrix_at(mat, 0, 0) = 99;
  ostringstream expected;
  expected << "1 1\n"
           << "99 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat;
}

TEST(test_width_2x2_matrix) {
  Matrix *mat = new Matrix; 

  const int value = 42;
  Matrix_init(mat, 2, 2);
  Matrix_fill(mat, value);

  ASSERT_EQUAL(Matrix_width(mat), 2);

  delete mat; 
}

TEST(test_height_4x1_matrix) {
  Matrix *mat = new Matrix; 

  const int value = 33;
  Matrix_init(mat, 4, 1);
  Matrix_fill(mat, value);

  ASSERT_EQUAL(Matrix_height(mat), 1);

  delete mat; 
}

TEST(test_Matrix_init_1x3_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 1, 3);
   ASSERT_EQUAL(Matrix_width(mat), 1);
   ASSERT_EQUAL(Matrix_height(mat), 3);
   delete mat;
}

TEST(test_Matrix_print_3x1_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 1, 3);
   *(Matrix_at(mat, 0, 0)) = 5;
   *(Matrix_at(mat, 1, 0)) = 10;
   *(Matrix_at(mat, 2, 0)) = 15;

   std::ostringstream os;
   Matrix_print(mat, os);
   ASSERT_EQUAL(os.str(), "1 3\n5 \n10 \n15 \n");

   delete mat;
}

// Test Case 19: Test getting and setting values using Matrix_at in a 2x3 Matrix
TEST(test_Matrix_at_get_set_values_2x3_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 2, 3);
   Matrix_fill(mat, 8);
   ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 8);
   *Matrix_at(mat, 1, 1) = 20;
   ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 20);
   delete mat;
}

// Test Case 20: Test getting the row and column of a specific element in a 4x4 Matrix
TEST(test_Matrix_row_column_of_element_4x4_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 4, 4);
   const int* ptr = Matrix_at(mat, 2, 3);
   ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
   ASSERT_EQUAL(Matrix_column(mat, ptr), 3);
   delete mat;
}

TEST(test_Matrix_fill_border_5x5_matrix) {
   Matrix *mat = new Matrix;
   Matrix_init(mat, 5, 5);
   Matrix_fill(mat, 3);
   Matrix_fill_border(mat, 11);
   ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 11);
   ASSERT_EQUAL(*Matrix_at(mat, 4, 4), 11);
   ASSERT_EQUAL(*Matrix_at(mat, 2, 2), 3);
   delete mat;
}


TEST(test_column_of_min_value_3x3_matrix) {
  Matrix *mat = new Matrix;
  const int value = 5;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);

  *(Matrix_at(mat, 1, 1)) = 1;
  int min_col = Matrix_column_of_min_value_in_row(mat, 1, 0, 3);
  ASSERT_EQUAL(min_col, 1);
  *(Matrix_at(mat, 1, 1)) = 5;

  *(Matrix_at(mat, 0, 1)) = 1;
  min_col = Matrix_column_of_min_value_in_row(mat, 0, 0, 3);
  ASSERT_EQUAL(min_col, 1);
  *(Matrix_at(mat, 0, 1)) = 5;

  *(Matrix_at(mat, 0, 2)) = 1;
  min_col = Matrix_column_of_min_value_in_row(mat, 1, 0, 3);
  ASSERT_EQUAL(min_col, 0);
  min_col = Matrix_column_of_min_value_in_row(mat, 0, 0, 3);
  ASSERT_EQUAL(min_col, 2);
  *(Matrix_at(mat, 0, 2)) = 5;

  *(Matrix_at(mat, 2, 2)) = 1;
  min_col = Matrix_column_of_min_value_in_row(mat, 2, 0, 3);
  ASSERT_EQUAL(min_col, 2);

  delete mat; 
}

TEST(test_min_value_4x4_matrix) {
  Matrix *mat = new Matrix; 
  const int value = 8;
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, value);

  *(Matrix_at(mat, 1, 1)) = 2;
  int min = Matrix_min_value_in_row(mat, 1, 0, 4);
  ASSERT_EQUAL(min, 2);
  *(Matrix_at(mat, 1, 1)) = 8;

  *(Matrix_at(mat, 0, 1)) = 1;
  min = Matrix_min_value_in_row(mat, 0, 0, 4);
  ASSERT_EQUAL(min, 1);
  *(Matrix_at(mat, 0, 1)) = 8;

  *(Matrix_at(mat, 0, 2)) = 1;
  min = Matrix_min_value_in_row(mat, 1, 0, 4);
  ASSERT_EQUAL(min, 8);
  min = Matrix_min_value_in_row(mat, 0, 0, 4);
  ASSERT_EQUAL(min, 1);
  *(Matrix_at(mat, 0, 2)) = 8;

  *(Matrix_at(mat, 2, 2)) = 1;
  min = Matrix_min_value_in_row(mat, 2, 0, 4);
  ASSERT_EQUAL(min, 1);

  delete mat; 
}

TEST_MAIN()
