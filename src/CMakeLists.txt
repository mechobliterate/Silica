include(FetchContent)

FetchContent_Declare(argparse GIT_REPOSITORY https://github.com/p-ranav/argparse.git)
FetchContent_MakeAvailable(argparse)

add_library(silica_core
        core/debug.cc
        core/error.h
        core/bytecode.h
        core/debug.h
        core/built_ins.h
        core/string_interner.h
        runtime/value.cc
        runtime/object_ptr.cc
        runtime/object.h
        runtime/object_ptr.h
        runtime/value.h
)

add_library(silica_lexer
        lexer/scanner.h
        lexer/token.h
        lexer/error.h
)
target_link_libraries(silica_lexer silica_core)

add_library(silica_parser
        parser/expr.h
        parser/stmt.h
        parser/parser.h
        parser/factory.h
        parser/ast_visitor.h
        parser/ast_pretty_printer.h
)
target_link_libraries(silica_parser silica_lexer)

add_library(silica_analyzer
        analyzer/type.h
        analyzer/var.h
        analyzer/type_constraint.h
        analyzer/union_find.h
        analyzer/type_inference.h
)
target_link_libraries(silica_analyzer silica_parser)

add_library(silica_compiler
        compiler/compiler.h
)
target_link_libraries(silica_compiler silica_analyzer)

add_library(silica_vm
        vm/vm.cc
        vm/vm.h
)
target_link_libraries(silica_vm silica_core)

add_library(silica_cli
        cli/silica.cc
        cli/silica.h
)
target_link_libraries(silica_cli silica_compiler silica_vm readline)

add_executable(silica cli/main.cc)
target_link_libraries(silica silica_cli argparse)
