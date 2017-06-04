#ifndef _SERVICELAYER_H
#define _SERVICELAYER_H

#include <stdbool.h>

#include "SimCom.h"

#define SL_CALLBACK_NUM 10
#define SL_BUF_LEN 200

bool sl_init();

#ifdef __cplusplus
extern "C" bool sl_config(char port, void (*callback)(char, char, const char*, SIMCOM_LENGTH_TYPE));
extern "C" bool sl_send(char from_port, char to_port, const char *data, SIMCOM_LENGTH_TYPE length);
#else
bool sl_config(char port, void (*callback)(char, char, const char*, SIMCOM_LENGTH_TYPE));
bool sl_send(char from_port, char to_port, const char *data, SIMCOM_LENGTH_TYPE length);
#endif

/*
  call it timely for your own project
*/
#ifdef __cplusplus
extern "C" bool sl_receive_intr();
#else
bool sl_receive_intr();
#endif

#endif
