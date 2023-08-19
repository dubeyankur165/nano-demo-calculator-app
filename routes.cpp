#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello world!"}; // Respond with "Hello world!"
}

crow::response add(const crow::request &req)
{
    // Parse the JSON request body
    auto input = crow::json::load(req.body);

    // Check if the JSON was parsed successfully
    if (!input)
    {
        return crow::response(400, "Invalid JSON format");
    }

    double first = input["first"].d();
    double second = input["second"].d();

    // Calculate the sum
    double result = first + second;

    // Create the JSON response
    crow::json::wvalue responseJson;
    responseJson["result"] = result;

    return crow::response{responseJson};
}

crow::response subtract(const crow::request &req)
{
    // Parse the JSON request body
    auto input = crow::json::load(req.body);

    // Check if the JSON was parsed successfully
    if (!input)
    {
        return crow::response(400, "Invalid JSON format");
    }

    double first = input["first"].d();
    double second = input["second"].d();

    // Calculate the difference
    double result = first - second;

    // Create the JSON response
    crow::json::wvalue responseJson;
    responseJson["result"] = result;

    return crow::response{responseJson};
}
