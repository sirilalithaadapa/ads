#include <stdlib.h>
#include <iostream>
using namespace std;
class HashTable
{
private:
    int size;
    int *H;

public:
    HashTable(int size)
    {
        this->size = size;
        H = (int *)calloc(size, sizeof(int));
    }
    int hashF(int key)
    {
        return key % size;
    }
    void insert(int key)
    {
        int i = hashF(key);
        H[i] = key;
        display();
    }
    void dele(int key)
    {
        int i = search(key);
        if (i != -1)
            H[i] = 0;
        else
            cout << "Element not found can't be deleted" << endl;
        display();
    }
    int search(int key)
    {
        int i = hashF(key);
        if (H[i] == key)
            return i;
        return -1;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "[ " << i << " : " << H[i] << " ]" << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    int size;
    cout<<"Enter the size of Hash Table" <<endl;
    cin >> size;
    HashTable myTable(size);
    cout << "1.Insert \n 2. Remove \n 3. Search \n 4. Any other to Quit" << endl;
    while (1)
    {
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int ele;
            cin >> ele;
            myTable.insert(ele);
            break;
        case 2:
            cin >> ele;
            myTable.dele(ele);
            break;
        case 3:
            cin >> ele;
            if (myTable.search(ele) != -1)
                cout << "Found" << endl;
            else
                cout << "Not Found <<endl";
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
