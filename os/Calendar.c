#include <stdio.h>
#include <stdlib.h>

struct Day{
    char *dayName;
    int date;
    char *activity;
};

struct Day create(){
    struct Day newDay;
    newDay.dayName = (char*)malloc(20 * sizeof(char));
    newDay.activity = (char*)malloc(100 * sizeof(char));
    
    printf("Enter Day Name : ");
    scanf("%s", newDay.dayName);
    
    printf("Enter Date : ");
    scanf("%d", &newDay.date);
    
    printf("Enter Activity: ");
    scanf("%s",newDay.activity);
    
    return newDay;
}

void read(struct Day calendar[], int numDays){
    for(int i = 0; i< numDays; i++){
        printf("Enter Details for Day %d :\n",i+1);
        calendar[i]=create();
    }
}

void display(struct Day calendar[], int numDays){
    printf("Calendar: \n");
    for(int i =1; i<=numDays;i++){
        printf("Day %d: %s\n", i + 1, calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("\n");
    }
}

int main(){
    int numDays = 7;
    struct Day calendar[7];
    
    read(calendar, numDays);
    display(calendar, numDays);
    
    return 0;
}

