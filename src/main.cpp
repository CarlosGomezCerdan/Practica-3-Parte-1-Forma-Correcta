#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
// SSID & Password
const char* ssid = "MiFibra-0828"; // Enter your SSID here
const char* password = "RLArukbK"; //Enter your Password here
WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)

void handle_root(void);

void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);

// Connect to your wi-fi modem
WiFi.begin(ssid, password);

// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
}

Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial
server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}

void loop() {
  server.handleClient();
}

// Codigo HTML sin modificar 
// HTML & CSS contents which display on web server
// String HTML = "<!DOCTYPE html>\ //
// <html>\ //
// <body>\ //
// <h1>My Primera Pagina con ESP32 - Station Mode &#128522;</h1>\ //
// </body>\ //
// </html>"; //

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<table border='2'>\
<tr>\
<th>Hora</th>\
<th>Lunes</th>\
<th>Martes</th>\
<th>Miercoles</th>\
<th>Jueves</th>\
<th>Viernes</th>\
</tr>\
<tr>\
<th>15:00 - 16:00</th>\
<td>Comunicaciones</td>\
<td>Fonaments</td>\
<td></td>\
<td>Fonaments</td>\
<td>Acustica</td>\
</tr>\
<tr>\
<th>16:00 - 17:00</th>\
<td>Comunicaciones</td>\
<td>Fonaments</td>\
<td>comunicaciones</td>\
<td>Fonaments</td>\
<td>Acustica</td>\
</tr>\
<tr>\
<th>17:00 - 18:00</th>\
<td>Implementacio</td>\
<td>Fonaments</td>\
<td>Comunicacions</td>\
<td>Procesadors digitals</td>\
<td>Acustica</td>\
</tr>\
<tr>\
<th>18:00 - 19:00</th>\
<td></td>\
<td>Implementacio</td>\
<td>Comunicacions</td>\
<td>Procesadors digitals</td>\
<td></td>\
</tr>\
<tr>\
<th>19:00 - 20:00</th>\
<td></td>\
<td>Implementacio</td>\
<td></td>\
<td>Procesadors digitals</td>\
<td></td>\
</tr>\
<tr>\
<th>20:00 - 21:00</th>\
<td></td>\
<td>Implementacio</td>\
<td></td>\
<td>Procesadors digitals</td>\
<td></td>\
</tr>\
</table>\
</body>\
</html>";

 
// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}
