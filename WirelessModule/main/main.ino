//  4 Channel Receiver | 4 Kanal Alıcı
//  PWM output on pins D2, D3, D4, D5 (Çıkış pinleri)
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

struct Signal
{
	byte throttle;
	byte pitch;
	byte roll;
	byte yaw;

	String ToString()
	{
		String outString = "throttle";
		outString.concat(throttle);
		outString.concat(", pitch");
		outString.concat(pitch);
		outString.concat(", roll");
		outString.concat(roll);
		outString.concat(", yaw");
		outString.concat(yaw);
		
		return outString;
	}
};

Signal data;
const uint64_t pipeIn = 0xE9E8F0F0E1LL;
RF24 radio(7, 8);

void ResetData()
{
	// Define the inicial value of each data input. | Veri girişlerinin başlangıç değerleri
	// The middle position for Potenciometers. (254/2=127) | Potansiyometreler için orta konum
	data.throttle = 127; // Motor Stop | Motor Kapalı
	data.pitch = 127;	 // Center | Merkez
	data.roll = 127;	 // Center | Merkez
	data.yaw = 127;		 // Center | Merkez
}

void setup()
{
	//Configure the NRF24 module
	ResetData();
	radio.begin();
	radio.openReadingPipe(1, pipeIn);

	radio.startListening(); //start the radio comunication for receiver | Alıcı olarak sinyal iletişimi başlatılıyor
}

unsigned long lastRecvTime = 0;
void recvData()
{
	while (radio.available())
	{
		radio.read(&data, sizeof(Signal));
		lastRecvTime = millis(); // receive the data | data alınıyor
	}
}

void loop()
{
	recvData();
	unsigned long now = millis();
	if (now - lastRecvTime > 1000)
	{
		ResetData(); // Signal lost.. Reset data | Sinyal kayıpsa data resetleniyor
	}

	Serial.println(data.ToString());
}