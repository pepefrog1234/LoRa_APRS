// comment out for arduino-Lora usage
#define USE_RADIOLIB

// Uncomment for SX126X module usage
#define USE_SX126X

// Check your module name at https://github.com/jgromes/RadioLib/wiki/Modules
#ifdef USE_SX126X
#define MODULE_NAME   SX1268
#else
#define MODULE_NAME   SX1278
#endif

// generic options
#define LED_TOGGLE_PERIOD     1000    // heartbeat LED period
#define SERIAL_BAUD_RATE      115200  // USB serial baud rate

// USB serial logging
// set to DebugLogLevel::LVL_TRACE for packet logging
// set to DebugLogLevel::LVL_NONE to disable logging
#define CFG_LOG_LEVEL         DebugLogLevel::LVL_TRACE

// select between client mode and APRS-IS gate mode
#define CFG_IS_CLIENT_MODE    false        // false - server mode (APRS-IS gate mode)

// change pinouts if not defined through native board LORA_* definitions
#ifndef LORA_RST
#pragma message("LoRa pin definitions are not found, redefining...")
#define LORA_RST              14
#define LORA_IRQ              33
#endif

// LoRa pinouts
#define CFG_LORA_PIN_SS       SS
#define CFG_LORA_PIN_RST      LORA_RST
#define CFG_LORA_PIN_A        33    // (sx127x - dio0, sx126x/sx128x - dio1)
#ifdef USE_SX126X
#define CFG_LORA_PIN_B        39          // (sx127x - dio1, sx126x/sx128x - busy)
#define CFG_LORA_PIN_RXEN     2           // (sx127x - unused, sx126x - RXEN pin number)
#define CFG_LORA_PIN_TXEN     4           // (sx127x - unused, sx126x - TXEN pin number)
#else
#define CFG_LORA_PIN_B        39 // (sx127x - dio1, sx126x/sx128x - busy)
#endif

// Redefine LED if not defined in Arduino to have module heartbeat indication
#ifndef BUILTIN_LED
#pragma message("BUILDIN_LED is not found, defining as 2")
#define BUILTIN_LED           12
#endif

// CAD and ISR usage selection
#ifdef USE_SX126X
#define CFG_LORA_USE_ISR      false       // reading in ISR does not work on sx126x
#define CFG_LORA_USE_CAD      true        // do not transmit if channel is busy
#else
#define CFG_LORA_USE_ISR      true        // true - read incoming data in ISR, false - do not read in ISR
#define CFG_LORA_USE_CAD      true        // set to true to utilize carrier detection
#endif

// LoRa protocol default parameters (they need to match between devices!!!)
#define CFG_LORA_FREQ_RX      430.64e6   // RX frequency in MHz
#define CFG_LORA_FREQ_TX      430.64e6   // TX frequency in MHz
#define CFG_LORA_BW           125e3       // bandwidth (from 7.8 kHz up to 500 kHz)
#define CFG_LORA_SF           12          // spreading factor (6 - 12), 6 requires implicit header mode
#define CFG_LORA_CR           8           // coding rate (5 - 8)
#define CFG_LORA_CRC          2           // 0 - disabled, 1 - 1 byte, 2 - 2 bytes
#define CFG_LORA_EXPLICIT     false        // header mode, true - explicit, false - implicit
#define CFG_LORA_SYNC         0x12        // sync word (0x12 - private used by other trackers, 0x34 - public used by LoRaWAN)
#define CFG_LORA_PWR          22          // output power in dBm

// WiFi client and AP options
#define CFG_WIFI_ENABLE_AP    false       // run as wifi access point (for CFG_KISS_TCP_IP mode)
#define CFG_WIFI_SSID         "3F"    // connect to SSID or run as this SSID in AP mode
#define CFG_WIFI_KEY          "9976192937"     // wifi key
//#define CFG_WIFI_SSID         "CHT5506"    // connect to SSID or run as this SSID in AP mode
//#define CFG_WIFI_KEY          "tcdmr4379"     // wifi key
//#define CFG_WIFI_SSID         "CHT5506"    // connect to SSID or run as this SSID in AP mode
//#define CFG_WIFI_KEY          "tcdmr4379"     // wifi key
// Bluetooth
#define CFG_BT_NAME           ""   // set to empty to disable Bluetooth
#define CFG_BT_USE_BLE        false       // set to true to use bluetooth low energy (for ios devices)

// USB serial
#define CFG_USB_SERIAL_ENABLE false       // true - enable KISS communication over USB Serial (e.g. with APRSDroid over USB-OTG), disables USB logging

// KISS protocol options
#define CFG_KISS_EXTENSIONS   false   // true - enable modem control from application with KISS commands and signal reports
#define CFG_KISS_TCP_IP       false   // true - run as KISS TCP/IP server, no bluetooth operations performed

// APRS-IS options, valid in when CFG_IS_CLIENT_MODE = false
#define CFG_APRS_LOGIN        "BX4ACP-1"
#define CFG_APRS_PASS         "18091"
#define CFG_APRS_FILTER	      "r/24.11/120.42/50"  // multiple are space separated, see http://www.aprs-is.net/javAPRSFilter.aspx
#define CFG_APRS_RAW_BKN    "BX4ACP-1>APZMDM,WIDE1-1:=2410.90NL12045.00E&LoRA 430.64MHz/BW125/SF12/CR8/0x12"//測試參數
//#define CFG_APRS_RAW_BKN      "BM2OBM-18>OBM2BM,WIDE1-1:=2335.06NL12037.14E&TMMARC https://www.tmmarc.org [LoRa APRS iGate 430.640MHz]"

//#define CFG_APRS_LOGIN        "BM2OBM-18"
//#define CFG_APRS_PASS         "16813"
//#define CFG_APRS_FILTER        "r/24.11/120.42/50"  // multiple are space separated, see http://www.aprs-is.net/javAPRSFilter.aspx
//#define CFG_APRS_RAW_BKN    "BX4ACP>APZMDM,WIDE1-1:!2410.70N/12043.00E#LoRA 430.64MHz/BW125/SF12/CR8/0x12" 正式參數
//#define CFG_APRS_RAW_BKN      "BM2OBM-18>OBM2BM,WIDE1-1:=2335.06NL12037.14E&TMMARC https://www.tmmarc.org [LoRa APRS iGate 430.640MHz]"

// APRS-IS gateway options, valid when CFG_IS_CLIENT_MODE = false
#define CFG_SIGNAL_REPORT     true    // include signal report into the comment when sending to APRS-IS
#define CFG_PERSISTENT_APRS   true    // keep tcp/ip connection open (lot of traffic), otherwise connect on new packet (very rare traffic)
#define CFG_DIGIREPEAT        false   // digirepeat incoming packets
#define CFG_RF_TO_IS          true    // forward packets from radio to internet
#define CFG_IS_TO_RF          false   // forward packets from internet to radio based on CFG_APRS_FILTER
#define CFG_BEACON            true   // enable perdiodic beacon from CFG_APRS_RAW_BKN
#define CFG_TEXT_PACKETS      true   // enable aprs text packets instead of binary for interoperability with other projects (disables KISS + AX.25!)

// Frequency correction for narrow band bandwidths
#define CFG_FREQ_CORR         false   // true - correct own frequency based on received packet
#define CFG_FREQ_CORR_DELTA   1000    // correct when frequency difference is larger than this value

// PTT control
#define CFG_PTT_ENABLE        false   // enable external ptt (relay) control (for amplifier)
#define CFG_PTT_PIN           12      // PTT pin
#define CFG_PTT_TX_DELAY_MS   50      // delay between relay switching ON and transmission startup
#define CFG_PTT_TX_TAIL_MS    10      // delay between stopping transmission and relay switching OFF
