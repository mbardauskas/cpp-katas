#include <iostream>
#include <boost/algorithm/string.hpp>
#include "./greeter.h"

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

std::string Greeter::greet(std::string name) {
  boost::trim(name);
  return this->getGreeting(timeGetter()) + " " + this->capitalize(name);
}

std::string Greeter::capitalize(std::string name) {
  name[0] = toupper(name[0]);
  return name;
}

std::string Greeter::getGreeting(int timeRepresentationHours) {
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

