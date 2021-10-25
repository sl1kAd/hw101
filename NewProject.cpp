#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();
    void clear();
    void sort(int m[], int lengthM);
    void push_back(T data);
    int GetSize() { return Size; }

    T& operator[](const int index);

private:

    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };


    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::sort(int m[], int lengthM)
{
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < lengthM; i++)
    {
        j = i;
        for (int k = i; k < lengthM; k++)
        {
            if (m[j] > m[k])
            {
                j = k;
            }
        }

        tmp = m[i];
        m[i] = m[j];
        m[j] = tmp;
    }
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    setlocale(0, "rus");
    List<int> lst;
    List<int> lst2;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(1);
    int m = lst.GetSize();
    int* b = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < lst.GetSize(); i++)
    {
        b[i] = lst[i];
        cout << lst[i] << "  " << b[i] << endl;

    }
    cout << b[0] << endl;
    cout << lst.GetSize() << endl;
    for (int i = 0; i < lst.GetSize(); i++) lst2.push_back(lst[i]);
    for (int i = 0; i < lst2.GetSize(); i++) cout << lst2[i] << endl;
    cout << lst2[0] << endl;
    for (int i = 0; i < lst.GetSize(); i++) cout << lst[i] << endl;
    lst.sort(b, m);
    for (int i = 0; i < lst.GetSize(); i++) cout << "\n" << lst[i] << endl;
    stack <int> first;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') first.push(s[i]);
        else
        {
            if (s[i] == ')' && !first.empty() && first.top() == '(') first.pop();
            else if (s[i] == '}' && !first.empty() && first.top() == '{') first.pop();
            else if (s[i] == ']' && !first.empty() && first.top() == '[') first.pop();
            else if ((s[i] == ']' || s[i] == '}' || s[i] == ')') && first.empty())
            {
                first.push(i);
                break;
            }
        }
    }
    if (first.empty()) {
        cout << "Впорядке\n";
    }
    else {
        cout << "Не впорядке\n";
    }
}


// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
