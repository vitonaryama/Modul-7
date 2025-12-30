#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == 19);
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

/*==========================================
    TAMBAHAN: pushAscending()
    Tugas Nomor 2
==========================================*/
void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    // pindahkan sementara elemen yg lebih besar
    while (!isEmpty(S) && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    // masukkan elemen x
    push(S, x);

    // kembalikan elemen temp
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
