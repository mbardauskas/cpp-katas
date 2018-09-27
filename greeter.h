#include <string>
#include <iostream>

using TimeGetter = std::function<int()>;

class Greeter {
  public:
    Greeter(const TimeGetter& timeGetter) : timeGetter(timeGetter) {}
    std::string greet(std::string name);

  private:
    TimeGetter timeGetter;
    std::string capitalize(std::string name);
    std::string getGreeting(int timeRepresentationHours);
};

