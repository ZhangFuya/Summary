# 使用Rust编写一个HelloWorld程序
```rust
//test.rs
fn main() {
	println!("HelloWorld!!!");
}
```

# 编译
- 编译命令 rustc test.rs
- 运行命令 ./test.exe

# Cargo
一般 rustc(rust complie)只适用于简单的Rust项目。较为复杂的Rust工程使用Cargo进行编译。
Cargo是Rust的构建系统和包管理工具。主要用于 构建代码、下载依赖的库、构建库
命令 `cargo new ProjectName` 可用于创建工程。

## Cargo 命令做了哪些事
- 创建名为 ProjectName 的项目
- 创建一个和项目名 ProjectName 同名的新目录
    - Cargo.toml(cargo管理器的配置文件)
    ```rust
    [package] #是一个区域表示下方区域是用来配置包的
    name = "RustRro01"  #项目名称
    version = "0.1.0"   #项目版本
    edition = "2021"    #Rust版本号

    [dependencies] #另一个区域的开始
    ```
    - src目录(包含了HelloWorld的main函数)
    - 初始化一个git仓库

# 使用Cargo构建和运行项目
- 项目目录下使用 `cargo build` 命令
使用 `cargo build`命令会生成 Cargo.lock 文件
Cargo.lock 文件负责追踪项目依赖的精确版本，不需要也尽可能不要手动修改。
- 使用 `cargo run` 命令可以构建并运行项目
注意 `cargo run` 是**构建并运行**项目，如果文件未被更改则直接运行
- `cargo check`
使用 `cargo check` 检查代码，确保能够通过编译，但是不会产生任何可执行文件。
因为 `cargo check` 比 `cargo build` 快的多，因此可以反复使用 `cargo check` 检查代码
- `cargo build --release` 构建发布版本

# 非Cargo项目转Cargo项目
- 创建一个src文件夹，并将源文件放入到src文件夹中
- 创建一个 Cargo.toml 并编写相应的配置信息即可