/*
** test.c for pamela in /home/legald_t/pamela
** 
** Made by Dieu
** Login   <legald_t@epitech.eu>
** 
** Started on  Wed Oct 12 19:09:46 2016 Dieu
// Last update Mon Oct 24 18:01:56 2016 Dieu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAM_SM_AUTH
#include <security/pam_appl.h>
#include <security/pam_modules.h>

PAM_EXTERN int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("open session\n");
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("close session\n");
  return PAM_SUCCESS;
}

