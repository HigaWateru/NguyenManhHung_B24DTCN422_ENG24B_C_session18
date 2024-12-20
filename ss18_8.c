#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int id,vt;
struct sinhvien{
    int id;
    char name[30];
    int age;
    char phone[15];
};
typedef struct sinhvien sinhvien;
void insertSV(sinhvien *a,int *size, int vt) {
    printf("Cap nhat thong tin sinh vien\n");
    printf("ID sinh vien: ");
    scanf("%d",&a[vt-1].id);
    getchar();
    printf("Ho va ten: ");
    fgets(a[vt-1].name,30,stdin);
    if(strlen(a[vt-1].name)>0&&a[vt-1].name[strlen(a[vt-1].name)-1]=='\n')a[vt-1].name[strlen(a[vt-1].name)-1]='\0';
    printf("Tuoi: ");
    scanf("%d",&a[vt-1].age);
    getchar();
    printf("So dien thoai: ");
    fgets(a[vt-1].phone,15,stdin);
    if(strlen(a[vt-1].phone)>0&&a[vt-1].phone[strlen(a[vt-1].phone)-1]=='\n')a[vt-1].phone[strlen(a[vt-1].phone)-1]='\0';
    printf("Cap nhap thong tin thanh cong!\n");
}
int main(){
    int n=5;
    sinhvien a[50]={
        {422,"Nguyen Manh Hung",18,"0987654321"},
        {123,"Nguyen Sy Trung",18,"19006776"},
        {66,"Nguyen Quyet Thang",20,"0123456789"},
        {312,"Nguyen Tuan Dung",18,"18002088"},
        {111,"Tran Anh Dung",18,"0987666444"}
    };
    printf("Nhap vi tri danh sach them thong tin: ");
    scanf("%d",&vt);
    getchar();
    if(vt<=0||vt>50)printf("Vi tri khong ton tai trong danh sach!\n");
    else insertSV(&a,50,vt);
    printf("STT  ID            Ho va ten      Tuoi So dien thoai\n");
    for(int i=0;i<50;i++)if(a[i].id!=0)printf("%2d  %3d%25s%3d%15s\n",i+1,a[i].id,a[i].name,a[i].age,a[i].phone);
}
