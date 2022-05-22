

#include"header.h"


/***********************************************************************************************************************

                            function to store the students data

************************************************************************************************************************/


void input_Data(Queue *ptr_q)
{

    //**** reserve a node of structure in the memory
   QueueNode *ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n)
   {

        strcpy(ptr_n->entry.name,"Rania Salah");
        strcpy(ptr_n->entry.address," Sharqia ");
        strcpy(ptr_n->entry.date," 24/12/95");
        ptr_n->entry.ID = 1000;
        ptr_n->entry.score = 100;
        ptr_n->entry.number = 1157136461;
        ptr_n->entry.sbjcts[math]      = 15;
        ptr_n->entry.sbjcts[chemistry] = 14;
        ptr_n->entry.sbjcts[physics]   = 12;
        ptr_n->entry.sbjcts[comp_snce] = 11;
        ptr_n->entry.sbjcts[french]    = 13;
        ptr_n->entry.sbjcts[english]   = 15;
        ptr_n->entry.score   = total_avrge(ptr_n);

      //******************************************

      ptr_n->pNext= NULL; // the next address points to NULL
      if(!(ptr_q->rear)) // check if the there are no nodes
       {
            ptr_q->Front = ptr_n; // make the front points to the new node
            ptr_n->pPrev = NULL;  // the previous  of node points to NULL
       }
     else
      {
           ptr_n->pPrev= ptr_q->rear;
           ptr_q->rear->pNext = ptr_n;
      }
     ptr_q->rear = ptr_n;
     ptr_q->Size ++;
   }
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }

   //************************************************************************************************

   //**** reserve a node of structure in the memory
    ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n)
   {

        strcpy(ptr_n->entry.name,"Abdullah Salah");
        strcpy(ptr_n->entry.address," cairo ");
        strcpy(ptr_n->entry.date," 1/1/95");
        ptr_n->entry.ID = 1001;
        ptr_n->entry.score = 99;
        ptr_n->entry.number = 1157136461;
        ptr_n->entry.sbjcts[math]      = 15;
        ptr_n->entry.sbjcts[chemistry] = 14;
        ptr_n->entry.sbjcts[physics]   = 12;
        ptr_n->entry.sbjcts[comp_snce] = 11;
        ptr_n->entry.sbjcts[french]    = 13;
        ptr_n->entry.sbjcts[english]   = 15;
         ptr_n->entry.score   = total_avrge(ptr_n);

      //******************************************
      ptr_n->pNext= NULL;
      if(!(ptr_q->rear))
       {
            ptr_q->Front = ptr_n;
            ptr_n->pPrev = NULL;
       }
     else
      {
           ptr_n->pPrev= ptr_q->rear;  // the previous of node points to the last node (rear)
           ptr_q->rear->pNext = ptr_n; // make the next of the last node points to the new node
      }
     ptr_q->rear = ptr_n; // make the rear pointer points to the last node (new node)
     ptr_q->Size ++;  // increase the size by one
   }// if   DMA is done successfully
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }

   //************************************************************************************************

   //**** reserve a node of structure in the memory
    ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n)
   {

        strcpy(ptr_n->entry.name,"Mohamed Salah");
        strcpy(ptr_n->entry.address," Alex ");
        strcpy(ptr_n->entry.date," 3/4/95");
        ptr_n->entry.ID = 1002;
        ptr_n->entry.score = 98;
        ptr_n->entry.number = 1157136461;
       ptr_n->entry.sbjcts[math]      = 15;
        ptr_n->entry.sbjcts[chemistry] = 14;
        ptr_n->entry.sbjcts[physics]   = 12;
        ptr_n->entry.sbjcts[comp_snce] = 10;
        ptr_n->entry.sbjcts[french]    = 13;
        ptr_n->entry.sbjcts[english]   = 15;
         ptr_n->entry.score   = total_avrge(ptr_n);

      //******************************************
      ptr_n->pNext= NULL;
      if(!(ptr_q->rear))
       {
            ptr_q->Front = ptr_n;
            ptr_n->pPrev = NULL;
       }
     else
      {
           ptr_n->pPrev= ptr_q->rear;
           ptr_q->rear->pNext = ptr_n;
      }
     ptr_q->rear = ptr_n;
     ptr_q->Size ++;
   }
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }

      //************************************************************************************************

   //**** reserve a node of structure in the memory
    ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n)
   {

        strcpy(ptr_n->entry.name,"Belal Sayed");
        strcpy(ptr_n->entry.address," cairo ");
        strcpy(ptr_n->entry.date," 1/1/95");
        ptr_n->entry.ID = 1003;
        ptr_n->entry.score = 97;
        ptr_n->entry.number = 1157136461;
       ptr_n->entry.sbjcts[math]      = 15;
        ptr_n->entry.sbjcts[chemistry] = 14;
        ptr_n->entry.sbjcts[physics]   = 12;
        ptr_n->entry.sbjcts[comp_snce] = 15;
        ptr_n->entry.sbjcts[french]    = 13;
        ptr_n->entry.sbjcts[english]   = 15;
         ptr_n->entry.score   = total_avrge(ptr_n);

      //******************************************
      ptr_n->pNext= NULL;
      if(!(ptr_q->rear))
       {
            ptr_q->Front = ptr_n;
            ptr_n->pPrev = NULL;
       }
     else
      {
           ptr_n->pPrev= ptr_q->rear;
           ptr_q->rear->pNext = ptr_n;
      }
     ptr_q->rear = ptr_n;
     ptr_q->Size ++;
   }
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }
      //************************************************************************************************

   //**** reserve a node of structure in the memory
    ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n)
   {

        strcpy(ptr_n->entry.name,"Sayed Magdy");
        strcpy(ptr_n->entry.address," cairo ");
        strcpy(ptr_n->entry.date," 1/1/95");
        ptr_n->entry.ID = 1004;
        ptr_n->entry.score = 96;
        ptr_n->entry.number = 1157136461;
        ptr_n->entry.sbjcts[math]     = 15;
        ptr_n->entry.sbjcts[chemistry] = 14;
        ptr_n->entry.sbjcts[physics]   = 12;
        ptr_n->entry.sbjcts[comp_snce] = 14;
        ptr_n->entry.sbjcts[french]    = 13;
        ptr_n->entry.sbjcts[english]   = 15;
        ptr_n->entry.score   = total_avrge(ptr_n);

      //******************************************
      ptr_n->pNext= NULL;
      if(!(ptr_q->rear))
       {
            ptr_q->Front = ptr_n;
            ptr_n->pPrev = NULL;
       }
     else
      {
           ptr_n->pPrev= ptr_q->rear;
           ptr_q->rear->pNext = ptr_n;
      }
     ptr_q->rear = ptr_n;
     ptr_q->Size ++;
   }
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }
   //************************************************************************************************
   //**** reserve a node of structure in the memory
    ptr_n =(QueueNode *) malloc(sizeof(QueueNode));
   if(ptr_n)
   {

        strcpy(ptr_n->entry.name,"Abdullah Mohamed");
        strcpy(ptr_n->entry.address," Alex ");
        strcpy(ptr_n->entry.date," 1/1/95");
        ptr_n->entry.ID = 1005;
        ptr_n->entry.score = 95;
        ptr_n->entry.number = 1157136461;
        ptr_n->entry.sbjcts[math]      = 15;
        ptr_n->entry.sbjcts[chemistry] = 14;
        ptr_n->entry.sbjcts[physics]   = 12;
        ptr_n->entry.sbjcts[comp_snce] = 9;
        ptr_n->entry.sbjcts[french]    = 13;
        ptr_n->entry.sbjcts[english]   = 15;
        ptr_n->entry.score   = total_avrge(ptr_n);

      //******************************************
      ptr_n->pNext= NULL;
      if(!(ptr_q->rear))
       {
            ptr_q->Front = ptr_n;
            ptr_n->pPrev = NULL;
       }
     else
      {
           ptr_n->pPrev= ptr_q->rear;
           ptr_q->rear->pNext = ptr_n;
      }
     ptr_q->rear = ptr_n;
     ptr_q->Size ++;
   }
   else
   {
       printf("the Heap is full Or DMA is failed ");

   }


}


/***********************************************************************************************************************

                  // function to calculate the percentage of score

************************************************************************************************************************/

float total_avrge(QueueNode *p_Node)
{
    int i,sum=0;
    float avg;

    for(i=0;i<SBJCTS_NUM;i++)
    {
        sum += p_Node->entry.sbjcts[i];

    }
        avg=((float)sum /(TOTAL_SCORE)*100);

    return avg;
}
