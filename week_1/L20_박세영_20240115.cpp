struct my_stack{
    int top;
    int stack_size;
    char* stack;

};

void push(char bracket,struct my_stack* s){
    s->stack[s->top] = bracket;
    s->top ++;
}

char pop(struct my_stack* s){
    s->top -- ;
    return s->stack[s->top];
}
bool is_empty(struct my_stack* s) {
    if(s->top<=0) return true;
    return false; 
}
bool is_full(struct my_stack* s) {
    if(s->stack_size>=s->top) return true;
    return false;
}


bool isValid(char* s) {
    struct my_stack b;
    b.top = 0;
    b.stack_size = strlen(s);
    b.stack = (char*) malloc(sizeof(char)*strlen(s));

    char open_b[3] = {'(','{','['};
    char close_b[3] = {')','}',']'};
    char p;
    for(int i =0;i<strlen(s);i++) {
        if(s[i]=='('||s[i]=='{'||s[i]=='[') push(s[i],&b);
        if((s[i]==')'||s[i]=='}'||s[i]==']')) {
            if(is_empty(&b)) return false;
            p = pop(&b);
           if( (p == '(')&&(s[i]==')')||(p == '{')&&(s[i]=='}')||(p == '[')&&(s[i]==']')) continue;
           else return false;
        }
    }
    if(!is_empty(&b)) return false;
        
    return true; 
}