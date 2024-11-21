#include <stdio.h>
#include <stdlib.h>
// 
int size = 3;
int counter = 0;
int *array;
// 
void Insert(int index, int value){
    if(index < counter){
        array[index] = value;
        printf("value inserted !\n");
    }
    else {
        printf("index not found !\n");
    }
}
int Delete_By_Value(int value){
    int index = -1;
    for (int i = 0; i < counter; i++) {
        if(array[i] == value){
            index = i;
            break;
        }
    }
    if(index >= 0){
        int k = 0;
        int temp[counter];
        for (int i = 0; i < counter; i++) {
            temp[i] = array[i];
        }
        for (int i = 0; i < counter; i++) {
            if (i == index) {
                continue;
            }
            else {
                array[k] = temp[i];
                k += 1;
            }
        }
        counter -= 1;
    }
    return index;
}
void Delete_By_Index(int input){
    int k = 0;
    int temp[counter];
    for (int i = 0; i < counter; i++) {
        temp[i] = array[i];
    }
    for (int i = 0; i < counter; i++) {
        if (i == input) {
            continue;
        }
        else {
            array[k] = temp[i];
            k += 1;
        }
    }
    counter -= 1;
}
void Display(){
    if(counter > 0){
        printf("Array : ");
        for (int i = 0; i < counter; i++) {
            printf("%d ",*(array + i));
        }
        printf("\n");
    }
    else {
        printf("Array is empty !\n");
    }
}
void Append(int input){
    if(counter == size){
        int temp[counter];
        for (int i = 0; i < counter; i++) {
            temp[i] = array[i];
        }
        size += 3;
        array = (int*)realloc(array, 3 + sizeof(int));
        for (int i = 0; i < counter; i++) {
            array[i] = temp[i];
        }
    }
    array[counter] = input;
    counter += 1;
    printf("value appended !\n");
}
void Reverse(int arr[]){
    int c = counter, tempNumber;
    int tempArr[c];
    for (int i = 0; i < c; i++) {
        tempArr[i] = arr[i];
    }
    for (int i = 0; i < c; i++) {
        tempNumber = tempArr[c-i-1];
        tempArr[c-i-1] = arr[i];
        arr[i] = tempNumber;
    }
}
int Search_By_Value(int value){
    int index = -1;
    for (int i = 0; i < counter; i++) {
        if(array[i] == value){
            index = i;
        }
    }
    return index;
}
void clearTerminal(){
    system("clear");
}
void toContinue(){
    char zero;
    printf("enter character to continue : ");
    scanf(" %c",&zero);
}
// 
int main(){
    char choise;
    array = (int*)calloc(size, sizeof(int));
    while (1) {
        clearTerminal();
        printf("Menu\n");
        printf( "1. Insert\n");
        printf( "2. Delete_By_Value\n");
        printf( "3. Delete_By_Index\n");
        printf( "4. Display\n");
        printf( "5. Append\n");
        printf( "6. Reverse\n");
        printf( "7. Search_By_Value\n");
        printf( "8. Exit\n");
        printf("\ninput number : ");
        scanf(" %c",&choise);
        if (choise == '1') {
            clearTerminal();
            int value, index;
            printf("input value : ");
            scanf("%d",&value);
            printf("input index : ");
            scanf("%d",&index);
            Insert(index, value);
            toContinue();
        }
        else if (choise == '2') {
            clearTerminal();
            int value;
            printf("input value : ");
            scanf("%d",&value);
            int result = Delete_By_Value(value);
            if(result >= 0){
                printf("value deleted, index : %d \n",result);
            } else {
                printf("value not found\n");
            }
            toContinue();
        }
        else if (choise == '3') {
            clearTerminal();
            int index;
            printf("input index : ");
            scanf("%d",&index);
            if(index >= 0 && index < counter){
                Delete_By_Index(index);
                printf("value deleted !\n");
            }
            else {
                printf("index not found !\n");
            }
            toContinue();
        }
        else if (choise == '4') {
            clearTerminal();
            Display();
            toContinue();
        }
        else if (choise == '5') {
            clearTerminal();
            int value;
            printf("input value : ");
            scanf("%d",&value);
            Append(value);
            toContinue();
        }
        else if (choise == '6') {
            clearTerminal();
            Reverse(array);
            printf("array reversed\n");
            toContinue();
        }
        else if (choise == '7') {
            clearTerminal();
            int value;
            printf("input value : ");
            scanf("%d",&value);
            int result = Search_By_Value(value);
            if(result >= 0){
                printf("index : %d\n",result);
            } else {
                printf("value not found\n");
            }
            toContinue();
        }
        else if (choise == '8') {
            clearTerminal();
            break;
        }
        else {
            printf("input true number ! \n");
            toContinue();
        }
    }
}
