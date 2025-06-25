#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
//OpenSSL lib
#include <openssl/ssl.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <openssl/evp.h>
//Declaration
#include "opensslLib.h"

//This function allows you to use different types of hashing and encryption functions
//EVP_md5()
//EVP_sha1()
//EVP_sha224()
//EVP_sha256()
//EVP_sha384()
//EVP_sha512()
// The purpose of this function is to take a string and hash it using a tested algorithms by OpenSSL
std::string hash_sha1_evp(const std::string& password)
{
	EVP_MD_CTX *ctx = EVP_MD_CTX_new(); //create a new context
	//EVP_sha256() returns a pointer to the SHA-256 algorithm implementation inside OpenSSl
	//You can alson use EVP_sha1() or EVP_sha512()
	const EVP_MD *md = EVP_sha1(); // Select the digest algorithm

	//hash holds the final hash bytes (EVP_MAX_MD_SIZE, which is 64 for SHA-512
	unsigned char hash[EVP_MAX_MD_SIZE];
	//length: output parameter to hold the number of bytes the hash actually used (32 for SHA-256)
	unsigned int length = 0;
	//Initializes the context ctx to use the md (SHA-256), nullptr means use default OpenSSL engine)
	EVP_DigestInit_ex(ctx, md, nullptr);
	//Feeds the input into the hashing function, You can call this more than once to hash data in chunks for a file
	EVP_DigestUpdate(ctx, password.c_str(), password.size());
	//Finalizes the hash computation, files the hash buffer with teh final digest and sets length to the number of bytes
	EVP_DigestFinal_ex(ctx, hash, &length);
	//Frees the memory allocated for the digest context
	EVP_MD_CTX_free(ctx); //cleanup
	//convert the raw bytes to hex
	std::ostringstream oss;
	for(unsigned int i = 0; i < length; ++i)
		oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	return oss.str();
}

std::string hash_sha512_evp(const std::string& password)
{
	EVP_MD_CTX *ctx = EVP_MD_CTX_new(); //create a new context
	//EVP_sha256() returns a pointer to the SHA-256 algorithm implementation inside OpenSSl
	//You can alson use EVP_sha1() or EVP_sha512()
	const EVP_MD *md = EVP_sha512(); // Select the digest algorithm

	//hash holds the final hash bytes (EVP_MAX_MD_SIZE, which is 64 for SHA-512
	unsigned char hash[EVP_MAX_MD_SIZE];
	//length: output parameter to hold the number of bytes the hash actually used (32 for SHA-256)
	unsigned int length = 0;
	//Initializes the context ctx to use the md (SHA-256), nullptr means use default OpenSSL engine)
	EVP_DigestInit_ex(ctx, md, nullptr);
	//Feeds the input into the hashing function, You can call this more than once to hash data in chunks for a file
	EVP_DigestUpdate(ctx, password.c_str(), password.size());
	//Finalizes the hash computation, files the hash buffer with teh final digest and sets length to the number of bytes
	EVP_DigestFinal_ex(ctx, hash, &length);
	//Frees the memory allocated for the digest context
	EVP_MD_CTX_free(ctx); //cleanup
	//convert the raw bytes to hex
	std::ostringstream oss;
	for(unsigned int i = 0; i < length; ++i)
		oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	return oss.str();
}
