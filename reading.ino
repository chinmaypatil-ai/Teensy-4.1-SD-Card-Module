//March 10 2025
#include <SD.h>

File file; //Defining Object

void setup() {
    Serial.begin(115200);
    delay(1000); 

    if (!SD.begin(BUILTIN_SDCARD)) {
        Serial.println("SD initialization failed!");
        while (1);
    }

    Serial.println("SD initialized successfully.");

    file = SD.open("Example1.txt"); // Open file in READ mode
    if (!file) {
        Serial.println("Failed to open file for reading.");
        while (1);
    }

    Serial.println("Reading data from data.txt:");

    // Read and print the file line by line
    while (file.available()) { 
        String line = file.readStringUntil('\n'); // Read until newline
        Serial.println(line);
    }

    file.close(); // Close the file after reading
    Serial.println("File reading complete.");
}

void loop() {
    // Nothing here
}
