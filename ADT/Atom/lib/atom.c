#include <string.h> /* memcpy   */
#include <limits.h> /* LONG_MIN */
#include "inc/atom.h"

#define NELEMS(x) ((sizeof (x)) / (sizeof ((x)[0])))

struct atom {
    struct atom *link;
    int          len;
    char        *str;
};

static struct atom *buckets[2048];
