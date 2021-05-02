//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::_;

cpr::Response NormalWeatherResponse(const std::string& city,
                                    const cpr::Url& url) {
  cpr::Response response;
  response.status_code = 200;
  response.text =
      R"({"coord":{"lon":37.5606,"lat":55.9041},"weather":[{"id":800,"main":"Clear","description":"clear sky","icon":"01d"}],"base":"stations","main":{"temp":283.15,"feels_like":281.66,"temp_min":283.15,"temp_max":283.15,"pressure":1014,"humidity":40},"visibility":10000,"wind":{"speed":3,"deg":320},"clouds":{"all":0},"dt":1619888424,"sys":{"type":1,"id":9027,"country":"RU","sunrise":1619833560,"sunset":1619888851},"timezone":10800,"id":565614,"name":"Dolgoprudnyy","cod":200})";
  return response;
}

cpr::Response NormalForecastResponse(const std::string& city,
                                     const cpr::Url& url) {
  cpr::Response response;
  response.status_code = 200;
  response.text =
      R"({"cod":"200","message":0,"cnt":40,"list":[{"dt":1619892000,"main":{"temp":283.15,"feels_like":282.49,"temp_min":280.22,"temp_max":283.15,"pressure":1014,"sea_level":1014,"grnd_level":994,"humidity":40,"temp_kf":2.93},"weather":[{"id":800,"main":"Clear","description":"clear sky","icon":"01n"}],"clouds":{"all":0},"wind":{"speed":1.82,"deg":261,"gust":2.13},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-01 18:00:00"},{"dt":1619902800,"main":{"temp":281.81,"feels_like":280.77,"temp_min":279.13,"temp_max":281.81,"pressure":1015,"sea_level":1015,"grnd_level":995,"humidity":46,"temp_kf":2.68},"weather":[{"id":802,"main":"Clouds","description":"scattered clouds","icon":"03n"}],"clouds":{"all":26},"wind":{"speed":2.01,"deg":245,"gust":2.76},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-01 21:00:00"},{"dt":1619913600,"main":{"temp":279.71,"feels_like":278.56,"temp_min":277.99,"temp_max":279.71,"pressure":1016,"sea_level":1016,"grnd_level":995,"humidity":58,"temp_kf":1.72},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04n"}],"clouds":{"all":54},"wind":{"speed":1.78,"deg":223,"gust":2.89},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-02 00:00:00"},{"dt":1619924400,"main":{"temp":277.69,"feels_like":276.74,"temp_min":277.69,"temp_max":277.69,"pressure":1017,"sea_level":1017,"grnd_level":995,"humidity":71,"temp_kf":0},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04d"}],"clouds":{"all":53},"wind":{"speed":1.38,"deg":227,"gust":2.07},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-02 03:00:00"},{"dt":1619935200,"main":{"temp":282.18,"feels_like":281.82,"temp_min":282.18,"temp_max":282.18,"pressure":1018,"sea_level":1018,"grnd_level":996,"humidity":52,"temp_kf":0},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04d"}],"clouds":{"all":76},"wind":{"speed":1.39,"deg":222,"gust":1.92},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-02 06:00:00"},{"dt":1619946000,"main":{"temp":284.44,"feels_like":282.72,"temp_min":284.44,"temp_max":284.44,"pressure":1017,"sea_level":1017,"grnd_level":995,"humidity":42,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":100},"wind":{"speed":1.66,"deg":180,"gust":2.33},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-02 09:00:00"},{"dt":1619956800,"main":{"temp":286.3,"feels_like":284.72,"temp_min":286.3,"temp_max":286.3,"pressure":1016,"sea_level":1016,"grnd_level":994,"humidity":40,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":100},"wind":{"speed":1.89,"deg":169,"gust":2.75},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-02 12:00:00"},{"dt":1619967600,"main":{"temp":284.77,"feels_like":283.5,"temp_min":284.77,"temp_max":284.77,"pressure":1015,"sea_level":1015,"grnd_level":994,"humidity":58,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":100},"wind":{"speed":2.89,"deg":146,"gust":3.69},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-02 15:00:00"},{"dt":1619978400,"main":{"temp":281.62,"feels_like":279.59,"temp_min":281.62,"temp_max":281.62,"pressure":1015,"sea_level":1015,"grnd_level":993,"humidity":82,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04n"}],"clouds":{"all":100},"wind":{"speed":3.39,"deg":131,"gust":6.51},"visibility":10000,"pop":0.07,"sys":{"pod":"n"},"dt_txt":"2021-05-02 18:00:00"},{"dt":1619989200,"main":{"temp":280.62,"feels_like":277.98,"temp_min":280.62,"temp_max":280.62,"pressure":1013,"sea_level":1013,"grnd_level":991,"humidity":88,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04n"}],"clouds":{"all":100},"wind":{"speed":4.12,"deg":109,"gust":9.73},"visibility":10000,"pop":0.14,"sys":{"pod":"n"},"dt_txt":"2021-05-02 21:00:00"},{"dt":1620000000,"main":{"temp":280.38,"feels_like":276.77,"temp_min":280.38,"temp_max":280.38,"pressure":1008,"sea_level":1008,"grnd_level":987,"humidity":94,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10n"}],"clouds":{"all":100},"wind":{"speed":6.28,"deg":91,"gust":14.14},"visibility":10000,"pop":0.48,"rain":{"3h":0.84},"sys":{"pod":"n"},"dt_txt":"2021-05-03 00:00:00"},{"dt":1620010800,"main":{"temp":280.46,"feels_like":276.64,"temp_min":280.46,"temp_max":280.46,"pressure":1004,"sea_level":1004,"grnd_level":983,"humidity":96,"temp_kf":0},"weather":[{"id":501,"main":"Rain","description":"moderate rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":6.98,"deg":115,"gust":13.6},"visibility":4953,"pop":1,"rain":{"3h":8.67},"sys":{"pod":"d"},"dt_txt":"2021-05-03 03:00:00"},{"dt":1620021600,"main":{"temp":282.25,"feels_like":279.4,"temp_min":282.25,"temp_max":282.25,"pressure":1000,"sea_level":1000,"grnd_level":979,"humidity":98,"temp_kf":0},"weather":[{"id":501,"main":"Rain","description":"moderate rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":5.58,"deg":128,"gust":14.48},"visibility":327,"pop":1,"rain":{"3h":5.91},"sys":{"pod":"d"},"dt_txt":"2021-05-03 06:00:00"},{"dt":1620032400,"main":{"temp":285.52,"feels_like":285.24,"temp_min":285.52,"temp_max":285.52,"pressure":998,"sea_level":998,"grnd_level":977,"humidity":93,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":5.65,"deg":175,"gust":12.59},"visibility":10000,"pop":0.7,"rain":{"3h":1.09},"sys":{"pod":"d"},"dt_txt":"2021-05-03 09:00:00"},{"dt":1620043200,"main":{"temp":287.36,"feels_like":287.06,"temp_min":287.36,"temp_max":287.36,"pressure":996,"sea_level":996,"grnd_level":975,"humidity":85,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":6.39,"deg":194,"gust":12.29},"visibility":10000,"pop":1,"rain":{"3h":0.34},"sys":{"pod":"d"},"dt_txt":"2021-05-03 12:00:00"},{"dt":1620054000,"main":{"temp":284.82,"feels_like":283.9,"temp_min":284.82,"temp_max":284.82,"pressure":996,"sea_level":996,"grnd_level":975,"humidity":71,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":42},"wind":{"speed":6.67,"deg":219,"gust":11.63},"visibility":10000,"pop":0.63,"rain":{"3h":0.31},"sys":{"pod":"d"},"dt_txt":"2021-05-03 15:00:00"},{"dt":1620064800,"main":{"temp":279.96,"feels_like":276.05,"temp_min":279.96,"temp_max":279.96,"pressure":998,"sea_level":998,"grnd_level":976,"humidity":72,"temp_kf":0},"weather":[{"id":802,"main":"Clouds","description":"scattered clouds","icon":"03n"}],"clouds":{"all":28},"wind":{"speed":6.82,"deg":226,"gust":11.66},"visibility":10000,"pop":0.25,"sys":{"pod":"n"},"dt_txt":"2021-05-03 18:00:00"},{"dt":1620075600,"main":{"temp":278.71,"feels_like":274.25,"temp_min":278.71,"temp_max":278.71,"pressure":998,"sea_level":998,"grnd_level":976,"humidity":67,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04n"}],"clouds":{"all":100},"wind":{"speed":7.39,"deg":217,"gust":12.82},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-03 21:00:00"},{"dt":1620086400,"main":{"temp":277.78,"feels_like":272.98,"temp_min":277.78,"temp_max":277.78,"pressure":997,"sea_level":997,"grnd_level":976,"humidity":72,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04n"}],"clouds":{"all":100},"wind":{"speed":7.59,"deg":213,"gust":14.42},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-04 00:00:00"},{"dt":1620097200,"main":{"temp":276.66,"feels_like":271.43,"temp_min":276.66,"temp_max":276.66,"pressure":997,"sea_level":997,"grnd_level":975,"humidity":82,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13d"}],"clouds":{"all":100},"wind":{"speed":7.86,"deg":215,"gust":14.94},"visibility":7288,"pop":0.21,"snow":{"3h":0.12},"sys":{"pod":"d"},"dt_txt":"2021-05-04 03:00:00"},{"dt":1620108000,"main":{"temp":276.17,"feels_like":270.83,"temp_min":276.17,"temp_max":276.17,"pressure":997,"sea_level":997,"grnd_level":976,"humidity":89,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":7.76,"deg":233,"gust":13.45},"visibility":1206,"pop":0.71,"rain":{"3h":0.85},"sys":{"pod":"d"},"dt_txt":"2021-05-04 06:00:00"},{"dt":1620118800,"main":{"temp":278.63,"feels_like":273.79,"temp_min":278.63,"temp_max":278.63,"pressure":998,"sea_level":998,"grnd_level":977,"humidity":72,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":8.5,"deg":241,"gust":13.87},"visibility":2642,"pop":1,"rain":{"3h":0.55},"sys":{"pod":"d"},"dt_txt":"2021-05-04 09:00:00"},{"dt":1620129600,"main":{"temp":280.03,"feels_like":275.59,"temp_min":280.03,"temp_max":280.03,"pressure":1000,"sea_level":1000,"grnd_level":978,"humidity":67,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":8.62,"deg":257,"gust":14.63},"visibility":10000,"pop":1,"rain":{"3h":0.72},"sys":{"pod":"d"},"dt_txt":"2021-05-04 12:00:00"},{"dt":1620140400,"main":{"temp":279.33,"feels_like":275.03,"temp_min":279.33,"temp_max":279.33,"pressure":1002,"sea_level":1002,"grnd_level":980,"humidity":69,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":98},"wind":{"speed":7.44,"deg":261,"gust":15.14},"visibility":10000,"pop":0.84,"rain":{"3h":0.38},"sys":{"pod":"d"},"dt_txt":"2021-05-04 15:00:00"},{"dt":1620151200,"main":{"temp":277.6,"feels_like":273.09,"temp_min":277.6,"temp_max":277.6,"pressure":1004,"sea_level":1004,"grnd_level":982,"humidity":76,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10n"}],"clouds":{"all":97},"wind":{"speed":6.63,"deg":256,"gust":12.52},"visibility":10000,"pop":0.44,"rain":{"3h":0.22},"sys":{"pod":"n"},"dt_txt":"2021-05-04 18:00:00"},{"dt":1620162000,"main":{"temp":276.39,"feels_like":271.56,"temp_min":276.39,"temp_max":276.39,"pressure":1005,"sea_level":1005,"grnd_level":984,"humidity":80,"temp_kf":0},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04n"}],"clouds":{"all":74},"wind":{"speed":6.59,"deg":265,"gust":12.04},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-04 21:00:00"},{"dt":1620172800,"main":{"temp":275.52,"feels_like":271.01,"temp_min":275.52,"temp_max":275.52,"pressure":1008,"sea_level":1008,"grnd_level":985,"humidity":84,"temp_kf":0},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04n"}],"clouds":{"all":65},"wind":{"speed":5.37,"deg":264,"gust":12.85},"visibility":10000,"pop":0,"sys":{"pod":"n"},"dt_txt":"2021-05-05 00:00:00"},{"dt":1620183600,"main":{"temp":275.3,"feels_like":271.79,"temp_min":275.3,"temp_max":275.3,"pressure":1008,"sea_level":1008,"grnd_level":986,"humidity":91,"temp_kf":0},"weather":[{"id":801,"main":"Clouds","description":"few clouds","icon":"02d"}],"clouds":{"all":17},"wind":{"speed":3.58,"deg":247,"gust":10.28},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-05 03:00:00"},{"dt":1620194400,"main":{"temp":280.11,"feels_like":277.13,"temp_min":280.11,"temp_max":280.11,"pressure":1009,"sea_level":1009,"grnd_level":987,"humidity":70,"temp_kf":0},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04d"}],"clouds":{"all":53},"wind":{"speed":4.58,"deg":246,"gust":9.05},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-05 06:00:00"},{"dt":1620205200,"main":{"temp":285.88,"feels_like":284.51,"temp_min":285.88,"temp_max":285.88,"pressure":1007,"sea_level":1007,"grnd_level":986,"humidity":50,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":94},"wind":{"speed":6.02,"deg":217,"gust":9.97},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-05 09:00:00"},{"dt":1620216000,"main":{"temp":288.5,"feels_like":287.37,"temp_min":288.5,"temp_max":288.5,"pressure":1006,"sea_level":1006,"grnd_level":985,"humidity":49,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":95},"wind":{"speed":7.14,"deg":218,"gust":12.04},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-05 12:00:00"},{"dt":1620226800,"main":{"temp":287.29,"feels_like":286.3,"temp_min":287.29,"temp_max":287.29,"pressure":1005,"sea_level":1005,"grnd_level":984,"humidity":59,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":98},"wind":{"speed":7.8,"deg":218,"gust":13.46},"visibility":10000,"pop":0.68,"rain":{"3h":0.29},"sys":{"pod":"d"},"dt_txt":"2021-05-05 15:00:00"},{"dt":1620237600,"main":{"temp":283.95,"feels_like":283.38,"temp_min":283.95,"temp_max":283.95,"pressure":1007,"sea_level":1007,"grnd_level":985,"humidity":88,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10n"}],"clouds":{"all":99},"wind":{"speed":5.23,"deg":221,"gust":11.56},"visibility":10000,"pop":0.96,"rain":{"3h":1.39},"sys":{"pod":"n"},"dt_txt":"2021-05-05 18:00:00"},{"dt":1620248400,"main":{"temp":282.09,"feels_like":280.56,"temp_min":282.09,"temp_max":282.09,"pressure":1008,"sea_level":1008,"grnd_level":987,"humidity":94,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10n"}],"clouds":{"all":74},"wind":{"speed":2.73,"deg":235,"gust":6.49},"visibility":10000,"pop":0.66,"rain":{"3h":0.53},"sys":{"pod":"n"},"dt_txt":"2021-05-05 21:00:00"},{"dt":1620259200,"main":{"temp":280.58,"feels_like":279.28,"temp_min":280.58,"temp_max":280.58,"pressure":1009,"sea_level":1009,"grnd_level":987,"humidity":96,"temp_kf":0},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04n"}],"clouds":{"all":84},"wind":{"speed":2.08,"deg":193,"gust":3.2},"visibility":10000,"pop":0.48,"sys":{"pod":"n"},"dt_txt":"2021-05-06 00:00:00"},{"dt":1620270000,"main":{"temp":281.72,"feels_like":279.56,"temp_min":281.72,"temp_max":281.72,"pressure":1007,"sea_level":1007,"grnd_level":985,"humidity":97,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":89},"wind":{"speed":3.68,"deg":146,"gust":9.52},"visibility":10000,"pop":0.31,"rain":{"3h":0.14},"sys":{"pod":"d"},"dt_txt":"2021-05-06 03:00:00"},{"dt":1620280800,"main":{"temp":285.24,"feels_like":284.44,"temp_min":285.24,"temp_max":285.24,"pressure":1005,"sea_level":1005,"grnd_level":984,"humidity":74,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":94},"wind":{"speed":6.96,"deg":178,"gust":15.18},"visibility":10000,"pop":0.34,"sys":{"pod":"d"},"dt_txt":"2021-05-06 06:00:00"},{"dt":1620291600,"main":{"temp":288.64,"feels_like":287.76,"temp_min":288.64,"temp_max":288.64,"pressure":1002,"sea_level":1002,"grnd_level":981,"humidity":58,"temp_kf":0},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"clouds":{"all":100},"wind":{"speed":9.23,"deg":177,"gust":16.23},"visibility":10000,"pop":0,"sys":{"pod":"d"},"dt_txt":"2021-05-06 09:00:00"},{"dt":1620302400,"main":{"temp":284.41,"feels_like":283.81,"temp_min":284.41,"temp_max":284.41,"pressure":1001,"sea_level":1001,"grnd_level":980,"humidity":85,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":9.71,"deg":197,"gust":16.96},"visibility":6863,"pop":1,"rain":{"3h":2.27},"sys":{"pod":"d"},"dt_txt":"2021-05-06 12:00:00"},{"dt":1620313200,"main":{"temp":281.72,"feels_like":278.58,"temp_min":281.72,"temp_max":281.72,"pressure":1004,"sea_level":1004,"grnd_level":982,"humidity":82,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain","icon":"10d"}],"clouds":{"all":100},"wind":{"speed":5.98,"deg":233,"gust":10.75},"visibility":10000,"pop":1,"rain":{"3h":1.39},"sys":{"pod":"d"},"dt_txt":"2021-05-06 15:00:00"}],"city":{"id":565614,"name":"Dolgoprudnyy","coord":{"lat":55.9041,"lon":37.5606},"country":"RU","population":68259,"timezone":10800,"sunrise":1619833560,"sunset":1619888851}})";
  return response;
}

cpr::Response ResponseForDiff(const std::string& city,
                                       const cpr::Url& url) {
  cpr::Response response;
  response.status_code = 200;

  if (city == "city1") {
    response.text =
        R"({"main": {"temp": 10.0}, "list": [0, 1, 2, 3, 4, 5, 6, {"main": {"temp": 15.0}}]})";
  } else if (city == "city2") {
    response.text =
        R"({"main": {"temp": 20.0}, "list": [0, 1, 2, 3, 4, 5, 6, {"main": {"temp": 21.0}}]})";
  } else if (city == "city3") {
    response.text =
        R"({"main": {"temp": 30.0}, "list": [0, 1, 2, 3, 4, 5, 6, {"main": {"temp": 25.0}}]})";
  } else if (city == "city4") {
    response.text =
        R"({"main": {"temp": 40.0}, "list": [0, 1, 2, 3, 4, 5, 6, {"main": {"temp": 39.0}}]})";
  } else if (city == "city5") {
    response.text =
        R"({"main": {"temp": 50.0}, "list": [0, 1, 2, 3, 4, 5, 6, {"main": {"temp": 50.0}}]})";
  }

  return response;
}

cpr::Response ErrorResponse(const std::string& city,
                            const cpr::Url& url) {
  cpr::Response response;
  response.status_code = 404;
  return response;
}

TEST_F(WeatherTestCase, GetWithWrongApi) {
  Weather weather;
  EXPECT_THROW(weather.GetTemperature("city"),
               std::invalid_argument);
}

TEST_F(WeatherTestCase, WorkingResponse) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      NormalWeatherResponse));
  auto result = weather.GetResponseForCity("city", "url");
  EXPECT_DOUBLE_EQ(result["main"]["temp"], 283.15);
}

TEST_F(WeatherTestCase, BadResponse) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(ErrorResponse));
  EXPECT_THROW(weather.GetResponseForCity("city", "url"),
               std::invalid_argument);
}

TEST_F(WeatherTestCase, CurrentTemperature) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      NormalWeatherResponse));
  EXPECT_FLOAT_EQ(weather.GetTemperature("city"), 283.15);
}

TEST_F(WeatherTestCase, TomorrowTemperature) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      NormalForecastResponse));
  EXPECT_FLOAT_EQ(weather.GetTomorrowTemperature("city"), 284.77);
}

TEST_F(WeatherTestCase, Diff) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      NormalWeatherResponse));
  EXPECT_FLOAT_EQ(weather.FindDiffBetweenTwoCities("city1", "city2"), 0.0);
}

TEST_F(WeatherTestCase, SetupKey) {
  Weather weather;
  EXPECT_NO_THROW(weather.SetApiKey("api_key"));
}

TEST_F(WeatherTestCase, GetDifferenceStringWarmer) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));
  EXPECT_EQ(weather.GetDifferenceString("city2", "city1"),
            "Weather in city2 is warmer than in city1 by 10 degrees");
}

TEST_F(WeatherTestCase, GetDifferenceStringColder) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));
  EXPECT_EQ(weather.GetDifferenceString("city1", "city2"),
            "Weather in city1 is colder than in city2 by 10 degrees");
}

TEST_F(WeatherTestCase, GetTomorrowDiffMuchWarmer) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));

  EXPECT_EQ(weather.GetTomorrowDiff("city1"), "The weather in city1 tomorrow will be much warmer than today.");
}

TEST_F(WeatherTestCase, GetTomorrowDiffWarmer) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));

  EXPECT_EQ(weather.GetTomorrowDiff("city2"), "The weather in city2 tomorrow will be warmer than today.");
}

TEST_F(WeatherTestCase, GetTomorrowDiffMuchColder) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));

  EXPECT_EQ(weather.GetTomorrowDiff("city3"), "The weather in city3 tomorrow will be much colder than today.");
}

TEST_F(WeatherTestCase, GetTomorrowDiffColder) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));

  EXPECT_EQ(weather.GetTomorrowDiff("city4"), "The weather in city4 tomorrow will be colder than today.");
}

TEST_F(WeatherTestCase, GetTomorrowDiffSame) {
  WeatherMock weather;
  ON_CALL(weather, Get(_, _)).WillByDefault(testing::Invoke(
      ResponseForDiff));

  EXPECT_EQ(weather.GetTomorrowDiff("city5"), "The weather in city5 tomorrow will be the same than today.");
}





