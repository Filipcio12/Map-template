template <typename keyType, typename valueType>

// I gotta implement map using linked list

class Map {
    private:
        struct Node {
            keyType key;
            valueType value;
            Node* prev;
            Node* next;

            Node(const keyType k, const valueType v) {
                key = k;
                value = v;
                prev = nullptr;
                next = nullptr;
            }
        }

        Node* head;
    
    public:
        Map() {
            head = nullptr;
        }
};