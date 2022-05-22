#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>


#define TRUE    1
#define FALSE   0

#define SBJCTS_NUM   6
#define TOTAL_SCORE   100



//*************************************************

// create some names to access the subjects array
// to avoid magic numbers
typedef enum
{
    math,
    comp_snce,
    physics,
    chemistry,
    english,
    french,
    total,
    finish

}Sbjct_t;

//*************************************************
// aliases names to used in switch cases
// to edit the student account
typedef enum
{
    NAME,
    DATE,
    ADDRESS,
    NUMBER,
    FINISH

}stdnt_data_t;



//*************************************************
// structure of student data

typedef struct student
{
    char name[50];
    char date[10];
    char address[10];
    long int number;
    int ID;
    float score;
    int sbjcts[SBJCTS_NUM]; // array of subjects scores

}Student;


//*************************************************
// structure of node that has the student data
// and two pointers of double queue
typedef struct Node
{
    Student entry;
    struct Node *pNext;
    struct Node *pPrev;

}QueueNode;



//*************************************************
// structure of Queue that has two pointers
// point to the first and the last node of the structure

typedef struct
{
    QueueNode *Front;
    QueueNode *rear;
    int Size;
}Queue;


/*************************************************

        functions prototypes

*************************************************/

// the main functions
void New_Student(Queue * ptr_q );
void delete_Student(Queue *p_Queue);
void Rank_Student(Queue *p_Queue);          //print according score
void Stdnt_Sbjcts_score(Queue *p_Queue);    // update students score
void Print_Students_Data(Queue *p_Queue);   // print random
void Students_List(Queue *p_Queue);         // print according Alphabetically
void Student_Edit(Queue *p_Queue);
void Prnt_Subs_Scr(Queue *p_Queue);         // print the subjects score
void MAIN_MENU(void);                       // print welcome screen


// sub functions to handle the program
float total_avrge(QueueNode *p_Node);
void Create_Queue(Queue * ptr_q);
void input_Data(Queue *ptr_q);
void Print_Data(QueueNode *p_Temp);
void Swap(Queue *p_Queue ,QueueNode *pNode1 ,QueueNode *pNode2 );


#endif // HEADER_H_INCLUDED
