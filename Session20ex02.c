#include<stdio.h>
#include<string.h>
struct SanPham{
	char maSanPham[50];
	char tenSanPham[100];
	float giaNhap;
	float giaBan;
	int soLuong;
};
struct SanPham sanPham[100];
	int n=0;
	float doanhThu=0.0;
//
void sanPhamCanThem();
//
void hienThiSanPham();
//
void capNhatThongTin();
//
void tangDan();
//
void giamDan();
//
void timSanPham();
//
void banSanPham();
//
void doanhThuSanPham();
//
int main(){
	int choice;
	do{
		printf("MENU\n");
		printf("1. Nhap so luong va thong tin san pham\n");
		printf("2. Hien thi danh sach san pham\n");
		printf("3. Nhap san pham\n");
		printf("4. Cap nhat thong tin san pham\n");
		printf("5. Sap xep san pham theo gia(tang/giam)\n");
		printf("6. Tim kiem san pham\n");
		printf("7. Ban san pham\n");
		printf("8. Doanh thu hien tai\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				sanPhamCanThem();
				break;
			}
			case 2:{
				hienThiSanPham();
				break;
			}
			case 3:{
				sanPhamCanThem();
				break;
			}
			case 4:{
				capNhatThongTin();
				break;
			}
			case 5:{
				int choose=0;
				printf("1. Sap xep gia tang dan\n");
				printf("2. Sap xep gia giam dan\n");
				printf("Lua chon cua ban: ");
				scanf("%d", &choose);
				if(choose==1){
					tangDan();
				}
				if(choose==2){
					giamDan();
				}
				break;
			}
			case 7:{
				timSanPham();
				break;
			}
			case 8:{
				doanhThuSanPham();
				break;
			}
		}
	}while(choice!=9);
}
//
//
void sanPhamCanThem(){
	struct SanPham sanPhamMoi;
	printf("Ban hay nhap ma san pham: ");
    scanf("%s", sanPhamMoi.maSanPham);
    
    printf("Ban hay nhap ten san pham: ");
    scanf("%s", sanPhamMoi.tenSanPham);
    
    printf("Ban hay nhap gia nhap cua san pham: ");
    scanf("%f", &sanPhamMoi.giaNhap);
    
    printf("Ban hay nhap gia ban cua san pham: ");
    scanf("%f", &sanPhamMoi.giaBan);
    
    printf("Ban hay nhap so luong cua san pham: ");
    scanf("%d", &sanPhamMoi.soLuong);
    
    for(int i=0; i<n; i++) {
        if(strcmp(sanPham[i].maSanPham, sanPhamMoi.maSanPham) == 0){
            sanPham[i].soLuong += sanPhamMoi.soLuong;
            doanhThu -= sanPhamMoi.giaNhap * sanPhamMoi.soLuong;
            printf("San pham da co san nen chi tang so luong\n");
            return;
        }
    }
    sanPham[n++] = sanPhamMoi;
    doanhThu -= sanPhamMoi.giaNhap * sanPhamMoi.soLuong;
    printf("San pham da duoc nhap\n");
}
//
void hienThiSanPham(){
	for(int i=0; i<n; i++){
        printf("Ma san pham: %s\n", sanPham[i].maSanPham);
        printf("Ten san pham: %s\n", sanPham[i].tenSanPham);
        printf("Gia nhap cua san pham: %.2f\n", sanPham[i].giaNhap);
        printf("Gia ban cua san pham: %.2f\n", sanPham[i].giaBan);
        printf("So luong cua san pham: %s\n", sanPham[i].soLuong);
    }
}
//
void capNhatThongTin(){
	char id[50];	
	printf("Ban hay nhap ma san pham muon cap nhat: ");
    scanf("%s", id);
    for(int i=0; i<n; i++){
        if(strcmp(sanPham[i].maSanPham, id)==0){
            printf("Ban hay nhap ten san pham: ");
            scanf("%s", sanPham[i].tenSanPham);
            printf("Ban hay nhap gia nhap: ");
            scanf("%f", &sanPham[i].giaNhap);
            printf("Ban hay nhap gia ban: ");
            scanf("%f", &sanPham[i].giaBan);
            printf("Ban hay nhap so luong: ");
            scanf("%d", &sanPham[i].soLuong);
            printf("San pham da duoc cap nhat\n");
            return;
        }
    }
    printf("Khong tim thay san pham\n");
}
//
void tangDan(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(sanPham[i].giaBan>sanPham[j].giaBan){
				struct SanPham temp=sanPham[i];
				sanPham[i]=sanPham[j];
				sanPham[j]=temp;
			}
		}
	}
	printf("Da sap xep tang dan\n");
}
//
void giamDan(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(sanPham[i].giaBan<sanPham[j].giaBan){
				struct SanPham temp=sanPham[i];
				sanPham[i]=sanPham[j];
				sanPham[j]=temp;
			}
		}
	}
	printf("Da sap xep giam dan\n");
}
//
void timSanPham(){
	char search[100];
	printf("Ban hay nhap ten san pham ma ban muon tim: ");
	scanf("%s", search);
	for(int i=0; i<n; i++){
		if(strcmp(sanPham[i].tenSanPham, search)==0){
			printf("Ma san pham: %s\n", sanPham[i].maSanPham);
        	printf("Ten san pham: %s\n", sanPham[i].tenSanPham);
      		printf("Gia nhap cua san pham: %.2f\n", sanPham[i].giaNhap);
      	  	printf("Gia ban cua san pham: %.2f\n", sanPham[i].giaBan);
      	  	printf("So luong cua san pham: %s\n", sanPham[i].soLuong);
		}
	}
	printf("Khong tim thay\n");
}
//
void banSanPham(){
	char tim[20];
    int ban;
    printf("Ban hay nhap ma san pham can ban: ");
    scanf("%s", tim);
    printf("Ban hay nhap so luong muon ban: ");
    scanf("%d", &ban);
    for (int i=0; i<n; i++){
    	if(strcmp(sanPham[i].maSanPham, tim)==0){
    		if(sanPham[i].soLuong<ban){
    			printf("Khong con hang\n");
                return;
			}else if(sanPham[i].soLuong==0){
				sanPham[i].soLuong-=ban;
                doanhThu+=ban*sanPham[i].giaBan;
                printf("Ban thanh cong\n");
                return;
			}
		}
	}
	printf("Khong tim thay san pham\n");
}
//
void doanhThuSanPham(){
	printf("Doanh thu hien tai la: %.2f\n", doanhThu);
}
