#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

int B[80000],  i , j;

void mergesort(int a[] , int low , int high);
void merge(int a[] , int low , int mid , int high);

void mergesort(int a[] , int low , int high){
    if(low < high){
        int mid = (high + low) /2 ;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
 
void merge(int a[] , int low , int mid , int high){
    int i = low , j = mid+1 , k = low ; // k is for new array

    while(i <= mid && j <= high){
        if(a[i] <= a[j])
            B[k++] = a[i++];
        else 
            B[k++] = a[j++];
    }

    while(i<= mid) B[k++] = a[i++];
    while(j <= high) B[k++] = a[j++];

    for(i= low ; i <= high ; i++)
        a[i] = B[i];
}

void generate_random(int a[] , int n){
    srand(time(0));

    for(i = 0 ; i< n ; i++)
        a[i] = rand() % 100000;
}

int main(){
    int a[80000];
    struct timeval t;
    double start , end ;
    FILE *fp , *pipe;

    fp = fopen("mergesort.txt","w");

    for(i = 10000 ; i<= 80000 ; i+= 10000){

        generate_random(a,i);

        gettimeofday(&t , NULL);

        start = t.tv_sec + (t.tv_usec / 1000000.0);

        mergesort(a,0,i-1);

        gettimeofday(&t,NULL);
        end = t.tv_sec + (t.tv_usec / 1000000.0);

        printf("%d \t %.6lf \n",i,end-start);
        fprintf(fp,"%d \t %.6lf \n",i,end-start);
    }

    fclose(fp);

    pipe = popen("gnuplot --persist" , "w");
    fprintf(pipe,"set title 'Run time analysis of Merge Sort'; \n");
    fprintf(pipe,"set ylabel 'Time(ms)'; \n");
    fprintf(pipe,"set xlabel 'Input Size (n)' ;\n");
    fprintf(pipe,"plot 'mergesort.txt' using 1:2 title 'Merge Sort' with linespoints; \n");
    pclose(pipe);

    return 0;
}