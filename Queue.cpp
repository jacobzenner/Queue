/****************************************************************************
*** NAME : Jacob Zenner                                                   ***
*** CLASS : CSc 300                                                       ***
*** ASSIGNMENT : 4                                                        ***
*** DUE DATE : 10/17/2022                                                 ***
*** INSTRUCTOR : GAMRADT                                                  ***
*** DESCRIPTION : This cpp file contains the member functions for the     *** 
*** Queue class                                                           ***
****************************************************************************/

#include "Queue.h"
#include <iostream>

using namespace std;

/****************************************************************************
*** FUNCTION Queue                                                        ***
*****************************************************************************
*** DESCRIPTION : This function is the constructor for the class          ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
Queue::Queue(const short num) : queue(nullptr), front(-1), back(-1), Q_SIZE(num)
{
    queue = new(std::nothrow) QElement [Q_SIZE];
}


/****************************************************************************
*** FUNCTION Queue                                                        ***
*****************************************************************************
*** DESCRIPTION : This function is the copy constructor for the class     ***
*** INPUT ARGS  : Queue & old                                             ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
Queue::Queue(Queue & old) : queue(nullptr), front(-1), back(-1), Q_SIZE(old.Q_SIZE)
{
    queue = new(std::nothrow) QElement [Q_SIZE];
    QElement num; 
    Queue temp(Q_SIZE);
    while(!old.isEmpty())
    {
        old.deQueue(num);
        temp.enQueue(num);
    }
    while(!temp.isEmpty())
    {
        temp.deQueue(num);
        old.enQueue(num);
        enQueue(num);
    }
}

/****************************************************************************
*** FUNCTION ~Queue                                                       ***
*****************************************************************************
*** DESCRIPTION : This function is the destructor for the class which     ***
***  deletes every element in the queue                                   ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
Queue::~Queue()
{
    QElement num;
    while(!isEmpty())
    deQueue(num);
}


/****************************************************************************
*** FUNCTION enQueue                                                      ***
*****************************************************************************
*** DESCRIPTION : This function adds an element to the queue              ***                                
*** INPUT ARGS  : const QElement num                                      ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Queue::enQueue(const QElement num)
{
    if(isFull())
    {
        cout << "The Queue is full, the element " << num << " was not added." << endl;
        return;
    }
    else if(isEmpty())
    {
        front ++;
        back ++;
    }
    else
    {
        back++;
    }
    queue[back] = num;
}

/****************************************************************************
*** FUNCTION deQueue                                                      ***
*****************************************************************************
*** DESCRIPTION : This function removes an element from the queue         ***                                
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : QElement & num                                          ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Queue::deQueue(QElement & num)
{
    
    if(isEmpty())
    {
    cout << "The Queue is Empty-- No element was removed" << endl;
    return;
    }
    else if(front == back)
    {
        num = queue[front];
        front = -1;
        back = -1;
    }
    else
    {
        num = queue[front];
        front++;
    }
}


/****************************************************************************
*** FUNCTION view                                                         ***
*****************************************************************************
*** DESCRIPTION : This function prints all the elements in the queue      ***                                
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Queue::view()
{
    QElement num;
    Queue temp(Q_SIZE);
    
    cout << "FRONT -> ";

    while(!isEmpty())
    {
        deQueue(num);
        cout << num << " -> ";
        temp.enQueue(num);
    }
    
    cout << "BACK" << endl;

    while(!temp.isEmpty())
    {
        temp.deQueue(num);
        enQueue(num);
    }


}

/****************************************************************************
*** FUNCTION isEmpty                                                      ***
*****************************************************************************
*** DESCRIPTION : This function checks if the queue is empty              ***                                
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : Boolean                                                 *** 
****************************************************************************/
bool Queue::isEmpty()const
{
    if(front==-1 && back == -1)
    return true;
    else return false;
}

/****************************************************************************
*** FUNCTION isFull                                                       ***
*****************************************************************************
*** DESCRIPTION : This function checks if the queue is full               ***                                
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : Boolean                                                 *** 
****************************************************************************/
bool Queue::isFull()const
{
    if((back+1)%Q_SIZE == front)
    return true;
    else return false;
}

