# Silica Architecture

Silica is a Swift-like interpreter written in C++. This document describes the project structure and architecture.

## Project Structure

```
Silica/
├── src/
│   ├── core/           # Core utilities and types
│   ├── lexer/          # Tokenization and scanning
│   ├── parser/         # AST and parsing
│   ├── analyzer/       # Type inference and semantic analysis
│   ├── compiler/       # Bytecode generation
│   ├── vm/             # Virtual machine and execution
│   ├── runtime/        # Runtime values and objects
│   └── cli/            # Command-line interface and REPL
├── tests/              # Unit and integration tests
└── examples/           # Example Silica programs
```

## Module Descriptions

### Core (`src/core/`)
Core utilities and fundamental types used throughout the project.

**Files:**
- `error.h` - Base error types for the Silica namespace
- `bytecode.h` - Bytecode instruction format and opcodes
- `debug.h/cc` - Debugging utilities for bytecode and values
- `built_ins.h` - Built-in functions (e.g., print)
- `string_interner.h` - String interning for efficient symbol management

### Lexer (`src/lexer/`)
Tokenization and lexical analysis of source code.

**Files:**
- `scanner.h` - Lexical scanner that converts source text to tokens
- `token.h` - Token types and token structure
- `error.h` - Lexer-specific errors (ScanError, SyntaxError, etc.)

### Parser (`src/parser/`)
Parsing tokens into an Abstract Syntax Tree (AST).

**Files:**
- `parser.h` - Recursive descent parser
- `expr.h` - Expression AST nodes
- `stmt.h` - Statement AST nodes
- `ast_visitor.h` - Visitor pattern for AST traversal
- `ast_pretty_printer.h` - Pretty-printing AST for debugging
- `factory.h` - Factory functions for creating AST nodes

### Analyzer (`src/analyzer/`)
Type inference and semantic analysis.

**Files:**
- `type.h` - Type system definitions (Int, Double, Bool, Function, Class, etc.)
- `type_inference.h` - Hindley-Milner style type inference
- `type_constraint.h` - Type constraints for inference
- `union_find.h` - Union-find data structure for type unification
- `var.h` - Variable representation with optional types

### Compiler (`src/compiler/`)
Code generation from AST to bytecode.

**Files:**
- `compiler.h` - Compiler that generates bytecode from typed AST

### VM (`src/vm/`)
Virtual machine for executing bytecode.

**Files:**
- `vm.h/cc` - Stack-based virtual machine with closure support

### Runtime (`src/runtime/`)
Runtime value representation and object management.

**Files:**
- `value.h/cc` - Tagged union value type (NaN-boxing)
- `object.h` - Object types (Function, Closure, Class, Instance, etc.)
- `object_ptr.h/cc` - Reference-counted smart pointer for objects

### CLI (`src/cli/`)
Command-line interface and REPL.

**Files:**
- `main.cc` - Entry point for the Silica interpreter
- `silica.h/cc` - High-level API for running Silica code

## Compilation Pipeline

```
Source Code
    ↓
[Lexer] → Tokens
    ↓
[Parser] → AST
    ↓
[Analyzer] → Typed AST
    ↓
[Compiler] → Bytecode
    ↓
[VM] → Execution
```

## Build System

The project uses CMake and is organized into modular libraries:

- `silica_core` - Core utilities
- `silica_lexer` - Tokenization
- `silica_parser` - AST and parsing
- `silica_analyzer` - Type checking
- `silica_compiler` - Code generation
- `silica_vm` - Virtual machine
- `silica_cli` - CLI and REPL
- `silica` - Main executable

## Type System

Silica uses Hindley-Milner type inference with support for:
- Primitive types: `Int`, `Double`, `Bool`, `Void`
- Function types: `(T1, T2, ...) -> R`
- Class types with members and methods
- Instance types

Type inference happens before compilation, ensuring type safety at runtime.

## Virtual Machine

The VM is a stack-based bytecode interpreter with:
- 32-bit instructions (8-bit opcode + 24-bit operand)
- Support for closures and upvalues
- Object-oriented features (classes, instances, methods)
- Global variables and local scopes

## Value Representation

Values use NaN-boxing for efficient storage:
- Doubles stored directly (canonical representation)
- Other types stored as tagged payloads in NaN space
- Objects stored as reference-counted pointers

## Development

Build the project:
```bash
cmake -B build
cmake --build build
```

Run the interpreter:
```bash
build/src/silica [file.swift]
```

Run tests:
```bash
build/tests/tests
```
