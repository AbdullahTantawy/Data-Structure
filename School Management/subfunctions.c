#include"header.h"

//**************************************************************************************************************

//              print the subjects score

//**************************************************************************************************************

void Prnt_Subs_Scr(Queue *p_Queue)
{
    QueueNode *p_Temp = p_Queue->Front;

        printf(" \n \t\t\t\t>>>>>>>>>> Students score <<<<<<<<<<<<<\n");
printf("____________________________________________________________________________________________________________________\n");
         printf(" \t Name \t\t| Math\t | comp-science "
                " | Physics   | Chemistry  | English \t | French \t | Score \n");
printf("____________________________________________________________________________________________________________________");
        while(p_Temp)
        {
            printf("\n %15s  \t   %d \t",p_Temp->entry.name ,p_Temp->entry.sbjcts[math]);
            printf("\t  %d",p_Temp->entry.sbjcts[comp_snce]);
            printf("\t %5d",p_Temp->entry.sbjcts[physics]);
            printf(" %12d",p_Temp->entry.sbjcts[chemistry]);
            printf("\t %8d",p_Temp->entry.sbjcts[english]);
            printf("\t %8d",p_Temp->entry.sbjcts[french]);
            printf("\t  %7.2f %%\n",p_Temp->entry.score);
printf("____________________________________________________________________________________________________________________");
            p_Temp = p_Temp->pNext;
        }// while
}

/***********************************************************************************************************************

                                create the Queue

************************************************************************************************************************/

void Create_Queue(Queue * ptr_q)
{
    ptr_q->Front = NULL;
    ptr_q->rear  = NULL;
    ptr_q->Size  = 0;
}



/***********************************************************************************************************************

                            Function to swap the nodes

************************************************************************************************************************/


void Swap(Queue *p_Queue ,QueueNode *pNode1 ,QueueNode *pNode2 )
{
    QueueNode *p_Temp = pNode1;

    if(!(pNode1->pPrev)) //in case if the the first node in the swap
    {
        // make the front pointer points to the second node
        p_Queue->Front = pNode2;
        //make the previous pointer of the third node points to the first node
        pNode2->pNext->pPrev = pNode1;

    }
    else if(!(pNode2->pNext)) // in case if the last node in the swap
    {
        // make the rear pointer points to the first node
        p_Queue->rear = pNode1;
        //make the next pointer of the node before the first points to the second node
        pNode1->pPrev->pNext    = pNode2;

    }
    else
    {
        pNode1->pPrev->pNext = pNode2;
        pNode2->pNext->pPrev = pNode1;
    }

    pNode1->pNext = pNode2->pNext;
    pNode2->pPrev = pNode1->pPrev;

    pNode1->pPrev = pNode2;
    pNode2->pNext = pNode1;

    pNode1 = pNode2;
    pNode2 = p_Temp;

}


/***********************************************************************************************************************

                            function to print a student data

************************************************************************************************************************/

void Print_Data(QueueNode *p_Temp) // print one student
{
        printf(" \n \t\t\t\t>>>>>>>>>> Student data <<<<<<<<<<<<<\n");
printf("____________________________________________________________________________________________________________________");
          printf("\n\t  Name \t     |\t ID \t|   Score %% \t|\t Number \t| Address\t|     Date \n");
printf("____________________________________________________________________________________________________________________");
            printf("\n %15s     |   %d ",p_Temp->entry.name ,p_Temp->entry.ID);
            printf("\t|  %2.2f %% ",p_Temp->entry.score);
            printf("\t|\t 0%ld",p_Temp->entry.number);
            printf("\t| %10s",p_Temp->entry.address);
            printf("\t| %10s\n",p_Temp->entry.date);
printf("____________________________________________________________________________________________________________________");
}// print function


/***********************************************************************************************************************

                            List the students According score

************************************************************************************************************************/


void Rank_Student(Queue *p_Queue)
{
    int i,k,count=0;
   QueueNode *pTemp;
   for(i=0; i < p_Queue->Size ;i++)
     {
       pTemp = p_Queue->Front;
       for(k=0; k < p_Queue->Size-1 ;k++)
            {
                if( pTemp->entry.score < pTemp->pNext->entry.score )
                    {
                        Swap(p_Queue,pTemp,pTemp->pNext);
                        count++;

                    }//if character greater than the next
                // else if characters are equal

                else
                {
                    pTemp = pTemp->pNext;
                }

            } // inner loop

            if(count == 0)
            {
                break;
            }
     } // outer loop

     printf(" \n \t\t\t\t        (( According score )) \n\n");
    Print_Students_Data(p_Queue);
}


/***********************************************************************************************************************

                                        MAIN MENU

************************************************************************************************************************/

void MAIN_MENU(void)
{
    printf(" \n\n\n\t\t\t\t\t"
           " Welcome to our Program \n\n\t\t\t\t"
           " (((((  School Management System  )))))\n\n\t\t\t\t\t"
           " The Targeted Activities  \n");
}

