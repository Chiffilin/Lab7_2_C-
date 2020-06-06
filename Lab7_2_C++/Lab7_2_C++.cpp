#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class Stack 
{

    private:node* head;

    public:Stack()//Конструктор по умолчанию
    { 
        head = NULL;
    }

    ~Stack()//Деструктор
    { 
        while (head != NULL)
        {
            node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void push(int data)  //Функция добавления элемента в стек
    {
        node* temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void pop()//Функция удаления элемента из вершины стека 
    { 
        if (head == NULL) 
        {
            cout << "Ошибка!Стек пуст!\n";
        }
        else 
        
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int min() //Функция поиска суммы элементов стека
    {
        node* temp = head;
        int min = 0;
        while (temp != NULL) 
        {
           
            min = temp->data;
           
            temp = temp->next;
        }
        return min;
    }

    void print()//Функция вывода списка на экран 
    { 
        bool flag = false;
        node* temp = head;
        cout << "Стек сейчас:\n";
        while (temp != NULL) 
        {
            cout << temp->data << " ";
            temp = temp->next;
            flag = true;
        }
        if (!flag) {
            cout << "Стек пуст!\n";
        }
        cout << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Stack st;
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(4);
    st.print();
    st.pop();
    st.print();
    cout << "Последний элемент стека: " << st.min() << "\n";
    return 0;
}