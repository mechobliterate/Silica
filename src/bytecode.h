#pragma once

#include <cstdint>
#include <vector>

#include "runtime/value.h"

using Instruction = uint32_t;

enum class Opcode : uint8_t {
  NO_OP = 0x00,

  NIL = 0x11,
  TRUE = 0x12,
  FALSE = 0x13,
  CONST = 0x14,
  CLOSURE = 0x15,

  ADD = 0x31,
  SUB = 0x32,
  MUL = 0x33,
  DIV = 0x34,
  MOD = 0x35,
  NEG = 0x36,
  EQ = 0x37,
  NEQ = 0x38,
  LT = 0x39,
  LTE = 0x3a,
  GT = 0x3b,
  GTE = 0x3c,
  AND = 0x3d,
  OR = 0x3e,
  NOT = 0x3f,

  BIT_AND = 0x40,
  BIT_OR = 0x41,
  BIT_XOR = 0x42,
  BIT_NOT = 0x43,
  SHIFT_LEFT = 0x44,
  SHIFT_RIGHT = 0x45,

  LOAD = 0x50,
  STORE = 0x51,
  DUP = 0x52,
  POP = 0x53,

  TEST = 0x60,
  JUMP = 0x61,
  CALL = 0x62,
  RETURN = 0x63,
  HALT = 0x64,

  GLOBAL_LOAD = 0x70,
  GLOBAL_STORE = 0x71,

  UPVALUE_LOAD = 0x80,
  UPVALUE_STORE = 0x81,
  UPVALUE_CLOSE = 0x82,

  MEMBER_GET = 0x90,
  MEMBER_SET = 0x91,
};

struct Chunk {
  std::vector<Instruction> instructions;
  std::vector<Value> constants;
};