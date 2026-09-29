# Library Management System – C++

## 📌 Project Description

The **Library Management System** is a console-based C++ program designed to manage different types of library items such as **Books, DVDs, and Magazines**.

The project demonstrates important **Object-Oriented Programming (OOP)** concepts including:

* Classes and Objects
* Inheritance
* Encapsulation
* Abstraction
* Polymorphism
* Constructors
* Virtual Functions
* Exception Handling
* Dynamic Memory Allocation

## ✨ Features

* Add a Book
* Add a DVD
* Add a Magazine
* Display all library items
* Search an item by title
* Check out an item
* Return an item
* Input validation
* Exception handling
* Maximum catalog capacity of 100 items
* Automatic memory cleanup

## 🛠️ Technologies Used

* **Language:** C++
* **Compiler:** GCC / Clang
* **Concepts:** OOP, Inheritance, Polymorphism, Exception Handling

## 📂 Project Structure

```text
Project5/
│
├── Project5.cpp
└── README.md
```

## 🧩 Classes Used

### 1. LibraryItem

The abstract base class containing common information:

* Title
* Author
* Due Date

It also defines virtual functions:

```cpp
checkOut()
returnItem()
displayDetails()
```

### 2. Book

Derived from `LibraryItem`.

Additional attributes:

* ISBN
* Quantity
* Checkout status

### 3. DVD

Derived from `LibraryItem`.

Additional attributes:

* Duration
* Checkout status

### 4. Magazine

Derived from `LibraryItem`.

Additional attributes:

* Issue Number
* Checkout status

## 📋 Main Menu

```text
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Search Item
6. Check Out Item
7. Return Item
8. Exit
```

## ▶️ How to Run

### Compile

```bash
g++ Project5.cpp -o Project5
```

### Run

```bash
./Project5
```

On Windows:

```bash
Project5.exe
```

## 🧠 OOP Concepts Demonstrated

### Encapsulation

Data members are kept private and accessed through public functions.

### Inheritance

`Book`, `DVD`, and `Magazine` inherit from the `LibraryItem` class.

### Polymorphism

Virtual functions allow different library item classes to provide their own implementations of:

```cpp
checkOut()
returnItem()
displayDetails()
```

### Abstraction

`LibraryItem` is an abstract class because it contains pure virtual functions.

### Exception Handling

The program uses exceptions to handle invalid inputs such as:

* Negative quantity
* Invalid ISBN
* Invalid DVD duration
* Invalid magazine issue number
* Empty title or author
* Full library catalog

## 🎥 Project Video

https://drive.google.com/drive/folders/1oRQppjEycQ6j3D9kbZcoZo1hb3NoukP6?usp=sharing

## 👨‍💻 Author

**Vansh Soni**

---

### ✅ Conclusion

This project demonstrates how C++ Object-Oriented Programming concepts can be used to create a practical **Library Management System** with multiple types of library items and basic library operations.
