#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Content-type: text/html\n\n";  // Required CGI header

    // Get environment variables from POST request
    string data;
    getline(cin, data);

    // Parse type from data (basic way)
    string type = "";
    if (data.find("type=lost") != string::npos)
        type = "lost";
    else if (data.find("type=found") != string::npos)
        type = "found";

    // Set correct file path
    string path = "C:/xampp/htdocs/kalpathon2025/";
    string filename = (type == "lost") ? "lost_items.txt" : "found_items.txt";

    ofstream file(path + filename, ios::app);
    if (file.is_open()) {
        file << data << endl;
        file.close();
    }

    // Response
    cout << "<html><body><h2>Item reported successfully!</h2></body></html>";

    return 0;
}
