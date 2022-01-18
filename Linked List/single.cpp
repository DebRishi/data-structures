#include<iostream>

using namespace std;

struct node
{
    int val;
    node * next;

    node(int x = 0,node * n = 0)
    {
        val = x;
        next = n;
    }
};

class List
{   
    node * head;
    int size;

    public  :

    List()
    {
        head = 0;
        size = 0;
    }

    void insert(int x,int pos = 0)
    {
        node * h = head;
        node * p = new node(x);
        
        if(head==0)
        head = p;

        else if(pos == 0 || pos == -size)
        {
            p->next = head;
            head = p;
        }

        else if(pos == -1 || pos == size)
        {
            while(h->next)
            h = h->next;

            h->next = p;
        }

        else if(pos > 0 && pos < size)
        {
            for(int i = 0 ; i < pos-1 ; i++)
            h = h->next;

            p->next = h->next;
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

        if(pos == 0)
        {
            temp = head;
            head = head->next;
            x = temp->val;
            delete(temp);
            size--;
            return x;
        }

        else if(pos == -1 || pos == size-1)
        {
            while(h->next->next)
            h = h->next;

            temp = h->next;
            h->next = temp->next;
            x = temp->val;
            delete(temp);
            size--;
            return x;
        }

        else if(pos > 0 && pos < size-1)
        {
            for(int i = 0 ; i < pos-1 ; i++)
            h = h->next;

            temp = h->next;
            h->next = temp->next;
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

    void delete_list()
    {
        if(!head)
        return;
        
        node * h = head;
        node * p;

        while(h)
        {
            p = h;
            h = h->next;
            cout<<p->val<<" ";
            delete(p);
        }

        head = 0;
        size = 0;
    }

    void reverse()
    {
        if(head == 0 || size == 1)
        return;

        node * current = head;
        node * prev = 0;
        node * next = 0;

        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void sort()
    {
        if(head == 0 || size == 1)
        return;
        
        for(node * i = head ; i != 0 ; i = i->next)
        {
            for(node * j = i->next ; j != 0 ; j = j->next)
            {
                if(j->val < i->val)
                {
                    int temp = i->val;
                    i->val = j->val;
                    j->val = temp;
                }
            }
        }
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
    l.insert(60,-1);
    l.traverse();
    l.sort();
    l.traverse();
    return 0;
}