template <typename keyType, typename valueType>

// I gotta implement map using linked list

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
    
    public:
        Map() 
        {
            head = nullptr;
        }

        valueType find(const keyType k) 
        {
            Node* current = head;
            while (current) {
                if (current->key == k) {
                    return current->value;
                }
                current = current->next;
            }
            return NULL;
        }

        void add(const keyType k, const valueType v) 
        {
            Node* newNode = new Node(k, v);
            if (!head) {
                head = newNode;
            }
            else {
                head->next = newNode;
                head = newNode;
            }
        }
};