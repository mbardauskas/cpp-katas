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

const auto EveningTimeGetter = []() {
  return 18;
};

const auto LateEveningTimeGetter = []() {
  return 21;
};

const auto NightTimeGetter = []() {
  return 22;
};

const auto LateNightTimeGetter = []() {
  return 5;
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

TEST(GreeterTest, ReturnsGoodEveningBetween18and22) {
  Greeter greeter = Greeter(EveningTimeGetter);
  Greeter another_greeter = Greeter(LateEveningTimeGetter);

  EXPECT_EQ("Good evening Tom", greeter.greet("tom")) << "must return Good evening <name>";
  EXPECT_EQ("Good evening Tom", another_greeter.greet("tom")) << "must return Good evening <name>";
}

TEST(GreeterTest, ReturnsGoodNightBetween18and22) {
  Greeter greeter = Greeter(NightTimeGetter);
  Greeter another_greeter = Greeter(LateNightTimeGetter);

  EXPECT_EQ("Good night Tom", greeter.greet("tom")) << "must return Good night <name>";
  EXPECT_EQ("Good night Tom", another_greeter.greet("tom")) << "must return Good night <name>";
}

