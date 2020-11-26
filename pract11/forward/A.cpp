#include "A.h"
#include "B.h"


void A::foo(const B& b) {
    b.foo(*this);
}
