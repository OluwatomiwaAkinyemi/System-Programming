#include <iostream>
#include <pqxx/pqxx>
#include <cstdlib>
#include <string>

int main() {
    try {
        // 1. Get database credentials from Environment Variables
        const char* db_host = std::getenv("DB_HOST");
        const char* db_port = std::getenv("DB_PORT");
        const char* db_name = std::getenv("DB_NAME");
        const char* db_user = std::getenv("DB_USER");
        const char* db_pass = std::getenv("DB_PASSWORD");

        // 2. Build the connection string
        // Format: postgresql://user:password@host:port/dbname
        std::string connection_string = "postgresql://" + 
                                        std::string(db_user) + ":" + 
                                        std::string(db_pass) + "@" + 
                                        std::string(db_host) + ":" + 
                                        std::string(db_port) + "/" + 
                                        std::string(db_name);

        // 3. Connect to the database
        std::cout << "Attempting to connect to database..." << std::endl;
        pqxx::connection C(connection_string);

        if (C.is_open()) {
            std::cout << "SUCCESS: Connected to database: " << C.dbname() << std::endl;
        } else {
            std::cout << "ERROR: Failed to open database." << std::endl;
            return 1;
        }

    } catch (const std::exception &e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
