//
//  main.cpp
//  WQUQPC
//
//  Created by Jayanti supransh murty on 6/5/16.
//  Copyright (c) 2016 jayanti supransh murty. All rights reserved.
//

#include <iostream>


using namespace std;


class wquwpc {


    int count;
    int *parent = nullptr;
    int *size = nullptr;
    
public:
    
    
    
    wquwpc(int n)
    {

        parent = new int[n];
        size = new int [n];
        count = n;
        
        for (int i =0 ; i < n ; i++)
        {
            parent[i] = i;
            size[i] = 1; }    }
    
    ~wquwpc() {
        
        
        parent= NULL;
        size = NULL;
        
        free(parent);
        free(size);
        
        delete (parent);
        delete (size);
        
    }
    
    
    int counter ()
    {return count;}
    
    
    
    bool connected( int a, int b )
    {return find(a) == find(b) ;}
    
    int find(int p)
    {
    
        
        
        int i = p;
        
        while (i != parent[i] )
            i = parent[i];
        
        while (p != i)
        {  int newp = parent[p];
        parent[p]= i ;
            p = newp; }
        
        return i ;
    
    }

    
    
    
    
    void unioner (int p , int q)
    
    {   int root_p = find(p);
        int root_q = find(q);
        
        if (root_p == root_q)
            return;
        
        else if (size[root_p] > size[root_q])
            {
                parent[root_q]=root_p;
                size[root_p] += size[root_q];
            
            }
            
            else if (size[root_p] < size[root_q])
                {
                    parent[root_p]=root_q;
                    size[root_q] += size[root_p];
                    
                }

                count--;
    
            }
    
                     };


           int main()
                     
            {
                int sz;
                cout << "enter a size  ";
                
                cin >> sz;
                
                wquwpc list1(sz);
                
                
                
                 char c;
                
                cout << "enter linkages, make queries ,press q to exit, anything else to continue (press q before last linkage)  ";
                
                while (c != 'q') {
                    
                    int p ;
                    int q ;
                    cin >> c >> p >> q ;
                    
                    if (list1.connected(p, q)) continue;
                    
                    list1.unioner(p, q);
                    
                    cout << p << "   " << q << "\n";
                }
                cout << list1.counter() << " components \n";
                
                
                list1.~wquwpc();
            }
            
        
                     
        
                     
                     
                     
                     
                     
                     
                     
                     
                    





