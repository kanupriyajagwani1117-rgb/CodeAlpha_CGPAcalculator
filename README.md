# 📊 Grades & CGPA Calculator

An interactive, command-line utility developed in C++ to help university students track, calculate, and manage their academic performance. The application dynamically computes a single semester's Grade Point Average (GPA) and seamlessly merges it with historical academic records to output an updated cumulative Cumulative Grade Point Average (CGPA).

---

## 🚀 Features

* **Dual-Mode Calculation:** Computes isolated single-semester GPA or combines past academic history to determine an updated cumulative CGPA.
* **Input Validation & Safety:** Robust checking loops handle invalid letter grade entries gracefully, ensuring clean runtime execution.
* **Dynamic Memory Allocations:** Leverages modern standard template library (`std::vector`) containers to store a flexible, user-defined number of course entries.
* **Tabular Performance Report:** Generates a structured, cleanly aligned report right inside the console using structured spacing metrics (`<iomanip>`).
* **Case-Insensitive Interpretation:** Accepts both lowercase and uppercase variations of letter inputs (e.g., `a` or `A`) for enhanced user experience.

---

## 🧮 Grade Mapping Scale

The application operates on a conventional 4.0 weighted academic scale:

| Letter Grade | Weighted Grade Points |
| :---: | :----------: |
|   A / a   |     4.0      |
|   B / b   |     3.0      |
|   C / c   |     2.0      |
|   D / d   |     1.0      |
|   F / f   |     0.0      |

---

## 🛠️ Installation & Compilation

To compile and run this application locally, ensure you have a standard C++ compiler installed (such as `g++` or `clang`).

### 1. Save the File
Copy the source code and save it on your machine as `main.cpp`.

### 2. Compile via Terminal
Open your terminal or command prompt inside the folder containing `main.cpp` and compile the program using the following command:
```bash
g++ -std=c++11 main.cpp -o cgpa_calculator
