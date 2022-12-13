#include <iostream>
#include <math.h>
using namespace std;
//largest disc is represented by highest number 
// A structure to represent a stack
struct Stack
{
int capacity;
int top;
int *array;
};
 
// function to create a stack of given capacity / size.
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
 
// function to check if stack is full
// Stack is full when top is equal to the last index

int isFull(struct Stack* stack)
{
return (stack->top == stack->capacity - 1);
}
 
// function to check if stack is empty
// Stack is empty when top is equal to -1

int isEmpty(struct Stack* stack)
{
return (stack->top == -1);
}
 
// function to add an item to stack. it increase top by 1
void push(struct Stack *stack, int item)
{
    if (isFull(stack)){
        return;
    }
    stack -> array[++stack -> top] = item;
}
 
// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack)){
        return 0;
    }
    return stack -> array[stack -> top--];
}
 
//Function to show the movement of disks
void moveDisk(char fromPeg, char toPeg, int disk)
{
    cout <<"Move the disk " << disk <<" from " << fromPeg << " to "<< toPeg << endl;
}
 
// Function to implement legal movement between two poles
void moveDisksBetweenTwoPoles(struct Stack *src,struct Stack *dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);
 
    // When pole 1 is empty
    if (pole1TopDisk == 0)
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
 
    // When pole2 pole is empty
    else if (pole2TopDisk == 0)
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
 
    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
 
    // When top disk of pole1 < top disk of pole2
    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

//Function to implement TOH puzzle
void TOH(int num_of_disks, struct Stack *src, struct Stack *aux,
        struct Stack *dest)
{
    int i, total_num_of_moves,tempr;
    char s = 'S', d = 'D', a = 'A';
 
    //If number of disks is even, then interchange
    //destination pole and auxiliary pole
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;
 
    //Larger disks will be pushed first
    //push all discs to src rod first
    for (i = num_of_disks; i >= 1; i--)
        push(src, i);
    // displaying all rods
    tempr=src->top;
    cout<<"S : ";
    for(int j=0;j<=tempr;j++){
        cout<<src->array[j]<<"  ";
    }
    cout<<endl;
    cout<<"A : ";
    tempr=aux->top;
    for(int j=0;j<=tempr;j++){
        cout<<aux->array[j]<<"  ";
    }
    cout<<endl;
    cout<<"D : ";
    tempr=dest->top;
    for(int j=0;j<=tempr;j++){
        cout<<dest->array[j]<<"  ";
    }
    cout<<endl;
    for (i = 1; i <= total_num_of_moves; i++) //for all moves
    {
        if (i % 3 == 1)
        moveDisksBetweenTwoPoles(src, dest, s, d);
        //for even disc movement between source and aux
        else if (i % 3 == 2)
        moveDisksBetweenTwoPoles(src, aux, s, a);
        //for even disc movement between source and destination
        else if (i % 3 == 0)
        moveDisksBetweenTwoPoles(aux, dest, a, d);
        //for even movement betwen aux and destination
        // displaying all rods
        tempr=src->top;
        cout<<"S : ";
        for(int j=0;j<=tempr;j++){
            cout<<src->array[j]<<"  ";
        }
        cout<<endl;
        cout<<"A : ";
        tempr=aux->top;
        for(int j=0;j<=tempr;j++){
            cout<<aux->array[j]<<"  ";
        }
        cout<<endl;
        cout<<"D : ";
        tempr=dest->top;
        for(int j=0;j<=tempr;j++){
            cout<<dest->array[j]<<"  ";
        }
        cout<<endl;
    }
}

// Driver Program
int main()
{
   
    // Input: number of disks
    int num_of_disks;
    cout<<"Enter number of disks : ";
    cin>>num_of_disks;
 
    struct Stack *src, *dest, *aux;
 
    // Create three stacks of size 'num_of_disks'
    // to hold the disks
    src = createStack(num_of_disks);
    aux = createStack(num_of_disks);
    dest = createStack(num_of_disks);
 
    TOH(num_of_disks, src, aux, dest);
    return 0;
}