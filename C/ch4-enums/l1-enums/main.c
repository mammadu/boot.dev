#define MUNIT_ENABLE_ASSERT_ALIASES

#include "munit.h"
#include "color.h"

MunitResult test_color_enum1(const MunitParameter params[], void* user_data_or_fixture){
    assert_int(RED, ==, 0);
    assert_int(GREEN, ==, 1);
    assert_int(BLUE, ==, 2);
}

MunitResult test_color_enum2(const MunitParameter params[], void* user_data_or_fixture){
    assert_int(RED, !=, 4);
    assert_int(GREEN, !=, 2);
    assert_int(BLUE, !=, 0);
}
// munit_case(RUN, test_color_enum1, {
//   assert_int(RED, ==, 0, "RED is defined as 0");
//   assert_int(GREEN, ==, 1, "GREEN is defined as 1");
//   assert_int(BLUE, ==, 2, "BLUE is defined as 2");
// });

// munit_case(SUBMIT, test_color_enum2, {
//   assert_int(RED, !=, 4, "RED is not defined as 4");
//   assert_int(GREEN, !=, 2, "GREEN is not defined as 2");
//   assert_int(BLUE, !=, 0, "BLUE is not defined as 0");
// });

int main() {
  MunitTest tests[] = {
      {
        "/are_defined",
        test_color_enum1
      },
      {
        "/are_defined_correctly",
        test_color_enum2
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  };

  MunitSuite suite = {
    "colors",
    tests
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
