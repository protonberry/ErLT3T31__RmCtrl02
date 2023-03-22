// File definitions
void listDir(fs::FS &fs, const char *dirname, uint8_t levels)
{
  Serial.printf("Listing directory: %s\r\n", dirname);

  File root = fs.open(dirname);
  if (!root)
  {
    debugln("- failed to open directory");
    return;
  }
  if (!root.isDirectory())
  {
    debugln(" - not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file)
  {
    if (file.isDirectory())
    {
      debug("  DIR : ");
      debugln(file.name());
      if (levels)
      {
        listDir(fs, file.name(), levels - 1);
      }
    }
    else
    {
      debug("  FILE: ");
      debug(file.name());
      debug("\tSIZE: ");
      debugln(file.size());
    }
    file = root.openNextFile();
  }
}

void readFile(fs::FS &fs, const char *path)
{
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory())
  {
    debugln("- failed to open file for reading");
    return;
  }

  debugln("- read from file:");
  while (file.available())
  {
    Serial.write(file.read());
  }
  file.close();
}

void writeFile(fs::FS &fs, const char *path, const char *message)
{
  Serial.printf("Writing file: %s\r\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file)
  {
    debugln("- failed to open file for writing");
    return;
  }
  if (file.print(message))
  {
    debugln("- file written");
  }
  else
  {
    debugln("- write failed");
  }
  file.close();
}

void appendFile(fs::FS &fs, const char *path, const char *message)
{
  //   Serial.printf("Appending to file: %s\r\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file)
  {
    debugln("- failed to open file for appending");
    return;
  }
  if (file.print(message))
  {
    //        Serial.print("- message appended");
  }
  else
  {
    debugln("- append failed");
  }
  file.close();
}

void renameFile(fs::FS &fs, const char *path1, const char *path2)
{
  Serial.printf("Renaming file %s to %s\r\n", path1, path2);
  if (fs.rename(path1, path2))
  {
    debugln("- file renamed");
  }
  else
  {
    debugln("- rename failed");
  }
}

void deleteFile(fs::FS &fs, const char *path)
{
  Serial.printf("Deleting file: %s\r\n", path);
  if (fs.remove(path))
  {
    debugln("- file deleted");
  }
  else
  {
    debugln("- delete failed");
  }
}

//#############################################################################################

//#############################################################################################
String HTML_Header()
{
  String page;
  page = "<!DOCTYPE html>";
  page += "<html lang = 'en'>";
  page += "<head>";
  page += "<title>Web Server</title>";
  page += "<meta charset='UTF-8'>"; // Needed if you want to display special characters like the ° symbol
  page += "<style>";
  page += "body {width:75em;margin-left:auto;margin-right:auto;font-family:Arial,Helvetica,sans-serif;font-size:16px;color:blue;background-color:#e1e1ff;text-align:center;}";
  page += "footer {padding:0.08em;background-color:cyan;font-size:1.1em;}";
  page += "table {font-family:arial,sans-serif;border-collapse:collapse;width:70%;}"; // 70% of 75em!
  page += "table.center {margin-left:auto;margin-right:auto;}";
  page += "td, th {border:1px solid #dddddd;text-align:left;padding:8px;}";
  page += "tr:nth-child(even) {background-color:#dddddd;}";
  page += "h4 {color:slateblue;font:0.8em;text-align:left;font-style:oblique;text-align:center;}";
  page += ".center {margin-left:auto;margin-right:auto;}";
  page += ".topnav {overflow: hidden;background-color:lightcyan;}";
  page += ".topnav a {float:left;color:blue;text-align:center;padding:0.6em 0.6em;text-decoration:none;font-size:1.3em;}";
  page += ".topnav a:hover {background-color:deepskyblue;color:white;}";
  page += ".topnav a.active {background-color:lightblue;color:blue;}";
  page += ".notfound {padding:0.8em;text-align:center;font-size:1.5em;}";
  page += ".left {text-align:left;}";
  page += ".medium {font-size:1.4em;padding:0;margin:0}";
  page += ".ps {font-size:0.7em;padding:0;margin:0}";
  page += ".sp {background-color:silver;white-space:nowrap;width:2%;}";
  page += "</style>";
  page += "</head>";
  page += "<body>";
  page += "<div class = 'topnav'>";
  page += "<a href='/'>Home</a>";
  page += "<a href='/dir'>Directory</a>";
  //  page += "<a href='/upload'>Upload</a> ";
  page += "<a href='/download'>Download</a>";
  //  page += "<a href='/stream'>Stream</a>";
  page += "<a href='/delete'>Delete</a>";
  //  page += "<a href='/rename'>Rename</a>";
  //  page += "<a href='/system'>Status</a>";
  // page += "<a href='/format'>Format FS</a>";
  //  page += "<a href='/newpage'>New Page</a>";
  //  page += "<a href='/logout'>[Log-out]</a>";
  page += "</div>";
  return page;
}
//#############################################################################################
String HTML_Footer()
{
  String page;
  page += "<br><br><footer>";
  page += "<p class='medium'>ESP Asynchronous WebServer Example</p>";
  page += "<p class='ps'><i>Copyright &copy;&nbsp;D L Bird 2021 Version " + Version + "</i></p>";
  page += "</footer>";
  page += "</body>";
  page += "</html>";
  return page;
}
//#############################################################################################
String ConvBinUnits(size_t bytes, byte resolution)
{
  if (bytes < 1024)
  {
    return String(bytes) + " B";
  }
  else if (bytes < 1024 * 1024)
  {
    return String(bytes / 1024, resolution) + " KB";
  }
  else if (bytes < (1024 * 1024 * 1024))
  {
    return String(bytes / 1024 / 1024, resolution) + " MB";
//    return String(bytes / 1024.0 / 1024.0, resolution) + " MB";
  }
  else
    return "";
}

//#############################################################################################
void Directory()
{
  numfiles = 0; // Reset number of FS files counter
  File root = SPIFFS.open("/");
  if (root)
  {
    root.rewindDirectory();
    File file = root.openNextFile();
    while (file)
    { // Now get all the filenames, file types and sizes
      Filenames[numfiles].filename = (String(file.name()).startsWith("/") ? String(file.name()).substring(1) : file.name());
      Filenames[numfiles].ftype = (file.isDirectory() ? "Dir" : "File");
      Filenames[numfiles].fsize = ConvBinUnits(file.size(), 1);
      file = root.openNextFile();
      numfiles++;
    }
    root.close();
  }
}
void Dir(AsyncWebServerRequest *request)
{
  String Fname1, Fname2;
  int index = 0;
  Directory(); // Get a list of the current files on the FS
  webpage = HTML_Header();
  webpage += "<h3>Filing System Content</h3><br>";
  if (numfiles > 0)
  {
    webpage += "<table class='center'>";
    webpage += "<tr><th>Type</th><th>File Name</th><th>File Size</th><th class='sp'></th><th>Type</th><th>File Name</th><th>File Size</th></tr>";
    while (index < numfiles)
    {
      Fname1 = Filenames[index].filename;
      Fname2 = Filenames[index + 1].filename;
      webpage += "<tr>";
      webpage += "<td style = 'width:5%'>" + Filenames[index].ftype + "</td><td style = 'width:25%'>" + Fname1 + "</td><td style = 'width:10%'>" + Filenames[index].fsize + "</td>";
      webpage += "<td class='sp'></td>";
      if (index < numfiles - 1)
      {
        webpage += "<td style = 'width:5%'>" + Filenames[index + 1].ftype + "</td><td style = 'width:25%'>" + Fname2 + "</td><td style = 'width:10%'>" + Filenames[index + 1].fsize + "</td>";
      }
      webpage += "</tr>";
      index = index + 2;
    }
    webpage += "</table>";
    webpage += "<p style='background-color:yellow;'><b>" + MessageLine + "</b></p>";
    MessageLine = "";
  }
  else
  {
    webpage += "<h2>No Files Found</h2>";
  }
  webpage += HTML_Footer();
  request->send(200, "text/html", webpage);
}
//#############################################################################################
void SelectInput(String Heading, String Command, String Arg_name)
{
  webpage = HTML_Header();
  webpage += "<h3>" + Heading + "</h3>";
  webpage += "<form  action='/" + Command + "'>";
  webpage += "Filename: <input type='text' name='" + Arg_name + "'><br><br>";
  webpage += "<input type='submit' value='Enter'>";
  webpage += "</form>";
  webpage += HTML_Footer();
}
//#############################################################################################
void File_Delete()
{
  SelectInput("Select a File to Delete", "handledelete", "filename");
}
//#############################################################################################
void Handle_File_Delete(String filename)
{ // Delete the file
  webpage = HTML_Header();
  if (!filename.startsWith("/"))
    filename = "/" + filename;
  File dataFile = SPIFFS.open(filename, "r"); // Now read FS to see if file exists
  if (dataFile)
  { // It does so delete it
    SPIFFS.remove(filename);
    webpage += "<h3>File '" + filename.substring(1) + "' has been deleted</h3>";
    webpage += "<a href='/dir'>[Enter]</a><br><br>";
  }
  else
  {
    webpage += "<h3>File [ " + filename + " ] does not exist</h3>";
    webpage += "<a href='/dir'>[Enter]</a><br><br>";
  }
  webpage += HTML_Footer();
}
//#############################################################################################
//#############################################################################################
void Page_Not_Found()
{
  webpage = HTML_Header();
  webpage += "<div class='notfound'>";
  webpage += "<h1>Sorry</h1>";
  webpage += "<p>Error 404 - Page Not Found</p>";
  webpage += "</div><div class='left'>";
  webpage += "<p>The page you were looking for was not found, it may have been moved or is currently unavailable.</p>";
  webpage += "<p>Please check the address is spelt correctly and try again.</p>";
  webpage += "<p>Or click <b><a href='/'>[Here]</a></b> for the home page.</p></div>";
  webpage += HTML_Footer();
}
//#############################################################################################
// Not found handler is also the handler for 'delete', 'download' and 'stream' functions
//#############################################################################################
int GetFileSize(String filename)
{
  int filesize;
  File CheckFile = SPIFFS.open(filename, "r");
  filesize = CheckFile.size();
  CheckFile.close();
  return filesize;
}
//#############################################################################################
String getContentType(String filenametype)
{ // Tell the browser what file type is being sent
  if (filenametype == "download")
  {
    return "application/octet-stream";
  }
  else if (filenametype.endsWith(".txt"))
  {
    return "text/plainn";
  }
  else if (filenametype.endsWith(".htm"))
  {
    return "text/html";
  }
  else if (filenametype.endsWith(".html"))
  {
    return "text/html";
  }
  else if (filenametype.endsWith(".css"))
  {
    return "text/css";
  }
  else if (filenametype.endsWith(".js"))
  {
    return "application/javascript";
  }
  else if (filenametype.endsWith(".png"))
  {
    return "image/png";
  }
  else if (filenametype.endsWith(".gif"))
  {
    return "image/gif";
  }
  else if (filenametype.endsWith(".jpg"))
  {
    return "image/jpeg";
  }
  else if (filenametype.endsWith(".ico"))
  {
    return "image/x-icon";
  }
  else if (filenametype.endsWith(".xml"))
  {
    return "text/xml";
  }
  else if (filenametype.endsWith(".pdf"))
  {
    return "application/x-pdf";
  }
  else if (filenametype.endsWith(".zip"))
  {
    return "application/x-zip";
  }
  else if (filenametype.endsWith(".gz"))
  {
    return "application/x-gzip";
  }
  return "text/plain";
}
void notFound(AsyncWebServerRequest *request)
{ // Process selected file types
  String filename;
  if (request->url().startsWith("/downloadhandler") ||
      request->url().startsWith("/streamhandler") ||
      request->url().startsWith("/deletehandler") ||
      request->url().startsWith("/renamehandler"))
  {
    // Now get the filename and handle the request for 'delete' or 'download' or 'stream' functions
    if (!request->url().startsWith("/renamehandler"))
      filename = request->url().substring(request->url().indexOf("~/") + 1);
    start = millis();
    if (request->url().startsWith("/downloadhandler"))
    {
      debugln("Download handler started...");
      MessageLine = "";
      File file = SPIFFS.open(filename, "r");
      String contentType = getContentType("download");
      AsyncWebServerResponse *response = request->beginResponse(contentType, file.size(), [file](uint8_t *buffer, size_t maxLen, size_t total) mutable -> size_t
                                                                {
        File filecopy = file;
        int bytes = filecopy.read(buffer, maxLen);
        if (bytes + total == filecopy.size()) filecopy.close();
        return max(0, bytes); });
      response->addHeader("Server", "ESP Async Web Server");

      request->send(response);
      downloadtime = millis() - start;
      downloadsize = GetFileSize(filename);
      request->redirect("/dir");
    }
    if (request->url().startsWith("/streamhandler"))
    {
      debugln("Stream handler started...");
      String ContentType = getContentType(filename);
      AsyncWebServerResponse *response = request->beginResponse(SPIFFS, filename, ContentType);
      request->send(response);
      downloadsize = GetFileSize(filename);
      downloadtime = millis() - start;
      request->redirect("/dir");
    }
    if (request->url().startsWith("/deletehandler"))
    {
      debugln("Delete handler started...");
      Handle_File_Delete(filename); // Build webpage ready for display
      request->send(200, "text/html", webpage);
    }
    if (request->url().startsWith("/renamehandler"))
    {
      //      Handle_File_Rename(request, filename, request->args()); // Build webpage ready for display
      request->send(200, "text/html", webpage);
    }
  }
  else
  {
    Page_Not_Found();
    request->send(200, "text/html", webpage);
  }
}
//#############################################################################################
void Handle_File_Download()
{
  String filename = "";
  int index = 0;
  Directory(); // Get a list of files on the FS
  webpage = HTML_Header();
  webpage += "<h3>Select a File to Download</h3>";
  webpage += "<table>";
  webpage += "<tr><th>File Name</th><th>File Size</th></tr>";
  while (index < numfiles)
  {
    webpage += "<tr><td><a href='" + Filenames[index].filename + "'></a><td>" + Filenames[index].fsize + "</td></tr>";
    index++;
  }
  webpage += "</table>";
  webpage += "<p>" + MessageLine + "</p>";
  webpage += HTML_Footer();
}
//#############################################################################################
void Select_File_For_Function(String title, String function)
{
  String Fname1, Fname2;
  int index = 0;
  Directory(); // Get a list of files on the FS
  webpage = HTML_Header();
  webpage += "<h3>Select a File to " + title + " from this device</h3>";
  webpage += "<table class='center'>";
  webpage += "<tr><th>File Name</th><th>File Size</th><th class='sp'></th><th>File Name</th><th>File Size</th></tr>";
  while (index < numfiles)
  {
    Fname1 = Filenames[index].filename;
    Fname2 = Filenames[index + 1].filename;
    if (Fname1.startsWith("/"))
      Fname1 = Fname1.substring(1);
    if (Fname2.startsWith("/"))
      Fname1 = Fname2.substring(1);
    webpage += "<tr>";
    webpage += "<td style='width:25%'><button><a href='" + function + "~/" + Fname1 + "'>" + Fname1 + "</a></button></td><td style = 'width:10%'>" + Filenames[index].fsize + "</td>";
    webpage += "<td class='sp'></td>";
    if (index < numfiles - 1)
    {
      webpage += "<td style='width:25%'><button><a href='" + function + "~/" + Fname2 + "'>" + Fname2 + "</a></button></td><td style = 'width:10%'>" + Filenames[index + 1].fsize + "</td>";
    }
    webpage += "</tr>";
    index = index + 2;
  }
  webpage += "</table>";
  webpage += HTML_Footer();
}
//#############################################################################################
void Home()
{
  webpage = HTML_Header();
  webpage += "<h1>Home Page</h1>";
  webpage += "<h2>ESP Asychronous WebServer Example</h2>";
  webpage += "<img src = 'icon' alt='icon'>";
  webpage += "<h3>File Management - Directory, Download and Delete </h3>";
  webpage += HTML_Footer();
}
String EncryptionType(wifi_auth_mode_t encryptionType)
{
  switch (encryptionType)
  {
  case (WIFI_AUTH_OPEN):
    return "OPEN";
  case (WIFI_AUTH_WEP):
    return "WEP";
  case (WIFI_AUTH_WPA_PSK):
    return "WPA PSK";
  case (WIFI_AUTH_WPA2_PSK):
    return "WPA2 PSK";
  case (WIFI_AUTH_WPA_WPA2_PSK):
    return "WPA WPA2 PSK";
  case (WIFI_AUTH_WPA2_ENTERPRISE):
    return "WPA2 ENTERPRISE";
  case (WIFI_AUTH_MAX):
    return "WPA2 MAX";
  default:
    return "";
  }
}
//#############################################################################################
bool StartMDNSservice(const char *Name)
{
  esp_err_t err = mdns_init(); // Initialise mDNS service
  if (err)
  {
    printf("MDNS Init failed: %d\n", err); // Return if error detected
    return false;
  }
  mdns_hostname_set(Name); // Set hostname
  return true;
}
