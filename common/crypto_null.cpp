
class CCrypto
{
public:
	static void RSASignSHA256(unsigned char const *, unsigned int, unsigned char *, unsigned int *,
							  unsigned char const *, unsigned int);
	static void RSAVerifySignatureSHA256(unsigned char const *, unsigned int, unsigned char const *, unsigned int,
										 unsigned char const *, unsigned int);
};

void CCrypto::RSASignSHA256(unsigned char const *, unsigned int, unsigned char *, unsigned int *, unsigned char const *,
							unsigned int)
{
}

void CCrypto::RSAVerifySignatureSHA256(unsigned char const *, unsigned int, unsigned char const *, unsigned int,
									   unsigned char const *, unsigned int)
{
}