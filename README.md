# Silica

A Swift-like interpreter written in C++ featuring Hindley-Milner type inference, bytecode compilation, and a stack-based virtual machine.

## Overview

Silica is a statically-typed programming language with Swift-inspired syntax. It implements a complete compilation pipeline from source code to bytecode execution, with automatic type inference ensuring type safety without explicit type annotations.

## Features

- **Hindley-Milner Type Inference** - Automatic type deduction without explicit annotations
- **Bytecode Virtual Machine** - Efficient stack-based execution engine
- **Object-Oriented Programming** - Classes with methods and instance variables
- **First-Class Functions** - Functions as values with closure support
- **NaN-Boxing** - Efficient value representation using tagged NaN values
- **Reference Counting** - Automatic memory management for objects
- **Interactive REPL** - Read-eval-print loop for experimentation

## Language Features

### Type System

Silica supports the following types:
- Primitive types: `Int`, `Double`, `Bool`, `Void`
- Function types: `(T1, T2, ...) -> R`
- Class types with methods and properties
- Automatic type inference for variables and functions

### Syntax Examples

**Functions:**
```swift
func fib(n: Int) -> Int {
    if n <= 1 {
        return n
    }
    return fib(n - 1) + fib(n - 2)
}

fib(10)
```

**Classes:**
```swift
class Foo {
    var integer = 0
    var double = 1.0
    var boolean = false

    func getInteger() -> Int {
        return self.integer
    }

    func getDouble() -> Double {
        return self.double
    }
}

var f = Foo()
var x = f.getDouble()
```

**Type Inference:**
```swift
var x = 42          // Inferred as Int
var y = 3.14        // Inferred as Double
var z = x + y       // Type error: cannot add Int and Double
```

## Architecture

The interpreter follows a multi-stage compilation pipeline:

```
Source Code → [Lexer] → Tokens → [Parser] → AST → [Analyzer] → Typed AST → [Compiler] → Bytecode → [VM] → Execution
```

### Components

- **Lexer** - Tokenizes source code into lexical tokens
- **Parser** - Builds an Abstract Syntax Tree (AST) from tokens
- **Analyzer** - Performs type inference and semantic analysis
- **Compiler** - Generates bytecode from the typed AST
- **VM** - Executes bytecode on a stack-based virtual machine
- **Runtime** - Manages values and objects with reference counting

For detailed architecture information, see [ARCHITECTURE.md](ARCHITECTURE.md).

## Building

Silica uses CMake as its build system and requires C++23.

### Initial Build

```bash
cmake -B build
```

### Subsequent Builds

```bash
cmake --build build
```

## Usage

### Running the REPL

Start an interactive session:

```bash
build/src/silica
```

### Running a File

Execute a Silica source file:

```bash
build/src/silica examples/fib.swift
```

### Verbose Mode

Enable verbose output to see the compilation stages:

```bash
build/src/silica --verbose examples/fib.swift
```

## Testing

Run the test suite:

```bash
build/tests/tests
```

The test suite includes:
- Parser tests
- Type inference tests
- Type equality tests
- Union-find data structure tests
- End-to-end integration tests

## Examples

The `examples/` directory contains sample programs:

- `fib.swift` - Recursive Fibonacci calculation
- `class.swift` - Class definition and method calls
- `adder.swift` - Function composition
- `assign_function.swift` - Functions as first-class values

## Implementation Details

### Value Representation

Silica uses NaN-boxing for efficient value storage. All values fit in 64 bits:
- Doubles are stored in their canonical representation
- Other types (integers, booleans, objects) are encoded in the NaN payload space

### Memory Management

Objects are managed using reference counting via the `ObjectPtr` smart pointer class. The garbage collector automatically frees objects when their reference count reaches zero.

### Virtual Machine

The VM uses a stack-based architecture with 32-bit instructions:
- 8-bit opcode
- 24-bit operand (for constants, locals, upvalues, etc.)

Supported features:
- Local variables and closures with upvalue capture
- Global variables
- Function calls and returns
- Class instantiation and method dispatch
- Arithmetic and logical operations

## Requirements

- CMake 3.30 or higher
- C++23 compatible compiler
- Google Test (automatically fetched during build)
