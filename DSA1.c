#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Day
{
    char*dayName;
    int date;
    char*activity;
};
void trimNewline(char*str){
size_t len=strlen(str);
if(len>0&&str[len-1]=='\n'){
    str[len-1]='\0';
}
}
void create(struct Day*day){
day ->dayName=(char*)malloc(sizeof(char)*50);
day ->activity=(char*)malloc(sizeof(char)*200);
printf("Enter the day name:");
fgets(day ->dayName,50,stdin);
trimNewline(day ->dayName);
printf("Enter the date:");
scanf("%d",& day ->date);
getchar();
printf("Enter the activity for the day:");
fgets(day ->activity,200,stdin);
trimNewline(day ->activity)
}
void read(struct Day*calendar,int size){
for(int i=0;i<size;i++){
    printf("Enter details for Day %d:\n",i+1);
    create(&calendar[i]);
}

}
void display(struct Day*calendar,int size){
printf("\n Week's Activity details:\n");
for(int i=0;i<size;i++){
    printf("Day %d:\n",i+1);
    printf("Day Name:%s\n",calendar[i].dayName);
    printf("Date:%d\n",calendar[i].date);
    printf("Activity:%s\n",calendar[i].activity);
    printf("\n");
}
}
void freeMemory(struct Day*calendar,int size){
for(int i=0;i<size;i++){
    free(calendar[i].dayName);
    free(calendar[i].activity);
}
}int main(){
int size;
printf("Enter the number of days in the week:");
scanf("%d",& size);
getchar();
struct Day*calendar=(struct Day*)malloc(sizeof(struct Day)*size);
if(calendar==NULL){
    printf("Memory allocation failed.Exiting program.\n");
    return 1;

}
read(calendar,size);
display(calendar,size);
freeMemory(calendar,size);
free(calendar);
return 0;
};
