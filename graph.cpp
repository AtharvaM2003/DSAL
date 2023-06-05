#include<iostream>
#include<iomanip>
using namespace std;

class Graph
{
    string city[10];
    int a[10][10];
    int n;
public:
    void input();
    void display();
  
};

void Graph::input()
{
    cout<<"\nEnter no. of cites: ";
    cin>>n;
    cout<<"\nEnter the names of cities: ";
    for(int i=0 ; i<n ; i++)
        cin >> city[i];

    cout<<"\nEnter the distances: ";
    for(int i=0 ; i<n ; i++)
        for(int j=i ; j<n ; j++)
        {
            if(i==j)
            {
                a[i][j] = 0;
                continue;
            }

            cout<<"\nEnter the distance between " << city[i] <<" and " << city[j]<< " : ";
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
}

void Graph::display()
{
    cout << endl;
    cout << setw(10) << " ";
    for(int i=0 ; i<n ; i++)
        
        cout << setw(10) << city[i];
    cout << endl;

    for(int i=0 ; i<n ; i++)
    {
        // Print row header with city name
        cout << setw(10) << city[i];

        for(int j=0 ; j<n ; j++)
        {
            cout << setw(10) << a[i][j];
        }
        cout << endl;
    }
}


int main()
{
    Graph g1;
    int choice;
MENU:
    cout<<"\n\nGRAPH TRAVERSAL";
    cout<<"\n1. Input data";
    cout<<"\n2. Display data";
    cout<<"\n3. Exit";
    cout<<"\nEnter your choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
    	g1.input();
    	break;
    case 2:
    	g1.display();
    	break;
    case 3:
    	return 0;
    default:
    	cout<<"\nInvalid choice.Try again!";
    }
    if(choice != 3)
    	goto MENU;
    return 0;
}
