/******************************************************************************
Problem 1: String Tokenization for Command Parsing
Problem Statement:
You are developing an embedded system that receives commands over UART. The commands come in the format: "CMD:param1,param2,param3" where parameters are separated by commas. Write a C++ function that parses this command string and extracts the command name and parameters using a stringstream.

Requirements:
• Function should return the command name and a vector of parameters
• Handle cases where there might be extra spaces around parameters
• Command name is always before the first colon
• Use stringstream for parsing, not strtok()
Example:

text
Input: "SET_LED:1,255,0,100"
Output: Command = "SET_LED", Parameters = ["1", "255", "0", "100"]

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::pair<std::string, std::vector<std::string>> parseCommand (const std::string& input)
{
    std::vector<std::string>params;
    
    size_t colonpos= input.find(':');
    if(colonpos== std::string::npos)
        return {input,params};
    
    std::string command = input.substr(0,colonpos);
    std::string paramString = input.substr(colonpos+1);
    
    std::stringstream ss(paramString);
    std::string param;
    std::vector <std::string> parameters;
    while(std:: getline(ss, param, ',' ))
    {
    parameters.push_back(param);
    }
    
    return {command,parameters};
}


int main() {
    // Example input command string
    std::string input = "SET_LED:1,255,0,100";
    
    // Parse the command
    auto result = parseCommand(input);
    
    // Print the parsed command
    std::cout << "Command: " << result.first << std::endl;
    
    // Print the parameters
    std::cout << "Parameters: [";
    for (size_t i = 0; i < result.second.size(); ++i) {
        std::cout << "\"" << result.second[i] << "\"";
        if (i < result.second.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
