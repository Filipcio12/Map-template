#include <exception>

template <typename keyType, typename valueType>

class Map {
    private:
        struct Node {
            keyType key;
            valueType value;
            Node* next;

            Node(const keyType k, const valueType v) {
                key = k;
                value = v;
                next = nullptr;
            }
        };

        Node* head;

        Node* findPtr(const keyType k) 
        {
            Node* current = head;
            while (current != NULL) {
                if (current->key == k) {
                    return current;
                }
                current = current->next;
            }
            return NULL;
        }

        void insert(const keyType k, const valueType v) 
        {
            Node* newNode = new Node(k, v);
            newNode->next = head;
            head = newNode;
        }

        void reverse()
        {
            Node* current = head;
            Node *prev = nullptr, *next = nullptr;
            while (current != NULL)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
    
    public:
        Map() 
        {
            head = nullptr;
        }

        Map(const Map& m)
        {
            head = nullptr;
            Node* current = m.head;
            while (current != NULL) {
                insert(current->key, current->value);
                current = current->next;
            }
            reverse();
        }

        ~Map() 
        {
            Node* current = head;
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }

        Map& operator=(const Map& m) 
        {
            this->~Map();
            head = nullptr;
            Node* current = m.head;
            while (current != NULL) {
                insert(current->key, current->value);
                current = current->next;
            }
            reverse();
            return *this;
        }

        valueType* find(const keyType k)
        {
            Node* node = findPtr(k);
            if (node == NULL) {
                throw std::runtime_error("Key not found.");
            }
            valueType* valuePtr = &(node->value);
            return valuePtr;
        }

        valueType findValue(const keyType k) 
        {
            Node* node = findPtr(k);
            if (node == NULL) {
                throw std::runtime_error("Key not found.");
            }
            return node->value;
        }

        void add(const keyType k, const valueType v) 
        {
            Node* node = findPtr(k);
            if (node != NULL) {
                node->value = v;
                return;
            }
            Node* newNode = new Node(k, v);
            newNode->next = head;
            head = newNode;
        }

        friend void printReverse(std::ostream& os, Node* h)
        {
            if (h == NULL) {
                return;
            }
            printReverse(os, h->next);
            os << h->key << "\t" << h->value << "\n";
        }

        friend std::ostream& operator<<(std::ostream& os, const Map& m)
        {
            printReverse(os, m.head);
            return os;
        }
};