#include "util.h"

static char buf[22];

const char *
get_url(int zoom, int x, int y)
{
   int xq, yq, val;
   xq = x;
   yq = y;
   buf[zoom] = '\0';
   while (zoom > 0)
     {
        val = (xq % 2) + (yq % 2) * 2;
        xq /= 2;
        yq /= 2;
		buf[zoom - 1] = val + 0x30;
        zoom--;
     }
   return buf;
}
