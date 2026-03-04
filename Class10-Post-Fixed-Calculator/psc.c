#include "../Class9-Stacks/stack.h"

void calculator(IntStack* stack, char* string){
    int i = 0; // string index count
    while(string[i] != '\0'){ // while the char on that index is not \0:
        // this char is a number -> typecast it and push it into the stack
        if(string[i] ==  '1' || string[i] ==  '2' || string[i] ==  '3' || string[i] ==  '4' || string[i] ==  '5' || string[i] ==  '6' || 
        string[i] ==  '7' || string[i] ==  '8' || string[i] ==  '9'){
            int num = string[i] - '0';
            push_int(stack, num);
        }
        else if(string[i] == '*'){ //then we proceed with four else ifs to check if it is an operation, in this case, *
            if(!isEmpty_int(stack)){ // if it is *, check if the stack is empty, if it isnt , get operand 1 through pop;
                int op1 = pop_int(stack);
                if(!isEmpty_int(stack)){ // then before getting operand two we do this check again, because you cannot perform an
                    int op2 = pop_int(stack); // operation with a single number.
                    int result = op1*op2;
                    push_int(stack, result); // then we perform the operations between the two operands and push them into the stack
                }
            }
        }
        else if(string[i] == '-'){ // again for subtraction and so on
            if(!isEmpty_int(stack)){
                int op1 = pop_int(stack);
                if(!isEmpty_int(stack)){
                    int op2 = pop_int(stack);
                    int result = op1-op2;
                    push_int(stack, result);
                }
            }
        }
        else if(string[i] == '+'){
            if(!isEmpty_int(stack)){
                int op1 = pop_int(stack);
                if(!isEmpty_int(stack)){
                    int op2 = pop_int(stack);
                    int result = op1+op2;
                    push_int(stack, result);
                }
            }
        }
        else if(string[i] == '/'){
            if(!isEmpty_int(stack)){
                int op1 = pop_int(stack);
                if(!isEmpty_int(stack)){
                    int op2 = pop_int(stack);
                    int result = op1/op2;
                    push_int(stack, result);
                }
            }
        }
        // I was going to implement an else statement for if it wasnt either a number nor an operation but the teacher said
        // not to consider those cases. Therefore the increment below takes us to the next char on the next iteration.
        i++;
    }
    print_top_int(stack); // after all iterations, the result will be the top of the stack
}

int main(){
    IntStack stack;
    create_int_stack(&stack, 10); // main that defines and creates a stack and a string and uses them as an input to the
                                  // calculator. Could easily make some changes to run it in a loop and through user inputs.

    char* string = "5+349-";

    calculator(&stack, string);
}