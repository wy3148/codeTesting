#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int* insertSort(int* a, int size, int* returnSize){

    *returnSize = size;

    int i,j;
    int m;

    int* res = malloc(sizeof(int)*size);

    res[0] = a[0];
    j=0;

    for(i = 1; i < size; i++){

        if(a[i] > res[j]){
            j++;
            res[j] = a[i];
        }else{
            int pos = 0;
            for( m =j; m >=0; m--){

                if(a[i] > res[m]){
                    pos = m+1;
                    break;
                }
            }

            if(pos == 0){
                m = -1;
            }

            int s;
            int tmp1 = res[m+1];
            for(s = m+1; s <= j+1; s++){
                int tmp2 = res[s+1];
                res[s+1] = tmp1;
                tmp1 = tmp2;
            }
            res[m+1] = a[i];
            j++;
        }
    }

    return res;
}

int main(int argc, char** argv){

    int a[] = {5,4,3,2,1,9};
    int returnSize = 0;
    int* res = insertSort(a,6,&returnSize);

    int i;
    for( i = 0 ; i < 6; i++){
        printf("%d\n",res[i]);
    }

    return 0;
}
