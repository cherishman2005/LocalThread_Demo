#include "tls_util.h"
#include <stdlib.h>

DECL_TLS void *GTLS_Slots::slot0 = NULL;
DECL_TLS void *GTLS_Slots::slot1 = NULL;
DECL_TLS void *GTLS_Slots::slot2 = NULL;
DECL_TLS void *GTLS_Slots::slot3 = NULL;
DECL_TLS void *GTLS_Slots::slot4 = NULL;

void *get_tls_slot0()
{
    return GTLS_Slots::slot0;
}
void *get_tls_slot1()
{
    return GTLS_Slots::slot1;
}
void *get_tls_slot2()
{
    return GTLS_Slots::slot2;
}
void *get_tls_slot3()
{
    return GTLS_Slots::slot3;
}
void *get_tls_slot4()
{
    return GTLS_Slots::slot4;
}

void set_tls_slot0(void *p)
{
    GTLS_Slots::slot0 = p;
}
void set_tls_slot1(void *p)
{
    GTLS_Slots::slot1 = p;
}
void set_tls_slot2(void *p)
{
    GTLS_Slots::slot2 = p;
}
void set_tls_slot3(void *p)
{
    GTLS_Slots::slot3 = p;
}
void set_tls_slot4(void *p)
{
    GTLS_Slots::slot4 = p;
}


