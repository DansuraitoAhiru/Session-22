#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char name[50];
	char phoneNumber[50];
	char email[50];
}Contact;

void addContact(Contact *p, int *length){
	int size;
	printf("Nhap so luong lien he muon them: ");
	scanf("%d", &size);
	getchar();
	for(int i=0;i<size;i++){
		Contact info;
		printf("Nhap thong tin lien lac %d: \n", i+1);
		printf("Nhap ten lien lac: ");
		fgets(info.name, sizeof(info.name), stdin);
		info.name[strcspn(info.name, "\n")]=0;
		printf("Nhap so dien thoai: ");
		fgets(info.phoneNumber, sizeof(info.phoneNumber), stdin);
		info.phoneNumber[strcspn(info.phoneNumber, "\n")]=0;
		printf("Nhap email lien he: ");
		fgets(info.email,sizeof(info.email), stdin);
		info.email[strcspn(info.email, "\n")]=0;
		p[*length+i]=info;
	}
	*length+=size;
	printf("Nhap thong tin thanh cong!");
}

void display(Contact *p, int length){
	if(length<=0){
		printf("Danh sach rong!");
		return;
	}
	printf("======================= Danh sach lien lac ======================\n");
	for(int i=0;i<length;i++){
		printf("\nTen: %-20s | SDT: %-20s | Email: %-30s\n",
		    p[i].name, p[i].phoneNumber, p[i].email);
	}
}

void search(Contact *p, int length){
	while(getchar() != '\n');
    char search[50];
	printf("Nhap ten lien he can tim: ");
	fgets(search,sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<length;i++){
		if(strcmp(p[i].name,search)==0){
			printf("Tim thay thong tin lien he: \nTen: %-20s | SDT: %-20s | Email: %-30s",
                p[i].name, p[i].phoneNumber, p[i].email);
                return;
		}
	}
	printf("Ko tim thay thong tin lien he cua %s!\n", search);
}

void deleteInfo(Contact *p, int *length){
	if(*length<=0){
		printf("Danh sach rong!\n");
	}
	while(getchar() != '\n');
	char search[50];
	printf("Nhap ten lien he can xoa: ");
	fgets(search,sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	int pos=-1;
	for(int i=0;i<*length;i++){
		if(strcmp(p[i].name, search) == 0){
			pos=i;
			break;
		}
	}
	if(pos==-1){
		printf("Ko tim thay thong tin lien he!\n");
		return;
	}
	for(int i=pos;i<*length-1;i++){
		p[i]=p[i+1];
	}
	(*length)--;
	printf("Da xoa thanh cong!\n");
}
			
int main(){
	Contact info[100];
	int size;
	int length=0;
	int choice;
	int flag=0;
	do{
		printf("\n======================== Menu ====================");
		printf("\n1. Them lien he moi");
		printf("\n2. Hien thi tat ca lien he");
		printf("\n3. Tim kiem lien he theo ten");
		printf("\n4. Xoa lien he theo ten");
		printf("\n5. Thoat");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				addContact(info,&length);
				flag=1;
				break;
			}
			case 2:{
				if(flag==0) printf("Chua co thong tin lien lac nao! Vui long chon 1!");
				else display(info,length);
				break;
			}
			case 3:{
				if(flag==0) printf("Chua co thong tin lien lac nao! Vui long chon 1!");
				else search(info,length);
				break;
			}
			case 4:{
				if(flag==0) printf("Chua co thong tin lien lac nao! Vui long chon 1!");
				else deleteInfo(info,&length);
				break;
			}
			case 5:{
				printf("Sayonara!");
				exit(0);
			}
		default:
			printf("Ko co lua chon %d", choice);
		}
	} while(choice !=5);
}
