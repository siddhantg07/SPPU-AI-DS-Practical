#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "Wokwi-GUEST";
const char *password = "";  // No password for Wokwi-GUEST
const int potPin = 34;
int potValue = 0;

WebServer server(80);

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Potentiometer Value:</h1>";
  html += "<p>" + String(potValue) + "</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(potPin, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Handle root URL
  server.on("/", HTTP_GET, handleRoot);

  // Start server
  server.begin();
}

void loop() {
  // Read potentiometer value
  potValue = analogRead(potPin);
  
  // Handle incoming HTTP requests
  server.handleClient();
  
  delay(100); // Adjust delay as needed
}
