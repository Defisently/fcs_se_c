#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int summator(const int num1, const int num2, const char operation){
    int ans = 1;

    if (operation == '/' && num2 != 0){
        ans = num1 / num2;

    } else if (operation == '*'){
        ans = num1 * num2;

    } else if (operation == '+'){
        ans = num1 + num2;

    } else if(operation == '/' && num2 == 0){
        ans = 0;

    } else if(operation == '-'){
        ans = num1 - num2;

    } else {
        ans = 0;
    }
    return ans;
}

int main() {
    int num1;
    int num2;
    char operation;

    printf("Введите первое чило, затем нажмите enter: ");
    scanf("%d", &num1);

    printf("Введите второе чило, затем нажмите enter: ");
    scanf("%d", &num2);

    printf("Введите операцию: * / + -, затем нажмите enter: ");
    scanf(" %c", &operation);

    if (num1 - num2 != 0 && summator(num1, num2, operation) == 0){
        printf("error\n");
    } else {
        printf("Результат: %d\n", summator(num1, num2, operation));
    }
    return 0;

}
