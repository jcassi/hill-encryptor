#include "client.h"

int main(int argc, char const *argv[]) {
	client_t client;

	//validar argvs
	client_init(&client, argv[3]);
	client_iterate(&client, argv[1],  argv[2]);
	client_uninit(&client);
	return 0;
}

