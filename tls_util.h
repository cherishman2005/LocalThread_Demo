#ifndef _TLS_UTIL_H
#define _TLS_UTIL_H

#define DECL_TLS    __thread

class GTLS_Slots
{
public:
	static DECL_TLS void *slot0;
	static DECL_TLS void *slot1;
	static DECL_TLS void *slot2;
	static DECL_TLS void *slot3;
	static DECL_TLS void *slot4;
	
};

void *get_tls_slot0();
void *get_tls_slot1();
void *get_tls_slot2();
void *get_tls_slot3();
void *get_tls_slot4();

void set_tls_slot0(void *);
void set_tls_slot1(void *);
void set_tls_slot2(void *);
void set_tls_slot3(void *);
void set_tls_slot4(void *);

//预定义，标记已被占用
#define GTLS_STAT_CONTEXT   GTLS_Slots::slot0

#endif