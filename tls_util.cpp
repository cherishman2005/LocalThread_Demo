#include "tls_util.h"
#include <stdlib.h>

#define DECLARE_SLOT(i) DECL_TLS void *GTLS_Slots::slot##i = NULL;

DECLARE_SLOT(0)
DECLARE_SLOT(1)
DECLARE_SLOT(2)
DECLARE_SLOT(3)
DECLARE_SLOT(4)


#define DECLARE_SLOT_FUNC(ID) \
    void *get_tls_slot##ID() { return GTLS_Slots::slot##ID; } \
    void set_tls_slot##ID(void *p) { GTLS_Slots::slot##ID = p; }


DECLARE_SLOT_FUNC(0)
DECLARE_SLOT_FUNC(1)
DECLARE_SLOT_FUNC(2)
DECLARE_SLOT_FUNC(3)
DECLARE_SLOT_FUNC(4)
    

