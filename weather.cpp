#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct WeatherRecord {
    Date date;
    string city;
    double temperature;
};

class DataStorage {
private:
    vector<string> cities;
    vector<int> years;
    vector<vector<double>> temperatureData;
    const double SENTINEL_VALUE = -999.0;

    int getCityIndex(const string& city) {
        for (int i = 0; i < cities.size(); ++i) {
            if (cities[i] == city) {
                return i;
            }
        }
        return -1;
    }

    int getYearIndex(int year) {
        for (int i = 0; i < years.size(); ++i) {
            if (years[i] == year) {
                return i;
            }
        }
        return -1; 
    }

public:
    DataStorage(const vector<string>& cityList, int startYear, int endYear) {
        cities = cityList;
        for (int y = startYear; y <= endYear; ++y) {
            years.push_back(y);
        }
        temperatureData.resize(years.size(), vector<double>(cities.size(), SENTINEL_VALUE));
    }

    bool insert(const WeatherRecord& data) {
        int yearIdx = getYearIndex(data.date.year);
        int cityIdx = getCityIndex(data.city);

        if (yearIdx != -1 && cityIdx != -1) {
            temperatureData[yearIdx][cityIdx] = data.temperature;
            cout << "Inserted: Temp " << data.temperature << " for " << data.city << " in " << data.date.year << endl;
            return true;
        }
        cerr << "Error: Could not insert data for " << data.city << " in " << data.date.year << ". City or Year not in system." << endl;
        return false;
    }

    bool remove(const string& city, int year) {
        int yearIdx = getYearIndex(year);
        int cityIdx = getCityIndex(city);

        if (yearIdx != -1 && cityIdx != -1) {
            temperatureData[yearIdx][cityIdx] = SENTINEL_VALUE;
            cout << "Deleted: Data for " << city << " in " << year << endl;
            return true;
        }
        cerr << "Error: Could not delete data for " << city << " in " << year << ". Not found." << endl;
        return false;
    }

    double retrieve(const string& city, int year) {
        int yearIdx = getYearIndex(year);
        int cityIdx = getCityIndex(city);

        if (yearIdx != -1 && cityIdx != -1) {
            return temperatureData[yearIdx][cityIdx];
        }
        return SENTINEL_VALUE;
    }

    void displayData() {
        cout << "\n--- Weather Data Table ---\n";
        cout << left << setw(8) << "Year";
        for (const auto& city : cities) {
            cout << setw(12) << city;
        }
        cout << "\n------------------------------------------------------\n";

        for (size_t i = 0; i < years.size(); ++i) {
            cout << left << setw(8) << years[i];
            for (size_t j = 0; j < cities.size(); ++j) {
                if (temperatureData[i][j] == SENTINEL_VALUE) {
                    cout << setw(12) << "N/A";
                } else {
                    cout << fixed << setprecision(1) << setw(12) << temperatureData[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void displayRowMajorAccess() {
        cout << "\n--- Accessing Data (Row-Major Order) ---\n";
        for (size_t i = 0; i < years.size(); ++i) {
            for (size_t j = 0; j < cities.size(); ++j) {
                double temp = temperatureData[i][j];
                 if (temp != SENTINEL_VALUE) {
                    cout << "Accessing [" << years[i] << "][" << cities[j] << "] -> " << temp << endl;
                 }
            }
        }
    }

    void displayColumnMajorAccess() {
        cout << "\n--- Accessing Data (Column-Major Order) ---\n";
        for (size_t j = 0; j < cities.size(); ++j) {
            for (size_t i = 0; i < years.size(); ++i) {
                double temp = temperatureData[i][j];
                if (temp != SENTINEL_VALUE) {
                    cout << "Accessing [" << years[i] << "][" << cities[j] << "] -> " << temp << endl;
                }
            }
        }
    }
};

int main() {
    vector<string> cityList = {"Delhi", "Mumbai", "Kolkata", "Chennai"};
    DataStorage weatherSystem(cityList, 2023, 2025);

    cout << "Weather Data System Initialized.\n" << endl;

    weatherSystem.insert({ {1, 1, 2023}, "Delhi", 15.5 });
    weatherSystem.insert({ {5, 3, 2023}, "Mumbai", 28.2 });
    weatherSystem.insert({ {12, 6, 2024}, "Kolkata", 32.0 });
    weatherSystem.insert({ {20, 8, 2025}, "Sohna", 30.5 });
    weatherSystem.insert({ {15, 5, 2025}, "Gurgaon", 35.1 });
    weatherSystem.insert({ {10, 11, 2023}, "Bengalore", 22.8 });

    weatherSystem.displayData();

    cout << "--- Retrieving Data ---\n";
    double temp = weatherSystem.retrieve("Delhi", 2023);
    if (temp != -999.0) {
        cout << "Retrieved temp for Delhi in 2023: " << temp << endl;
    } else {
        cout << "No data available for Delhi in 2023." << endl;
    }
    
    temp = weatherSystem.retrieve("Mumbai", 2024);
    if (temp != -999.0) {
        cout << "Retrieved temp for Mumbai in 2024: " << temp << endl;
    } else {
        cout << "No data available for Mumbai in 2024 (Sparse Data)." << endl;
    }

    cout << "\n--- Deleting Data ---\n";
    weatherSystem.remove("Kolkata", 2023);
    weatherSystem.displayData();

    weatherSystem.displayRowMajorAccess();
    weatherSystem.displayColumnMajorAccess();
    
    cout << "\n--- Complexity Analysis ---\n";
    cout << "See the README.md file for a detailed breakdown of the time and space complexity.\n";

    return 0;
}

