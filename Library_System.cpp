#include <iostream>
#include<algorithm>
const int MAX_BOOKS = 10;
const int MAX_USERS = 10;

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

bool cmp_book_by_name(Book& a, Book& b) {
	return a.name < b.name;
}

bool cmp_book_by_id(Book& a, Book& b) {
	return a.id < b.id;
}

struct user {
	int id;
	std::string name;
	int borrowed_books_ids[MAX_BOOKS];
	int len;

	user() {
		name = "";
		len = 0;
		id = -1;
	}

	void read() {
		std::cout << "Enter user name & national id: ";
		std::cin >> name >> id;
	}

	void borrow(int book_id) {
		borrowed_books_ids[len++] = book_id;
	}
	void return_copy(int book_id) {
		bool removed = false;
		for (int i = 0; i < len; ++i) {
			if (borrowed_books_ids[i] == book_id) {
				
				for (int j = i + 1; j < len; ++j)
					borrowed_books_ids[j - 1] = borrowed_books_ids[j];
				removed = true;
				--len;
				break;
			}
		}
		if (!removed)
			std::cout << "User " << name << " never borrowed book id " << book_id
			<< "\n";
	}

	bool is_borrowed(int book_id) {
		for (int i = 0; i < len; ++i) {
			if (book_id == borrowed_books_ids[i])
				return true;
		}
		return false;
	}

	void print() 
	{
		std::sort(borrowed_books_ids, borrowed_books_ids + len);
		std::cout << "user " << name << " id " << id << " borrowed books ids: ";
		for (int i = 0; i < len; ++i)
			std::cout << borrowed_books_ids[i] << " ";
		std::cout << "\n";
	}
};


int main()
{
    
}

