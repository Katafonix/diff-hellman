#ifndef DIFFHELL_H
#define DIFFHELL_H
#include <string>
using namespace std;

class DiffHell
{
public:

    DiffHell(int value1,int value2);

    void generate_public_key();

    void generate_secret_key(int pub_key);

    string encrypt_message(string message);

    string decrypt_message(string message);

    void Set(int priv_key);

    int Get();

    int modpow(int a, int b, int m);

private:

    int public_key = 0;
    int p;
    int g;
    int private_key;
    int secret_key = 0;
};

#endif // DIFFHELL_H
