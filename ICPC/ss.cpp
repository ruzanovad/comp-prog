#include <climits>
#include <stddef.h>
#include <stdint.h>
#include <cstdio>

template <typename T>
size_t num_bits()
{
    return sizeof (T) * (CHAR_BIT);
}

int main()
{
    printf("uint8_t : %d\n", num_bits<uint8_t>());
    printf("size_t : %d\n", num_bits<size_t>());
    printf("long long : %d\n", num_bits<long long>());
    printf("void* : %d\n", num_bits<void*>());
    printf("bool : %d\n", num_bits<bool>());
    printf("float : %d\n", num_bits<float>());
    printf("double : %d\n", num_bits<double>());
    printf("long double : %d\n", num_bits<long double>());
    printf("long double : %d\n", num_bits<unsigned long long >());
    return 0;
}