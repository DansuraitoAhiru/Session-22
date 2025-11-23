#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int date;
	int month;
	int year;
}Birth;

typedef struct{
	char maSv[50];
	char name[50];
	Birth sn;
	char address[50];
	char phoneNumber[50];
}Student;

void enterInfo(Student *sv){
	printf("Nhap ma SV: ");
	fgets(sv->maSv, sizeof(sv->maSv), stdin);
	sv->maSv[strcspn(sv->maSv, "\n")]=0;
	printf("Nhap ten: ");
	fgets(sv->name, sizeof(sv->name), stdin);
	sv->name[strcspn(sv->name, "\n")]=0;
	printf("Nhap ngay/thang/nam sinh: ");
	scanf("%d %d %d", &sv->sn.date, &sv->sn.month, &sv->sn.year);
	while(getchar() != '\n');
	printf("Nhap dia chi: ");
	fgets(sv->address, sizeof(sv->address), stdin);
	sv->address[strcspn(sv->address,"\n")]=0;
	printf("Nhap SDT: ");
	fgets(sv->phoneNumber, sizeof(sv->phoneNumber), stdin);
	sv->phoneNumber[strcspn(sv->phoneNumber, "\n")]=0;
}

void enterList(Student *sv, int *length){
	int size;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &size);
	getchar();
	for(int i=0;i<size;i++){
		printf("Nhap thong tin sinh vien %d: ",i+1);
		enterInfo(&sv[*length+i]);
	}
	*length+=size;
	printf("Nhap thong tin sinh vien thanh cong!\n");
}

void display(Student *sv, int length){
	if(length<=0){
		printf("Danh sach rong");
		return;
	}
	printf("================================================== Danh sach sinh vien ==================================================\n");
	printf(" %-10s | %-30s | %-10s | %-40s | %-12s \n",
           "Ma SV", "Ho ten", "Ngay sinh", "Dia chi", "So DT");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    for (int i=0;i<length;i++) {
        printf(" %-10s | %-30s | %02d/%02d/%4d | %-40s | %-12s \n",
		    sv[i].maSv, sv[i].name, sv[i].sn.date, sv[i].sn.month, sv[i].sn.year, sv[i].address, sv[i].phoneNumber);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void add(Student *sv, int *length){
	while(getchar() != '\n');
	printf("Them thong tin sinh vien: ");
	enterInfo(&sv[*length]);
	(*length)++;
	printf("Them thanh cong!");
}

void earse(Student *sv, int *length){
	while(getchar() != '\n');
	char search[50];
	printf("Nhap ma sinh vien can tim: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<*length;i++){
		if(strcmp(sv[i].maSv, search)==0){
			for(int j=i;j<*length-1;j++){
				sv[j]=sv[j+1];
			}
			(*length)--;
			printf("Xoa thanh cong!\n");
			return;
		}
	}
	printf("Ko tim thay sinh vien nay!\n");
}
	
void update(Student *sv, int length){
	while(getchar() != '\n');
	char search[50];
	printf("Nhap ma sinh vien can tim: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<length;i++){
		if(strcmp(sv[i].maSv, search)==0){
			printf("Nhap thong tin sinh vien moi: \n");
			enterInfo(&sv[i]);
			printf("Cap nhat thanh cong!\n");
			return;
		}
	}
	printf("Ko tim thay sinh vien nay!\n");
}

char *tachTen(char *name) {
    char *last = strrchr(name, ' ');
    return last ? last + 1 : name;
}

void sapXepTheoTen(Student *ds, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(tachTen(ds[i].name), tachTen(ds[j].name)) > 0) {
                Student temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void search(Student *sv, int length){
	while(getchar() != '\n');
	char search[50];
	printf("Nhap ma sinh vien can tim: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<length;i++){
		if(strcmp(sv[i].maSv, search)==0){
			printf("Tim thay thong tin sinh vien: \n");
			printf(" %-10s | %-30s | %02d/%02d/%4d | %-40s | %-12s \n",
		    sv[i].maSv, sv[i].name, sv[i].sn.date, sv[i].sn.month, sv[i].sn.year, sv[i].address, sv[i].phoneNumber);
		    return;
		}
	}
	printf("Ko tim thay sinh vien nay!\n");
}

int main(){
	Student sv[1000];
	int length=0;
	int choice;
	int flag=0;
	do{
		printf("\n================== Menu ===================");
		printf("\n1. Nhap thong tin sinh vien");
		printf("\n2. Hien thi thong tin sinh vien");
		printf("\n3. Them sinh vien vao cuoi danh sach");
		printf("\n4. Xoa sinh vien theo ma sinh vien");
		printf("\n5. Cap nhat thong tin theo ma sinh vien");
		printf("\n6. Sap xep sinh vien theo ho ten (A-Z)");
		printf("\n7. Tim kiem sinh vien theo ma sinh vien");
		printf("\n8. Thoat");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: {
				enterList(sv, &length);
				flag=1;
				break;
			}
			case 2:{
				if(flag==0) printf("Chua co thong tin sinh vien nao! Vui long chon 1!\n");
				else display(sv,length);
				break;
			}
			case 3:{
				if(flag==0) printf("Chua co thong tin sinh vien nao! Vui long chon 1!\n");
				else add(sv,&length);
				break;
			}
			case 4:{
				if(flag==0) printf("Chua co thong tin sinh vien nao! Vui long chon 1!\n");
				else earse(sv,&length);
				break;
			}
			case 5:{
				if(flag==0) printf("Chua co thong tin sinh vien nao! Vui long chon 1!\n");
				else update(sv,length);
				break;
			}
			case 6:{
				if(flag==0) printf("Chua co thong tin sinh vien nao! Vui long chon 1!\n");
				else sapXepTheoTen(sv,length);
				break;
			}
			case 7:{
				if(flag==0) printf("Chua co thong tin sinh vien nao! Vui long chon 1!\n");
				else search(sv,length);
				break;
			}
			case 8:{
				printf("Sayonara!");
				exit(0);
			}
		default:
			printf("Ko co lua chon %d\n",choice);
		}
	}while(choice != 8);
}	
