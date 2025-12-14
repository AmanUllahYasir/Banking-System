# Secure Banking Management System in C

A **console-based banking system** implemented in C, designed to be **secure, modular, and scalable**.  
It supports account management, deposits, withdrawals, transfers, transaction history, and secure password authentication.  

This project demonstrates **real-world C programming skills**, including file handling, data structures, hashing, and modular code design—perfect for a GitHub showcase or portfolio.  

---

## Features

### Account Management
- Create, edit, and view accounts
- Accounts have unique account numbers, names, hashed passwords, and balances
- Secure login with SHA256 password hashing  

### Transactions
- Deposit, withdraw, and transfer money between accounts
- Each transaction is logged with **timestamp** and details
- Transaction history viewable per account

### Security
- Passwords stored as **SHA256 hashes**  
- Binary file storage for accounts and transactions  
- Input validation to prevent buffer overflows and invalid data  
- Transaction integrity ensured with timestamps  

### Scalability
- Modular design (`account.c/h`, `transaction.c/h`, `auth.c/h`, `file.c/h`, `utils.c/h`)  
- Supports **thousands of accounts** and transactions  
- File-based storage can be easily replaced with a database later  

### User-Friendly
- Interactive console menu  
- Clear prompts and messages  
- Easily extensible for more features  

---

## Installation

- Clone the repository
- compile it
  
