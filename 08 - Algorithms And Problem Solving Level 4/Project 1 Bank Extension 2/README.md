# Bank & User Management System (C++)

A robust, console-based **Bank Management System** developed in C++. This application manages client financial records and administrative user accounts using a file-based database system. It features a sophisticated **bitmask-based permission system** to control access to various parts of the application.

## 🚀 Features

### 🏦 Client Management
* **List Clients:** View all registered bank clients with details (Account Number, Name, Balance, etc.).
* **Add New Clients:** Register new clients with unique account numbers.
* **Update/Delete:** Modify existing client information or remove records securely.
* **Find Client:** Quick search functionality by account number.

### 💰 Transactions
* **Deposit:** Add funds to a specific account.
* **Withdraw:** Remove funds with built-in validation to prevent overdrafts.
* **Total Balances:** View a summary of all client balances and the total bank liquidity.

### 👥 User & Permission Management
* **Secure Login:** Authentication system requiring a username and password.
* **Access Control:** Administrative users can grant or revoke specific permissions for other users.
* **Full Admin Support:** Special "Admin" account protection and full access overrides.

---

## 🛠 Technical Implementation

* **Language:** C++
* **Data Persistence:** Flat-file database (`Clients.txt` and `Users.txt`) using `#//#` as a custom separator.
* **Data Structures:** Utilizes `struct` for record modeling and `std::vector` for dynamic memory management.
* **Permission Logic:** Implements **Bitwise Operations** to manage user access levels efficiently.

---

## 🔐 Permission Levels

| Permission | Value | Description |
| :--- | :--- | :--- |
| `pListClients` | 1 | Access to view the client list |
| `pAddNewClient`| 2 | Ability to add new clients |
| `pDeleteClient`| 4 | Ability to remove clients |
| `pUpdateClients`| 8 | Ability to modify client data |
| `pFindClient`  | 16 | Access to the search tool |
| `pTranactions` | 32 | Access to the Transactions menu |
| `pManageUsers` | 64 | Access to User Management |
| `eAll`         | -1 | Full system access |

---

## 💻 How to Run

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/YourUsername/Bank-System-CPP.git
    ```
2.  **Ensure Data Files Exist:** Create `Clients.txt` and `Users.txt` in the same directory.
3.  **Compile:**
    ```bash
    g++ main.cpp -o BankSystem
    ```
4.  **Execute:**
    ```bash
    ./BankSystem
    ```

---
*Note: This project is intended to demonstrate file handling and administrative logic in C++.*
