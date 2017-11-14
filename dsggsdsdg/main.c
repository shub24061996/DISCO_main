#include<stdio.h>

void arr_print(int a[],int n){
    /*utility function : prints array a from index 0 to index n-1 both inclusive*/
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int find_path(int matrix[100][100],int path[100],int n,int curr_length){
    int i,response;

    if(curr_length == n)
        if(matrix[path[curr_length-1]][0] == 1) return 1;
        else return 0;

    for(i=0;i<n;i++){
        if(matrix[path[curr_length-1]][i] == 0 || matrix[i][n] == 1) continue;
        path[curr_length] = i;
        matrix[i][n] = 1;

        response = find_path(matrix,path,n,curr_length+1);
        if(response == 1){

            if(curr_length == n-1){
                path[n]++;

                // UNCOMMENT THE FOLLOWING LINES IF YOU ALSO WISH TO PRINT THE POSSIBLE PATHS FOUND

                /*int temp;
                temp = path[n];
                path[n] = 0;
                arr_print(path,n+1);
                path[n] = temp;*/


                path[curr_length] = 0;
                matrix[i][n] = 0;
            }
            return 0;
        }
        else{
            path[curr_length] = 0;
            matrix[i][n] = 0;
        }
    }
}

int main(){
    int n,m,i,j;
    scanf("%d",&n);
    scanf("%d",&m);

    int matrix[100][100],path[100];
    /*
        matrix is the adjacency matrix of the corresponding graph
        the nth column of matrix is not a part of the adjacency matrix
        the nth column is made only to track whether the ith row of matrix has been traversed
        if the ith row has been traversed(already covered in path) at any instant the value of
        matrix[i][n] is 1, else 0
    */


    /*
        path array stores the path being checked at any point of time. This solution is made
        by making minor changes to the solution of problem 1. To achieve that with as little changes
        as possible, path[n] has been used to store the number of possible paths at any point of time.
        That is, number_of_paths = path[n]
    */
    for(i=0;i<n+1;i++) path[i] = 0;

    for(i=0;i<n;i++) for(j=0;j<1+n;j++) matrix[i][j] = 0;

    for(i=0;i<m;i++){
        int in1,in2;
        scanf("%d %d",&in1,&in2);
        matrix[in1][in2] = 1;
        // matrix[in2][in1] = 1;
    }

    matrix[0][n] = 1;
    find_path(matrix,path,n,1);
    printf("Number of paths : %d\n",path[n]);

    return 0;
}

// m!das
