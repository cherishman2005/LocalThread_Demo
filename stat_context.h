#ifndef _STAT_CONTEXT_H
#define _STAT_CONTEXT_H

#include <vector>
using namespace std;

class StatContext
{
public:
	static StatContext* GetInstance();
	void UpdateCounter();
	int GetCounter() const;
		
private:
	StatContext();
	~StatContext() {}
	static void _CreateInstance(StatContext *&p);
	
private:
	int counter_;
};


class StatManager
{
public:
	static StatManager* GetInstance();
	void Register(StatContext *p);
	static int GetCounter();
	
private:
	StatManager() {}
	~StatManager() {}
	
private:
	static StatManager *stat_manager_;
	static int counter_;
	static std::vector<StatContext *> stat_context_vec_;
};


#endif