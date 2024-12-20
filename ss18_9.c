#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char name[100];
    int prime;
}dish;
dish a[100]={
    {1,"Banh My Paste",10},
    {2,"Banh My Trung La Ngai",15},
    {3,"My Tron Sot Pho Mai",25},
    {4,"Xoai Lac",15},
    {5,"Banh My Paste Trung",20}
};
void insertDish(dish *a,int size, int vt){
    if(vt<=0||vt>100)printf("Vi tri khong ton tai trong danh sach!\n");
    else{
        printf("Cap nhat mon an:\nID mon an: ");
        scanf("%d",&a[vt-1].id);
        getchar();
        printf("Ten mon an: ");
        fgets(a[vt-1].name,50,stdin);
        if(strlen(a[vt-1].name)>0&&a[vt-1].name[strlen(a[vt-1].name)-1]=='\n')a[vt-1].name[strlen(a[vt-1].name)-1]='\0';
        printf("Gia tien(kVND): ");
        scanf("%d",&a[vt-1].prime);
        getchar();
        if(a[vt-1].prime>1000)a[vt-1].prime/=1000;
        printf("Cap nhat thong tin thanh cong!\n");
    }
}
void editDish(dish *a,int size, int vt){
    if(vt<=0||vt>100||a[vt-1].id==0)printf("Vi tri khong ton tai trong danh sach!\n");
    else{
        printf("Cap nhat mon an:\nID mon an: ");
        scanf("%d",&a[vt-1].id);
        getchar();
        printf("Ten mon an: ");
        fgets(a[vt-1].name,50,stdin);
        if(strlen(a[vt-1].name)>0&&a[vt-1].name[strlen(a[vt-1].name)-1]=='\n')a[vt-1].name[strlen(a[vt-1].name)-1]='\0';
        printf("Gia tien(kVND): ");
        scanf("%d",&a[vt-1].prime);
        getchar();
        if(a[vt-1].prime>1000)a[vt-1].prime/=1000;
        printf("Cap nhat thong tin thanh cong!\n");
    }
}
void deleteDish(dish *a, int size, int vt){
    if(vt<=0||vt>100||a[vt-1].id==0)printf("Vi tri khong ton tai trong danh sach!\n");
    else{
        a[vt-1].id=0;
        printf("Da xoa thong tin mon an!\n");
    }
}
void swap(dish *ptr1, dish *ptr2){
    dish temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
void selectionSortG(dish *a,int size){
    for(int i=0;i<99;i++){
        if(a[i].id!=0){
            int x=i;
            for(int j=i+1;j<100;j++)if(a[j].id!=0&&a[j].prime>a[x].prime)x=j;
            swap(&a[i],&a[x]);
        }
    }
}
void selectionSortT(dish *a,int size){
    for(int i=0;i<99;i++){
        if(a[i].id!=0){
            int x=i;
            for(int j=i+1;j<100;j++)if(a[j].id!=0&&a[j].prime<a[x].prime)x=j;
            swap(&a[i],&a[x]);
        }
    }
}
int linearSearch(dish *a,int size, char name[]){
    for(int i=0;i<size;i++)if(a[i].id!=0&&strcmp(a[i].name,name)==0)return i;
}
int binarySearch(dish *a,int size, char name[]){
    int l=0,r=size-1;
    while (l<=r){
        int m=(l+r)/2;
        if(a[m].name==name)return 1;
        else if(a[m].name<name)l=m+1;
        else r=m-1;
    }
    return 0;
}
int d,vt;
char ch;
char name[100];
int main(){
    do{
        printf("MENU\n1.In ra menu mon an\n2.Them mon an vao vi tri chi dinh\n3.Sua mon an o vi tri chi dinh\n4.Xoa phan tu mon an chi dinh\n5.Sap xep mon an theo gia tien\n6.Tim kiem ten mon an\n7.Thoat\nLua chon cua ban: ");
        scanf("%d",&d);
        switch (d)
        {
            case 1:
                printf("            MENU mon an\n STT  ID          Ten mon an        Gia tien(kVND)\n");
                for(int i=0;i<100;i++)if(a[i].id!=0)printf("%3d %4d %25s       %4d\n",i+1,a[i].id,a[i].name,a[i].prime);
                break;
            case 2:
                printf("Vi tri mon an trong danh sach: ");
                scanf("%d",&vt);
                insertDish(&a,100,vt);
                break;
            case 3:
                printf("Vi tri mon an trong danh sach can sua: ");
                scanf("%d",&vt);
                editDish(&a,100,vt);
                break;
            case 4:
                printf("Vi tri mon an trong danh sach can xoa: ");
                scanf("%d",&vt);
                deleteDish(&a,100,vt);
            case 5:
                do{
                    printf("a. Giam dan theo gia tien\nb. Tang dan theo gia tien\nLua chon cua ban: ");
                    scanf("%s",&ch);
                }while(ch!='a'&&ch!='b');
                if(ch=='a')selectionSortG(&a,100);
                else selectionSortT(&a,100);
                printf("Da sap xep danh sach!\n");
                break;
            case 6:
                do{
                    printf("a. Tim kiem tuyen tinh\nb. Tim kiem nhi phan\nLua chon cua ban: ");
                    scanf("%s",&ch);
                }while(ch!='a'&&ch!='b');
                getchar();
                printf("Ten mon an can tim: ");
                fgets(name,50,stdin);
                if(strlen(name)>0&&name[strlen(name)-1]=='\n')name[strlen(name)-1]='\0';
                if(ch=='a')printf("Vi tri mon an trong danh sach: %d\n",linearSearch(&a,100,name)+1);
                else printf("Vi tri mon an trong danh sach: %d\n",binarySearch(&a,100,name)+1);
            default:
                break;
        }
    }while(d!=7);
}
