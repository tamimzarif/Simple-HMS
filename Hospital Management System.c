#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//PATIENT STRUCT
typedef struct Patient
{
    int id;
    char name[50];
    int emergency; // 1 = emergency, 0 = normal
    char doctor[50];
    struct Patient* next;
} Patient;

//LINKED LIST (FOR INPUT)
Patient* head = NULL;

void addPatientToList(int id, char name[], int emergency)
{

    Patient* newNode = (Patient*)malloc(sizeof(Patient));

    newNode->id = id;

    strcpy(newNode->name, name);

    newNode->emergency = emergency;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Patient* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

//NORMAL QUEUE
Patient* normalFront = NULL;

Patient* normalRear = NULL;

void enqueueNormal(Patient* p)
{
    p->next = NULL;
    if (normalRear == NULL)
    {
        normalFront = normalRear = p;
    }
    else
    {
        normalRear->next = p;
        normalRear = p;
    }
}

//EMERGENCY QUEUE
Patient* emergencyFront = NULL;

Patient* emergencyRear = NULL;

void enqueueEmergency(Patient* p)
{
    p->next = NULL;
    if (emergencyRear == NULL)
    {
        emergencyFront = emergencyRear = p;
    }
    else
    {
        emergencyRear->next = p;
        emergencyRear = p;
    }
}

//STACK (TREATED PATIENT HISTORY)
Patient* stackTop = NULL;

void push(Patient* p)
{
    p->next = stackTop;
    stackTop = p;
}
void pop()
{

    if (stackTop == NULL)
    {
        printf("No treated patient history.\n");
        return;
    }
    Patient* temp = stackTop;

    printf("\nLast Treated Patient\n");

    printf("ID: %d\n", temp->id);

    printf("Name: %s\n", temp->name);

    printf("Doctor: %s\n", temp->doctor);

    stackTop = stackTop->next;

    free(temp);
}

//DOCTOR ASSIGN
void assignDoctor(Patient* p)
{

    char doctors[5][50] =
    {
        "Dr Rahman",
        "Dr Karim",
        "Dr Ahmed",
        "Dr Sultana",
        "Dr Hasan"
    };

    int count = 5;

    int index = rand() % count;

    strcpy(p->doctor, doctors[index]);
}

//PROCESS LINKED LIST
void processPatients()
{
    Patient* temp = head;
    while (temp != NULL)
    {
        Patient* nextNode = temp->next;

        assignDoctor(temp);

        if (temp->emergency == 1)
            enqueueEmergency(temp);
        else
            enqueueNormal(temp);

        temp = nextNode;
    }

    head = NULL;

    printf("Patients moved to queues successfully.\n");
}

//TREAT PATIENT
void treatPatient()
{

    Patient* treated = NULL;

    if (emergencyFront != NULL)
    {

        treated = emergencyFront;
        emergencyFront = emergencyFront->next;

        if (emergencyFront == NULL)
            emergencyRear = NULL;

        printf("\nTreating Emergency Patient\n");
    }

    else if (normalFront != NULL)
    {

        treated = normalFront;
        normalFront = normalFront->next;

        if (normalFront == NULL)
            normalRear = NULL;

        printf("\nTreating Normal Patient\n");
    }

    else
    {
        printf("No patients available.\n");
        return;
    }

    printf("ID: %d\n", treated->id);
    printf("Name: %s\n", treated->name);
    printf("Doctor: %s\n", treated->doctor);

    push(treated);
}


//MAIN FUNCTION
int main()
{

    srand(time(NULL));

    int choice, id, emergency;
    char name[50];

    while (1)
    {

        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. Process Patients (Move to Queue)\n");
        printf("3. Treat Patient\n");
        printf("4. Show Last Treated Patient\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {

            printf("Enter ID: ");
            scanf("%d", &id);

            printf("Enter Name: ");
            scanf("%s", name);

            printf("Emergency? (1 = Yes, 0 = No): ");
            scanf("%d", &emergency);

            addPatientToList(id, name, emergency);
        }

        else if (choice == 2)
        {
            processPatients();=
        }

        else if (choice == 3)
        {
            treatPatient();
        }

        else if (choice == 4)
        {
            pop();
        }

        else if (choice == 5)
        {
            exit(0);
        }

        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}



