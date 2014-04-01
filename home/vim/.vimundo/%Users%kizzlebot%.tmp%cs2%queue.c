Vim�UnDo� Y�����r,�s��3�U%a���N�DU>��o+   n   #include "queue.c"                             R�H\    _�                             ����                                                                                                                                                                                                                                                                                                                                                             R�G     �         �       5�_�                    )        ����                                                                                                                                                                                                                                                                                                                            )          :          V       R�GP     �   (   )          F    // Enqueue one more item, then try several dequeues and one front.       enqueue(MyQueuePtr, 2);   0    printf("Dequeue %d\n", dequeue(MyQueuePtr));   =    printf("At Front of Queue Now: %d\n", front(MyQueuePtr));   0    printf("Dequeue %d\n", dequeue(MyQueuePtr));   0    printf("Dequeue %d\n", dequeue(MyQueuePtr));          +    // See if we can detect an empty queue.   0    printf("Is empty: %d\n", empty(MyQueuePtr));          G    // Try enqueuing and dequeuing again to make sure that our previous   -    // operations didn't "corrupt" the queue.       enqueue(MyQueuePtr, 5);       enqueue(MyQueuePtr, 9);   0    printf("Dequeue %d\n", dequeue(MyQueuePtr));   0    printf("Dequeue %d\n", dequeue(MyQueuePtr));              system("PAUSE");5�_�                    (       ����                                                                                                                                                                                                                                                                                                                            )          )          V       R�GS     �   (   *   �    5�_�                            ����                                                                                                                                                                                                                                                                                                                            *          *          V       R�GU    �   �   �          K// Post-condition: if the queue pointed to by qPtr is non-empty, the value �   }                 �   z   |                  �   u   w              �   r   t              �   o   q                  �   l   n              �   h   j              �   e   g              �   a   c          K//                 at the front of the queue is deleted from the queue and �   \   ^                  return 0;   �   X   Z              �   T   V                  �   O   Q                  �   L   N                  �   G   I                  �   C   E                       �   @   B              �   =   ?              �   0   2               �   '   )              �   $   &              �      !              �                    5�_�                    ,        ����                                                                                                                                                                                                                                                                                                                            ,           ,           V        R�G^     �   +   -   �       5�_�                            ����                                                                                                                                                                                                                                                                                                                                       +           V        R�G�     �                int main() {       6    // Allocate space for our queue and initialize it.   K    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));       init(MyQueuePtr);           // Enqueue some items.       enqueue(MyQueuePtr, 3);       enqueue(MyQueuePtr, 7);       enqueue(MyQueuePtr, 4);           // Try one dequeue.   0    printf("Dequeue %d\n", dequeue(MyQueuePtr));               return 0;   }5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        R�H     �                void init(struct queue* qPtr);   )int enqueue(struct queue* qPtr, int val);    int dequeue(struct queue* qPtr);   int empty(struct queue* qPtr);   int front(struct queue* qPtr);    5�_�      	              	        ����                                                                                                                                                                                                                                                                                                                                       	           V        R�H     �      	          &// Stores one node of the linked list.   struct node {       int data;       struct node* next;   };       // Stores our queue.   struct queue {       struct node* front;       struct node* back;   };    5�_�      
           	           ����                                                                                                                                                                                                                                                                                                                            	           	           V        R�H     �         o       5�_�   	              
      
    ����                                                                                                                                                                                                                                                                                                                            	           	           V        R�H     �         o      
#include "5�_�   
                         ����                                                                                                                                                                                                                                                                                                                                                V       R�H0    �                #define EMPTY -15�_�                            ����                                                                                                                                                                                                                                                                                                                                                             R�H[    �         n      #include "queue.c"5��