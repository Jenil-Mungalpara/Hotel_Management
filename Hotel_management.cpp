#include<bits/stdc++.h>
using namespace std;

class Room {
    int room_No;
    string room_type;
    double price;
    bool availablity;

public:
    Room(int num, string type, double p) {
        room_No = num;
        room_type = type;
        price = p;
        availablity = true;
    }

    int get_no() { return room_No; }
    string get_type() { return room_type; }
    double get_price() { return price; }
    bool get_availabliy() { return availablity; }
    void set_availabliy(bool val) { availablity = val; }

    void display() {
        cout << "  - Room #" << room_No << " [" << room_type << "], Price: $" << price 
             << ", Available: " << (availablity ? "Yes" : "No") << endl;
    }
};

class Customer {
protected:
    string name;
    int id;
    string phone;

public:
    Customer(string n = "", int i = 0, string p = "") : name(n), id(i), phone(p) {}
    
    virtual ~Customer() {}

    string get_name() { return name; }
    int get_id() { return id; }
    virtual double discount() { return 0.0; }
    virtual void display() {
        cout << "  - Customer ID: " << id << ", Name: " << name << ", Phone: " << phone << endl;
    }
};

class VIPCustomer : public Customer {
public:
    VIPCustomer(string n, int i, string p) : Customer(n, i, p) {}
    double discount() override {
        return 0.15;
    }
    void display() override {
        cout << "  - VIP Customer ID: " << id << ", Name: " << name 
             << ", Phone: " << phone << " [15% Discount]" << endl;
    }
};

class Booking {
    int id;
    Customer* customer; 
    Room* room;

public:
    Booking(int i, Customer* c, Room* r) {
        customer = c;
        id = i;
        room = r;
        if (room) room->set_availabliy(false);
    }

    int get_id() const { return id; }
    Room* get_room() { return room; }
    
    double calculate(int nights) {
        if (!room) return 0.0;
        double total = room->get_price() * nights;
        total -= total * customer->discount();
        return total;
    }

    void display() {
        cout << "Booking ID: " << id << endl;
        cout << "  Customer Details:" << endl;
        customer->display();
        cout << "  Room Details:" << endl;
        room->display();
    }
};

class Hotel {
    vector<Room> r;
    vector<Customer*> c; 
    vector<Booking> b;
    int customer_id = 1;
    int booking_id = 1;

public:
    // Destructor to clean up allocated customer memory
    ~Hotel() {
        for (auto cust : c) delete cust;
    }

    void add_room(int num, string type, double price) {
        r.push_back(Room(num, type, price));
        cout << "Room #" << num << " added successfully." << endl;
    }

    void showAvailableRooms() {
        cout << "\n--- Available Rooms ---" << endl;
        bool found = false;
        for (auto &room : r) {
            if (room.get_availabliy()) {
                room.display();
                found = true;
            }
        }
        if (!found) cout << "No room available at the moment." << endl;
    }

    void book_room() {
        showAvailableRooms();
        cout << "Enter room number to book: ";
        int roomNum;
        cin >> roomNum;

        Room* tempRoom = nullptr;
        for (auto &room : r) {
            if (room.get_no() == roomNum && room.get_availabliy()) {
                tempRoom = &room;
                break;
            }
        }

        if (!tempRoom) {
            cout << "Invalid room number or room not available." << endl;
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter customer name: ";
        string name;
        getline(cin, name);

        cout << "Enter customer phone: ";
        string phone;
        cin >> phone;

        cout << "Is this a VIP customer? (1 for Yes / 0 for No): ";
        bool isVip;
        cin >> isVip;

        Customer* newCust;
        if (isVip)
            newCust = new VIPCustomer(name, customer_id++, phone);
        else
            newCust = new Customer(name, customer_id++, phone);

        c.push_back(newCust);
        b.push_back(Booking(booking_id++, newCust, tempRoom));

        cout << "Room #" << roomNum << " booked successfully for " << name << "!" << endl;
    }

    void checkOut() {
        cout << "Enter booking ID to check-out: ";
        int id;
        cin >> id;

        auto it = find_if(b.begin(), b.end(), [id](const Booking &bk) { return bk.get_id() == id; });

        if (it == b.end()) {
            cout << "Booking ID not found." << endl;
            return;
        }

        cout << "Enter number of nights stayed: ";
        int nights;
        cin >> nights;

        double bill = it->calculate(nights);
        cout << "\n--- Final Bill ---" << endl;
        it->display();
        cout << "Nights Stayed: " << nights << endl;
        cout << "Total Bill: $" << bill << endl;
        cout << "------------------\n" << endl;

        it->get_room()->set_availabliy(true);
        b.erase(it);
    }

    void searchCustomer() {
        cout << "Enter customer ID to search: ";
        int id;
        cin >> id;

        auto it = find_if(c.begin(), c.end(), [id](Customer* cust) { return cust->get_id() == id; });

        if (it != c.end()) {
            cout << "\n--- Customer Found ---" << endl;
            (*it)->display();
        } else {
            cout << "Customer with ID " << id << " not found." << endl;
        }
    }

    void displayAllRooms() {
        for (auto &room : r) room.display();
    }
};

void showMenu() {
    cout << "\n===== Hotel Management System =====\n"
         << "1. Add Room\n2. Show Available Rooms\n3. Book a Room\n"
         << "4. Check-Out & Generate Bill\n5. Search Customer\n6. Show All Rooms\n7. Exit\n"
         << "Enter choice: ";
}

int main() {
    Hotel hotel;
    hotel.add_room(101, "Single", 80.0);
    hotel.add_room(102, "Double", 120.0);
    
    int choice;
    do {
        showMenu();
        if (!(cin >> choice)) break;
        
        if (choice == 1) {
            int n; double p; string t;
            cout << "Room No: "; cin >> n;
            cout << "Type: "; cin >> t;
            cout << "Price: "; cin >> p;
            hotel.add_room(n, t, p);
        } else if (choice == 2) hotel.showAvailableRooms();
        else if (choice == 3) hotel.book_room();
        else if (choice == 4) hotel.checkOut();
        else if (choice == 5) hotel.searchCustomer();
        else if (choice == 6) hotel.displayAllRooms();
        
    } while (choice != 7);

    return 0;
}