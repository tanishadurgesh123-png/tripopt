# TripOpt+ : Travel Planner in C

##  Overview
TripOpt+ is a C-based travel planning system that helps users select the best set of places to visit within a given budget and time limit. It combines Dynamic Programming and Greedy algorithms to provide an optimized travel plan.



##  Features
- Accepts user input for places (cost, time, enjoyment score)
- Uses Dynamic Programming to select the best combination of places
- Uses Greedy approach to determine the visiting order
- Displays selected places with total cost, time, and enjoyment



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



##  Technologies Used
- C Programming Language
- GCC Compiler
- Command Line Interface



## ▶️ How to Run

1. Compile the program:
### Step 1: Compile
```bash
gcc tripopt.c -o tripopt

Step 2: Run
Bash
./tripopt

📌 Example Run
Input
Enter number of places: 3
Cost, Time, Enjoyment for Place 1: 10 2 50
Cost, Time, Enjoyment for Place 2: 15 3 60
Cost, Time, Enjoyment for Place 3: 20 4 100
Enter Budget: 25
Enter Time Limit: 5
Output
Maximum Enjoyment: 110

Visit Order (Greedy):
Place 1 (Ratio: 25.00)
Place 2 (Ratio: 20.00)
Place 3 (Ratio: 25.00)

📊 Explanation

Dynamic Programming selects the best combination of places within budget and time constraints
Greedy algorithm sorts selected places based on enjoyment/time ratio
This ensures both optimal selection and efficient visiting order

⚠️ Limitations

Assumes fixed input size
Greedy approach may not always give globally optimal route
Does not include real-world map distances

🔮 Future Improvements

Add GUI interface
Integrate real map APIs
Improve route optimization using advanced algorithms
Add user-friendly menu system