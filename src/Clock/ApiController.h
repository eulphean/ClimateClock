#pragma once

#include "ofMain.h"
#include "ofxHttpUtils.h"
#include "ofxJSONElement.h"

class ApiController {
public:
    void setup() {
        request_url = "https://api.climateclock.world/v1/clock";
        ofxHttpResponse response = httpUtils.getUrl(request_url);
        string body = (string) response.responseBody;
        bool ps = json.parse(body);
        if (ps) {
            cout << "Success: JSON parsed.." << endl;
        } else {
            cout << "Failed to parse JSON." << endl;
        }
    }
    
    // Helper functions to request parsed data.
    string getEndDate() {
        return json["data"]["modules"]["carbon_deadline_1"]["timestamp"].asString();
    }
    
    // This is helpful for debugging.
    void printRawJSON() {
        cout << json.getRawString(true) << endl;
    }
private:
    ofxJSONElement json;
    ofxHttpUtils httpUtils;
    string request_url;
};
