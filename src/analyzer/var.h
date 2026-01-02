#ifndef VAR_H
#define VAR_H
#include <optional>

#include "../core/string_interner.h"
#include "type.h"

using VariableName = SymbolId;

struct Var {
  SymbolId name;
  std::optional<std::shared_ptr<Type>> type;

  explicit Var(SymbolId name)
    : name(name), type(std::nullopt) {}

  Var(SymbolId name, std::optional<std::shared_ptr<Type>> type)
    : name(name), type(std::move(type)) {}

  bool operator==(const Var& other) const {
    if (name != other.name) return false;

    if (!type.has_value() && !other.type.has_value()) return true;

    if (type.has_value() != other.type.has_value()) return false;

    return *type.value() == *other.type.value();
  }

  bool operator!=(const Var &other) const = default;
};

#endif