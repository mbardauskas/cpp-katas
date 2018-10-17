#include <string>
#include <iostream>

typedef std::function<int()> TimeGetter;
typedef std::function<void(std::string)> Logger;

class Greeter {
  public:
    Greeter(TimeGetter const& timeGetter, Logger const& logger) : timeGetter(timeGetter), logger(logger) {}
    std::string greet(std::string name);

  private:
    TimeGetter timeGetter;
    Logger logger;
    std::string capitalizeFirstLetter(std::string const& name) const;
    std::string getGreeting(int const& timeRepresentationHours) const;
};

