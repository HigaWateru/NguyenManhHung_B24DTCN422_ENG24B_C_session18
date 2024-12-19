#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sv{
    char name[1000];
    int age;
    char phone[20];
};
typedef struct sv sv;
int main(){
    sv s;
    strcpy(s.name,"Nguyen Manh Hung");
    s.age=18;
    strcpy(s.phone,"0824817599");
    printf("Ho ten sinh vien: %s\nTuoi: %d\nSo dien thoai: %s",s.name,s.age,s.phone);
}
