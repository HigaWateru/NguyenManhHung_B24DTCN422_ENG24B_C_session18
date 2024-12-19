#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int id;
char name[50];
struct sinhvien{
    int id;
    char name[30];
    int age;
    char phone[15];
};
typedef struct sinhvien sinhvien;
void delSV(sinhvien *a,int *size, char name[]) {
    int vt=-1;
    for(int i=0;i< *size;i++)if(strcmp(a[i].name,name)==0){
        vt=i;
        break;
    }
    if(vt==-1)printf("Them sinh vien khong ton tai!\n");
    else{
        for(int i=vt;i< *size;i++)a[i]=a[i+1];
        (*size)--;
    }
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
    printf("Nhap ho ten sinh vien can xoa: ");
    fgets(name,50,stdin);
    if(strlen(name)>0&&name[strlen(name)-1]=='\n')name[strlen(name)-1]='\0';
    delSV(&a,&n,name);
    printf("ID            Ho va ten      Tuoi So dien thoai\n");
    for(int i=0;i<n;i++)printf("%3d%25s%3d%15s\n",a[i].id,a[i].name,a[i].age,a[i].phone);
}
