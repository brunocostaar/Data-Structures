#include <stdio.h>
#include "stack.h"

char rev(char c){
    switch(c){
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
    }
    return '\0'; 
}

int main(){
	
	CharStack s;
	create_char_stack(&s, 10);
	
	char* str = "({})()[{]}"; // TODO: implement mathematical hierarchy - too tired and busy rn
	
	int valid;
	
	for (char* pc = str; *pc != '\0'; pc++) {
        char current = *pc;
        if (current == '(' || current == '[' || current == '{') {
            push_char(&s, current);
        }
        else if (current == ')' || current == ']' || current == '}') {
            if (isEmpty_char(&s)) {
                valid = 0;
                break;
            }
            // Reads stack top before popping it
            char top_char = s.vector[s.i]; 
            
            // Pops top element
            pop_char(&s); 

            // Checks if closing matches opening
            if (rev(top_char) != current) {
                valid = 0;
                break; 
            }
        }
    }

    if (valid && !isEmpty_char(&s)) { // this prevents that strings like ((( are valid. It could only be valid if the stack is empty at the end.
        valid = 0;
    }
    
    printf("%s\n", valid ? "Valid!" : "Invalid!"); 

	destroy_char(&s);
	
	return 0;
}