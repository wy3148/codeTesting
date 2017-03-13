#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


//insert sort complexity  O(n) best, worst  O(n^2)


//from wiki
void insertion_sort(int arr[], int len) 
{
    int i, j;
    int temp;
    for (i = 1; i < len; i++) 
    {
        temp = arr[i]; 
//與已排序的數逐一比較，大於temp時，該數向後移
        j = i - 1;  
// 如果将赋值放到下一行的for循环内, 会导致在第10行出现j未声明的错误
        for (; j >= 0 && arr[j] > temp; j--) 
       { //j循环到-1时，由于[[短路求值]](http://zh.wikipedia.org/wiki/短路求值)，不会运算array[-1]
            arr[j + 1] = arr[j];
        }
    arr[j + 1] = temp; 
    //被排序数放到正确的位置
    }
}


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

            //tooooooo complicated
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
