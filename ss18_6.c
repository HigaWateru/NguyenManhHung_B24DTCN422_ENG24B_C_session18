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
void editSV(sinhvien *a, int id, int *size) {
    int tg=0;
    for(int i=0;i<*size;i++)if(id==a[i].id){
        tg=1;
        printf("ID sinh vien da ton tai!");
        break;
    }
    if(!tg){
        (*size)++;
        a[*size-1].id=id;
        printf("Cap nhat thong tin sinh vien ID %d\nHo va ten: ",id);
        getchar();
        fgets(a[*size-1].name,25,stdin);
        a[*size-1].name[strcspn(a[*size-1].name,"\n")]='\0';
        printf("Tuoi: ");
        scanf("%d",&a[*size-1].age);
        getchar();
        printf("So dien thoai: ");
        fgets(a[*size-1].phone,15,stdin);
        a[*size-1].phone[strcspn(a[*size-1].phone,"\n")]='\0';
        printf("Da cap nhat thong tin!\n");
    }
}
int main(){
    int n=5;
    sinhvien a[10]={
        {422,"Nguyen Manh Hung",18,"0987654321"},
        {123,"Nguyen Sy Trung",18,"19006776"},
        {66,"Nguyen Quyet Thang",20,"0123456789"},
        {312,"Nguyen Tuan Dung",18,"18002088"},
        {111,"Nguyen Anh Dung",18,"0987666444"}
    };
    printf("Nhap ID sinh vien can them: ");
    scanf("%d",&id);
    editSV(&a,id,&n);
    printf("ID            Ho va ten      Tuoi So dien thoai\n");
    for(int i=0;i<n;i++)printf("%3d%25s%3d%15s\n",a[i].id,a[i].name,a[i].age,a[i].phone);
}
