#define MAX_STRING 100

//Pre: string es un vector terminado en \0
int strlen(char string[MAX_STRING]){
    int i = 0;

    while(string[i] != '\0'){
        i++;
    }

    return i;
}

//Pre: la primera vez i vale 0
//     string es un vector terminado en \0
int strlen_recursivo(char string[MAX_STRING], int pos_actual, int tope){
    if(string[pos_actual] == '\0'){
        return pos_actual;
    }

    return strlen_recursivo(string, pos_actual+1);
}
