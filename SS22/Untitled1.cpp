#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char name[50];
	int age;
	float grade;
}Student;

void enterInfo(Student *students, int *length){
	int size;
	printf("Nhap so luong hoc sinh: ");
	scanf("%d", &size);
	getchar();
	for(int i=0;i<size;i++){
		Student hs;
		printf("Nhap thong tin hoc sinh %d: \n",i+1);
		printf("Nhap ten hs: ");
		fgets(hs.name,sizeof(hs.name),stdin);
		hs.name[strcspn(hs.name,"\n")]=0;
		printf("Nhap tuoi: ");
		scanf("%d", &hs.age);
		printf("Nhap diem trung binh: ");
		scanf("%f", &hs.grade);
		while(getchar() != '\n');
		students[*length+i]=hs;
	}
	*length+=size;
	printf("Nhap thong tin hoc sinh thanh cong!");
}

void display(Student *hs, int length){
	if(length<=0){
		printf("Mang rong!");
		return;
	}
	printf("======================= Danh sach hoc sinh ======================\n");
	for(int i=0;i<length;i++){
		printf("\nTen: %-30s | Tuoi: %-12d | Diem trung binh: %-8.1f\n",
		        hs[i].name,hs[i].age,hs[i].grade);
	}	    
}	

void average(Student *hs, int length){
	float sum=0;
	float avg;
	for(int i=0;i<length;i++){
		sum+=hs[i].grade;
	}
	avg=sum/(length*1.0);
	printf("Gia tri trung binh cua tat ca cac phan tu là: %.1f", avg);
}  	    

int main(){
	Student hs[100];
	int length=0;
	int choice;
	int flag=0;
	do{
	    printf("\n=================== Menu =================");
		printf("\n1. Nhap thong tin hs");
		printf("\n2. Hien thi thong tin hs");
		printf("\n3. Tinh diem trung binh cua tat ca hs");
		printf("\n4. Thoat");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice);
		getchar();
		switch (choice){
			case 1:{
				enterInfo(hs,&length);
				flag=1;
				break;
			}
			case 2:{
				if(flag==0) printf("Chua co thong tin hs nao! Vui long chon lai 1!");
				else display(hs,length);
				break;
			}
			case 3:{
				if(flag==0) printf("Chua co thong tin hs nao! Vui long chon lai 1!");
				else average(hs,length);
				break;
			}
			case 4:
				printf("Thoat chuong trinh!");
				exit(0);
		default:
			printf("Ko co lua chon %d", choice);
		}
	} while (choice!=4);
}
