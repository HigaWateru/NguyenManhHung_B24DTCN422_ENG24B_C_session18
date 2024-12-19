#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct sinhvien
{
    char name[1000];
    int age;
    char phone[20];
};
int main(){
    struct sinhvien a[100];
    for(int i=0;i<5;i++){
        fgets(a[i].name,1000,stdin);
        if(strlen(a[i].name)>0&&a[i].name[strlen(a[i].name)-1]=='\n')a[i].name[strlen(a[i].name)-1]='\0';
        scanf("%d",&a[i].age);
        getchar();
        fgets(a[i].phone,15,stdin);
    }
    printf("Thong tin sinh vien\n");
    for(int i=0;i<5;i++){
        printf("Sinh vien %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n",i+1,a[i].name,a[i].age,a[i].phone);
    }
}