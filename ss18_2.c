#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sinhvien
{
    char name[1000];
    int age;
    char phone[20];
};
char str[1005];
typedef struct sinhvien sv;
int main(){
    sv s;
    printf("Ho va ten: ");
    fgets(s.name,1000,stdin);
    if(strlen(s.name)>0&&s.name[strlen(s.name)-1]=='\n')s.name[strlen(s.name)-1]='\0';
    printf("Tuoi: ");
    scanf("%d",&s.age);
    getchar();
    printf("So dien thoai: ");
    fgets(s.phone,20,stdin);
    printf("Ho va ten: %s\nTuoi: %d\nSo dien thoai: %s",s.name,s.age,s.phone);
}