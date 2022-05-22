#include"header.h"

int main()
{
    Queue school; // create a Queue
    Create_Queue(&school); // initialize the Queue
    int scan;

    // array of functions (pointer)
    void (*ptr_to_fun[])(Queue *ptr_q)={New_Student,delete_Student,Print_Students_Data
    ,Students_List,Student_Edit,Rank_Student,Stdnt_Sbjcts_score,Prnt_Subs_Scr};

     MAIN_MENU();
     input_Data(&school);
     //Print_Students_Data(&school);


     while(1)
        {
            //print the targeted activities
            printf( "\n\n select your operation :: press \n\n"
                    " 0 --> ADD New Student\t\t 1 --> DELETE Account\t\t"
                    " 2 --> PRINT the list \t\t  \n"
                    " 3 --> PRINT (Alphabetically) \t 4--> EDIT Account \t\t 5-->PRINT (According score)"
                    "\n 6 --> Update subjects score \t 7--> print Subjects score \t 8 --> EXIT : ");
            scanf("%d",&scan);
            //Array of pointers ================================
            // call the targeted function
            ptr_to_fun[scan](&school);

      } // while
      return 0;
}


