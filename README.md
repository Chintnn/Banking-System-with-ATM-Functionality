# Banking System with ATM Functionality

## Programming and Paradigms CA3 – Mini Project

---

## **Abstract**
This project presents an **Object-Oriented Banking System** in C++ with **ATM integration**. The system models real-world banking operations, supporting multiple account types, transaction handling, and financial services. It demonstrates the application of **inheritance, polymorphism, and encapsulation** to create a structured and efficient banking framework. The study explores the implementation of overdraft facilities, interest accrual, and premium services, ensuring scalability and ease of modification.

## **Introduction**
With the increasing digitization of financial services, the demand for a secure, efficient, and scalable banking system has grown significantly. Traditional banking software often lacks modularity and adaptability, making it difficult to introduce new features. This project aims to provide a flexible, **Object-Oriented Banking System** that allows users to manage different types of bank accounts, perform financial transactions, and access ATM services in a seamless manner.

## **Problem Statement**
Banking institutions require dynamic account management systems to support diverse customer needs, such as:
- Secure and structured **financial transactions**.
- Overdraft management for **current accounts**.
- Interest calculation for **savings accounts**.
- Exclusive benefits for **premium customers**.

The proposed system provides an automated, modular, and extensible solution, allowing the addition of new features with minimal restructuring.

## **Objectives**
1. **Develop an Object-Oriented Banking System** to manage multiple account types.
2. **Implement ATM functionalities**, including deposits, withdrawals, and balance checks.
3. **Support overdraft protection** for current accounts.
4. **Automate interest calculations** for savings and premium accounts.
5. **Enhance code reusability and maintainability** through inheritance and polymorphism.
6. **Ensure secure and efficient transactions** through structured financial operations.

## **System Design and Implementation**
### **Architecture Overview**
The system is structured using a multi-layered approach:
- **Person Class**: Represents the account holder.
- **BankAccount Class**: Serves as a base for all account types.
- **SavingsAccount Class**: Extends `BankAccount`, adding interest calculation.
- **CurrentAccount Class**: Supports overdraft handling.
- **PremiumAccount Class**: Builds upon `SavingsAccount`, offering premium services.
- **Overdraft Class**: Implements overdraft limit checks for current accounts.
- **ATM Class**: Provides an interactive menu-driven interface for banking transactions.

### **Workflow**
1. **User Authentication**: The system verifies the entered account number and account type.
2. **Transaction Processing via ATM**:
   - Balance Inquiry
   - Deposits and Withdrawals (with overdraft protection if applicable)
   - Interest Accrual for Savings and Premium Accounts
3. **Dynamic Account Customization**: Premium accounts offer additional personalized banking services.
4. **Exit and Data Retention**: The system allows multiple transactions before session termination.

## **Customizing Premium Account Features**
Premium accounts in this system offer exclusive financial services tailored for high-value customers. The following customizations can be integrated:
- **Higher Interest Rates**: Adjustable interest rates based on user transactions.
- **Priority Customer Support**: Dedicated customer service access.
- **Loan and Credit Facilities**: Easy approvals for loans and overdrafts.
- **Wealth Management Tools**: Personalized investment advisory.
- **Exclusive Discounts & Cashback**: Benefits for premium account holders.
- **Multi-Currency Support**: Facilities for international transactions.

## **Results and Discussion**
### **Performance Analysis**
The system effectively demonstrates:
- **Dynamic Polymorphism**: ATM services interact seamlessly with different account types.
- **Encapsulation and Security**: Controlled access to account details and transactions.
- **Efficient Financial Management**: Overdraft protection, interest computation, and automated deposits enhance the user experience.

## **Future Scope**
To improve the system, the following features can be integrated:
1. **Graphical User Interface (GUI)** for a more interactive experience.
2. **Database Connectivity** for persistent storage.
3. **Cloud-Based Banking** enabling remote access and multi-device compatibility.
4. **Artificial Intelligence Integration** for fraud detection and predictive analytics.
5. **Multi-threading** for handling concurrent transactions efficiently.

## **Conclusion**
This project presents a **modular, extensible, and feature-rich banking system**, demonstrating how **Object-Oriented Programming (OOP)** principles can enhance real-world applications. The **integration of ATM functionalities**, along with structured financial operations, showcases the scalability and flexibility of the system. Future enhancements will focus on automation, security, and user experience, making the system more adaptable to modern banking needs.

---


