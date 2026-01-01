# 📹 CCTV Footage Management System

🔗 **Live Demo (Frontend):**  
👉 [Open Project in Browser](https://deeksha-602.github.io/CCTV-Footage-Management-System/)

---

## 📌 Project Overview

The **CCTV Footage Management System** is a system-based application that simulates how real-world CCTV surveillance systems manage and track recorded footage in environments such as offices, malls, campuses, and security centers.

The project is divided into:
- **C++ Backend** – Core logic and secure data handling  
- **HTML, CSS, JavaScript Frontend** – User interface and interaction  

Instead of storing actual video files, the system manages **footage metadata**, which closely mirrors how professional CCTV systems maintain footage logs.

---

## 🎯 Objectives

- Simulate a real CCTV footage management workflow
- Store footage records securely
- Enable fast searching and retrieval of footage data
- Maintain persistent data storage
- Demonstrate frontend–backend separation

---

## 🚀 Key Features

- **Add CCTV Footage**
  - Camera ID
  - Date & Time
  - Duration
  - Location

- **View All Footage Records**
  - Displays all stored footage metadata
  - Useful for monitoring and auditing

- **Search Footage by Camera ID**
  - Quickly locate specific camera logs
  - Helpful during investigations

- **Delete Footage Records**
  - Remove expired or unwanted data
  - Storage file updates in real time

- **Persistent Storage**
  - Data remains intact even after program exit

---

## 🔐 Secure Binary Data Storage

This project stores CCTV footage metadata in a **binary file format** using C++ file handling.

### Why Binary Storage?
- ✔ Data is **not human-readable**
- ✔ Prevents unauthorized manual access
- ✔ More secure than text-based storage
- ✔ Mimics real CCTV system log handling

📁 Storage File:

Only the backend program can read or modify this file, ensuring **controlled access and data integrity**.

---

## ▶ How to Run the Project

### 🔹 Frontend
Open the live demo directly in browser:
https://deeksha-602.github.io/CCTV-Footage-Management-System/

yaml
Copy code

---

### 🔹 Backend
Compile and run the C++ backend:

```bash
g++ main.cpp src/Footage.cpp -o cctv
./cctv


