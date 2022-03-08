// We define MY_LED to be the LED that we want to blink.
const pin_t MY_LED = D7;

// The following line is optional, but recommended in most firmware. It
// allows your code to run before the cloud is connected. In this case,
// it will begin blinking almost immediately instead of waiting until
// breathing cyan,
SYSTEM_THREAD(ENABLED);

// The setup() method is called once when the device boots.
void setup()
{
	// Configure LED as an output pin
	pinMode(MY_LED, OUTPUT);
}

void loop()
{
    // Flash first name in morse code - Beau
	morseB();
	morseE();
	morseA();
	morseU();

    // Delay 3 seconds before repeating (4 second total with between chars)
    delay(3s);
}

// Short flash - .125ms
void dit()
{
    // Turn on LED for .125ms second
    digitalWrite(MY_LED,HIGH);
    delay(125ms);
    
    betweenFlash();
}

// Long flash - 500ms
void dah()
{
    
    digitalWrite(MY_LED, HIGH);
    delay(500ms);
    
    betweenFlash();
}

// Delay between flashes - 500ms
void betweenFlash()
{
    digitalWrite(MY_LED, LOW);
    delay(500ms);
}

// Delay between characters - 500ms - 1 second total when combined with each flash calling betweenFlash()
void betweenChars()
{
    digitalWrite(MY_LED, LOW);
    delay(500ms);
}

// Morse code letter B (-...)
void morseB()
{
    dah();
    dit();
    dit();
    dit();
    
    betweenChars();
}

// Morse code letter E (.)
void morseE()
{
    dit();
    
    betweenChars();
}

// Morse code letter A (.-)
void morseA()
{
    dit();
    dah();
    
    betweenChars();
}

// Morse code letter U (..-)
void morseU()
{
    dit();
    dit();
    dah();
    
    betweenChars();
}