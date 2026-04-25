# 🚆 Train Route Optimization System

## 📌 Overview

The **Train Route Optimization System** is a console-based C++ application designed to simulate a real railway route planner. It helps users find the **most efficient path between two train stations** by calculating the shortest distance using **Dijkstra’s Algorithm**.

This project demonstrates how **Data Structures and Algorithms (DSA)** can be applied in real-world transportation systems such as railway navigation, metro route planning, and logistics networks.

Each station is represented as a node, and the railway connections between stations are represented as weighted edges containing:

- 📍 Distance (in KM)
- 💰 Fare (in INR)

The system then identifies the best route and displays:

- Shortest path
- Total distance
- Total fare


---

## ✨ Features

✅ Find shortest route between any two train stations  
✅ Displays complete travel path station-by-station  
✅ Calculates total travel distance  
✅ Calculates total ticket fare  
✅ Uses real DSA concept: Graph + Priority Queue  
✅ Fast route searching using Dijkstra’s Algorithm  
✅ Easy to expand with more stations and routes  
✅ Console-based lightweight application  


---

## 🧠 Concepts Used

This project is built using the following core programming concepts:

### 📚 Data Structures

- **Graph (Adjacency List)**  
  Used to store train stations and routes efficiently.

- **Priority Queue (Min Heap)**  
  Helps select the nearest unvisited station quickly.

- **Vectors**  
  Dynamic storage for route connections.

### ⚙️ Algorithms

- **Dijkstra’s Algorithm**  
  Finds the minimum distance path from source station to destination.

### 💻 C++ Concepts

- Structures (`struct`)
- Functions
- Arrays
- STL (`vector`, `priority_queue`)
- Loops & Conditions


---

## 🚉 Sample Train Network

The current project includes the following stations:

| Station No. | Station Name |
|------------|--------------|
| 0 | Delhi |
| 1 | Noida |
| 2 | Ghaziabad |
| 3 | Agra |
| 4 | Kanpur |
| 5 | Lucknow |
| 6 | Prayagraj |
| 7 | Varanasi |
| 8 | Patna |
| 9 | Gaya |
| 10 | Madhubani |

### Example Routes

- Delhi ↔ Agra  
- Lucknow ↔ Prayagraj  
- Prayagraj ↔ Varanasi  
- Varanasi ↔ Patna  
- Patna ↔ Madhubani  
- Kanpur ↔ Lucknow  


---

## 🖥️ Sample Output

===== Train Route Optimization System =====

===== Available Train Stations =====

0. Delhi
1. Noida
2. Ghaziabad
3. Agra
4. Kanpur
5. Lucknow
6. Prayagraj
7. Varanasi
8. Patna
9. Gaya
10. Madhubani

Enter Source Station Number      : 0
Enter Destination Station Number : 10

===== Best Route =====

Delhi -> Agra -> Lucknow -> Prayagraj -> Patna -> Madhubani

Total Distance : 1220 km
Total Fare : Rs. 1380

---

## ▶️ How to Run

```bash id="1a7hds"
g++ train.cpp -o train


