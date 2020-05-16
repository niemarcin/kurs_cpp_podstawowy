#pragma once

int fibonacci_iterative(int sequence) { 
    if (sequence <= 1) {
        return sequence;
    }
    
    int current = 0;
    int previous = 1;
    int prev_previous = 0;

    for(int i = 2; i <= sequence; i++){
        
        current = previous + prev_previous;
        prev_previous = previous;
        previous = current;
    }

    return current;
}

int fibonacci_recursive(int sequence) {
    if (sequence <= 1) {
        return sequence;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
