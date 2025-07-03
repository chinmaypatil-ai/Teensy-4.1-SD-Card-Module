#include <SD.h>

void setup() {
    Serial.begin(115200);
    delay(1000); 

    if (!SD.begin(BUILTIN_SDCARD)) {
        Serial.println("SD initialization failed!");
        while (1);
    }

    Serial.println("SD initialized successfully.");

    if (SD.exists("data.csv")) {
        Serial.println("File found! Deleting...");

        if (SD.remove("data.csv")) {
            Serial.println("File deleted successfully.");
        } else {
            Serial.println("File deletion failed!");
        }
    } else {
        Serial.println("File does not exist.");
    }
}

void loop() {
    // Nothing here
}
