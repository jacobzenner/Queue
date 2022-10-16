/*****************************************************************************
*** NAME : Jacob Zenner                                                    ***
*** CLASS : CSc 300                                                        ***
*** ASSIGNMENT : 4                                                         ***
*** DUE DATE : 10/17/2022                                                  ***
*** INSTRUCTOR : GAMRADT                                                   ***
******************************************************************************
*** DESCRIPTION : This program implements a queue which has the member     ***
*** functions enqueue, dequeue, and view                                   ***
*****************************************************************************/
#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
    double value;
    Queue first;
    Queue second(5);
    first.enQueue(1.5);
    first.enQueue(2.5);
    first.enQueue(3.5);
    first.enQueue(4.5);
    first.enQueue(5.5);
    first.enQueue(6.5);
    first.enQueue(7.5);
    first.enQueue(8.5);

    second.enQueue(1.25);
    second.enQueue(2.25);
    second.enQueue(3.25);
    second.enQueue(4.25);
    second.enQueue(5.25);

    cout << "Printing first queue" << endl << endl;
    first.view();

    cout << endl << "deQueue all elements from first queue" << endl;
    first.deQueue(value);
    first.deQueue(value);
    first.deQueue(value);
    first.deQueue(value);
    first.deQueue(value);
    first.deQueue(value);
    first.deQueue(value);
    first.deQueue(value);

    cout << endl << "Printing first queue again" << endl;
    first.view();

    cout << endl << "Printing second queue" << endl;
    second.view();

    cout << "Copying second queue to new queue" << endl << endl;

    Queue third(second);
    cout << "Dequeue element from new copied list." << endl;
    third.deQueue(value);
    cout << "Printing copied list" << endl << endl;
    third.view();
    cout <<  endl << endl;
    cout << "Printing old list" << endl << endl;
    second.view();
    first.view();

}