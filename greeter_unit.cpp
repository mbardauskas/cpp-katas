#include <limits.h>
#include <iostream>
#include "gtest/gtest.h"
#include "greeter.h"

TEST(GreeterTest, ReturnsHelloName) {
  Greeter greeter = Greeter();
  EXPECT_EQ("Hello Tom", greeter.greet("Tom")) << "must equal Hello <name>";
}

TEST(GreeterTest, TrimsName) {
  Greeter greeter = Greeter();
  EXPECT_EQ("Hello Tom", greeter.greet(" Tom ")) << "must trim the name";
}

TEST(GreeterTest, CapitalizesFirstLetterOfTheName) {
  Greeter greeter = Greeter();
  EXPECT_EQ("Hello Tom", greeter.greet("tom")) << "must capitalize name";
}

