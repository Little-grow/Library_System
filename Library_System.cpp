#include <iostream>

struct Book
{
    int id;
    std::string name;
    int total_quantity;
    int total_borrowed;

    Book()
    {
        total_quantity = total_borrowed = 0;
        id = -1;
        name = "";
    }

    void read()
    {
        std::cout << "Enter your name , id , quantity\n";
        std::cin >> name >> id >> total_quantity;
    }

    bool borrow(int user_id)
    {
        if (total_quantity - total_borrowed <= 0)
            return false;
        ++total_borrowed;
        return true;
    }

    void return_copy()
    {
        if (total_borrowed > 0)
            --total_borrowed;
    }

    bool has_prefix(std::string prefix)
    {
        int len = (int)prefix.size();
        if (len > (int) name.size())
            return false;
        for (size_t i = 0; i < len; i++)
        {
            if (prefix[i] != name[i])
                return false;
        }
        return true;
    }

    void print()
    {
        std::cout << "Id: " << id << "  Name: " << name << '\n';
    }
};
int main()
{
    
}

