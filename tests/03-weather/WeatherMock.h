//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
 public:
  MOCK_METHOD(cpr::Response, Get, (const std::string&, const cpr::Url&), (override));
};