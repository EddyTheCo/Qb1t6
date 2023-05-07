#include"encoding/qb1t6.hpp"
#undef NDEBUG
#include <assert.h>


using namespace qencoding::qb1t6;

int main(int argc, char** argv)
{
    auto binary=QByteArray::fromHex("00");
    auto ternary=get_Trytes_from_Bytes(binary);
    assert(ternary==QByteArray("99"));

    binary=QByteArray::fromHex("0001027e7f8081fdfeff");
    ternary=get_Trytes_from_Bytes(binary);
    assert(ternary==QByteArray("99A9B9RESEGVHVX9Y9Z9"));


    binary=QByteArray::fromHex("9ba06c78552776a596dfe360cc2b5bf644c0f9d343a10e2e71debecd30730d03");
    ternary=get_Trytes_from_Bytes(binary);
    assert(ternary==QByteArray("GWLW9DLDDCLAJDQXBWUZYZODBYPBJCQ9NCQYT9IYMBMWNASBEDTZOYCYUBGDM9C9"));

	return 0;
}
