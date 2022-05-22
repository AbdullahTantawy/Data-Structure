
#include"header.h"




/***********************************************************************************************************************

                                    Add New Student

************************************************************************************************************************/

void New_Student(Queue * pQueue)
{
    // variable and pointer to determine the ID
    int scan=1000;
    QueueNode *pTemp = pQueue->Front;
    //**** create a node of structure in the memory
   QueueNode *ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n) // if the heap full or failed
   {
       //-----------------------------------------------------------------
       //receive the data from user
     printf("\n\n\t\t Enter the student Data :::: \n");
       //***** receive the data of student from user
      printf(" Name     : ");
      fflush(stdin); // to delete the enter character
      scanf("%[^\n]s",ptr_n->entry.name);
      printf(" Number   : ");
      scanf("%ld",&ptr_n->entry.number);
      printf(" Address  : ");
      fflush(stdin);
      scanf("%[^\n]s",ptr_n->entry.address);
      printf("BirthDate : ");
      fflush(stdin);
      scanf("%[^\n]s",ptr_n->entry.date);
      //-------------------------------------------------
      //initialize the score and the subjects to 0 to avoid garbage values
      ptr_n->entry.score = 0.00;
      for(int i=0;i<SBJCTS_NUM;i++)
      {
          ptr_n->entry.sbjcts[i] = 0.00;
      }
      //-------------------------------------------------
      // create an ID to the new student
      for(int i=0;i<pQueue->Size;i++)
      {
          if(scan == pTemp->entry.ID)
          {
              scan+=1;
              pTemp = pTemp->pNext;
          }
          else
          {
              break;
          }
          ptr_n->entry.ID = scan;
      }

      // print the student data stored
      Print_Data(ptr_n);

      //******************************
                //Modify the pointers of the Queue and nodes after adding the new student
      //******************************
      ptr_n->pNext= NULL;  // the next of the new node points to NULL
      if(!(pQueue->rear)) //if there is no nodes in the queue
       {
            pQueue->Front = ptr_n;  // make the front points to the new node
            ptr_n->pPrev = NULL;    // the previous  of node points to NULL
       }
     else
      {
           ptr_n->pPrev= pQueue->rear;  // the previous  of node points to the last node (rear)
           pQueue->rear->pNext = ptr_n; // the next of last node points to the new node
      }

     pQueue->rear = ptr_n; //the rear points to the new node

     pQueue->Size ++; // increase size
   }// if DMA
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }

}


/***********************************************************************************************************************

                                    Delete a Student Account

************************************************************************************************************************/

void delete_Student(Queue *p_Queue)
{
    int flag=1;
    int id; // flag to break the while loop
    char str_name[50]; // to print the student deleted name
    QueueNode *pTemp = p_Queue->Front;
    printf(" \n ------>>>>>>> please enter the ID of student TO DELETE :  ");
    scanf("%d",&id);
    // loop to check if the target is found
    //  the target not found
    while( flag && pTemp)
    {
        if( pTemp->entry.ID == id )
        {
            // if the previous is null And the next is null
            // it will be the only student in the Queue
            if( !(pTemp->pNext) && !(pTemp->pPrev))
            {
                //print the name
                strcpy(str_name,pTemp->entry.name);
                //make the rear and the front points to NULL
                p_Queue->rear =NULL;
                p_Queue->Front = NULL;
                // delete the node
                free(pTemp);
                printf("\n\n >>>>> %s   Account is deleted successfully  && the Queue is EMPTY ",str_name);
                flag = 0;
            }
             // if the next is null it will be the last student
            else if( !(pTemp->pNext))
            {
                //print the name
                strcpy(str_name,pTemp->entry.name);
                //1-make the rear pointer points to the previous node
                p_Queue->rear = pTemp->pPrev;
                //2-make the previous of the target node points to the NULL
                p_Queue->rear->pNext = NULL;
                //2- delete the target node
                free(pTemp);
                printf("\n\n >>>>> %s   Account is deleted successfully ",str_name);
                // break the loop
                flag = 0;

            } //else if the last student in the queue
            // if the previous is NULL it will be the fist in the Queue
            else if( !(pTemp->pPrev))
            {
                strcpy(str_name,pTemp->entry.name);
                p_Queue->Front = pTemp->pNext;
                p_Queue->Front->pPrev = NULL;
                free(pTemp);
                printf("\n\n >>>>> %s Account is deleted successfully ",str_name);
                flag = 0;

            } //if the first student int queue

            else  // the student in the middle
            {
                // print the Student name
                strcpy(str_name,pTemp->entry.name);
                // 1-make the previous node points to the next
                pTemp->pPrev->pNext = pTemp->pNext;
                // 2-make the next node points to the previous
                pTemp->pNext->pPrev = pTemp->pPrev;
                // 3-delete the the target node
                free(pTemp);
                printf("\n\n >>>>> %s   Account is deleted successfully ",str_name);
                //this flag to break the loop
                flag=0;

            } // else if the student not the first

        } // if comparing the id
        else
        {
            pTemp = pTemp->pNext;
        } // else of // if comparing the id

    }//while loop to comparison

    if(flag == 1)
    {
        printf(" >>>>>>>>>>> this ID not found ");
    }
    else
    {
         p_Queue->Size --;
    }

}// delete function

/***********************************************************************************************************************

                                    print Students data according Alphabetically

************************************************************************************************************************/

void Students_List(Queue *p_Queue)
{

   int i,j,k,count=0; //for loops
   QueueNode *pTemp; // create a temporary pointer to move from node to next
   //outer loop to check the all nodes
   for(i=0; i < p_Queue->Size ;i++)
     {
       pTemp = p_Queue->Front; // make the temp pointer points to the first node

       for(k=0; k < p_Queue->Size-i-1 ;k++) //inner loop to compare each node with all nodes
            {
                //if to compare the characters
                if( pTemp->entry.name[0] > pTemp->pNext->entry.name[0] )
                    {
                        Swap(p_Queue,pTemp,pTemp->pNext);
                        count++;

                    }//if character greater than the next
                // else if characters are equal
                else if( pTemp->entry.name[0] == pTemp->pNext->entry.name[0])
                    {
                        j=1;
                        //loop to check the second and third to 15th characters
                        while(j<15)
                            {
                                //if the character is greater than -> swap and break
                                if(pTemp->entry.name[j] > pTemp->pNext->entry.name[j])
                                    {
                                        Swap(p_Queue,pTemp,pTemp->pNext);
                                        count++;
                                        break;
                                    }
                                    //else if smaller than -> break
                                else if(pTemp->entry.name[j] < pTemp->pNext->entry.name[j])
                                    {
                                        break;
                                    }
                                    // if equal increase the array index to check the next characters
                                    j++;
                            } // ending of loop to check the other characters if equal
                    } // else if characters are equal
                    // else not equal or greater increase the nodes and check again
                else
                {
                    pTemp = pTemp->pNext;
                }

            } // inner loop
            // no any swap done so they are sorted so don't continue and break the outer loop
            if(count == 0)
            {
                break;
            }
     } // outer loop


    printf(" \n \t\t\t\t         (( Alphabetically )) \n");
    Print_Students_Data(p_Queue);
}//Students_List


/***********************************************************************************************************************

                                   Edit a Student data

************************************************************************************************************************/


void Student_Edit(Queue *p_Queue)
{
    int flag=1,out_flag = 0,id; // flag to break the while loop
    // two arrays of string to print the student deleted name
    char str_name[50] ,str_scan[10];
    int scan;
    QueueNode *pTemp = p_Queue->Front;


    printf(" \n ----->>>>>>> please enter the ID of student to EDIT : ");
    scanf("%d",&id);


    // loop to check if the target is found or the target not found
    // flag to break the loop if the id founded
    while( flag && pTemp)
    {
        if( pTemp->entry.ID == id )
        {
            //print the data of targeted student
            Print_Data(pTemp);
            while(!(out_flag)) // loop to edit multiple choices and finish if user need
                {
                    printf( "\n\n select your edit :: press \n"
                            " 0 --> Name\t  1 --> Date\t 2 --> Address \t 3 --> Number \t 4--> Finish : ");

                            scanf("%d",&scan);

                    switch(scan)
                        {
                        case NAME:
                            {
                                printf(" \n enter the new Name : ");
                                fflush(stdin);
                                scanf("%[^\n]s",str_name);
                                strcpy(pTemp->entry.name ,str_name);

                                break;
                            }

                        case DATE:
                            {
                                printf(" enter the new BirthDate : ");
                                fflush(stdin);
                                fgets(str_scan,10,stdin);
                                strcpy(pTemp->entry.date , str_scan);
                                break;
                            }
                        case ADDRESS:
                            {
                                printf(" Address  : ");
                                fflush(stdin);
                                scanf("%[^\n]s",str_scan);
                                strcpy(pTemp->entry.address ,str_scan);
                                break;
                            }
                        case NUMBER:
                            {
                                printf(" Number   : ");
                                scanf("%ld",&pTemp->entry.number);
                                break;
                            }

                        case FINISH:
                            {
                                out_flag=1; // to end the edit loop
                                break;
                            }
                        default:
                            {
                                printf("\n >>>>>>> wrong input \n");
                                break;
                            }
                        }//END OF SWITCH CASE

                } // while
           flag = 0; // to break the loop of searching for id after finishing the edit

        }// if id matches
        else
        {
            pTemp = pTemp->pNext;
        }// else
    } // end while loop
    if(flag == 1)
    {
        printf("\n >>>>>>> this ID not exist <<<<<<<");
    }
} // EDIT function



/***********************************************************************************************************************

                            print the Students data

************************************************************************************************************************/

void Print_Students_Data(Queue *p_Queue)
{
    //create a temporary pointer to traverse all student
    // and make it points to the first student
    QueueNode *p_Temp = p_Queue->Front;
    printf(" \n \t\t\t\t>>>>>>>>>> Students list <<<<<<<<<<<<<\n");

printf("____________________________________________________________________________________________________________________");
         printf("\n\t  Name \t     |\t ID \t|   Score %% \t|\t Number \t| Address\t|     Date \n");
printf("____________________________________________________________________________________________________________________");
        while(p_Temp)
        {
            printf("\n %15s     |   %d ",p_Temp->entry.name ,p_Temp->entry.ID);
            printf("\t|  %2.2f %% ",p_Temp->entry.score);
            printf("\t|\t 0%ld",p_Temp->entry.number);
            printf("\t| %10s",p_Temp->entry.address);
            printf("\t| %10s\n",p_Temp->entry.date);
printf("_____________________________________________________________________________________________________________________");
            // make the pointer points to the next student (node)
            p_Temp = p_Temp->pNext;
        }// while

}// print function


/***************************************************************************

                update the subjects scores of the students

**************************************************************************/

void Stdnt_Sbjcts_score(Queue *p_Queue)
{
    int scan,out_flag=1;
    //create a pointer to traverse the all students
    QueueNode *pTemp = p_Queue->Front;



    while(out_flag){ // loop to update more than a subject score

            // make the pointer points to the first node(student)
            pTemp = p_Queue->Front;
            printf("\n>>>> Select the Subject <<<<<<\n"
                   "\n  :: press \n"
                    " 0 --> Math\t 1 --> computer science\t "
                    "2 --> Physics \t 3 --> Chemistry  \t 4 --> English \t 5--> French \t 7--> Finish : ");
        scanf("%d",&scan);
        // switch the subject selected by user
        switch(scan)
        {
        case math:
            {
                printf(" \n >>>>>>>>>>>>>>>>>> MATH Score <<<<<<<<<<<<<<<<\n");
                while(pTemp)
                    {
                        printf("\n %15s : ",pTemp->entry.name);
                        scanf("%d",&pTemp->entry.sbjcts[math]);
                        //pass this values to update the total grade
                        pTemp->entry.score = total_avrge(pTemp);
                        pTemp = pTemp->pNext;
                    }
                break;
            }
         case comp_snce:
            {
                printf(" \n >>>>>>>>>>>>>>>>>> CMPTR_SNCE Score <<<<<<<<<<<<<<<<\n");
                while(pTemp)
                    {
                        printf("\n %15s : ",pTemp->entry.name);
                        scanf("%d",&pTemp->entry.sbjcts[comp_snce]);
                        pTemp->entry.score = total_avrge(pTemp);
                        pTemp = pTemp->pNext;
                    }
                break;
            }
         case physics:
            {
                printf(" \n >>>>>>>>>>>>>>>>>> PHYSICS Score <<<<<<<<<<<<<<<<\n");
                while(pTemp)
                    {
                        printf("\n %15s : ",pTemp->entry.name);
                        scanf("%d",&pTemp->entry.sbjcts[physics]);
                        pTemp->entry.score = total_avrge(pTemp);
                        pTemp = pTemp->pNext;
                    }
                break;
            }
         case chemistry:
            {
                printf(" \n >>>>>>>>>>>>>>>>>> CHEMISTRY Score <<<<<<<<<<<<<<<<\n");
                while(pTemp)
                    {
                        printf("\n %15s : ",pTemp->entry.name);
                        scanf("%d",&pTemp->entry.sbjcts[chemistry]);
                        pTemp->entry.score = total_avrge(pTemp);
                        pTemp = pTemp->pNext;
                    }
                break;
            }
         case english:
            {
                printf(" \n >>>>>>>>>>>>>>>>>> ENGLISH Score <<<<<<<<<<<<<<<<\n");
                while(pTemp)
                    {
                        printf("\n %15s : ",pTemp->entry.name);
                        scanf("%d",&pTemp->entry.sbjcts[english]);
                        pTemp->entry.score = total_avrge(pTemp);
                        pTemp = pTemp->pNext;
                    }
                break;
            }
        case french:
            {
                printf(" \n >>>>>>>>>>>>>>>>>> FRENCH Score <<<<<<<<<<<<<<<<\n");
                while(pTemp)
                    {
                        printf("\n %15s : ",pTemp->entry.name);
                        scanf("%d",&pTemp->entry.sbjcts[french]);
                        pTemp->entry.score = total_avrge(pTemp);
                        pTemp = pTemp->pNext;
                    }
                break;
            }
        case finish:
            {
                // to break the loop and return to the main menu
                out_flag=0;
                break;
            }
        default:
            {
                // in case of the user enter a wrong input
                printf("\n wrong input ");
                break;
            }

       }// switch
    }//while
}// end the function


/***********************************************************************************************************************


************************************************************************************************************************/

