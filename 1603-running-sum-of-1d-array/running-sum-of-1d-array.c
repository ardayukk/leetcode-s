#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int fd[2];
    pipe(fd);
    int n = numsSize;
    *returnSize = numsSize;
    int *arr = (int *)malloc(n * sizeof(int));

    pid_t pid = fork();

    if(pid == 0){
        close(fd[0]);
        for(int i = 1; i < numsSize; i++){
            nums[i] += nums[i-1];
        }
        write(fd[1], nums, n*sizeof(int));
        close(fd[1]);
        _exit(0);
    } else {
        close(fd[1]);
        read(fd[0], arr, n*sizeof(int));
        close(fd[0]);

        wait(NULL);
        return arr;
    }
    return NULL;
}