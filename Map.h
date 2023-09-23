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
            Node* current = head;
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;

            current = m.head;
            while (current != NULL) {
                insert(current->key, current->value);
                current = current->next;
            }
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

        friend std::ostream& operator<<(std::ostream& os, const Map& m)
        {
            Node* current = m.head;
            while (current != NULL) {
                os << current->key << "\t" << current->value << "\n"; 
                current = current->next;
            }
            return os;
        }
};