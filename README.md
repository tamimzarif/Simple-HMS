# Simple Hospital Management System Submitted using C
The Hospital Management System is designed to simulate a real-world hospital patient management workflow using fundamental data structures. The system handles patient input, triage, doctor assignment, treatment, and history retrieval. Emergency patients are always prioritized over normal patients.
The core objective of the system is to efficiently handle dynamic patient data. Since patient data changes constantly — patients arrive, get triaged, and are treated — appropriat


#Proposed Methodology:
The project follows a structured and modular development approach where each major functionality is implemented using the most suitable data structure.
System Design and Data Structure Mapping:

Singly Linked List (Patient Input)
• Used to store incoming patients before triage processing
• Allows efficient sequential insertion at the tail
• Serves as a temporary buffer before patients are moved to their respective queues

Emergency Queue (FIFO)
• Dedicated FIFO queue for patients flagged as emergency cases
• Emergency patients are always dequeued and treated before any normal patients
• Ensures life-critical cases receive prompt attention

Normal Queue (FIFO)
• Standard FIFO queue for non-emergency patients
• Patients are served in the order they arrive when no emergencies are pending

Stack (Treatment History)
• Maintains a history of treated patients using LIFO order
• Allows retrieval of the most recently treated patient at any time
Supports undo-like access to treatment records.

Doctor Assignment
• A pool of five doctors is pre-defined in the system
• Doctors are randomly assigned to patients using the C standard rand() function
• Assignment occurs during the triage/processing phase
