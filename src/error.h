#pragma once

#include <stdexcept>

namespace Silica {

class Error : public std::runtime_error {
 public:
  Error(const std::string& message) : std::runtime_error(message) {}
};

}