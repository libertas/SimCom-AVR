#include "SimCom.h"
#include "ServiceLayer.h"

bool simcom_init()
{
  return sl_init();
}
