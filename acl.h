/*
 * acl.h - Define the ACL (Access Control List) interface
 */

#ifndef __ACL_H__
#define __ACL_H__

#define BLACK_LIST 0
#define WHITE_LIST 1

int init_acl(const char *path);
void free_acl(void);

int acl_match_host(const char *ip);
int acl_add_ip(const char *ip);
int acl_remove_ip(const char *ip);

int get_acl_mode(void);

int outbound_block_match_host(const char *host);

#endif // __ACL_H__
