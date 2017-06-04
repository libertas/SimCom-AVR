#ifndef _SIMCOM_H
#define _SIMCOM_H

#include <stdbool.h>
#include <stdint.h>

/*
  You can modify this for your own project
*/
#define SIMCOM_LENGTH_TYPE uint16_t
#define SIMCOM_DLENGTH_TYPE uint32_t

#ifdef __cplusplus
extern "C" bool simcom_init();
#else
bool simcom_init();
#endif

#endif

