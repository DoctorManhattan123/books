# LLVM

Last uptated: 2022-08

## Summary

* Umbrella project of low-level toolchain components
* Modular design
* Unique intermediate representation & optimizer

The LLVM Project is a collection of modular and reusable compiler and toolchain technologies. Despite its name, LLVM has little to do with traditional virtual machines. The name "LLVM" itself is not an acronym; it is the full name of the project.

A few of the most used language compilers use LLVM as their base:

1. C
2. C++
3. Rust
4. Julia
5. Swift

## History

Small summary at [llvmorg.org](https://llvm.org/)

## Distribution

Publicly available for [download](https://releases.llvm.org/) under an open source License.

## Primary sub-projects

The most prominent examples are:

1. LLVM Core

2. [Clang](https://clang.llvm.org/)

3. [LLDB](https://lldb.llvm.org/)

## LLVM Core

Source -> Scanner -> Parsing -> Intermediate Representation -> IR Optimizer -> Semantic Analysis -> Target Code -> Compiled Code

### Intermediate Representation

Possible approaches:

* Structured
* Flat, tuple-based
* Flat, stack-based

#### LLVM IR

* Low-level programming languages similar to assembly
* Strongly typed RISC intruction set
* Infinete set of temporary registers (%0, %1, ....)

Source Code -> Frontend -> LLVM IR Optimizer -> Backend

* Has three isomorphic forms (Text -> Memory -> Bitcode -> Text)

#### Other examples/appraoches

* Java and .NET virtual machines + JIT
* Translate source to C and use C compilers
* GCC (monolithic)

#### LLVM IR Optimizer

* Look for a pattern to be transformed
* Verify that the transformation is safe/correct
* If true, then do the transformation

Example:

```c
// c
unsigned add1(unsigned a, unsigned b) {
    return a+b;
}
```
```llvm
// llvm
define i32 @add1(i32 %a, i32 %b){
entry:
    %tmp1 = add i32 %a, %b
    ret i32 %tmp1
}
```

#### Writing an LLVM IR Optimization

* x-x -> 0
* x-0 -> x
* (x*2)-x -> x

Actual code examples

```llvm
%example1 = sub i32 %a, %a

%example2 = sub i32 %b, 0

%tmp = mul i32 %c, 2
%example3 = sub i32 %tmp, %c
```

LLVM is written in C++.