#include <iostream>
#include <boost/algorithm/string.hpp>
#include "./greeter.h"

using std::string;

const auto TimeGetterImpl = []() {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [2];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,2,"%H",timeinfo);
  puts(buffer);
  return std::stoi(buffer);
};

string Greeter::greet(string name) {
  string processedName = capitalizeFirstLetter(boost::trim_copy(name));
  return getGreeting(timeGetter()) + " " + processedName;
}

string Greeter::capitalizeFirstLetter(string const& name) const {
  string firstLetter = name.substr(0, 1);
  string remainingLetters = name.substr(1, name.size()-1);

  return boost::to_upper_copy<string>(firstLetter) + remainingLetters;
}

string Greeter::getGreeting(int const& timeRepresentationHours) const {
  if (timeRepresentationHours >= 6 && timeRepresentationHours < 12) {
    return "Good morning";
  }
  if (timeRepresentationHours >= 18 && timeRepresentationHours < 22) {
    return "Good evening";
  }
  if (timeRepresentationHours >= 22 || timeRepresentationHours < 6) {
    return "Good night";
  }
  return "Hello";
}

