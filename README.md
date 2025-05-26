# Embedded-cli

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square) ![CMake](https://img.shields.io/badge/CMake-%3E%3D3.10-blue?style=flat-square) ![Minicom](https://img.shields.io/badge/Minicom-2.7.1-blue?style=flat-square) ![Clang](https://img.shields.io/badge/Compiler-Clang-green?style=flat-square) ![MSVC 2017+](https://img.shields.io/badge/Compiler-MSVC%202017%2B-yellow?style=flat-square) ![GCC](https://img.shields.io/badge/Compiler-GCC-lightgrey?style=flat-square)

---

## Overview

**embedded-cli** is a professional, modular C++ framework that empowers engineers to interact with embedded firmware via a command-line interface. Its primary goals are to simplify configuration, enhance real-time debugging, and standardize diagnostics across diverse hardware platforms.

## Core Features

- **Extensible Command Registration**  
  A clean API to register custom commands with descriptions and handlers.

- **Built-In Utilities**  
  - `help` &mdash; List all commands.
  - `version` &mdash; Display firmware/build information.
  - `get` / `set` &mdash; Read and write configuration parameters.
  - `status` &mdash; Report system health and metrics.
  - `debug` &mdash; Toggle verbose logging.
  - `reboot` &mdash; Trigger a controlled system restart.

- **Robust Input Parsing**  
  Uses `std::istringstream` for reliable tokenization of user input.

- **Platform-Agnostic Stubs**  
  Easily hook into your hardware abstraction layer for storage, reboot, or peripheral control.

- **Host-Target Separation**  
  The CLI core is unit-testable on the host; integration with embedded-specific code lives in separate modules.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites

- A C++17-compatible compiler (Clang, GCC, or MSVC 2017+)  
- CMake (≥ 3.10)  
- A serial terminal emulator (e.g., Minicom) for UART/CDC connectivity

## Installation

```bash
# Clone the repository
git clone https://github.com/YOUR_GITHUB_USERNAME/embedded-cli.git
cd embedded-cli

# Create and enter build directory
mkdir build && cd build

# Configure and build
cmake ..
make
```

This produces an executable `cli_app` linked against the `cli_lib` library.

## Usage

1. Launch the CLI application:
   ```bash
   ./cli_app
   # You will see: Embedded CLI v1.0. Type 'help' for a list of commands.
   ```
2. Connect via your terminal emulator to the embedded device (e.g., `/dev/ttyUSB0` at 115200 baud):
   ```bash
   minicom -D /dev/ttyUSB0 -b 115200
   ```
3. Type `help` to view available commands, then issue operations such as:
   ```bash
   get log_level
   set log_level debug
   status
   reboot
   ```

## Project Structure

```
embedded-cli/        # Root directory
├── include/         # Public headers (CLI.hpp)
├── src/             # Core implementation and `main.cpp`
├── CMakeLists.txt   # Build configuration
└── README.md        # This document
```

Please adhere to the existing code style and include relevant unit tests or integration examples.

## License

This project is licensed under the [MIT License](LICENSE).
