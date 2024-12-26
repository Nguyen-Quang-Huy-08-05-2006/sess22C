#include<stdio.h>
#include<string.h>

typedef struct{
    char id[50];
    char name[50];
    int age;
}Students;

void printfList();
void addStudent();
void fixInfo();
void deleteStudent();
void searchId();
void sortList();
void save();

int main(){
	FILE *file;
	file=fopen("SinhVien.bin","wb");
	if(file==NULL){
		printf("ko the mo file");
		return 1;
	}
    Students students[100];
    int studentsNum=0;
    int answer;
    do{
        printf("-----MENU-----\n");
        printf("1. In danh sach sv.\n");
        printf("2. Them sv.\n");
        printf("3. Sua thong tin sv.\n");
        printf("4. Xoa sv.\n");
        printf("5. Tim kiem sv.\n");
        printf("6. Sap xep danh sach.\n");
        printf("7. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&answer);
        getchar(); 

        switch(answer){
            case 1:
				printfList(students,&studentsNum);
			break;
            case 2:
				addStudent(students,&studentsNum);
				save(students,studentsNum);
			break;
            case 3:
				fixInfo(students,&studentsNum);
				save(students,studentsNum);
			break;
            case 4:
				deleteStudent(students,&studentsNum);
				save(students,studentsNum);
			break;
            case 5:
				searchId(students,studentsNum);
			break;
            case 6:
				sortList(students,studentsNum);
				save(students,studentsNum);
			break;
            case 7:
			printf("---------------------------------\n");
			printf("Ket thuc chuong trinh.\n");
			return 0;
        }
    }while(answer!=7);
	fclose(file);
    return 0;
}

void save(Students students[],int studentsNum){
    FILE *file=fopen("SinhVien.bin","wb");
    if(file==NULL){
        printf("Khong the ghi vao file.\n");
        return;
    }
    fwrite(students,sizeof(Students),studentsNum,file);
    fclose(file);
}


void printfList(Students students[],int *studentsNum){
    for(int i=0;i<*studentsNum;i++){
        printf("Sinh vien [%d]\n",i+1);
        printf("[ID: %s] [Name: %s] [Age: %d]\n",students[i].id,students[i].name,students[i].age);
    }
}

void addStudent(Students students[],int *studentsNum){
    printf("Nhap thong tin sinh vien:\n");
    printf("ID: ");
    fgets(students[*studentsNum].id,50,stdin);
    students[*studentsNum].id[strcspn(students[*studentsNum].id,"\n")]='\0';
    printf("Name: ");
    fgets(students[*studentsNum].name,50,stdin);
    students[*studentsNum].name[strcspn(students[*studentsNum].name,"\n")]='\0';
    printf("Age: ");
    scanf("%d",&students[*studentsNum].age);
    getchar();
    (*studentsNum)++;
}

void fixInfo(Students students[],int *studentsNum){
    char id[50];
    printf("Nhap ID sinh vien ban muon sua: ");
    fgets(id,50,stdin);
    id[strcspn(id,"\n")]='\0';

    for(int i=0;i<*studentsNum;i++){
        if(strcmp(students[i].id,id)==0){
            printf("Sua thong tin:\n");
            printf("Name: ");
            fgets(students[i].name,50,stdin);
            students[i].name[strcspn(students[i].name,"\n")]='\0';
            printf("Age: ");
            scanf("%d",&students[i].age);
            getchar();
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID: %s\n",id);
}

void deleteStudent(Students students[],int *studentsNum){
    char id[50];
    printf("Nhap ID sinh vien ban muon xoa: ");
    fgets(id,50,stdin);
    id[strcspn(id,"\n")]='\0';
    for(int i=0;i<*studentsNum;i++){
        if(strcmp(students[i].id,id)==0){
            printf("Thong tin sinh vien:\n");
            printf("[ID: %s] [Name: %s] [Age: %d]\n",students[i].id,students[i].name,students[i].age);
            return;
        }
    }
}

void searchId(Students students[],int studentsNum){
    char id[50];
    printf("Nhap ID sinh vien ban muon tim: ");
    fgets(id,50,stdin);
    id[strcspn(id,"\n")]='\0';
    for(int i=0;i<studentsNum;i++){
        if(strcmp(students[i].id,id)==0){
            printf("Thong tin sinh vien:\n");
            printf("[ID: %s] [Name: %s] [Age: %d]\n",students[i].id,students[i].name,students[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID: %s\n",id);
}

void sortList(Students students[],int studentsNum){
    for(int i=0;i<studentsNum-1;i++){
        for(int j=i+1;j<studentsNum;j++){
            if(strcmp(students[i].id,students[j].id)>0){
                Students temp=students[i];
                students[i]=students[j];
                students[j]=temp;
            }
        }
    }
}
