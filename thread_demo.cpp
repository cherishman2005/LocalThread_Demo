#include <stdio.h>
#include <pthread.h>
#include "stat_context.h"

#define NLOOP (2)

void *MyTest(void *arg)
{
    int *num = (int *)arg;
    StatContext *stat = StatContext::GetInstance();
    
    int i;
    for (i = 0; i < *num; i++)
    {
        stat->UpdateCounter();
    }
    //printf("__thread: %p, counter: %d\n", 
    //    StatContext::GetInstance(), StatContext::GetInstance()->GetCounter());
}

int g_loop[NLOOP] = {5000, 1000};

int main()
{
	pthread_t tid[NLOOP];
	int i;
    for (i = 0; i < NLOOP; i++)
    {
	    ::pthread_create(&tid[i], NULL, MyTest, (void *)&g_loop[i]);
	}

    for (i = 0; i < NLOOP; i++)
    {
	    ::pthread_join(tid[i], NULL);
	}	

	printf("statistic total counter: %d\n", 
	    StatManager::GetInstance()->GetCounter());
	
    return 0;
}




