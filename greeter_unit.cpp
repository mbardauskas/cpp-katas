#include <limits.h>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "greeter.h"

int RegularTimeGetter() {
  return 14;
};

int MorningTimeGetter() {
  return 6;
};

int LateMorningTimeGetter() {
  return 6;
};

int EveningTimeGetter() {
  return 18;
};

int LateEveningTimeGetter() {
  return 21;
};

int NightTimeGetter() {
  return 22;
};

int LateNightTimeGetter() {
  return 5;
};

void MockLogger(std::string text) {
  std::cout << "cout" << text;
};

TEST(GreeterTest, ReturnsHelloName) {
  Greeter greeter = Greeter(RegularTimeGetter, MockLogger);
  EXPECT_EQ("Hello Tom", greeter.greet("Tom")) << "must equal Hello <name>";
}

TEST(GreeterTest, TrimsName) {
  Greeter greeter = Greeter(RegularTimeGetter, MockLogger);
  EXPECT_EQ("Hello Tom", greeter.greet(" Tom ")) << "must trim the name";
}

TEST(GreeterTest, CapitalizesFirstLetterOfTheName) {
  Greeter greeter = Greeter(RegularTimeGetter, MockLogger);
  EXPECT_EQ("Hello Tom", greeter.greet("tom")) << "must capitalize name";
}

TEST(GreeterTest, SupportsOneLetterNames) {
  Greeter greeter = Greeter(RegularTimeGetter, MockLogger);
  EXPECT_EQ("Hello T", greeter.greet("t")) << "must capitalize name";
}

TEST(GreeterTest, ReturnsGoodMorningBetween6and12) {
  Greeter greeter = Greeter(MorningTimeGetter, MockLogger);
  Greeter another_greeter = Greeter(LateMorningTimeGetter, MockLogger);

  EXPECT_EQ("Good morning Tom", greeter.greet("tom")) << "must return Good morning <name>";
  EXPECT_EQ("Good morning Tom", another_greeter.greet("tom")) << "must return Good morning <name>";
}

TEST(GreeterTest, ReturnsGoodEveningBetween18and22) {
  Greeter greeter = Greeter(EveningTimeGetter, MockLogger);
  Greeter another_greeter = Greeter(LateEveningTimeGetter, MockLogger);

  EXPECT_EQ("Good evening Tom", greeter.greet("tom")) << "must return Good evening <name>";
  EXPECT_EQ("Good evening Tom", another_greeter.greet("tom")) << "must return Good evening <name>";
}

TEST(GreeterTest, ReturnsGoodNightBetween18and22) {
  Greeter greeter = Greeter(NightTimeGetter, MockLogger);
  Greeter another_greeter = Greeter(LateNightTimeGetter, MockLogger);

  EXPECT_EQ("Good night Tom", greeter.greet("tom")) << "must return Good night <name>";
  EXPECT_EQ("Good night Tom", another_greeter.greet("tom")) << "must return Good night <name>";
}

//TEST(GreeterTest, LogsToConsole) {
//  Greeter greeter = Greeter(NightTimeGetter, MockLogger);
//
//  ON_CALL(greeter, greet("tom")).WillByDefault(testing::Invoke(MockLogger));
//}

