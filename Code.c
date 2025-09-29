#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char patientName[50];
    char medicines[200];
    float amount;
} Bill;

typedef struct {
    int id;
    char patientName[50];
    char medicines[200];
    float prices[10];
    int medCount;
    float totalAmount;
} PharmaReceipt;

typedef struct {
    int id;
    char patientName[50];
    char hospitalName[50];
    char reportDetails[200];
} LabReport;

typedef struct {
    int id;
    char patientName[50];
    char date[11];
    int status;
} Appointment;

typedef struct {
    char name[50];
    int quantity;
} MedicineStock;

typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char disease[50];
} PatientRecord;

Bill bills[50];
int billCount = 0;
PharmaReceipt pharmaReceipts[50];
int pharmaCount = 0;
LabReport labReports[50];
int labCount = 0;
Appointment appointments[50] = {
    {1, "Alice Smith", "2025-09-28", 0},
    {2, "Bob Johnson", "2025-09-28", 1},
    {3, "Carol White", "2025-09-29", 0}
};
int appointmentCount = 3;

MedicineStock stock[10] = {
    {"Paracetamol", 100},
    {"Amoxicillin", 50},
    {"Ibuprofen", 75},
    {"Cough Syrup", 30},
    {"Vitamin C", 200}
};
int stockCount = 5;

PatientRecord patientRecords[10] = {
    {1, "Alice Smith", 30, 'F', "Flu"},
    {2, "Bob Johnson", 45, 'M', "Diabetes"},
    {3, "Carol White", 28, 'F', "Asthma"},
    {4, "David Brown", 50, 'M', "Hypertension"},
    {5, "Eva Green", 35, 'F', "Migraine"},
    {6, "Frank Black", 40, 'M', "Allergy"},
    {7, "Grace Lee", 32, 'F', "Cold"},
    {8, "Henry King", 60, 'M', "Arthritis"},
    {9, "Ivy Scott", 25, 'F', "Skin Allergy"},
    {10, "Jack White", 55, 'M', "Heart Disease"}
};
int patientRecordCount = 10;

void administratorMenu();
void doctorMenu();
void receptionistMenu();
void laboratoristMenu();
void pharmacistMenu();
void generateBill();
void printPharmaReceipt();
void printLabReceipt();
void viewBillByName(char name[50]);
void viewPharmaReceiptByName(char name[50]);
void viewLabReceiptByName(char name[50]);
void generateMedicineReceipt();
void orderLabTest();
void todaysAppointments();
void checkAppointmentStatus();
void getCurrentDate(char* date);
void checkMedicineStock();
void restockMedicine();
void bookAppointment();
void viewPatientRecords();

int main() {
    char username[20], password[20];
    printf("=====================================================\n");
    printf("   Welcome to Gcoey Multispeciality Hospital\n");
    printf("=====================================================\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if ((strcmp(username, "Sarthak") == 0 && strcmp(password, "Sarthak@1234") == 0) ||
        (strcmp(username, "Rameshwar") == 0 && strcmp(password, "Rameshwar@1234") == 0) ||
        (strcmp(username, "Mashur") == 0 && strcmp(password, "Mashur@1234") == 0)) {
        printf("Welcome Dr. %s!\n", username);
        doctorMenu();
    } else if ((strcmp(username, "Ganesh") == 0 && strcmp(password, "Ganesh@1234") == 0) ||
               (strcmp(username, "Girish") == 0 && strcmp(password, "Girish@1234") == 0) ||
               (strcmp(username, "Prafull") == 0 && strcmp(password, "Prafull@1234") == 0)) {
        printf("Welcome Administrator %s!\n", username);
        administratorMenu();
    } else if ((strcmp(username, "Saurabh") == 0 && strcmp(password, "Saurabh@1234") == 0) ||
               (strcmp(username, "Pranay") == 0 && strcmp(password, "Pranay@1234") == 0)) {
        printf("Welcome Pharmacist %s!\n", username);
        pharmacistMenu();
    } else if ((strcmp(username, "Sapna") == 0 && strcmp(password, "Sapna@1234") == 0) ||
               (strcmp(username, "Siya") == 0 && strcmp(password, "Siya@1234") == 0) ||
               (strcmp(username, "Vishal") == 0 && strcmp(password, "Vishal@1234") == 0)) {
        printf("Welcome Receptionist %s!\n", username);
        receptionistMenu();
    } else if ((strcmp(username, "Hrishav") == 0 && strcmp(password, "Hrishav@1234") == 0) ||
               (strcmp(username, "Anthony") == 0 && strcmp(password, "Anthony@1234") == 0) ||
               (strcmp(username, "Parth") == 0 && strcmp(password, "Parth@1234") == 0)) {
        printf("Welcome Laboratory Staff %s!\n", username);
        laboratoristMenu();
    } else {
        printf("Invalid username or password.\n");
    }
    return 0;
}

void administratorMenu() {
    int choice;
    do {
        printf("\nAdministrator Menu:\n1. Manage User Accounts\n2. Assign Roles & Permissions\n3. Monitor System Performance\n4. Update/Customize Software\n5. Technical Maintenance\n6. Logout\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Managing user accounts...\n"); break;
            case 2: printf("Assigning roles & permissions...\n"); break;
            case 3: printf("Monitoring system performance...\n"); break;
            case 4: printf("Updating/customizing software...\n"); break;
            case 5: printf("Handling technical maintenance...\n"); break;
            case 6: printf("Logging out...\n"); break;
            default: printf("Invalid selection.\n");
        }
    } while(choice!=6);
}

void doctorMenu() {
    int choice;
    char name[50];
    do {
        printf("\nDoctor Menu:\n1. View Bills\n2. View Pharma Receipts\n3. View Lab Reports\n4. Generate Medicine Receipt\n5. Order Lab Test\n6. Today's Appointments\n7. Appointment Status\n8. Logout\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter patient name: "); scanf(" %[^\n]s", name); viewBillByName(name); break;
            case 2: printf("Enter patient name: "); scanf(" %[^\n]s", name); viewPharmaReceiptByName(name); break;
            case 3: printf("Enter patient name: "); scanf(" %[^\n]s", name); viewLabReceiptByName(name); break;
            case 4: generateMedicineReceipt(); break;
            case 5: orderLabTest(); break;
            case 6: todaysAppointments(); break;
            case 7: checkAppointmentStatus(); break;
            case 8: printf("Logging out...\n"); break;
            default: printf("Invalid selection.\n");
        }
    } while(choice!=8);
}

void receptionistMenu() {
    int choice;
    char name[50];
    do {
        printf("\nReceptionist Menu:\n1. Greet Patients\n2. Manage Calls\n3. Schedule Appointments\n4. Maintain Patient Records\n5. Assist with Medical Forms\n6. Generate Bills\n7. View Bills & Receipts\n8. View Patient Records\n9. Logout\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Greeting patients...\n"); break;
            case 2: printf("Managing calls...\n"); break;
            case 3: bookAppointment(); break;
            case 4: printf("Maintaining patient records...\n"); break;
            case 5: printf("Assisting with medical forms...\n"); break;
            case 6: generateBill(); break;
            case 7: printf("Enter patient name: "); scanf(" %[^\n]s", name); viewBillByName(name); viewPharmaReceiptByName(name); viewLabReceiptByName(name); break;
            case 8: viewPatientRecords(); break;
            case 9: printf("Logging out...\n"); break;
            default: printf("Invalid selection.\n");
        }
    } while(choice!=9);
}

void laboratoristMenu() {
    int choice;
    do {
        printf("\nLaboratorist Menu:\n1. Receive Samples\n2. Conduct Tests\n3. Operate Lab Equipment\n4. Record and Report Results\n5. Manage Supplies\n6. Follow Safety Protocols\n7. Print Lab Receipt\n8. Generate Lab Report\n9. Logout\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Receiving samples...\n"); break;
            case 2: printf("Conducting tests...\n"); break;
            case 3: printf("Operating lab equipment...\n"); break;
            case 4: printf("Recording test results...\n"); break;
            case 5: printf("Managing lab supplies...\n"); break;
            case 6: printf("Following lab safety protocols...\n"); break;
            case 7: printLabReceipt(); break;
            case 8: orderLabTest(); break;
            case 9: printf("Logging out...\n"); break;
            default: printf("Invalid selection.\n");
        }
    } while(choice!=9);
}

void pharmacistMenu() {
    int choice;
    do {
        printf("\nPharmacist Menu:\n1. Manage Medication\n2. Counsel Patients\n3. Collaborate with Staff\n4. Generate Medicine Receipt\n5. Monitor Drug Charts\n6. Dispense Inventory\n7. Compound Medicines\n8. Conduct Quality Assurance\n9. Print Pharma Receipt\n10. Check Medicine Stock\n11. Restock Medicine\n12. Logout\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Managing medication...\n"); break;
            case 2: printf("Counseling patients...\n"); break;
            case 3: printf("Collaborating with staff...\n"); break;
            case 4: generateMedicineReceipt(); break;
            case 5: printf("Monitoring drug charts...\n"); break;
            case 6: printf("Dispensing medicines...\n"); break;
            case 7: printf("Compounding medicines...\n"); break;
            case 8: printf("Conducting quality assurance...\n"); break;
            case 9: printPharmaReceipt(); break;
            case 10: checkMedicineStock(); break;
            case 11: restockMedicine(); break;
            case 12: printf("Logging out...\n"); break;
            default: printf("Invalid selection.\n");
        }
    } while(choice!=12);
}

void generateBill() {
    if(billCount>=50){printf("Bill storage full.\n"); return;}
    Bill b;
    b.id = billCount + 1;
    printf("Enter patient name: ");
    scanf(" %[^\n]s", b.patientName);
    printf("Enter medicines (comma separated): ");
    scanf(" %[^\n]s", b.medicines);
    printf("Enter total amount: ");
    scanf("%f", &b.amount);
    bills[billCount++] = b;
    printf("\n====================== BILL ======================\n");
    printf("| ID | Patient Name        | Medicines           | Amount  |\n");
    printf("| %-2d | %-19s | %-18s | %-7.2f |\n", b.id, b.patientName, b.medicines, b.amount);
    printf("==================================================\n");
}

void generateMedicineReceipt() {
    if(pharmaCount >= 50) {printf("Pharmacy receipt storage full.\n"); return;}
    PharmaReceipt p;
    p.id= pharmaCount + 1;
    printf("Enter patient name: ");
    scanf(" %[^\n]s", p.patientName);
    strcpy(p.medicines, "");
    printf("Enter number of medicines: ");
    scanf("%d", &p.medCount);
    p.totalAmount=0;
    int actualCount=0;
    for(int i=0;i<p.medCount;i++) {
        char medName[50];
        float price;
        int available=0;
        printf("Enter medicine %d name: ", i+1);
        scanf(" %[^\n]s", medName);
        for(int j=0;j<stockCount;j++){
            if(strcmp(stock[j].name,medName)==0){
                available=1;
                if(stock[j].quantity<=0){
                    printf("Medicine %s is out of stock!\n", medName);
                    available=0;
                } else {
                    stock[j].quantity--;
                }
                break;
            }
        }
        if(!available){ printf("Medicine %s not available, skipping...\n", medName); continue; }
        strcat(p.medicines, medName);
        if(actualCount!=p.medCount-1) strcat(p.medicines, ", ");
        printf("Enter price for %s: ", medName);
        scanf("%f",&price);
        p.prices[actualCount]=price;
        p.totalAmount+=price;
        actualCount++;
    }
    p.medCount=actualCount;
    pharmaReceipts[pharmaCount++]=p;
    printf("Medicine receipt generated successfully!\n");
}

void orderLabTest() {
    if(labCount >= 50) {printf("Lab report storage full.\n"); return;}
    LabReport l;
    l.id = labCount +1;
    strcpy(l.hospitalName, "Gcoey Multispeciality Hospital");
    printf("Enter patient name: ");
    scanf(" %[^\n]s", l.patientName);
    printf("Enter lab test report details: ");
    scanf(" %[^\n]s", l.reportDetails);
    labReports[labCount++] = l;
    printf("Lab test ordered and report recorded successfully!\n");
}

void printPharmaReceipt() {
    if(pharmaCount==0) {printf("No pharmacy receipts available.\n"); return;}
    for(int i=0;i<pharmaCount;i++){
        printf("\n================== PHARMA RECEIPT ==================\n");
        printf("| ID | Patient Name        | Medicines           | Total  |\n");
        printf("| %-2d | %-19s | %-18s | %-7.2f |\n", pharmaReceipts[i].id, pharmaReceipts[i].patientName, pharmaReceipts[i].medicines, pharmaReceipts[i].totalAmount);
        printf("====================================================\n");
    }
}

void printLabReceipt() {
    if(labCount == 0) {printf("No lab reports available.\n"); return;}
    for(int i=0;i<labCount;i++){
        printf("\n================== LAB RECEIPT ====================\n");
        printf("| ID | Patient Name        | Hospital Name       | Report Details                    |\n");
        printf("| %-2d | %-19s | %-19s | %-30s |\n", labReports[i].id, labReports[i].patientName, labReports[i].hospitalName, labReports[i].reportDetails);
        printf("====================================================\n");
    }
}

void viewBillByName(char name[50]) {
    int found=0;
    for(int i=0;i<billCount;i++){
        if(strcmp(bills[i].patientName,name) ==0){
            printf("\n====================== BILL ======================\n");
            printf("| ID | Patient Name        | Medicines           | Amount  |\n");
            printf("| %-2d | %-19s | %-18s | %-7.2f |\n", bills[i].id, bills[i].patientName, bills[i].medicines, bills[i].amount);
            printf("==================================================\n");
            found=1;
        }
    }
    if(!found) printf("No bill found for %s\n", name);
}

void viewPharmaReceiptByName(char name[50]) {
    int found=0;
    for(int i=0;i<pharmaCount;i++){
        if(strcmp(pharmaReceipts[i].patientName,name)==0){
            printf("\n================== PHARMA RECEIPT ==================\n");
            printf("| ID | Patient Name        | Medicines           | Total  |\n");
            printf("| %-2d | %-19s | %-18s | %-7.2f |\n", pharmaReceipts[i].id, pharmaReceipts[i].patientName, pharmaReceipts[i].medicines, pharmaReceipts[i].totalAmount);
            printf("====================================================\n");
            found=1;
        }
    }
    if(!found) printf("No pharma receipt found for %s\n", name);
}

void viewLabReceiptByName(char name[50]) {
    int found=0;
    for(int i=0;i<labCount;i++){
        if(strcmp(labReports[i].patientName,name)==0){
            printf("\n================== LAB RECEIPT ====================\n");
            printf("| ID | Patient Name        | Hospital Name       | Report Details                    |\n");
            printf("| %-2d | %-19s | %-19s | %-30s |\n", labReports[i].id, labReports[i].patientName, labReports[i].hospitalName, labReports[i].reportDetails);
            printf("====================================================\n");
            found=1;
        }
    }
    if(!found) printf("No lab report found for %s\n", name);
}

void todaysAppointments() {
    char today[11];
    getCurrentDate(today);
    printf("\nToday's Appointments (%s):\n", today);
    int found=0;
    for(int i=0;i<appointmentCount;i++) {
        if(strcmp(appointments[i].date,today)==0) {
            printf("Appointment ID %d: Patient %s, Status: %s\n", appointments[i].id, appointments[i].patientName, appointments[i].status ? "Completed" :"Pending");
            found=1;
        }
    }
    if(!found)
