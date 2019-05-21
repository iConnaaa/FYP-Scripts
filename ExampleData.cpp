#include "ExampleData.h"

char CurlCommandBuffer[500] = { 0 }; //Initialize the buffer to a default value of NULL

const char* RawCommand = "curl -X PUT http://localhost:8080/api/2/things/thing:a-drill  -u ditto:ditto -d \"{\\\"attributes\\\":{\\\"brand\\\":\\\"aDrill\\\"},\\\"features\\\":{\\\"mechanics\\\":{\\\"properties\\\":{\\\"drill-speed(rpm)\\\":%i,\\\"battery-level(%%)\\\":%i}},\\\"environment-sensor\\\":{\\\"properties\\\":{\\\"temperature(C)\\\":%.2f,\\\"humidity(RH)\\\":%i,\\\"airPressure(psi)\\\":%i}}}}";

int main() {
	for (int i = 100; i >= 0; i--) {
		//Generate new random values for sending to ditto
		int newDrillSpeed = i == 0 ? 0 : randomInt(1200, 2100); //Sets the drill speed to 0 should the battery Level reach 0. Else it generates the random number
		int newBatteryLevel = i;

		float newTemperature = randomFloat(20, 30);
		int newHumidityValue = randomInt(15, 40);
		int newAirPressure = randomInt(5, 10);

		printf("-----New Stats-----\n");
		printf("Drill Speed: %iRPM\n", newDrillSpeed);
		printf("Battery Level: %i%%\n", newBatteryLevel);
		printf("Drill Temperature: %.2fC\n", newTemperature);
		printf("Humidity: %i%%\n", newHumidityValue);
		printf("Air Pressure: %i PSI\n", newAirPressure);
		printf("-----End Of Stats-----\n\n");

		memset(CurlCommandBuffer, 0, 500);//Clear the buffer to prevent accidental data being left over
		sprintf(CurlCommandBuffer, RawCommand, newDrillSpeed, newBatteryLevel, newTemperature, newHumidityValue, newAirPressure);
		system(CurlCommandBuffer);

		Sleep(500); //Delay the loop for 5 seconds
	}
}
	