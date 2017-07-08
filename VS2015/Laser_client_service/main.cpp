#include <cstdio>
#include "LayserService.h"
int main(){

	LayserService* service = new LayserService();
	service->Start(7777);

	while (1);
	return 0;
}