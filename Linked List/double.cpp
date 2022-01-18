#include<iostream>

using namespace std;

struct node
{
    int val;
    node * next;
    node * prev;

    node(int x = 0,node * n = 0,node * p = 0)
    {
        val = x;
        next = n;
        prev = p;
    }
};

class List
{
    node * head;
    node * last;
    int size;

    public : 

    List()
    {
        head = 0;
        last = 0;
        size = 0;
    }

    void insert(int x,int pos = 0)
    {
        node * h = head;
        node * p = new node(x);

        if(head == 0)
        {
            head = p;
            last = p;
        }

        else if(pos == 0 || pos == -size)
        {
            p->next = h;
            h->prev = p;
            head = p;
        }

        else if(pos == -1 || pos == size)
        {
            last->next = p;
            p->prev = last;
        }

        else if(pos > 0 && pos < size)
        {
            for(int i = 0 ; i < pos - 1 ; i++)
            h = h->next;

            p->next = h->next;
            p->prev = h;
            h->next = p;
        }

        else
        return;

        size++;
    }

    int remove(int pos = 0)
    {
        if(!head)
        return -1;

        node * h = head;
        node * temp;
        int x;

        if(size == 1)
        {
            temp = head;
            head = 0;
            last = 0;
            x = temp->val;
            delete(temp);
            size--;
            return x;
        }
        
        else if(pos == 0)
        {
            temp = head;
            head = head->next;
            head->prev = 0;
            x = temp->val;
            delete(temp);
            size--;
            return x;
        }

        else if(pos == -1 || pos == (size - 1))
        {
            temp = last;
            last = last->prev;
            last->next = 0;
            x = temp->val;
            delete(temp);
            size--;
            return x;
        }

        else if(pos > 0 && pos < size - 1)
        {
            for(int i = 0 ; i < pos-1 ; i++)
            h = h->next;

            temp = h->next;
            h->next = temp->next;
            temp->next->prev = h;
            x = temp->val;
            delete(temp);
            size--;
            return x;
        }

        else
        return -1;
    }

    void traverse()
    {
        if(!head)
        {
            cout<<"No list Exists";
        }
        
        node * h = head;

        while(h)
        {
            cout<<h->val<<" ";
            h = h->next;
        }

        cout<<endl;
    }
};

int main()
{
    List l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    l.remove(0);
    l.traverse();
    return 0;
}