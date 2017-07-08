#include <cstdio>
#ifdef MDebug
#include "LayserSDK.h"
int main() {
	LayserSDK sdk;
	sdk.Start();
	while (1) {
		Tracker* var = sdk.GetChipData(0);
		printf("%f	%f	%f	%f\n", var->Qw, var->Qx, var->Qy, var->Qz);
	}
	return 0;
}

#endif