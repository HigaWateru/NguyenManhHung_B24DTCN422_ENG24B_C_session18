#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int id;
struct sinhvien{
    int id;
    char name[30];
    int age;
    char phone[15];
};
typedef struct sinhvien sinhvien;
void insertSV(sinhvien *a, int id, int size) {
    int tg=0;
    for(int i=0;i<size;i++) {
        if(a[i].id==id){
            tg=1;
            printf("Cap nhat thong tin:\n");
            printf("Ho va ten: ");
            getchar();
            fgets(a[i].name,25,stdin);
            printf("Tuoi: ");
            scanf("%d",&a[i].age);
            getchar();
            printf("So dien thoai: ");
            fgets(a[i].phone,15,stdin);
            a[i].phone[strcspn(a[i].phone,"\n")]='\0';
            printf("Da cap nhat thong tin!\n");
            break;
        }
    }
    if (!tg)printf("Khong tim thay sinh vien co id %d!\n",id);
}
int main(){
    sinhvien a[5]={
        {422,"Nguyen Manh Hung",18,"0987654321"},
        {123,"Nguyen Sy Trung",18,"19006776"},
        {66,"Nguyen Quyet Thang",20,"0123456789"},
        {312,"Nguyen Tuan Dung",18,"18002088"},
        {111,"Nguyen Anh Dung",18,"0987666444"}
    };
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d",&id);
    insertSV(&a,id,5);
    printf("ID            Ho va ten      Tuoi So dien thoai\n");
    for(int i=0;i<5;i++)printf("%3d%25s%3d%15s\n",a[i].id,a[i].name,a[i].age,a[i].phone);
}
