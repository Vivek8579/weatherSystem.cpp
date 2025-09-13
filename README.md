# weatherSystem.cpp
weather system application developed by me through the help of C++.
🌦️ Weather Data Storage System 🌦️
My Project for Data Structures (ENCS205)
Hey! This is my submission for the first Data Structures assignment. The goal was to build a system in C++ to handle weather data. I created a program that can store and manage temperature records for different cities over a few years. It's built around a 2D vector and showcases some cool concepts we've been learning, like ADTs, how data is stored in memory, and dealing with missing data points.

1. The Weather Record ADT 📝
For the basic building block of my system, I designed a WeatherRecord Abstract Data Type (ADT). Think of it as a custom data container that holds all the important info for a single weather update.

What's inside?

Date: I made a special struct for this to hold the day, month, and year together. It keeps things tidy!

City: A simple string for the city's name.

Temperature: A double because temperatures can definitely have decimal points.

Basically, each WeatherRecord is a neat little package that represents the temperature for one city on one specific day.

2. Memory Strategy: Row-Major vs. Column-Major 🧠
The heart of my data storage is a 2D vector, which acts like a grid. How C++ stores this grid in memory is super important for performance. It uses something called Row-Major Order.

Row-Major (The C++ Way 👍):

How it Works: All the data for the first row gets laid out in memory, one piece after the other. Then the second row, and so on. It's like reading a book, left-to-right, top-to-bottom.

My Implementation: The displayRowMajorAccess() function shows this off. The outer loop goes through the years (rows) and the inner loop goes through the cities (columns).

Why it's Fast 🚀: This is the most efficient way to access data in C++. When the CPU needs one piece of data from a row, it often grabs the nearby data too (thanks to something called the cache). This means accessing the rest of that row is lightning-fast because the data is already there!

Column-Major (The Scenic Route 🐢):

How it Works: This would mean storing all the data for the first column together, then the second column, etc.

My Implementation: I simulated this in the displayColumnMajorAccess() function by flipping the loops—the outer loop handles cities (columns) and the inner one handles years (rows).

Why it's Slower: In C++, this method is inefficient. To get data from the next row in the same column, the program has to jump to a completely different spot in memory. This causes a "cache miss," which is a fancy way of saying the CPU has to wait, slowing everything down.

3. Handling Sparse Data (aka Missing Info) 🤔
Let's be real, you're not always going to have data for every single city for every single year. This is called "sparse data." I needed a way to handle these gaps.

My Solution: The Sentinel Value

I decided to use a sentinel value. It's just a special number that I know will never be a real temperature.

Implementation: I declared a constant SENTINEL_VALUE = -999.0. When I first create the data grid, I fill every single spot with this number. If I get real data, it overwrites the sentinel. If not, the -999.0 stays, letting me know there's no data for that spot.

Why I Chose It: It's a straightforward and solid approach for a project of this size. It keeps the super-fast O(1) access time of the 2D array, which is a big plus. While it's not the most memory-efficient solution for a massive, mostly empty dataset, it's perfect for this assignment.

4. Time and Space Complexity Analysis ⚙️
Here’s a quick breakdown of the efficiency of my program. I'll use Y for the number of years and C for the number of cities.

Space Complexity
O(Y * C): The amount of memory my program uses is directly tied to the size of the 2D grid. A bigger grid (more years or cities) means more memory. Simple as that!

Time Complexity
insert(), retrieve(), remove():

The time it takes to run these functions is O(Y + C).

Why? Before I can access the grid, I have to find the correct row and column index by searching through my years and cities lists. In the worst case, I have to check every year and every city.

displayRowMajorAccess(), displayColumnMajorAccess():

The time complexity here is O(Y * C).

Why? To display everything, I have to visit every single cell in the grid, so the time taken is proportional to the size of the grid.

How to Compile and Run My Code 💻
Save the code as weather_system.cpp.

Open up a terminal.

Navigate to where you saved the file.

Compile it with g++:

g++ weather_system.cpp -o weather_system

Run it!

./weather_system
