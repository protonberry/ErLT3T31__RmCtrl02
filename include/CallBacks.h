//Callback function called when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
//  Serial.print("\r\nLast Packet Send Status:\t");
//  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
sprDataOK.fillSprite(TFT_BLUE);
  if(status != ESP_NOW_SEND_SUCCESS) {sprDataOK.fillSprite(TFT_ORANGE);}
 sprDataOK.pushSprite(ScreenW-10, ScreenH-10);
}

// Callback function executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&MV_Data, incomingData, sizeof(MV_Data));
  NewMVdata = true;
}
