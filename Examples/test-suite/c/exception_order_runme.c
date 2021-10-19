#include <stdio.h>
#include <stdlib.h>

#define SWIG_DEFINE_WRAPPER_ALIASES
#include "exception_order/exception_order_wrap.h"

int main() {
  A* a = A_new();

  A_foo(a);
  if (!SWIG_PendingException_get()) {
    fprintf(stderr, "foo: bad exception order\n");
  } else {
      SWIG_PendingException_reset();
  }

  A_bar(a);
  if (!SWIG_PendingException_get()) {
    fprintf(stderr, "bar: bad exception order\n");
  } else {
      SWIG_PendingException_reset();
  }

  A_foobar(a);
  if (!SWIG_PendingException_get()) {
    fprintf(stderr, "foobar: bad exception order\n");
  } else {
      SWIG_PendingException_reset();
  }

  A_barfoo(a, 1);
  if (!SWIG_PendingException_get()) {
    fprintf(stderr, "barfoo(1): bad exception order\n");
  } else {
      SWIG_PendingException_reset();
  }

  A_barfoo(a, 2);
  if (!SWIG_PendingException_get()) {
    fprintf(stderr, "barfoo(2): bad exception order\n");
  } else {
      SWIG_PendingException_reset();
  }

  exit(0);
}

