#include <iostream>
#include "decryption.hpp"

using namespace std;

int main() {

	string msg = "9EO?26FBO6?@:EDHO7@O69E69DO2OCC2>3F4O6?:HDO?2\\O]>:8D5tO](OC6<;:sO2CEDBO69%:ED6F7@O?@E69HO2OC69A>@4OOC6EFEO?24O<?:9@?OD:6C@>O6E?:O:ED6C9EO8?";

	string decrypted_msg = decrypt(msg);

	cout << decrypted_msg << endl;

	return 0;
}

