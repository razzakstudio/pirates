#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string getValue(const string& data, const string& key) {
    size_t start = data.find(key + "=");
    if (start == string::npos) return "";
    start += key.length() + 1;
    size_t end = data.find("&", start);
    return data.substr(start, end - start);
}

int main() {
    cout << "Content-type: text/html\n\n";

    string postData;
    char *lenStr = getenv("CONTENT_LENGTH");
    if (!lenStr) return 1;

    int len = atoi(lenStr);
    for (int i = 0; i < len; ++i)
        postData += getchar();

    string type = getValue(postData, "type");
    string item = getValue(postData, "item");
    string desc = getValue(postData, "desc");
    string location = getValue(postData, "location");
    string contact = getValue(postData, "contact");

    string filename = (type == "lost") ? "lost_items.txt" : "found_items.txt";
    ofstream file(filename, ios::app);
    file << item << "," << desc << "," << location << "," << contact << "\n";
    file.close();

    cout << "<h2>Submitted successfully!</h2>";
    cout << "<a href='index.html'>Go Back</a>";

    return 0;
}