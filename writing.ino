// march 10 2025

#include <SD.h>  //BY Arduino, Sparkfun

File file; //Creating the object to use to perform operations in Whole code

void setup() {
    Serial.begin(115200);
    delay(1000);  

    if (!SD.begin(BUILTIN_SDCARD)) { // Using onboard SD slot
        Serial.println("SD initialization failed!"); 
        while (1);
    }

    Serial.println("SD initialized successfully.");

    //(filename.extension(TXT/CSV) , (FILE_WRITE)) Compulsary to set it in Write Mode
    file = SD.open("Example1.TXT", FILE_WRITE); //Crete new or append data in existing file if found of same name
    if (!file) {
        Serial.println("Failed to open file for writing.");
        while (1);
    }

    // Writing multiple lines/ we also save data in tabs using(/t)
    file.println("Hello from Teensy!");  //file.println("Hello from Teensy!/t how are you/t nice");
    file.println("This is the second line./t HEllo");
    file.println("Logging sensor data...");
    file.println("Line 4: More data coming...");
    
    file.close(); // closing file that we creted or modified

    Serial.println("Data written to Example.TXT");
}

void loop() {
    // Nothing here
}
