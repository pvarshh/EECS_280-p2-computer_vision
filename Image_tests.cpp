#include "Matrix.hpp"
#include "Image_test_helpers.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_input) {
  Image *img = new Image;
  string input_s = "P3\n2 2 \n255\n100 200 249 1 2 3 \n1 2 3 4 5 6\n";

  istringstream input(input_s);

  Image_init(img, input);
  ostringstream s;
  Image_print(img, s);
  
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "100 200 249 1 2 3 \n";
  correct << "1 2 3 4 5 6 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img;
}

TEST(test_image_from_and_to_stream) {
  Image *img = new Image;

  // A very poorly behaved input PPM.
  string input = "P3 2 2\t255 255 0 0\n0\n255 0 \n0 0 255 255 255 255 \n";
  std::istringstream ss_input(input);
  Image_init(img, ss_input);

  // Should be well behaved when you print it though!
  string output_correct = "P3\n2 2\n255\n255 0 0 0 255 0 \n0 0 255 255 255 255 \n";
  std::ostringstream ss_output;
  Image_print(img, ss_output);
  string actual = ss_output.str();
  std::cout << actual << std::endl;
  ASSERT_EQUAL(actual, output_correct);

  delete img;
}

TEST(test_image_basic) {
  Pixel red = {255, 0, 0};
  Pixel green = {0, 255, 0};
  Image *img = new Image;
  
  Image_init(img, 3, 4);
  
  ASSERT_EQUAL(Image_width(img), 3);
  ASSERT_EQUAL(Image_height(img), 4);

  Image_fill(img, red);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 2), red));

  Image_set_pixel(img, 0, 0, green);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), green));

  delete img;
}

TEST(test_minimum) {
  Image *img = new Image;
  
  Image_init(img, 1, 1);

  Pixel amb = {25, 50 ,75};
  Image_set_pixel(img, 0, 0, amb);

  ASSERT_EQUAL(Image_height(img), 1);
  ASSERT_EQUAL(Image_width(img), 1);

  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), amb));
  delete img;
}



TEST(test_image_getpixel) {
  Image *img =new Image;

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);

  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  ASSERT_TRUE(Pixel_equal(red, Image_get_pixel(img, 0,0)));
  ASSERT_TRUE(Pixel_equal(green, Image_get_pixel(img, 0,1)));
  ASSERT_TRUE(Pixel_equal(blue, Image_get_pixel(img, 1,0)));
  ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, 1,1)));

  delete img;
}

TEST(test_image_fill) {
  Image *img = new Image();

  const Pixel green = {0, 255, 0};

  Image_init(img, 15,15);
  Image_fill(img, green);
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      ASSERT_TRUE(Pixel_equal(green, Image_get_pixel(img, i, j)));
      ASSERT_EQUAL(green.b,Image_get_pixel(img,i,j).b);
      ASSERT_EQUAL(green.r,Image_get_pixel(img,i,j).r);
      ASSERT_EQUAL(green.g,Image_get_pixel(img,i,j).g);
    }
  }


  ASSERT_EQUAL(Image_width(img), 15);
  ASSERT_EQUAL(Image_height(img), 15);
  
  
  delete img;
}

TEST(test_max) {
  Image *img = new Image();

  Image_init(img, MAX_MATRIX_WIDTH, MAX_MATRIX_HEIGHT);
  Pixel white = {255, 255 ,255};
  Pixel red = {255, 0, 0};
  Image_fill(img, white);

  ASSERT_EQUAL(Image_width(img), 500);
  ASSERT_EQUAL(Image_height(img), 500);

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, i, j)));
    }
  }

  Image_set_pixel(img, 499, 499, red);
  ASSERT_TRUE(Pixel_equal(red, Image_get_pixel(img, 499, 499)));
  ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, 498, 499)));
  ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, 499, 0)));
  ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, 0, 499)));
  ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, 0, 0)));

  delete img;



}

TEST(test_min) {
  Image *img = new Image();

  Image_init(img, 1, 1);
  Pixel black = {0, 0, 0};
  Pixel white = {255, 255, 255};
  Image_fill(img, white);
  ASSERT_EQUAL(Image_width(img), 1);
  ASSERT_EQUAL(Image_height(img), 1);
  ASSERT_TRUE(Pixel_equal(white, Image_get_pixel(img, 0, 0)));
  Image_set_pixel(img, 0, 0, black);
  ASSERT_TRUE(Pixel_equal(black, Image_get_pixel(img, 0, 0)));

  delete img;
}


TEST(test_image_init_zero) {
  Image *img = new Image;
  Image_init(img, 1, 1);
  ASSERT_EQUAL(Image_width(img), 1);
  ASSERT_EQUAL(Image_height(img), 1);
  delete img;
}



TEST(test_image_equality) {
  Image *img1 = new Image;
  Image *img2 = new Image;
  Image_init(img1, 2, 2);
  Image_init(img2, 2, 2);

  const Pixel red = {255, 0, 0};
  Image_fill(img1, red);
  Image_fill(img2, red);

  ASSERT_TRUE(Image_equal(img1, img2));

  delete img1;
  delete img2;
}

TEST(test_image_inequality) {
  Image *img1 = new Image;
  Image *img2 = new Image;
  Image_init(img1, 2, 2);
  Image_init(img2, 2, 2);

  const Pixel red = {255, 0, 0};
  const Pixel blue = {0, 0, 255};
  Image_fill(img1, red);
  Image_fill(img2, blue);

  ASSERT_FALSE(Image_equal(img1, img2));

  delete img1;
  delete img2;
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.hpp as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here