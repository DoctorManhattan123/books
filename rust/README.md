# Rust

[Rust](https://www.rust-lang.org/learn) is a multi-paradigm, general-purpose, statically-typed, compiled programming language.

# Idea behind Rust

The idea is to be memory, type and thread safe without compromising on performance or hardware control. No more null pointer exceptions, dangling pointers, buffer overflows or memory leaks while still having full control.

## Requirements

1. [rustup](https://www.rust-lang.org/tools/install) - includes `rustc`, `cargo`, `rustup`
2. A Linker (e.g. from GCC or Clang)
    
    e.g. Ubuntu 20.04
    ```sh
    sudo apt install build-essential
    ```

## Hello, world!

```rust
// main.rs
fn main() {
    println!("Hello, world!);
}
```

```sh
$  rustc main.rs
$  ./main
Hello, world!
```

## Cargo

Unless you only need one file and no dependencies you will never ever write a Rust program like in the chapter before. 

You will use Cargo, Rust's build system and package manager. From now on we will assume that you use cargo. It's the best way.

## Create a project

```sh
cargo new new_project
cd new_project
```

This command creates the following files/directories:
1. Cargo.toml - this file includes information about your project. Name, version, dependencies, build-dependencies. This information is important for Cargo (Cargo.toml is something like package.json for an npm project)

2. src/main.rs - The entry file for the program (with the `Hello world` program code).

3. .git/ (Read about [Git](../git//README.md) for more information)

4. .gitignore (Read about [Git](../git//README.md) for more information)
