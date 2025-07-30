# MyCalc - A Command-Line Calculator (C-based REPL)

## Overview
**MyCalc** is a lightweight, command-line-based calculator that functions like a **REPL (Read-Eval-Print Loop)**.  
It dynamically compiles expressions using **C**, allowing users to evaluate:
- **Arithmetic expressions**
- **Trigonometric functions (in degrees)**
- **Factorials**
- **Prime number calculations**
- **Other mathematical functions**

Originally started in the **2020–2021 academic year** during the COVID-19 lockdown, this project was one of my earliest explorations into programming logic. In **2025**, it was modernized with Makefile support, cross-platform compatibility, and cleanup logic.


## Features
- **Basic Arithmetic**: `+`, `-`, `*`, `/`, `()`  
- **Trigonometry (Radians)**: `sin(x)`, `cos(x)`, `tan(x)` (accepts radians)  
- **Trigonometry (Degrees)**: `sin_deg(x)`, `cos_deg(x)`, `tan_deg(x)` (accepts degrees)  
- **Logarithms**: `log(x)`, `log10(x)`  
- **Factorial Calculation**: `fact(n)` (Supports up to `fact(20)`)  
- **Power Functions**: `pow(base, exponent)`  
- **Prime Number Utilities**:
   - Check if a number is prime → `isprime(n)`
   - Find the nth prime → `nth_prime(n)`  
- **Reverse a Number**: `reverse(n)`  
- **Find Factors**: `factors(n)`  
- **Dynamic Help Commands**:
   - **`help()`** → Displays a static list of available functions and usage examples.
   - **`help_all()`** → Dynamically lists all functions defined in `wincalc.h`.
- **Special Command**:
   - **`exit()`** → Exits the calculator and triggers cleanup.


## How to Install & Run
1. **Clone the repository**:
   ```sh
   git clone https://github.com/wineel10/MyCalc.git
   cd MyCalc
   ```

2. **Run the calculator**:
   ```sh
   make run
   ```

   - The calculator now supports colored result output (bright green)
   - Works on macOS, Linux, and Windows (via WSL, Git Bash, or MinGW)

3. **Enter expressions** and see instant results:
   ```
   >>> 1+2
   3
   >>> sin(90)
   1
   >>> fact(5)
   120
   >>> help()
   >>> help_all()
   ```
   
4. **To exit**, type:
   ```
   >>> exit()
   ```

5. **Auto Cleanup**:  
   - When you exit, `win.h`, `input.exe`, and `output.exe` are **automatically deleted** for security.


## Terminal Colors
Results are printed in bright green using ANSI escape codes.


## Cross-Platform Makefile
The provided `Makefile`:
- Detects Windows vs macOS/Linux
- Uses correct file delete and null device syntax per OS
- Supports dynamic recompilation in a REPL loop


## Available Functions
| Function          | Description                    | Example         | Output                  |
|-------------------|--------------------------------|-----------------|-------------------------|
| `1+2`             | Basic Arithmetic               | `1+2`           | `3`                     |
| `sin(90)`         | Sine (in degrees)              | `sin(90)`       | `1`                     |
| `fact(5)`         | Factorial                      | `fact(5)`       | `120`                   |
| `isprime(11)`     | Prime number check             | `isprime(11)`   | `1` (true)              |
| `nth_prime(5)`    | Find the 5th prime             | `nth_prime(5)`  | `11`                    |
| `reverse(1234)`   | Reverse the number             | `reverse(1234)` | `4321`                  |
| `factors(10)`     | Find factors of 10             | `factors(10)`   | `1 2 5 10`              |
| `help()`          | Show static function list      | `help()`        | Displays usage examples |
| `help_all()`      | Dynamically list functions     | `help_all()`    | Reads `wincalc.h`       |
| `exit()`          | Exit the calculator            | `exit()`        | Program closes          |


## Project Structure
```
MyCalc
│──  Input.c           # Takes user input, generates win.h
│──  Output.c          # Executes the calculation
│──  wincalc.h         # Math functions, including trigonometry in degrees
│──  Makefile          # Cross-platform build and run automation
│──  README.md         # Documentation on how to use the project
│──  .gitignore        # Prevents unnecessary files from being committed
```


##  `.gitignore` (Files That Should NOT Be Uploaded)
```
*.exe
.vscode/
win.h
errors.log
*.o
*.obj
input
output
exit_marker.txt
```
These files are **auto-generated** during compilation and should NOT be committed to GitHub.


## Why This Project?
Started during the **2020–2021 academic year** at the time of COVID-19 lockdowns, this was one of my earliest programming experiments in C. In **2025**, I enhanced it with professional touches like Makefile automation, cross-platform support, and ANSI-colored output.It demonstrates:
- How to use **C as a REPL**
- How Makefile or batch/shell files can **control execution flow**
- How **real-time mathematical expression evaluation** works in C


## Future Improvements
- **Improve UI/UX** (colored output, better formatting)
- **Support for more math functions** (e.g., modulus, permutations, combinations)
- **Cross-platform compatibility** (Linux/macOS/Windows with `make` or shell scripts)
- **Enhance security** (prevent unintended code execution)


## License
This project is **open-source** and licensed under the **MIT License**.  
Feel free to modify and improve upon it!


## Author  
- **WINEEL WILSON DASARI**  
- wineel10wilson@gmail.com  
- GitHub: [wineel10](https://github.com/wineel10)  
