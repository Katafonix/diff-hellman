#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "DIFFHELL.h"
using namespace std;


    DiffHell::DiffHell(int value1,int value2)
    {
        p = value1;
        g = value2;
    }

    void DiffHell::generate_public_key()
	{
        public_key = modpow(p, private_key, g);
	}

    void DiffHell::generate_secret_key(int pub_key)
	{
        secret_key = modpow(pub_key, private_key, g);
	}

    string DiffHell::encrypt_message(string message)
	{
		string encrypted_message = "";

        int key = secret_key;
		for (int i = 0; i < message.size(); i++)
		{
			encrypted_message += (char)((int)message[i] +key);
		}
	
		return encrypted_message;
	}

    string DiffHell::decrypt_message(string message)
	{
		string decrypted_message = "";
        int key = secret_key;
		for (int i = 0; i < message.size(); i++)
		{
			decrypted_message += (char)((int)message[i] - key);
		}
		return decrypted_message;
	}

    void DiffHell::Set(int priv_key)
	{
		private_key = priv_key;
	}

    int DiffHell::Get()
	{
        return public_key;
	}


    int DiffHell::modpow(int a, int b, int m) // a^b % m
    {
        if (b == 0)
            return 1;
        int z = modpow(a, b / 2, m);
        if (b % 2 == 0)
          return (z*z) % m;
        else
          return (a*z*z) % m;

    }
