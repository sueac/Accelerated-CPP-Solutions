#include <iostream>
#include <string>
#include <vector>
#include "Ref_count.h"
#include "Ptr_count.h"

using std::cout;

class Animal {
public:
    Animal(const std::string& n): name(n) { ++live; cout << "  [created " << name << "]\n"; }
    Animal(const Animal& a): name(a.name) { ++live; cout << "  [copied " << name << "]\n"; }
    virtual ~Animal() { --live; cout << "  [destroyed " << name << "]\n"; }

    virtual std::string speak() const { return "..."; }
    virtual Animal* clone() const { return new Animal(*this); }

    std::string name;
    static int live;                 // how many Animals exist right now
};
int Animal::live = 0;

class Dog : public Animal {
public:
    Dog(const std::string& n): Animal(n) { }
    std::string speak() const { return "Woof"; }
    Dog* clone() const { return new Dog(*this); }
};

int main()
{
    // ---------- Part 1: Ref_count on its own ----------
    cout << "Part 1: Ref_count alone\n";
    Ref_count a;
    cout << "  a alone, unique? " << a.unique() << "\n";            // 1

    {
        Ref_count b = a;                                            // shares a's counter
        cout << "  after copy, a unique? " << a.unique() << "\n";   // 0
    }                                                               // b destroyed, count back to 1
    cout << "  b gone, a unique? " << a.unique() << "\n";           // 1

    Ref_count c;                                                    // c has its own counter
    bool died = c.reattach(a);                                      // c leaves its group, joins a's
    cout << "  c's old group died? " << died << "\n";               // 1
    cout << "  a and c share, a unique? " << a.unique() << "\n";    // 0

    bool split = c.make_unique();                                   // c gets a fresh counter
    cout << "  c split off? " << split << "\n";                     // 1
    cout << "  a unique again? " << a.unique() << "\n";             // 1

    // ---------- Part 2: Ptr using Ref_count ----------
    cout << "\nPart 2: Ptr<Animal>\n";
    {
        Ptr<Animal> p(new Dog("Rex"));
        Ptr<Animal> q = p;                         // shared, no copy of the Dog
        cout << "  p says " << p->speak() << "\n"; // virtual call: Woof

        q.make_unique();                           // shared, so q clones the Dog
        q->name = "Max";
        cout << "  p is " << p->name << ", q is " << q->name << "\n";
        cout << "  live animals: " << Animal::live << "\n";         // 2

        p = q;                                     // p was last owner of Rex, so Rex is deleted
        cout << "  after p = q, live animals: " << Animal::live << "\n";   // 1

        {
            std::vector< Ptr<Animal> > v;
            v.push_back(p);
            v.push_back(p);                        // three handles, still one Dog
            cout << "  with vector, live animals: " << Animal::live << "\n"; // 1
        }                                          // vector's handles die, Dog survives
        cout << "  vector gone, p still valid: " << p->name << "\n";

        p = p;                                     // self-assignment is safe
        cout << "  leaving scope...\n";
    }                                              // q then p destroyed; last one deletes Max
    cout << "  live animals at end: " << Animal::live << "\n";         // 0

    return 0;
}
