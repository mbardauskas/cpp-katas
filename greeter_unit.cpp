#include <limits.h>
#include <iostream>
#include "gtest/gtest.h"
#include "greeter.h"

const auto RegularTimeGetter = []() {
  return 14;
};

const auto MorningTimeGetter = []() {
  return 6;
};

const auto LateMorningTimeGetter = []() {
  return 6;
};

TEST(GreeterTest, ReturnsHelloName) {
  Greeter greeter = Greeter(RegularTimeGetter);
  EXPECT_EQ("Hello Tom", greeter.greet("Tom")) << "must equal Hello <name>";
}

TEST(GreeterTest, TrimsName) {
  Greeter greeter = Greeter(RegularTimeGetter);
  EXPECT_EQ("Hello Tom", greeter.greet(" Tom ")) << "must trim the name";
}

TEST(GreeterTest, CapitalizesFirstLetterOfTheName) {
  Greeter greeter = Greeter(RegularTimeGetter);
  EXPECT_EQ("Hello Tom", greeter.greet("tom")) << "must capitalize name";
}

TEST(GreeterTest, ReturnsGoodMorningBetween6and12) {
  Greeter greeter = Greeter(MorningTimeGetter);
  Greeter another_greeter = Greeter(LateMorningTimeGetter);

  EXPECT_EQ("Good morning Tom", greeter.greet("tom")) << "must return Good morning <name>";
  EXPECT_EQ("Good morning Tom", another_greeter.greet("tom")) << "must return Good morning <name>";
}

