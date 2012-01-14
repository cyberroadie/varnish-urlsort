C{
#include "../urlsort.c"
}C

sub vcl_recv {
    C{
       const char *url = VRT_r_req_url(sp);
       char *urldup = strdup(url);
       char *sorted = urlsort(urldup);
       VRT_l_req_url(sp, sorted, vrt_magic_string_end);
    }C
}

