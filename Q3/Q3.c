/*Q3: Sort Array Using Stack*/
#include <stdio.h>

struct Stack 
{
     int top_index;
     int stack[10];
};

struct Stack push(struct Stack stack, int value) 
{
    
    int stack_size = sizeof(stack.stack)/sizeof(int);

    if(stack.top_index < stack_size){
        stack.stack[stack.top_index] = value;
        stack.top_index++;
    }
    else {
        printf("Stack full!");
    }
    return stack;
}

struct Stack pop(struct Stack stack) {
    stack.stack[stack.top_index] = 0;
    stack.top_index--;

    return stack;
}

int empty(struct Stack stack) {
    if(stack.top_index > 0)
        return 0;
    else
        return 1;
}

int top(struct Stack stack) {
    return stack.stack[stack.top_index - 1];
}

struct Stack sortStack(struct Stack input)
{
    struct Stack tmp_stack;
    tmp_stack.top_index = 0;
 
    while (!empty(input))
    {
        int tmp = top(input);
        input = pop(input);
 
        while (!empty(tmp_stack) && top(tmp_stack) < tmp)
        {
            input = push(input, top(tmp_stack));
            tmp_stack = pop(tmp_stack);
        }

        tmp_stack = push(tmp_stack, tmp);
    }
 
    return tmp_stack;
}
 
void sortArrayUsingStacks(int arr[], int n)
{
    struct Stack input;
    input.top_index = 0;

    for (int i=0; i<n; i++)
       input = push(input, arr[i]);

    struct Stack tmp_stack = sortStack(input);
    
    for (int i=0; i<n; i++)
    {
        arr[i] = top(tmp_stack);
        tmp_stack = pop(tmp_stack);
    }
}
 
int main()
{
    int arr[] = {8, 5, 7, 1, 9, 12, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++)
        printf("%d  ", arr[i]);
 
    sortArrayUsingStacks(arr, n);
 
    printf("\nSorted array-\n");
    for(int i=0; i<n; i++)
       printf("%d   ", arr[i]);
 
    return 0;
}