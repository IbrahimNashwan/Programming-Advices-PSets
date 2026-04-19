# ATM Management System (C++)

A specialized **ATM Simulation System** built with C++ that emulates the core functionalities of a bank's automated teller machine. This project focuses on client-side operations, providing a secure login and a variety of financial transaction options through a clean console interface.

## 🚀 Key Features

### 🔐 Secure Authentication
* **Client Login:** Users access their accounts using a unique **Account Number** and **PIN Code**.
* **Validation:** Robust input validation to ensure only authorized clients can access the system.

### 💸 Withdrawal Options
* **Quick Withdraw:** A fast-access menu for common withdrawal amounts (20, 50, 100, up to 1000).
* **Normal Withdraw:** Allows users to enter a custom amount (validated to be multiples of 5, as per standard ATM logic).
* **Balance Protection:** Built-in checks to prevent withdrawing more than the available account balance.

### 💳 Account Services
* **Deposit:** Easily add funds to the account with real-time balance updates.
* **Check Balance:** Instant view of the current account standing.
* **Persistent Storage:** All transactions are updated and saved automatically in the `Clients.txt` file.

---

## 🛠 Technical Highlights

* **Language:** C++
* **Data Persistence:** Uses a flat-file database (`Clients.txt`) with a custom delimiter (`#//#`).
* **Object Mapping:** Implements `struct` (sClient) to represent account data and `std::vector` for efficient data handling.
* **Input Handling:** Specialized functions to handle numerical range validation and prevent system crashes from invalid inputs.
* **Logic Flow:** Modular design with clear separation between UI menus and backend transaction logic.

---

## 💻 How to Use

1. **Setup Environment:** Ensure you have a C++ compiler (like GCC) installed.
2. **Data File:** Create a file named `Clients.txt` in the same directory.
   * *Format:* `AccountNum#//#Pin#//#Name#//#Phone#//#Balance`
3. **Compile:**
   ```bash
   g++ main.cpp -o ATMSystem
   ```
4. **Run:**
   ```bash
   ./ATMSystem
   ```

---

## 📖 System Menu Structure
* **[1] Quick Withdraw:** Choose from pre-set amounts.
* **[2] Normal Withdraw:** Enter a custom amount (must be divisible by 5).
* **[3] Deposit:** Increase account balance.
* **[4] Check Balance:** View current funds.
* **[5] Logout:** Securely exit to the login screen.


---
*Note: This project was developed for educational purposes to demonstrate advanced logic, file I/O operations, and user experience design in C++.*
