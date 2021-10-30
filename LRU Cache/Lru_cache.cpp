class LRUCache
{
public:
    struct Node
    {
        int key, val;
        Node *next, *prev;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size;
    map<int, Node *> mp;

    Node *insertNode(int _key, int _value)
    {
        Node *temp = new Node(_key, _value);
        Node *next_node = head->next;

        head->next = temp;
        temp->next = next_node;
        next_node->prev = temp;
        temp->prev = head;
        return temp;
    }

    void deleteNode(Node *temp)
    {
        Node *next_node = temp->next;
        Node *prev_node = temp->prev;

        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete temp;
    }

    LRUCache(int capacity)
    {
        size = capacity;

        head->next = tail;
        tail->prev = head;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    int get(int key)
    {

        if (mp.find(key) == mp.end())
            return -1;

        Node *temp = mp[key];
        int value = temp->val;
        deleteNode(temp);
        Node *temp2 = insertNode(key, value);
        mp[key] = temp2;

        return value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end() && mp.size() < size)
        {
            Node *temp = insertNode(key, value);
            mp[key] = temp;
        }
        else if (mp.find(key) == mp.end() && mp.size() == size)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);

            Node *temp2 = insertNode(key, value);
            mp[key] = temp2;
        }
        else if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            deleteNode(temp);
            Node *newNode = insertNode(key, value);

            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */