#include <stdio.h>
#include <omp.h>

int main(){
	int myid, nthreads = 4;

	omp_set_num_threads(4);
	#pragma omp parallel private(myid)
	{
		myid = omp_get_thread_num();
	//	nthreads = omp_get_num_threads();
		printf("%d of %d - hello world!\n", myid, nthreads);
	}
	return 0;
}
