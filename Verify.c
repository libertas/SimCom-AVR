#include "Verify.h"

char verify(const char *data, SIMCOM_LENGTH_TYPE length)
{
  char result = 0;
  SIMCOM_LENGTH_TYPE i;
  for(i = 0; i < length; i++) {
    result += data[i];
  }

  return result;
}
