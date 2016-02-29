#include <iostream>
using namespace std;

class Item_base {
    public:
        Item_base(const std::string &book = "", double sales_price = 0.0):
            isbn(book), price(sales_price){}
        std::string book() const {return isbn;}

        virtual double net_price(std::size_t n) const
        {
            std::cout << "BASE CLASS" << std::endl;
            return n*price; 
        }
        
        virtual Item_base* clone() const {
            return new Item_base(*this);
        }
        virtual ~Item_base() {}

    private:
        std::string isbn;
    protected:
        double price;
};

class Bulk_item:public Item_base {
    public:
        double net_price(std::size_t) const;
        Bulk_item* clone() const {
            return new Bulk_item(*this);
        }
    private:
        std::size_t min_qty;
        double discount;
};

double Bulk_item::net_price(std::size_t cnt) const
{
    std::cout << "DERIVED CLASS" << std::endl;
    if (cnt >= min_qty)
        return cnt*(1-discount)*price;
    else
        return cnt*price;
}

void get_prices(Item_base object, 
        const Item_base *pointer,
        const Item_base &reference)
{
    cout << "pointer: " << pointer->net_price(1) << endl;
    cout << "reference: " << reference.net_price(1) << endl;

    cout << "object: " << object.net_price(1) << endl;
}

class Sales_item {
    public:
        Sales_item() : p(0), use(new std::size_t(1)) {}
        Sales_item(const Item_base&);
        Sales_item(const Sales_item& i): p(i.p), use(i.use) { ++*use; }
        ~Sales_item() { decr_use(); }
        Sales_item& operator=(const Sales_item&);

        const Item_base *operator->() const {
            if (p) 
                return p;
            else
                throw std::logic_error("unbound Sales item ->");
        }
        const Item_base &operator*() const {
            if (p)
                return *p;
            else
                throw std::logic_error("unbound Sales item *");
        }

    private:
        Item_base *p;
        std::size_t *use;
        void decr_use() { if (--*use == 0) {delete p; delete use;}}
};

Sales_item& 
Sales_item::operator=(const Sales_item& i)
{
    ++*i.use;
    decr_use();
    p = i.p;
    use = i.use;
    return *this;
}
Sales_item::Sales_item(const Item_base& item):
    p(item.clone()), use(new std::size_t(1)) {}

int main()
{
    Bulk_item item2;
    Bulk_item *i = &item2;
    
    item2.net_price(20);
    i->net_price(10);
    std::cout << "Helloooo" << std::endl;

    get_prices(item2, i, item2);

    cout << "#####" << endl;

    Sales_item item(Bulk_item("1234", 35, 3, .20));

    item->net_price();

    return 0;
}

