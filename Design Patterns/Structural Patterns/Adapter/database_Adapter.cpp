#include <iostream>
#include <string>

// Target interface (SQL Database)
class SQLDatabase {
public:
    virtual void connect(const std::string& connectionString) = 0;
    virtual void executeQuery(const std::string& query) = 0;
    virtual ~SQLDatabase() {}
};

// Adaptee class (NoSQL Database)
class NoSQLDatabase {
public:
    void connectToNoSQL(const std::string& url) const {
        std::cout << "Connecting to NoSQL database at " << url << "\n";
    }

    void runNoSQLQuery(const std::string& query) const {
        std::cout << "Running NoSQL query: " << query << "\n";
    }
};

// Adapter class (adapts NoSQLDatabase to SQLDatabase interface)
class NoSQLAdapter : public SQLDatabase {
private:
    const NoSQLDatabase& noSQLDb; // The Adaptee
public:
    NoSQLAdapter(const NoSQLDatabase& db) : noSQLDb(db) {}

    // Adapts the connect() method to NoSQL's connectToNoSQL()
    void connect(const std::string& connectionString) override {
        noSQLDb.connectToNoSQL(connectionString); // Call Adaptee's method
    }

    // Adapts the executeQuery() method to NoSQL's runNoSQLQuery()
    void executeQuery(const std::string& query) override {
        noSQLDb.runNoSQLQuery(query); // Call Adaptee's method
    }
};

// Client code that expects an SQLDatabase interface
void useDatabase(SQLDatabase& db) {
    db.connect("localhost");
    db.executeQuery("SELECT * FROM users");
}

int main() {
    NoSQLDatabase noSQLDb; // Adaptee (NoSQL database)
    NoSQLAdapter adapter(noSQLDb); // Adapter for NoSQL

    // Client can now use the NoSQL database through the SQLDatabase interface
    useDatabase(adapter);

    return 0;
}

/*
    Connecting to NoSQL database at localhost
    Running NoSQL query: SELECT * FROM users
*/