# weatherSystem.cpp
# 🌦️ Weather Data Storage System in C++

A simple and efficient C++ program to store, manage, and access temperature data for multiple cities across a range of years.

---

## 📋 Features

- 🏙️ Store temperature records by **city** and **year**
- ➕ Insert temperature data
- ❌ Delete temperature data
- 🔍 Retrieve data for a specific city and year
- 📊 Display all data in a tabular format
- 🧭 Traverse data in both **row-major** and **column-major** order
- ⚠️ Handles invalid entries using a sentinel value

---

## 🧠 Time & Space Complexity

| Operation         | Time Complexity | Space Complexity |
|------------------|-----------------|------------------|
| Insert / Remove  | O(n)            | O(Y × C)         |
| Retrieve         | O(n)            |                  |
| Display          | O(Y × C)        |                  |

> 🔄 Where `Y` is the number of years and `C` is the number of cities  
> ⚡ Can be optimized using `unordered_map` for faster lookups
> ----
>
> ## 📌 Sentinel Value

To mark "no data available", the system uses:

```cpp

## 🖥️ Sample Output (displayData)
------------------------------------------------------
2023    15.5       28.2        N/A         N/A        
2024    N/A        N/A         32.0        N/A        
2025    N/A        N/A         N/A         N/A        

