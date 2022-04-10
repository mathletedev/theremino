const int TRIG_PIN = 3;
const int ECHO_PIN = 4;
const int TONE_PIN = 8;

float prevDistance = 0;

void setup() {
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);

	float distance = pulseIn(ECHO_PIN, HIGH) / 58;
	if (distance > 100 || abs(prevDistance - distance) < 4) return;
	prevDistance = distance;

	tone(TONE_PIN, distance * 4 + 200);
}
