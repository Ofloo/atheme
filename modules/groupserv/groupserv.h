/* groupserv.h - group services public interface
 *
 * Include this header for modules other than groupserv/main
 * that need to access group functionality.
 *
 * Copyright (C) 2010 Atheme Development Group
 */

#ifndef GROUPSERV_H
#define GROUPSERV_H

#include "main/groupserv_common.h"

mygroup_t * (*mygroup_add)(const char *name);
mygroup_t * (*mygroup_find)(const char *name);

unsigned int (*mygroup_count_flag)(mygroup_t *mg, unsigned int flag);
unsigned int (*myuser_count_group_flag)(myuser_t *mu, unsigned int flagset);

groupacs_t * (*groupacs_add)(mygroup_t *mg, myuser_t *mu, unsigned int flags);
groupacs_t * (*groupacs_find)(mygroup_t *mg, myuser_t *mu, unsigned int flags);
void (*groupacs_delete)(mygroup_t *mg, myuser_t *mu);
bool (*groupacs_sourceinfo_has_flag)(mygroup_t *mg, sourceinfo_t *si, unsigned int flag);

void use_groupserv_main_symbols(module_t *m)
{
    MODULE_TRY_REQUEST_DEPENDENCY(m, "groupserv/main");
    MODULE_TRY_REQUEST_SYMBOL(m, mygroup_add, "groupserv/main", "mygroup_add");
    MODULE_TRY_REQUEST_SYMBOL(m, mygroup_find, "groupserv/main", "mygroup_find");
    MODULE_TRY_REQUEST_SYMBOL(m, mygroup_count_flag, "groupserv/main", "mygroup_count_flag");
    MODULE_TRY_REQUEST_SYMBOL(m, myuser_count_group_flag, "groupserv/main", "myuser_count_group_flag");
    MODULE_TRY_REQUEST_SYMBOL(m, groupacs_add, "groupserv/main", "groupacs_add");
    MODULE_TRY_REQUEST_SYMBOL(m, groupacs_find, "groupserv/main", "groupacs_find");
    MODULE_TRY_REQUEST_SYMBOL(m, groupacs_delete, "groupserv/main", "groupacs_delete");
    MODULE_TRY_REQUEST_SYMBOL(m, groupacs_sourceinfo_has_flag, "groupserv/main", "groupacs_sourceinfo_has_flag");
}

#endif
