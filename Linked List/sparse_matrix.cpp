#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int val[3];
    node * next;

    node(int r,int c,int x)
    {
        val[0] = r;
        val[1] = c;
        val[2] = x;
        next = 0;
    }
};

class sparse
{
    int row;
    int col;
    node * head;

    public :

    sparse()
    {
        row = 0;
        col = 0;
        head = 0;
    }

    sparse(int r,int c)
    {
        row = r;
        col = c;
        head = 0;
    }

    sparse(vector<vector<int>> x)
    {
        row = x.size();
        col = x[0].size();
        head = 0;
        node * last = 0;

        for(int i = 0 ; i < x.size() ; i ++)
        {
            for(int j = 0 ; j < x[0].size() ; j++)
            {
                if(x[i][j])
                {
                    node * p = new node(i,j,x[i][j]);
                    if(head == 0)
                    {
                        head = p;
                        last = p;
                    }

                    else
                    {
                        last->next = p;
                        last = p;
                    }
                }
            }
        }
    }
    
    void sort()
    {
        for(node * x = head ; x != 0 ; x = x->next)
        {
            for(node * y = x->next ; y != 0 ; y = y->next)
            {
                if(y->val[0] < x->val[0])
                {
                    swap(x->val[0],y->val[0]);
                    swap(x->val[1],y->val[1]);
                    swap(x->val[2],y->val[2]);
                }
            }
        }

        for(node * x = head ; x != 0 ; x = x->next)
        {
            for(node * y = x->next ; y != 0 ; y = y->next)
            {
                if((y->val[0] == x->val[0]) && (y->val[1] < x->val[1]))
                {
                    swap(x->val[0],y->val[0]);
                    swap(x->val[1],y->val[1]);
                    swap(x->val[2],y->val[2]);
                }
            }
        }
    }
    
    void display()
    {
        vector<vector<int>> x(row,vector<int> (col));

        node * h = head;

        while(h != 0)
        {
            x[h->val[0]][h->val[1]] = h->val[2];
            h = h->next;
        }

        cout<<"OUTPUT : "<<endl;

        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                cout<<x[i][j]<<" ";
            }

            cout<<endl;
        }
    }

    void display_table()
    {
        cout<<"table format : "<<endl;
        node * h = head;

        while(h)
        {
            cout<<h->val[0]<<"\t"<<h->val[1]<<"\t"<<h->val[2]<<endl;
            h = h->next;
        }
    }

    void remove_duplicates()
    {
        node * i = head;

        while(i)
        {
            node * prev = i;
            node * j = i->next;

            while(j)
            {
                if(i->val[0] == j->val[0] && i->val[1] == j->val[1])
                {
                    i->val[2] = i->val[2] + j->val[2];

                    node * temp = j;
                    prev->next = j->next;
                    j = j->next;
                    delete(temp);
                }
                
                else
                {
                    prev = j;
                    j = j->next;
                }
            }

            i = i->next;
        }
    }

    sparse transpose()
    {
        sparse x(row,col);
        node * h = head;
        node * p = 0;
        while(h)
        {
            node * t = new node(h->val[1],h->val[0],h->val[2]);

            if(x.head == 0)
            {
                x.head = t;
                p = t;
            }

            else
            {
                p->next = t;
                p = p->next;
            }

            h = h->next;
        }

        x.sort();

        return x;
    }

    sparse addition(sparse s)
    {
        if(row != s.row || col != s.col)
        return sparse();

        sparse x(row,col);
        
        node * i = head;
        node * j = s.head;
        node * p = 0;

        while(i != 0 && j != 0)
        {
            if(i->val[0] == j->val[0])
            {
                if(i->val[1] == j->val[1])
                {
                    node * t = new node(i->val[0],i->val[1],i->val[2] + j->val[2]);

                    if(x.head == 0)
                    {
                        x.head = t;
                        t = p;
                    }

                    else
                    {
                        p->next = t;
                        p = p->next;
                    }

                    i = i->next;
                    j = j->next;
                }

                else if(i->val[1] < j->val[1])
                {
                    node * t = new node(i->val[0],i->val[1],i->val[2]);

                    if(x.head == 0)
                    {
                        x.head = t;
                        t = p;
                    }

                    else
                    {
                        p->next = t;
                        p = p->next;
                    }

                    i = i->next;
                }

                else
                {
                    node * t = new node(j->val[0],j->val[1],j->val[2]);

                    if(x.head == 0)
                    {
                        x.head = t;
                        t = p;
                    }

                    else
                    {
                        p->next = t;
                        p = p->next;
                    }

                    j = j->next;
                }
            }

            else if(i->val[0] < j->val[0])
            {
                node * t = new node(i->val[0],i->val[1],i->val[2]);

                if(x.head == 0)
                {
                    x.head = t;
                    p = t;
                }

                else
                {
                    p->next = t;
                    p = p->next;
                }

                i = i->next;
            }

            else
            {
                node * t = new node(j->val[0],j->val[1],j->val[2]);

                if(x.head == 0)
                {
                    x.head = t;
                    p = t;
                }

                else
                {
                    p->next = t;
                    p = p->next;
                }

                j = j->next;
            }
        }

        while(i != 0)
        {
            node * t = new node(i->val[0],i->val[1],i->val[2]);
            p->next = t;
            p = p->next;
            i = i->next;
        }

        while(j != 0)
        {
            node * t = new node(j->val[0],j->val[1],j->val[2]);
            p->next = t;
            p = p->next;
            j = j->next;
        }

        return x;
    }

    sparse multiplication(sparse s)
    {
        if(col != s.row)
        return sparse();

        sparse r(row,s.col);

        sparse t = s.transpose();

        node * i = head;
        node * p = 0;

        while(i)
        {
            node * j = t.head;

            while(j)
            {
                if(i->val[1] == j->val[1])
                {
                    node * temp = new node(i->val[0],j->val[0],(i->val[2] * j->val[2]));

                    if(r.head == 0)
                    {
                        r.head = temp;
                        p = temp;
                    }

                    else
                    {
                        p->next = temp;
                        p = p->next;
                    }
                }

                j = j->next;
            }

            i = i->next;
        }

        r.remove_duplicates();

        r.sort();

        return r;
    }
};

int main()
{
    vector<vector<int>> x = { {0,10,0,12} , {0,0,0,0} , {0,0,5,0} , {15,12,0,0} };
    sparse s(x);
    vector<vector<int>> y = { {0,0,8,0} , {0,0,0,23} , {0,0,9,0} , {20,25,0,0} };
    sparse s1(y);
    s.display();
    s1.display();
    (s.multiplication(s1)).display();
    return 0;
}