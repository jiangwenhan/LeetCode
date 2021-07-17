#pragma once

unsigned int Log2n(unsigned int n) {
  return (n > 1) ? 1 + Log2n(n / 2) : 0;
}
