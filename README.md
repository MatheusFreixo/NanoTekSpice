# NanoTekSpice

NanoTekSpice is a logic simulator built in C++. It simulates a graph of digital electronic components (chipsets) and processes inputs to compute the expected output based on Boolean logic.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Components](#components)
- [Commands](#commands)
- [Future Improvements](#future-improvements)

## Features
- Simulates digital logic gates (AND, OR, XOR, NOT)
- Handles inputs, outputs, and clocks
- Implements a basic circuit simulation with configuration files
- Follows boolean logic with an additional undefined state (`U`)

## Installation

### Requirements
- C++17 or higher
- `Make` for compilation

### Build Instructions

1. Clone the repository:
    ```bash
    git clone https://github.com/MatheusFreixo/NanoTekSpice.git
    cd NanoTekSpice
    ```

2. Compile the project using the provided Makefile:
    ```bash
    make
    ```

3. To clean the compiled object files:
    ```bash
    make clean
    ```

4. To clean all compiled files (including the binary):
    ```bash
    make fclean
    ```

5. To recompile the project:
    ```bash
    make re
    ```

## Usage

To run the NanoTekSpice simulator, provide a circuit configuration file as an argument:

```bash
./nanotekspice path/to/configuration_file.nts
```

The simulator supports interactive commands via standard input.

## Components

The following components are supported:

### Special Components
- `input`: Component with a single input pin
- `output`: Component with a single output pin
- `clock`: Flips its value at each tick
- `true`: Constant true component
- `false`: Constant false component

### Logic Gates
- `AND`: Standard AND gate
- `OR`: Standard OR gate
- `XOR`: Standard XOR gate
- `NOT`: Inverter gate

### Example Configuration File
```plaintext
.chipsets:
input in_1
input in_2
output out
and gate

.links:
in_1:1 gate:1
in_2:1 gate:2
out:1 gate:3
```

## Commands

- `simulate`: Simulates a tick of the circuit.
- `display`: Displays the current state of the inputs and outputs.
- `input=value`: Sets the value of an input. Values can be `0`, `1`, or `U` (undefined).
- `exit`: Exits the simulator.

## Future Improvements
- Add graphical output for the circuit.
