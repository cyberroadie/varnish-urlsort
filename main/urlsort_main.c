#include "../urlsort.c"

int main(int argc, char *argv[]) {
  char *out;
  out = urlsort(argv[1]);
  puts(out);
}

