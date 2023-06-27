#include <stdio.h>
#include <stdlib.h>



#define NO_Calibration_Point 5

struct
{
	double X[NO_Calibration_Point];
	double Y[NO_Calibration_Point];
} cal_data;

double linear_mapping(double x)
{
	double y = 0.0;

	int index = -1;

	
	if (x <= cal_data.X[0]) {
		index = 0;
	}
	else if (x >= cal_data.X[NO_Calibration_Point - 1]) {
		index = NO_Calibration_Point - 2;
	}
	else {
		for (int i = 0; i < NO_Calibration_Point - 1; i++) {
			if (x >= cal_data.X[i] && x < cal_data.X[i + 1]) {
				index = i;
				break;
			}
		}
	}

	
	if (index >= 0) {
		y = ((cal_data.Y[index] - cal_data.Y[index + 1]) / (cal_data.X[index] - cal_data.X[index + 1])) * (x - cal_data.X[index + 1]) + cal_data.Y[index + 1];
	}
	else {
		
		y = 0.0; 
	}

	return y;
}

int main() {
	 cal_data = 
	 {
		{0.0, 1.0, 2.0, 3.0, 4.0}, // X ¹üÀ§
		{10.0, 20.0, 30.0, 40.0, 50.0} // y °ª
	 };

	
	double x = 4.0;
	double y = linear_mapping(x);

	printf("For x = %lf, linear mapping result: %lf\n", x, y);

	return 0;
}





