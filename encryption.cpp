#include "encryption.h"

#include <vector>

#define char unsigned char

using namespace std;

string KEY = "";

vector<char> bit2byte(vector<bool>);
vector<bool> gen_via_lfsr(int, vector<bool>, vector<bool>);
vector<bool> gen_via_lfsr(int, vector<bool>, vector<bool>, vector<bool>, vector<bool>, vector<bool>, vector<bool>);
vector<char> rc4(vector<char>);

vector<char> encode(vector<char> msg, vector<bool> lfsr_init, vector<bool> lfsr2_init, vector<bool> lfsr3_init, bool gefe, bool defrc4) {
	int sz = msg.size();

	int m1 = 26;
	vector<bool> lfsr1 = lfsr_init;
	vector<bool> a1(m1, 0);
	a1[0] = a1[6] = a1[7] = a1[m1 - 1] = 1;
	reverse(a1.begin(), a1.end());

	vector<char> key;

	if (gefe) {
		int m2 = 34;
		vector<bool> lfsr2 = lfsr2_init;
		vector<bool> a2(m2, 0);
		a2[0] = a2[13] = a2[14] = a2[m2 - 1] = 1;
		reverse(a2.begin(), a2.end());

		int m3 = 24;
		vector<bool> lfsr3 = lfsr3_init;
		vector<bool> a3(m3, 0);
		a3[0] = a3[2] = a3[3] = a3[m3 - 1] = 1;
		reverse(a3.begin(), a3.end());

		key = bit2byte(gen_via_lfsr(sz, a1, lfsr1, a2, lfsr2, a3, lfsr3));
	}
	else {
		key = bit2byte(gen_via_lfsr(sz, a1, lfsr1));
	}

	if (defrc4) key = rc4(key);

	KEY = "";

	for (int i = 0; i < key.size(); ++i) {
		int tmp = key[i];
		vector<int> v(8,0);
		int j = 7;
		while (tmp != 0) {
			v[j] = tmp % 2;
			j--;
			tmp /= 2;
		}
		for (int j = 0; j < 8; ++j)
			KEY += v[j] + '0';
	}

	vector<char> cph(msg.size());

	for (int i = 0; i < msg.size(); ++i)
		cph[i] = msg[i] ^ key[i];

	return cph;

}


vector<char> bit2byte(vector<bool> vec) {
	vector<char> ans;

	char chr = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (i % 8 == 0) {
			ans.push_back(chr);
			chr = vec[i];
		}
		else {
			chr = chr * 2 + vec[i];
		}
	}
	ans.push_back(chr);

	return ans;
}

vector<bool> gen_via_lfsr(int size, vector<bool> a, vector<bool> regInit) {

	size *= 8;

	int m = a.size();

	vector<bool> lfsr1 = regInit;
	vector<bool> ans;

	for (int i = 0; i < size; ++i) {

		bool sum = 0;
		for (int j = 0; j < m; ++j) {
			sum ^= a[j] * lfsr1[j];
		}

		ans.push_back(lfsr1[0]);
		for (int j = 0; j < lfsr1.size() - 1; ++j) {
			lfsr1[j] = lfsr1[j + 1];
		}

		lfsr1[m - 1] = sum;

	}

	return ans;
}

vector<bool> gen_via_lfsr(int size, vector<bool> a1, vector<bool> reg1Init,
	vector<bool> a2, vector<bool> reg2Init,
	vector<bool> a3, vector<bool> reg3Init
) {

	size *= 8;

	int m1 = a1.size();
	vector<bool> lfsr1 = reg1Init;
	int m2 = a2.size();
	vector<bool> lfsr2 = reg2Init;
	int m3 = a3.size();
	vector<bool> lfsr3 = reg3Init;

	vector<bool> ans;

	for (int i = 0; i < size; ++i) {

		bool sum = 0;
		for (int j = 0; j < m1; ++j) {
			sum ^= a1[j] * lfsr1[j];
		}

		bool x1 = lfsr1[0];
		for (int j = 0; j < lfsr1.size() - 1; ++j) {
			lfsr1[j] = lfsr1[j + 1];
		}
		lfsr1[m1 - 1] = sum;


		sum = 0;
		for (int j = 0; j < m2; ++j) {
			sum ^= a2[j] * lfsr2[j];
		}

		bool x2 = lfsr2[0];
		for (int j = 0; j < lfsr2.size() - 1; ++j) {
			lfsr2[j] = lfsr2[j + 1];
		}
		lfsr2[m2 - 1] = sum;


		sum = 0;
		for (int j = 0; j < m3; ++j) {
			sum ^= a3[j] * lfsr3[j];
		}

		bool x3 = lfsr1[0];
		for (int j = 0; j < lfsr3.size() - 1; ++j) {
			lfsr3[j] = lfsr3[j + 1];
		}
		lfsr3[m3 - 1] = sum;

		ans.push_back((x1 && x2) || (!x1 && x3));
	}

	return ans;
}

vector<char> rc4(vector<char> u) {

	vector<char> s(256);
	for (int i = 0; i < 256; ++i) {
		s[i] = i;
	}


	for (int i = 0, j = 0; i < 256; ++i) {
		j = (j + s[i] + u[i % u.size()]) % 256;
		swap(s[i], s[j]);
	}

	vector<char> key(u.size());

	for (int i = 0, j = 0, k = 0; k < key.size(); ++k) {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;
		swap(s[i], s[j]);

		int t = (s[i] + s[j]) % 256;

		key[k] = s[t];
	}

	return key;
}
