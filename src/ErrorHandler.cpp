#include "ErrorHandler.h"

void logError(const String& errorMessage) {
    File errorFile = SD_MMC.open("/error.log", FILE_APPEND);
    errorFile.println(esp_timer_get_time() + ": " + errorMessage);
    errorFile.close();
}
