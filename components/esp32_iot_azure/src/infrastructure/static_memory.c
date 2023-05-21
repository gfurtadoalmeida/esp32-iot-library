#include "infrastructure/static_memory.h"

// When  IoT Hub and DPS are not being called on different
// tasks, at the same time, we can use just one buffer.
#if CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_MERGE_IOT_HUB_DPS_BUFFERS == 1

#if CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_BUFFER_SIZE_IOT_HUB > CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_BUFFER_SIZE_DPS
static uint8_t _STATIC_MEMORY_MERGED[CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_BUFFER_SIZE_IOT_HUB];
#else
static uint8_t _STATIC_MEMORY_MERGED[CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_BUFFER_SIZE_DPS];
#endif

uint8_t *STATIC_MEMORY_IOT_HUB = _STATIC_MEMORY_MERGED;

#if CONFIG_ESP32_IOT_AZURE_HUB_FEATURES_DPS_ENABLED == 1
uint8_t *STATIC_MEMORY_DPS = _STATIC_MEMORY_MERGED;
#endif

#else
static uint8_t _STATIC_MEMORY_IOT_HUB[CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_BUFFER_SIZE_IOT_HUB];
uint8_t *STATIC_MEMORY_IOT_HUB = _STATIC_MEMORY_IOT_HUB;

#if #if CONFIG_ESP32_IOT_AZURE_HUB_FEATURES_DPS_ENABLED == 1
static uint8_t _STATIC_MEMORY_DPS[CONFIG_ESP32_IOT_AZURE_TRANSPORT_MQTT_BUFFER_SIZE_DPS];
uint8_t *STATIC_MEMORY_DPS = _STATIC_MEMORY_DPS;
#endif

#endif

#if CONFIG_ESP32_IOT_AZURE_HUB_FEATURES_DU_ENABLED == 1

static uint8_t _STATIC_MEMORY_ADU_SCRATCH_BUFFER[CONFIG_ESP32_IOT_AZURE_DU_BUFFER_SIZE_SCRATCH];
static uint8_t _STATIC_MEMORY_ADU_DOWNLOAD[CONFIG_ESP32_IOT_AZURE_DU_BUFFER_SIZE_HTTP_DOWNLOAD];

uint8_t *STATIC_MEMORY_ADU_SCRATCH_BUFFER = _STATIC_MEMORY_ADU_SCRATCH_BUFFER;
uint8_t *STATIC_MEMORY_ADU_DOWNLOAD = _STATIC_MEMORY_ADU_DOWNLOAD;

#endif