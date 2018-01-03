// Laser_sdk_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include "LayserSDK.h"

int main()
{
	LayserSDK sdk;
	sdk.Start();

	Tracker* a = new Tracker();
	a->Test();
	while (1) {
		Tracker* var = sdk.GetChipData(0);
		printf("%f	%f	%f	%f\n", var->Qw, var->Qx, var->Qy, var->Qz);
	}
    return 0;
}

