#include <iostream>
#include "my_vector.h"
#include <string>

using namespace std;


class A{
    int c;
public:
    A(){}
    A(int c){
        this->c = c;
    }
   friend ostream& operator<<(ostream& os, const A& dt);
   bool operator !=(A& a){
       return a.c>this->c;
   }
};

ostream& operator<<(ostream& os, const A& dt)
{
    os << dt.c;
    return os;
}

int main()
{
    my_vector<A> vec;
    vec.push_back(A(5));
    vec.push_back(A(67));
    vec.push_back(A(447));

    vec.push_back(A(457));
    vec.pop_back();
    for (auto i: vec)
        cout << i << " ";

}
