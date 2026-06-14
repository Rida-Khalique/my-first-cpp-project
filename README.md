# Object-Oriented Employee Management System (C++)

An interactive, terminal-based corporate hierarchy management application built using advanced Object-Oriented Programming (OOP) architectures in C++. The system models real-world corporate structures, handling employee tracking, task delegation, and direct memory cleanups safely.

## 🚀 Key Features
* **Role-Based Hierarchy**: Supports distinct management profiles for `Manager`, `Developer`, and hybrid `TeamLead` roles.
* **Polymorphic Work Execution**: Automatically routes job descriptions and specific task logs based on employee data structures.
* **Tracking Metrics**: Uses real-time tracking variables to monitor active structural allocations.
* **Memory Safety & Exception Management**: Fully integrated customized numerical error catch-blocks and dynamic array cleanups.

## 🛠️ Advanced OOP Concepts Utilized
* **Abstract Base Classes**: Implements the `Employee` template containing pure virtual operational targets (`virtual void work() = 0`).
* **The Diamond Problem Resolution**: Uses `virtual public` inheritance across derived roles to prevent compiler ambiguity and resource redundancy for the `TeamLead` class.
* **Runtime Polymorphism**: Employs structural arrays loaded with base object pointers (`Employee*`) resolving specialized actions dynamically during terminal inputs.
* **Static Class Members**: Tracks aggregate instance generation independently from standalone data scopes.

## 🖥️ Compilation and Execution Instructions

### Prerequisites
Ensure a compatible C++ compiler like `g++` is installed on your local operating machine.

### Windows / macOS / Linux Setup
1. **Clone or Download**: Save the main source file onto your machine as `main.cpp`.
2. **Compile Project**: Open your system terminal, navigate to the target directory, and build using:
   ```bash
   g++ main.cpp -o EmployeeSystem
   ```
3. **Run Application**: Launch the finalized executable framework using:
   ```bash
   ./EmployeeSystem
   ```

## 📋 Interactive Operations Menu
Upon launching, the interactive CLI application provides eight core functions:
1. **Add Manager**: Creates structural oversight blocks with dedicated target tracking array metrics.
2. **Add Developer**: Allocates language-specific engineering instances to the system.
3. **Add Team Lead**: Constructs multi-tier hybrid profiles executing both code structures and target tracking arrays.
4. **Show All Employees**: Sequentially streams registered profiles and details to the stdout view window.
5. **Show Employee Work**: Fires dynamic target functions across individual role instances.
6. **Show Total Employees**: Employs static queries returning historical active record counts.
7. **Delete All Records**: Purges memory allocations systematically using heap destruction frameworks.
8. **Exit**: Gracefully shuts down active interface instances safely.
