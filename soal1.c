/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : Danny Rahmat Pratama (13224019)
 *   Nama File           : Soal1.c
 *   Deskripsi           : Mencari degree, degree maksimal, dan isolated vertex
 * 
 */

#include <stdio.h>

int getSum(int arr[], int n) {

    // Initialize sum to 0
    int sum = 0;
    for (int i = 0; i < n; i++) {

        // Add each element to sum
        sum += arr[i];
    }
    return sum;
}

int main(){
    int matSize = 0;
    scanf("%d", &matSize);

    int degMat[matSize];

    // Inisiasi degree
    for(int i = 0; i < matSize; i++){
        degMat[i] = 0;
    }

    int maxVertex = 0;
    int idxMaxVertex = 0;

    int isIsolated[matSize];

    // Insiasi isIsolated
    for(int i = 0; i < matSize; i++){
        isIsolated[i] = 0;
    }

    // Input matrix
    int adjMat[matSize][matSize];
    for(int i = 0; i < matSize; i++){
        for(int j = 0; j < matSize; j++){
            scanf("%d", &adjMat[i][j]);
            degMat[i] += adjMat[i][j];
        }
    }

    // Mencari indeks max vertex
    for(int i = 0; i < matSize; i++){
        if(degMat[i] > maxVertex){
            maxVertex = degMat[i];
            idxMaxVertex = i;
        }

        if (degMat[i] == 0){
            isIsolated[i] = 1;
        }
    }

    // Print output
    for(int i = 0; i < matSize; i ++){
        printf("DEGREE %d %d\n", i, degMat[i]);
    }

    printf("MAX_VERTEX %d\n", idxMaxVertex);

    if(getSum(isIsolated, matSize) == 0){
        printf("ISOLATED NONE");
    } else{
        printf("ISOLATED");
        for(int i = 0; i < matSize; i++){
            if(isIsolated[i] == 1){
                printf(" %d", i);
            }
        }
    }


}
