#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function to read numbers from file and create a dynamic 2D array
std::vector<std::vector<int>> readNumbersFromFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    std::vector<std::vector<int>> array2D;

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::vector<int> row;
            size_t pos = 0;
            std::string token;
            while ((pos = line.find(',')) != std::string::npos) {
                token = line.substr(0, pos);
                row.push_back(std::stoi(token));
                line.erase(0, pos + 1);
            }
            row.push_back(std::stoi(line));  // Add the last number in the row
            array2D.push_back(row);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }

    return array2D;
}

// Function to convert coordinates of integer values to a formatted string array
std::vector<std::string> convertCoordinatesToStringArray(const std::vector<std::vector<int>>& array2D) {
    std::vector<std::string> coordinatesArray;

    for (size_t i = 0; i < array2D.size(); ++i) {
        for (size_t j = 0; j < array2D[i].size(); ++j) {
            while (coordinatesArray.size() <= static_cast<size_t>(array2D[i][j])) {
                // If the size of the array is less than the current integer value,
                // add empty strings until the array is large enough.
                coordinatesArray.emplace_back("");
            }

            // Append coordinates to the string for the corresponding index
            coordinatesArray[array2D[i][j]] += std::to_string(i) + "," + std::to_string(j) + ";";
        }
    }

    return coordinatesArray;
}

// Function to write the content of the string array to a text file
void writeStringArrayToFile(const std::string& filePath, const std::vector<std::string>& stringArray) {
    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        for (const std::string& line : stringArray) {
            // Write the line and '*' after each line, even for blank lines
            if (line.empty()) {
                outputFile << 'n';
            }
            else {
                outputFile << line;
            }
            outputFile << '*';
        }
        outputFile.close();
    }
    else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }
}

int main() {
    std::string inputFilePath;
    std::string outputFilePath;

    // Prompt the user for the input file path and check if the file exists
    while (true) {
        std::cout << "Enter the input file path, including the .txt extension (or type 'exit' to quit): ";
        std::getline(std::cin, inputFilePath);

        if (inputFilePath == "exit") {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }

        std::ifstream testFile(inputFilePath);
        if (testFile.is_open()) {
            testFile.close();
            break;
        }
        else {
            std::cerr << "File does not exist. Please try again." << std::endl << std::endl;
        }
    }

    std::cout << std::endl;

    // Prompt the user for the output file path and check if it includes the .txt extension
    while (true) {
        std::cout << "Enter the output file path, including the .txt extension (or type 'exit' to quit): ";
        std::getline(std::cin, outputFilePath);

        if (outputFilePath == "exit") {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }

        if (outputFilePath.size() >= 4 && outputFilePath.substr(outputFilePath.size() - 4) == ".txt") {
            break;
        }
        else {
            std::cerr << "Output file path must include the .txt extension. Please try again." << std::endl << std::endl;
        }
    }

    std::cout << std::endl;

    // Call the function to read numbers and create the dynamic 2D array
    std::vector<std::vector<int>> resultArray = readNumbersFromFile(inputFilePath);

    // Call the function to convert coordinates to a formatted string array
    std::vector<std::string> coordinatesArray = convertCoordinatesToStringArray(resultArray);

    // Call the function to write the string array to a text file
    writeStringArrayToFile(outputFilePath, coordinatesArray);

    // Notify the user about the successful encoding
    std::cout << "Picture encoding was performed successfully. The file named " << outputFilePath << " was added to the project folder.";
    std::cout << std::endl;

    return 0;
}