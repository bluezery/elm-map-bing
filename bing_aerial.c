#include "Elementary.h"
#include <Eina.h>

#define __UNUSED__  __attribute__((unused))

EAPI char *
map_module_source_name_get(void)
{
   return strdup("bing_aerial");
}

EAPI int
map_module_tile_zoom_min_get(void)
{
   return 1;
}

EAPI int
map_module_tile_zoom_max_get(void)
{
   return 21;
}

static const char *
get_url(int zoom, int x, int y)
{
   static char buf[22];
   char *idx;
   int xq, yq, xr, yr;
   int w;
   xq = x;
   yq = y;
   memset(buf, 0, sizeof(buf));
   while (zoom > 0)
     {
        xr = xq % 2;
        yr = yq % 2;
        xq = xq / 2;
        yq = yq / 2;
        w = xr + yr * 2;
        idx = buf + zoom - 1;
        w += 0x30;
        memcpy(idx, &w, 1);
        zoom--;
     }
   printf("%s\n", buf);
   return buf;
}

EAPI char *
map_module_tile_url_get(Evas_Object *obj __UNUSED__, int x, int y, int zoom)
{
   char buf[PATH_MAX];
   snprintf(buf, sizeof(buf), "http://ecn.t3.tiles.virtualearth.net/tiles/a%s.png?g=471",
            get_url(zoom, x, y));
   return strdup(buf);
}

EAPI char *
map_module_route_source_get(void)
{
   return NULL;
}

EAPI Eina_Bool
map_module_tile_geo_to_coord(const Evas_Object *obj __UNUSED__, int zoom __UNUSED__, double lon __UNUSED__, double lat __UNUSED__, int size __UNUSED__, int *x __UNUSED__, int *y __UNUSED__)
{
   return EINA_FALSE;
}

EAPI Eina_Bool
map_module_tile_coord_to_geo(const Evas_Object *obj __UNUSED__, int zoom __UNUSED__, int x __UNUSED__, int y __UNUSED__, int size __UNUSED__, double *lon __UNUSED__, double *lat __UNUSED__)
{
   return EINA_FALSE;
}

EAPI double
map_module_tile_scale_get(const Evas_Object *obj __UNUSED__, double lon __UNUSED__, double lat __UNUSED__, int zoom __UNUSED__)
{
	return 0;
}

static Eina_Bool
_module_init(void)
{
   return EINA_TRUE;
}

static void
_module_shutdown(void)
{
}

EINA_MODULE_INIT(_module_init);
EINA_MODULE_SHUTDOWN(_module_shutdown);
