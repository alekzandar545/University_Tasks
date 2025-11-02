#include <iostream>
#include <stdexcept>

// Дефиниране на напитките като битови маски
enum Drinks {
    BEER = 1 << 0,
    VODKA = 1 << 1,
    WHISKEY = 1 << 2,
    TEQUILA = 1 << 3,
    COLA = 1 << 4,
    RUM = 1 << 5,
    GIN = 1 << 6,
    MINT = 1 << 7
};

// Структура за място в бара
struct BarSlot {
    unsigned char availableDrinks;
    bool occupied;
    BarSlot* next;
    
    BarSlot() : availableDrinks(0), occupied(false), next(nullptr) {}
};

// Структура за клиент
struct Client {
    unsigned char requiredDrinks;
    Client* next;
    Client* prev;
    
    Client() : requiredDrinks(0), next(nullptr), prev(nullptr) {}
};

// Помощни функции за запазване и възстановяване на състоянието
bool* saveOccupiedState(BarSlot* bar) {
    int len = 0;
    for (BarSlot* curr = bar; curr != nullptr; curr = curr->next) len++;
    
    bool* state = new bool[len];
    int i = 0;
    for (BarSlot* curr = bar; curr != nullptr; curr = curr->next) {
        state[i++] = curr->occupied;
    }
    return state;
}

void restoreOccupiedState(BarSlot* bar, const bool* state) {
    int i = 0;
    for (BarSlot* curr = bar; curr != nullptr; curr = curr->next) {
        curr->occupied = state[i++];
    }
}

// Функция за настаняване на група (част а)
bool place(BarSlot* bar, Client* clients) {
    if (!clients) return true;

    // Пресмятане на размера на групата
    int groupSize = 0;
    for (Client* c = clients; c != nullptr; c = c->next) groupSize++;

    BarSlot* currBar = bar;
    while (currBar) {
        if (!currBar->occupied && (currBar->availableDrinks & clients->requiredDrinks) == clients->requiredDrinks) {
            BarSlot** candidate = new BarSlot*[groupSize];
            candidate[0] = currBar;
            
            Client* currClient = clients->next;
            BarSlot* prev = currBar;
            bool valid = true;
            
            for (int i = 1; currClient != nullptr; i++, currClient = currClient->next) {
                BarSlot* next = prev->next;
                int steps = 0;
                while (next && steps < 5) {
                    if (!next->occupied && (next->availableDrinks & currClient->requiredDrinks) == currClient->requiredDrinks) {
                        candidate[i] = next;
                        prev = next;
                        break;
                    }
                    next = next->next;
                    steps++;
                }
                if (!next || steps >= 5) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                for (int i = 0; i < groupSize; i++)
                    candidate[i]->occupied = true;
                delete[] candidate;
                return true;
            }
            
            delete[] candidate;
        }
        currBar = currBar->next;
    }
    return false;
}

// Функция за проверка на всички групи (част б)
bool placeAllHelper(BarSlot* bar, Client** groups, int count) {
    if (count == 0) return true;
    
    for (int i = 0; i < count; i++) {
        if (!groups[i]) continue;
        
        bool* savedState = saveOccupiedState(bar);
        if (place(bar, groups[i])) {
            Client* temp = groups[i];
            groups[i] = nullptr;
            
            if (placeAllHelper(bar, groups, count)) {
                delete[] savedState;
                return true;
            }
            
            restoreOccupiedState(bar, savedState);
            groups[i] = temp;
        }
        delete[] savedState;
    }
    return false;
}

bool placeAll(BarSlot* bar, Client** groups, int groupCount) {
    Client** copy = new Client*[groupCount];
    for (int i = 0; i < groupCount; i++) copy[i] = groups[i];
    
    bool result = placeAllHelper(bar, copy, groupCount);
    delete[] copy;
    return result;
}

// Помощни функции за въвеждане на данни
BarSlot* createBar(int seats) {
    BarSlot* head = new BarSlot();
    BarSlot* curr = head;
    for (int i = 1; i < seats; i++) {
        curr->next = new BarSlot();
        curr = curr->next;
    }
    return head;
}

Client* createGroup(int size) {
    Client* head = new Client();
    Client* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new Client();
        curr->next->prev = curr;
        curr = curr->next;
    }
    return head;
}

// Главна функция (част в)
int main() {
    int n, groupsCount;
    
    // Въвеждане на данни за бара
    std::cout << "places in bar: ";
    std::cin >> n;
    BarSlot* bar = createBar(n);
    
    BarSlot* curr = bar;
    for (int i = 0; i < n; i++) {
        std::cout << "drinks per place " << (i+1) << " (1-berr, 2-vodka, 3-whiskeyu, 4-tekila, 5-cola, 6-rum, 7-gin, 8-mint): ";
        int drinks;
        std::cin >> drinks;
        curr->availableDrinks = drinks;
        curr = curr->next;
    }
    
    // Въвеждане на групи
    std::cout << "Брой групи: ";
    std::cin >> groupsCount;
    Client** groups = new Client*[groupsCount];
    
    for (int i = 0; i < groupsCount; i++) {
        int k;
        std::cout << "Размер на група " << (i+1) << ": ";
        std::cin >> k;
        groups[i] = createGroup(k);
        
        Client* client = groups[i];
        for (int j = 0; j < k; j++) {
            std::cout << "drinks per client " << (j+1) << ": ";
            int drinks;
            std::cin >> drinks;
            client->requiredDrinks = drinks;
            client = client->next;
        }
    }
    
    // Опит за настаняване
    if (placeAll(bar, groups, groupsCount)) {
        std::cout << "all groups found their place\n";
    } else {
        std::cout << "the following groups didnt find a place to sit:\n";
        for (int i = 0; i < groupsCount; i++) {
            if (groups[i]) std::cout << "group " << (i+1) << "\n";
        }
    }
    
    // Почистване на паметта
    // ... (добавете код за изтриване на структурите)
    
    return 0;
}