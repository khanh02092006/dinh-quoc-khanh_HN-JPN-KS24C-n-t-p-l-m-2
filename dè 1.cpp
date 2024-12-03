#include<stdio.h>
int main () {
    int mang[100][100];
    int n, m;
    int lua_chon;

    while (1) {
      
        printf("\n1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tich\n");
        printf("4. In ra cac phan tu tren duong cheo chinh\n");
        printf("5. In ra cac phan tu tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                printf("Nhap so hang: ");
                scanf("%d", &n);
                printf("Nhap so cot: ");
                scanf("%d", &m);
                if (n > 100 || m > 100) {
                    printf("Kich thuoc khong hop le! (Toi da 100x100).\n");
                    break;
                }
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("Phan tu [%d][%d]: ", i, j);
                        scanf("%d", &mang[i][j]);
                    }
                }
                break;

            case 2:
                printf("Cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", mang[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                int tich = 1;
                printf("Cac phan tu tren bien:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                            printf("%d ", mang[i][j]);
                            tich *= mang[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren bien: %d\n", tich);
                break;
            }

            case 4:
                printf("Cac phan tu tren duong cheo chinh:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", mang[i][i]);
                }
                printf("\n");
                break;

            case 5:
                printf("Cac phan tu tren duong cheo phu:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", mang[i][m - 1 - i]);
                }
                printf("\n");
                break;

            case 6: {
                int cheo_chinh[100], k = 0;

                
                for (int i = 0; i < n && i < m; i++) {
                    cheo_chinh[k++] = mang[i][i];
                }

                for (int i = 0; i < k - 1; i++) {
                    for (int j = i + 1; j < k; j++) {
                        if (cheo_chinh[i] > cheo_chinh[j]) {
                            int temp = cheo_chinh[i];
                            cheo_chinh[i] = cheo_chinh[j];
                            cheo_chinh[j] = temp;
                        }
                    }
                }

                
                k = 0;
                for (int i = 0; i < n && i < m; i++) {
                    mang[i][i] = cheo_chinh[k++];
                }

                printf("Ma tran sau khi sap xep duong cheo chinh:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", mang[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 7: {
                int x, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (mang[i][j] == x) {
                            printf("Gia tri %d nam o vi tri [%d][%d]\n", x, i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay gia tri %d trong mang.\n", x);
                }
                break;
            }

            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
        }
    }
    return 0;
}

