void use_wrapper();
void use_tokens();

#if UINTPTR_MAX == 0xffFFffFF
// 32-bit platform
#warning Building for 32 bit
#elif UINTPTR_MAX == 0xffFFffFFffFFffFF
// 64-bit platform
#warning Building for 64 bit
#else
#error Unknown platform - does not look either like 32-bit or 64-bit
#endif

int main() {
    use_wrapper();
    use_tokens();
}
