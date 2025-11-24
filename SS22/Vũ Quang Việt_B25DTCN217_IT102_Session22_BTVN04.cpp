#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int date;
	int month;
	int year;
}Birth;

typedef struct {
	char ma[50];
	char name[50];
	Birth sn;
	float money;
	char status[50];
}Order;

int checkDate(int d, int m, int y) {
    if (y < 1900 || y > 2100) return 0;
    if (m < 1 || m > 12) return 0;
    int maxDay;
    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31; break;
        case 4: case 6: case 9: case 11:
            maxDay = 30; break;
        case 2:
            maxDay = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
            break;
    }
    return d >= 1 && d <= maxDay;
}

void enterInfo(Order *don){
	printf("Nhap ma don hang: ");
	fgets(don->ma, sizeof(don->ma), stdin);
	don->ma[strcspn(don->ma, "\n")]=0;
	printf("Nhap ten khach hang: ");
	fgets(don->name, sizeof(don->name), stdin);
	don->name[strcspn(don->name, "\n")]=0;
	printf("Nhap ngay dat hang: ");
	while (1) {
	    if (scanf("%d %d %d", &don->sn.date, &don->sn.month, &don->sn.year) != 3 ||
	        !checkDate(don->sn.date, don->sn.month, don->sn.year)) 
	    {
	        printf("Ngay thang nam khong hop le! Nhap lai: ");
	        while (getchar() != '\n'); 
	    } else {
	        while (getchar() != '\n');
	        break;
	    }
	}
	printf("Nhap tong tien: ");
	scanf("%f", &don->money);
	while(getchar() != '\n');
	printf("Nhap trang thai don hang: ");
	fgets(don->status, sizeof(don->status), stdin);
	don->status[strcspn(don->status, "\n")]=0;
}

void enterList(Order *don, int *length){
	int size;
	printf("Nhap so luong don hang muon nhap: ");
	scanf("%d", &size);
	getchar();
	for(int i=0;i<size;i++){
		printf("Nhap thong tin don hang %d: \n",i+1);
		enterInfo(&don[*length+i]);
	}
	*length+=size;
	printf("Nhap thong tin thanh cong!\n");
}

void display(Order *don, int length){
	if(length<=0){
		printf("Chua co don hang nao!\n");
		return;
	}
	printf("================================================== Danh sach don hang ==================================================\n");
	printf(" %-10s | %-30s | %-16s | %-20s | %-12s \n",
           "Ma don hang", "Ho ten", "Ngay dat hang", "Tong tien", "Trang thai");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    for (int i=0;i<length;i++) {
        printf(" %-11s | %-30s |    %02d/%02d/%4d    | %-20.0f | %-12s \n",
		    don[i].ma, don[i].name, don[i].sn.date, don[i].sn.month, don[i].sn.year, don[i].money, don[i].status);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}	

void updateStatus(Order *don, int length){
	char search[50];
	printf("Nhap ma: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<length;i++){
		if(strcmp(don[i].ma, search)==0){
			printf("Nhap trang thai moi: ");
			fgets(don[i].status, sizeof(don[i].status), stdin);
			don[i].status[strcspn(don[i].status, "\n")]=0;
			printf("Cap nhat thanh cong!\n");
			return;
		}
	}
	printf("Ko tim thay ma!\n");
}

void earse(Order *don, int *length){
	char search[50];
	printf("Nhap ma: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<*length;i++){
		if(strcmp(don[i].ma, search)==0){
			for(int j=i;j<*length-1;j++){
				don[j]=don[j+1];
			}
			(*length)--;
			printf("Xoa thanh cong!\n");
			return;
		}
	}
	printf("Ko tim thay ma!\n");
}

void sort(Order *don, int length){
	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1-i;j++){
     	    if(don[j].money>don[j+1].money){
     	    	int temp=don[j].money;
     	    	don[j].money=don[j+1].money;
     	    	don[j+1].money=temp;
     	    }
     	}
    }
    printf("Sap xep thanh cong!");
}

void search(Order *don, int length){
	char search[50];
	printf("Nhap ma: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<length;i++){
		if(strcmp(don[i].ma, search)==0){
			printf("Tim thay thong tin don hang: \n");
			printf("================================================== Danh sach don hang ==================================================\n");
			printf(" %-10s | %-30s | %-16s | %-20s | %-12s \n",
		           "Ma don hang", "Ho ten", "Ngay dat hang", "Tong tien", "Trang thai");
		    printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf(" %-11s | %-30s |    %02d/%02d/%4d    | %-20.0f | %-12s \n",
		    don[i].ma, don[i].name, don[i].sn.date, don[i].sn.month, don[i].sn.year, don[i].money, don[i].status);
		    printf("------------------------------------------------------------------------------------------------------------------------\n");
	        return;
	    }
	}
	printf("Ko tim thay don hang!\n");
}

int main(){
	int choice;
	int length=0;
	Order don[50];
	int flag=0;
	do{
		printf("\n================== Menu ===================");
		printf("\n1. Nhap thong tin don hang");
		printf("\n2. Hien thi thong tin don hang");
		printf("\n3. Cap nhat trang thai don hang");
		printf("\n4. Xoa don hang theo ma");
		printf("\n5. Sap xep thong tin don hang theo tong tien");
		printf("\n6. Tim kiem thong tin don hang theo ma");
		printf("\n7. Thoat");
		printf("\nLua chon cua ban la: ");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1:{
				enterList(don, &length);
				flag=1;
				break;
			}
			case 2:{
				if(flag==0) printf("Chua co don hang nao! Vui long chon 1!\n");
				else display(don,length);
				break;
			}
			case 3:{
				if(flag==0) printf("Chua co don hang nao! Vui long chon 1!\n");
				else updateStatus(don,length);
				break;
			}
			case 4:{
				if(flag==0) printf("Chua co don hang nao! Vui long chon 1!\n");
				else earse(don, &length);
				break;
			}
			case 5:{
				if(flag==0) printf("Chua co don hang nao! Vui long chon 1!\n");
				else sort(don,length);
				break;
			}
			case 6:{
				if(flag==0) printf("Chua co don hang nao! Vui long chon 1!\n");
				else search(don,length);
				break;
			}
			case 7:{
				printf("Sayonara!");
				exit(0);
			}
		default:
			printf("Ko co lua chon %d\n", choice);
		}
	} while (choice != 7);
}
