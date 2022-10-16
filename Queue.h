/****************************************************************************
*** NAME : Jacob Zenner                                                   ***
*** CLASS : CSc 300                                                       ***
*** ASSIGNMENT : 4                                                        ***
*** DUE DATE : 10/5/2022                                                  ***
*** INSTRUCTOR : GAMRADT                                                  ***
*** DESCRIPTION : This h file defines a Queue class which has the member  *** 
*** functions enQueue, deQueue, and view                                  ***
****************************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

typedef double QElement;

class Queue {
    public:

        /****************************************************************************
        *** FUNCTION Queue                                                        ***
        *****************************************************************************
        *** DESCRIPTION : This function is the constructor for the class          ***
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        explicit Queue(const short num = 3);

        /****************************************************************************
        *** FUNCTION Queue                                                        ***
        *****************************************************************************
        *** DESCRIPTION : This function is the copy constructor for the class     ***
        *** INPUT ARGS  : Queue & old                                             ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        Queue(Queue &);

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
        ~Queue();

        /****************************************************************************
        *** FUNCTION enQueue                                                      ***
        *****************************************************************************
        *** DESCRIPTION : This function adds an element to the queue              ***                                
        *** INPUT ARGS  : const QElement                                          ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        void enQueue(const QElement);

        /****************************************************************************
        *** FUNCTION deQueue                                                      ***
        *****************************************************************************
        *** DESCRIPTION : This function removes an element from the queue         ***                                
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : QElement &                                              ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        void deQueue(QElement &);


        /****************************************************************************
        *** FUNCTION view                                                         ***
        *****************************************************************************
        *** DESCRIPTION : This function prints all the elements in the queue      ***                                
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        void view();
    private:
        const short Q_SIZE;
        typedef QElement * QPointer;
        QPointer queue;
        short front, back;
        bool isEmpty() const;
        bool isFull() const;
};

#endif