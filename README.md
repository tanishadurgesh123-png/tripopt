# TripOpt+ : Travel Planner in C

##  Overview
TripOpt+ is a C-based travel planning system that helps users select the best set of places to visit within a given budget and time limit. It combines Dynamic Programming and Greedy algorithms to provide an optimized travel plan.

---

##  Features
- Accepts user input for places (cost, time, enjoyment score)
- Uses Dynamic Programming to select the best combination of places
- Uses Greedy approach to determine the visiting order
- Displays selected places with total cost, time, and enjoyment

---

##  Algorithms Used

### 🔹 Dynamic Programming
- Solves a constrained optimization problem
- Maximizes total enjoyment under:
  - Budget constraint
  - Time constraint

### 🔹 Greedy Algorithm
- Sorts selected places based on:
  - Enjoyment / Time ratio
- Helps decide efficient visiting order

---

##  Technologies Used
- C Programming Language
- GCC Compiler
- Command Line Interface

---

## ▶️ How to Run

1. Compile the program:
### Step 1: Compile
```bash
gcc tripopt.c -o tripopt

Step 2: Run
Bash
./tripopt
