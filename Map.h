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
    
    public:
        Map() 
        {
            head = nullptr;
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

        valueType find(const keyType k) 
        {
            Node* node = findPtr(k);
            if (node == NULL) {
                throw std::invalid_argument("Key not found.");
            }
            return node->value;
        }

        void add(const keyType k, const valueType v) 
        {
            Node* newNode = new Node(k, v);
            newNode->next = head;
            head = newNode;
        }
};