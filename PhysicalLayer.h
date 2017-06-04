#ifndef _PHYSICALLAYER_H
#define _PHYSICALLAYER_H

#include <stdbool.h>

#include "CharQueue.h"
#include "SimCom.h"

#define PH_BUF_LEN 500

/*
  These functions should be called only by the data link layer
*/
bool ph_init();
bool ph_receive(char *data);
bool ph_send(char data);

/*
  When data received by the device, call this function
  to tell the physical layer
*/
#ifdef __cplusplus
extern "C" bool ph_receive_intr(char data);
#else
bool ph_receive_intr(char data);
#endif

/*
  Modify it and call it timely for your own project
*/
#ifdef __cplusplus
extern "C" void ph_send_intr();
#else
void ph_send_intr();
#endif


#endif

