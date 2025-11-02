#include <iostream>

#define CARD_INPUT_MAXLEN 3
#define MAX_DECK_SIZE 52
#define MAX_STR_LEN 100
#define MAX_CARDS_IN_HAND 13

enum Color : bool{
    RED,
    BLACK
};

enum Suit : char{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum Honor : char{
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14
};

struct Card
{
    Suit suit; 
    Color color; 
    union
    {
        int small; 
        Honor honor;
    };
    bool isSmall;
};

Card ReadCard(){
    Card card;
    char info[CARD_INPUT_MAXLEN];
    std::cin.getline(info, CARD_INPUT_MAXLEN);
    char num = info[0];
    char suit = info[1];
    //1 represents 10
    if(num >= '1' && num <='9'){
        card.isSmall = true;
        if(num == '1')
            card.small = 10;
        else
            card.small = num - '0';
    }
    else{
        card.isSmall = false;
        switch (num) 
        {
            case 'J':
                card.honor = JACK;
                break;
            case 'Q':
                card.honor = QUEEN;
                break;
            case 'K':
                card.honor = KING;
                break;
            case 'A':
                card.honor = ACE;
                break;
        }
    }
    switch (suit)
    {
        case 'H':
            card.suit = HEARTS;
            card.color = RED;
            break;
        case 'D':
            card.suit = DIAMONDS;
            card.color = RED;
            break;
        case 'C':
            card.suit = CLUBS;
            card.color = BLACK;
            break;
        case 'S':
            card.suit = SPADES;
            card.color = BLACK;
            break;
    }
    return card;
}

void PrintCard(const Card& card){
    if(card.isSmall)
        std::cout << card.small;
    else{
        switch (card.honor)
        {
        case JACK:
            std::cout << "Jack";
            break;
        case QUEEN:
            std::cout << "Queen";
            break;
        case KING:
            std::cout << "King";
            break;
        case ACE:
            std::cout << "Ace";
            break;
        }
    }
    std::cout << " of ";

    switch (card.suit)
    {
    case HEARTS:
        std::cout << "Hearts";
        break;
    case DIAMONDS:
        std::cout << "Diamonds";
        break;
    case CLUBS:
        std::cout << "Clubs";
        break;
    case SPADES:
        std::cout << "Spades";
        break;
    }
    std::cout << '\n';
}

struct Deck{
    Card deck[MAX_DECK_SIZE] = {
        {HEARTS, RED, 2, true}, {HEARTS, RED, 3, true}, {HEARTS, RED, 4, true},
        {HEARTS, RED, 5, true}, {HEARTS, RED, 6, true}, {HEARTS, RED, 7, true},
        {HEARTS, RED, 8, true}, {HEARTS, RED, 9, true}, {HEARTS, RED, 10, true},
        {HEARTS, RED, JACK}, {HEARTS, RED, QUEEN}, {HEARTS, RED, KING},
        {HEARTS, RED, ACE},
        {DIAMONDS, RED, 2, true}, {DIAMONDS, RED, 3, true}, {DIAMONDS, RED, 4, true},
        {DIAMONDS, RED, 5, true}, {DIAMONDS, RED, 6, true}, {DIAMONDS, RED, 7, true},
        {DIAMONDS, RED, 8, true}, {DIAMONDS, RED, 9, true}, {DIAMONDS, RED, 10, true},
        {DIAMONDS, RED, JACK}, {DIAMONDS, RED, QUEEN}, {DIAMONDS, RED, KING},
        {DIAMONDS, RED, ACE},
        {CLUBS, BLACK, 2, true}, {CLUBS, BLACK, 3, true}, {CLUBS, BLACK, 4, true},
        {CLUBS, BLACK, 5, true}, {CLUBS, BLACK, 6, true}, {CLUBS, BLACK, 7, true},
        {CLUBS, BLACK, 8, true}, {CLUBS, BLACK, 9, true}, {CLUBS, BLACK, 10, true},
        {CLUBS, BLACK, JACK}, {CLUBS, BLACK, QUEEN}, {CLUBS, BLACK, KING},
        {CLUBS, BLACK, ACE},
        {SPADES, BLACK, 2, true}, {SPADES, BLACK, 3, true}, {SPADES, BLACK, 4, true},
        {SPADES, BLACK, 5, true}, {SPADES, BLACK, 6, true}, {SPADES, BLACK, 7, true},
        {SPADES, BLACK, 8, true}, {SPADES, BLACK, 9, true}, {SPADES, BLACK, 10, true},
        {SPADES, BLACK, JACK}, {SPADES, BLACK, QUEEN}, {SPADES, BLACK, KING},
        {SPADES, BLACK, ACE}        
    };
    unsigned remaining = MAX_DECK_SIZE;
};

struct Player{
    char name[MAX_STR_LEN];
    int cards[MAX_CARDS_IN_HAND];
};

void DealPlayer(Player& player, Deck& deck){
    //we keep only indexes
    if(deck.remaining == 0){
        std::cout << "No more cards!";
        return;
    }

    for (size_t i = 0; i < MAX_CARDS_IN_HAND; i++)
    {
        player.cards[i] = deck.remaining - 1;
        deck.remaining--;
    }
    
}

void ShowHand(const Player& player, const Deck& deck){
    for (size_t i = 0; i < MAX_CARDS_IN_HAND; i++)
    {
        PrintCard(deck.deck[player.cards[i]]);
    }
}

int main(){
    Deck deck;
    Player p1, p2, p3, p4;
    Player players[] = {p1, p2, p3, p4};
    const short numPlayers = sizeof(players) / sizeof(players[0]);
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin.getline(players[i].name, MAX_STR_LEN);
    }
    for (int i = 0; i < numPlayers; i++) 
    {
        DealPlayer(players[i], deck);
    }

    for (int i = 0; i < numPlayers; i++) 
    {
        std::cout << "//////\n" << players[i].name <<"\n///////\n";
        ShowHand(players[i], deck);
    }
    return 0;
}