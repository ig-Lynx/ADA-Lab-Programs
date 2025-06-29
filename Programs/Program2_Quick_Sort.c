#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<stdlib.h>

int i , j ; // global variables

int partition(int a[] , int low , int high);

void quicksort(int a[] , int low , int high){
    if(low < high){
        int pivot = partition(a , low , high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high); 
    }
}

// Partition Function
int partition(int a[] , int low , int high){
    int pivot = a[low];
    int temp;
    int i = low ;
    int j = high ;

    while(i<= j){
        while(a[i]<= pivot)
            i++;
        while(a[j] > pivot)
            j--;
        
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }   
    }

    // when (i >= j)
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void generate_random(int a[] , int n){

    srand(time(0));

    for(i = 0 ; i  < n ; i++){
        a[i] = rand() % 100000;
    }
}

int main(){
    int a[80000];
    struct timeval t;
    double start , end ;
    FILE *fp , *pipe ;

    fp = fopen("quicksort.txt","w");

    for(i = 10000 ; i <= 50000 ; i+= 10000){

        generate_random(a , i);

        gettimeofday(&t,NULL);
        start = t.tv_sec + (t.tv_usec / 1000000.0);
        quicksort(a,0,i-1);
        gettimeofday(&t,NULL);
        end = t.tv_sec +(t.tv_usec / 1000000.0);
        
        printf("%d \t %.6lf \n",i,(end-start)*1000);
        fprintf(fp,"%d \t %.6lf \n",i,(end-start)*1000);
    }

    fclose(fp);

    pipe = popen("gnuplot --persist","w");
    fprintf(pipe,"set title 'Run Time Analysis  of Quick Sort'; \n");
    fprintf(pipe,"set ylabel 'Time [ms]'; \n");
    fprintf(pipe,"set xlabel 'Input Size(n)'; \n");
    fprintf(pipe,"plot 'quicksort.txt' using 1:2 title 'Quick-sort' with linespoints; \n");

    pclose(pipe);
    return 0;
}