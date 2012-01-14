import urlsort;

sub vcl_recv {
  set req.url = urlsort.sortquery(req.url);
}

