Gcoey Multispeciality Hospital Management System

Overview

The Gcoey Multispeciality Hospital Management System is a console-based application written in C that provides an organized and efficient way to manage the operations of a multispeciality hospital. The system supports multiple user roles including administrators, doctors, receptionists, pharmacists, and laboratorists. Each role has a dedicated menu with functionalities tailored to their responsibilities.

The system manages:

Patient bills

Pharmacy receipts

Lab reports

Appointments

Medicine stock

Patient records


This project is designed for educational purposes and can be extended into a full-fledged hospital management software.


---

Features

1. User Authentication & Roles

Secure login for multiple user types with unique credentials.

Role-based access control ensures users can only access functionalities relevant to their role.
Example Roles & Users:

Role	Username	Password

Doctor	Sarthak	Sarthak@1234
Administrator	Ganesh	Ganesh@1234
Pharmacist	Saurabh	Saurabh@1234
Receptionist	Sapna	Sapna@1234
Laboratorist	Hrishav	Hrishav@1234




---

2. Billing System

Doctors and receptionists can generate patient bills.

Bills include:

Patient name

Medicines prescribed

Total amount


Bills are stored in memory and can be retrieved by patient name.


Example Bill Output:

====================== BILL ======================
| ID | Patient Name        | Medicines           | Amount  |
| 1  | Alice Smith         | Paracetamol, Vitamin C | 250.00 |
==================================================


---

3. Pharmacy Management

Pharmacists can generate medicine receipts, check stock availability, and restock medicines.

Medicines have:

Name

Price

Quantity in stock


Automatic stock deduction upon dispensing medicines.


Example Pharma Receipt:

================== PHARMA RECEIPT ==================
| ID | Patient Name        | Medicines           | Total  |
| 1  | Alice Smith         | Paracetamol, Vitamin C | 200.00 |
====================================================


---

4. Laboratory Management

Laboratory staff can:

Record and report lab tests

Print lab receipts

Manage lab supplies


Lab reports include:

Patient name

Hospital name

Report details



Example Lab Report:

================== LAB RECEIPT ====================
| ID | Patient Name        | Hospital Name       | Report Details                    |
| 1  | Alice Smith         | Gcoey Multispeciality Hospital | Blood Test: Normal  |
====================================================


---

5. Appointment Management

Receptionists can schedule appointments.

Doctors can view today's appointments and check status (Pending/Completed).

Appointment details include:

Patient name

Appointment date

Status



Example Output:

Today's Appointments (2025-09-29):
Appointment ID 3: Patient Carol White, Status: Pending


---

6. Patient Records

Static records of patients are available for viewing.

Includes:

ID, Name, Age, Gender, Disease



Example Patient Record:

================ PATIENT RECORDS ================
| ID | Name               | Age | Gender | Disease          |
| 1  | Alice Smith        | 30  | F      | Flu              |
| 2  | Bob Johnson        | 45  | M      | Diabetes         |
=================================================


---

7. Medicine Stock Management

Pharmacists can check stock levels of medicines.

Restock medicines manually.

Warns if a medicine is out of stock when generating receipts.


Example Stock Table:

Medicine Stock:
| Medicine Name        | Quantity |
---------------------------------
| Paracetamol          | 100      |
| Amoxicillin          | 50       |


---

Technology Stack

Language: C

Platform: Console-based application

Data Storage: In-memory arrays

Libraries Used: <stdio.h>, <string.h>, <time.h>



---

Installation & Running

1. Compile the code:



gcc hospital_management.c -o hospital_management

2. Run the executable:



./hospital_management

3. Login using the predefined username and password for your role.


4. Navigate menus to perform operations based on your role.




---

Usage Examples

Generate a Bill (Doctor or Receptionist)

Generate Pharma Receipt (Pharmacist)

Order Lab Test (Doctor or Laboratorist)

Check Appointments (Doctor or Receptionist)

View Patient Records (Receptionist)

Restock Medicines (Pharmacist)



---

Limitations

Data is not persistent; all records are lost after the program exits.

Limited to 50 entries for bills, lab reports, pharmacy receipts, and appointments.

Patient records are static and cannot be edited.

No advanced error handling (e.g., invalid date formats or negative stock values).



---

Future Enhancements

Integrate persistent storage (file or database) for bills, appointments, lab reports, and patient records.

Develop a graphical user interface (GUI) for easier interaction.

Dynamic user management: add, edit, or remove users.

Advanced analytics: revenue tracking, medicine usage, appointment trends.

Integration with online payment systems and email notifications for appointments.
