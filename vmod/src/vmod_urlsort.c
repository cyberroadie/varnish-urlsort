#include "../urlsort.c"
#include "vrt.h"
#include "bin/varnishd/cache.h"
#include "vcc_if.h"

int init_function(struct vmod_priv *priv, const struct VCL_conf *conf) {
   return (0);
}

const char * vmod_sortquery(struct sess *sp, const char *in) {
  return urlsort(in);
}

