#include "tls_util.h"
#include "stat_context.h"
#include <stdlib.h>
#include <stdio.h>

StatContext::StatContext() 
{ 
    counter_ = 0; 
}

StatContext* StatContext::GetInstance()
{
    StatContext *p = (StatContext *)get_tls_slot0();
    if (NULL != p)
    {
        return p;
    }

	_CreateInstance(p);
    
    StatManager::GetInstance()->Register(p);
    printf("__thread: %p\n", p);
    
    return p;
}

void StatContext::UpdateCounter()
{
	++counter_;
}

inline int StatContext::GetCounter() const
{
	return counter_;
}

void StatContext::_CreateInstance(StatContext *&p)
{
    p = new StatContext;
    set_tls_slot0(p);
}


StatManager *StatManager::stat_manager_ = NULL;
int StatManager::counter_ = 0;
std::vector<StatContext *> StatManager::stat_context_vec_;

StatManager* StatManager::GetInstance()
{
	if (NULL == stat_manager_)
	{
		stat_manager_ = new StatManager;
	}
	return stat_manager_;
}

void StatManager::Register(StatContext *p)
{
	stat_context_vec_.push_back(p);
}

int StatManager::GetCounter()
{
	int count = 0;
	int i;
	for (i = 0; i < stat_context_vec_.size(); i++)
	{
		count += stat_context_vec_[i]->GetCounter();
	}
	return count;
}


