#include <Weather.h>
#include <iostream>
int main() {
  Weather weather;
  weather.SetApiKey("78ad61f2b45cbda69c5abb148aba01b5");

  std::cout << weather.GetTemperature("London") << std::endl;
  std::cout << weather.GetTomorrowTemperature("London") << std::endl;
  std::cout << weather.GetTomorrowDiff("Moscow") << std::endl;
}