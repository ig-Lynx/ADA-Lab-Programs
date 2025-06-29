#include<stdio.h> 
#include<time.h> // data type such as time_t is defined here & handles time realted operations
#include<sys/time.h> // struct timeval t ; is defined in this & also gettimeofday 
#include<stdlib.h> // for functions like srand() to generate random numbers 


int i , j ; // global variables 

// function to generate random numbers
void generate_rand(int arr[] , int n){

    srand(time(0)); 
    // time 0 return the current time 
    // also srand sets a starting point (seed) ,
    // rand() produces random numbers 

    for(i = 0 ; i < n ; i++){
        arr[i] = rand() % 100000 ; // random number between 0 to 99,999
    }
}

// Selection sort program
void Selection_Sort(int arr[] , int n){
    
    for( i = 0 ; i < n ; i++){

        int min_idx = i ; // assuming that arr[i] is having the least value

        for(j = i+1 ; j < n ; j++){
            if ( arr[j] < arr[min_idx]){
                min_idx= j;
            }
        }

        // swap the positions now 
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp ;
    }
}

// Printing the array elements
void Print_arr(int arr[] , int n){
    for(i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[100000] ;
    struct timeval t;
    double start , end ; // track the execution time 
    FILE *fp , *pipe;  // file pointers to store sorting

    fp = fopen("Sorting.txt" ,"w");

    for(i = 10000 ; i <= 80000 ; i += 10000){

        generate_rand(arr,i); // call the random generating number funtion 

        gettimeofday(&t,NULL); // here second parameter is null becuase it the timezone

        start = t.tv_sec + t.tv_usec / 1000000.0; // start recording the time 

        Selection_Sort(arr,i); // selection sort algo

        gettimeofday(&t,NULL);

        end = t.tv_sec + t.tv_usec / 1000000.0; // execution end time 

        printf("%d \t %.6lf \n ", i , end - start); // print in terminal 
        fprintf(fp,"%d \t %.6lf \n",i, end-start); // store the data in file 

    }

    fclose(fp); // closing of the file 

    // plotting of graph using GNU plot 

    pipe = popen("gnuplot --persist","w");

    fprintf(pipe,"set title 'Run time analysis of Selection sort algo' \n");
    fprintf(pipe,"set xlabel 'Input'  \n"); // set the x axis as Input
    fprintf(pipe,"set ylabel 'Time [m sec]' \n"); // sets the y axis as Time(ms)
    fprintf(pipe,"plot 'Sorting.txt' using 1:2 title 'Selection Sort' with linespoints \n");

    pclose(pipe); // close gnuplot

    return 0;
}