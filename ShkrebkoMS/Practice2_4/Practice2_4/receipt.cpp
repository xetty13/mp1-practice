
#include "Receipt.h"
#include "Container.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <ctime>

TProductsDatabase::TProductsDatabase(const string& filename) 
{
    get_correct_file_name(filename);
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        stringstream f_line(line);
        string stuff;
        TInfoProduct tmp;
        TProduct curr_prod;

        getline(f_line, stuff, ';');
        curr_prod.code = stol(stuff);

        getline(f_line, stuff, ';');
        curr_prod.name = stuff;

        getline(f_line, stuff, ';');
        curr_prod.price = stod(stuff);

        tmp.product = curr_prod;

        getline(f_line, stuff, ';');
        tmp.count = stoi(stuff);

        products.insert(tmp);

    }

    file.close();
}
void TProductsDatabase::get_correct_file_name(const string& fname) const 
{
    bool file_exist;
    do 
    {
        getline(cin, const_cast<string&>(fname));
        file_exist = check_file_name(fname);
        if (!file_exist)
            cout << "Such file doesn't exist" << std::endl;
    } while (!file_exist);
}
bool TProductsDatabase::check_file_name(const string& fname) const
{
    ifstream fin(fname);
    return !fin.fail();
}

TInfoProduct& TProductsDatabase::operator[](int ind) 
{
    return products[ind];
}
int TProductsDatabase::Get_num_prods()  const
{
    return products.getSize();
}
int TProductsDatabase::barcode_search(const int barcode) 
{
    for (int i = 0; i < products.getSize(); i++)
    {
        if (products[i].product.code == barcode)
        {
            return i;
        }
    }
    return -1;
}
void TProductsDatabase::Updating_remove(const TProduct& prod) 
{
    int ind_such_prod = this->barcode_search(prod.code);
    (*this)[ind_such_prod].count -= 1;
}

void TProductsDatabase::Updating_add(const TProduct& prod) 
{
    int ind_such_prod = this->barcode_search(prod.code);
    (*this)[ind_such_prod].count += 1;
}
    
ostream& operator<<(ostream& out, const TInfoProduct& prod) {
    out << endl;
    out << "Product: "<< endl << prod.product;
    out << "Quantity of product in stock: " << prod.count;

    return out;
}
bool TInfoProduct::operator==(const TInfoProduct& p) const
{
    return (product == p.product && count == p.count);
}


bool TProduct::operator==(const TProduct& p) const
{
    return (code == p.code && name == p.name && price == p.price);
}
ostream& operator<<(ostream& out, const TProduct& p)
{
    out << "Product code: " << p.code << "   ";
    out << "Product name: " << p.name << "   ";
    out << "Cost per unit: " << p.price;

    return out;
}

ostream& operator<<(ostream& out, const TProductsDatabase& db)
{
    out << db.products;
    return out;
}
TReceiptLine::TReceiptLine() 
{
    count = 0;
    summ = 0;
}

TReceiptLine::TReceiptLine(TProduct& product, int count, double sum_price)
{
    this->product = product;
    this->count = count;
    this->summ = sum_price;
}

TReceiptLine::TReceiptLine(const TReceiptLine& rec_line) 
{
    this->product = rec_line.product;
    this->count = rec_line.count;
    this->summ = rec_line.summ;
}

const TProduct& TReceiptLine::Get_product() const
{
    return product;
}

int TReceiptLine::Get_count() const
{
    return count;
}

double TReceiptLine::Get_sum_cost() const 
{
    return summ;
}

void TReceiptLine::Set_count(int c) 
{
    count = c;
}

void TReceiptLine::Set_sum_cost(double s) 
{
    summ = s;
}

const TReceiptLine& TReceiptLine::operator=(const TReceiptLine& rec_line) 
{
    this->product = rec_line.product;
    this->count = rec_line.count;
    this->summ = rec_line.summ;

    return (*this);
}

bool TReceiptLine::operator==(const TReceiptLine& rec_line) const
{
    return (this->product == rec_line.product);
}

ostream& operator<<(std::ostream& out, const TReceiptLine& rec_line)
{
    out << rec_line.product << endl;
    out << rec_line.count << " counts" << endl;
    out << "total cost:" << rec_line.summ << "rubles" << endl << endl;

    return out;
}


TTime::TTime() 
{
    hour = 0;
    minute = 0;
    second = 0;
}

TDate::TDate() 
{
    year = 0;
    month = 0;
    day = 0;
}

long TReceipt::code = -1;
void TReceipt::Code_increase()
{
    code++;
}

TReceipt::TReceipt() {}

TReceipt::TReceipt(const TReceipt& rec) 
{
    this->code = rec.code;
    this->time = rec.time;
    this->date = rec.date;
    this->products = rec.products;
}

TReceiptLine& TReceipt::operator[](int ind) 
{
    return products[ind];
}

const TReceipt& TReceipt::operator= (const TReceipt& rec)
{
    if (this == &rec)
        return (*this);

    this->code = rec.code;
    this->time = rec.time;
    this->date = rec.date;
    this->products = rec.products;

    return (*this);
}

std::ostream& operator<<(std::ostream& out, TReceipt& rec) 
{
    rec.Code_increase();

    out << "\n------------------------------------------\n";
    out << "Receipt code: " << rec.code << "\n\n";
    out << rec.date.day << "." << rec.date.month << "." << rec.date.year << "  ";
    out << rec.time.hour << ":" << rec.time.minute << ":" << rec.time.second << "\n";
    out << "Your products: \n";

    out << rec.products;

    out << "TOTAL SUM:  " << rec.Get_total_sum() << " rubles\n";

    out << "------------------------------------------\n";

    return out;
}

int TReceipt::Get_num_products() const 
{
    return products.getSize();
}

void TReceipt::Add_new_prod(const TReceiptLine& rec_line) 
{
    products.insert(rec_line);
}

int TReceipt::Find_product(const long code) const
{
    for (int i = 0; i < products.getSize(); i++)
    {
            if (products[i].Get_product().code == code) 
            {
                return i;
            }
        }
    return -1;
}

double TReceipt::Get_total_sum() const
{
    double total_sum = 0;
    int count = this->Get_num_products();

    for (int i = 0; i < count; i++) 
    {
        total_sum += this->products[i].Get_sum_cost();
    }

    return total_sum;
}

void TReceipt::SetTime() 
{
    std::time_t now = std::time(0);
    std::tm* localtime = std::localtime(&now);
    this->time.hour = localtime->tm_hour;
    this->time.minute = localtime->tm_min;
    this->time.second = localtime->tm_sec;

    this->date.day = localtime->tm_mday;
    this->date.month = localtime->tm_mon + 1;
    this->date.year = localtime->tm_year + 1900;
}

void TReceipt::Delete_prod(const int ind)
{
    cout << "This product was deleted: " << this->products[ind].Get_product() << endl;
    if (this->products[ind].Get_count() == 1)
        this->products.remove(ind);
    else
        this->products[ind].Set_count(this->products[ind].Get_count() - 1);
}
void TReceipt::Delete(TProductsDatabase& db)
{
    if (this->Get_num_products() == 0)
    {
        cout << "The receipt is empty" << endl;
    }
    else
    {
        cout << "Enter product barcode" << endl;
        int search;
        string barcode;
        do
        {

            getline(cin, barcode);
            search = this->Find_product(stol(barcode));
            if (search == -1)
            {
                cout << "No product with this barcode" << endl;
            }

        } while (search == -1);
        db.Updating_add((*this)[search].Get_product());
        this->Delete_prod(search);
    }
}
void TReceipt :: Add(TProductsDatabase& db, int search)
{
    TProduct curr_product = db[search].product;
    cout << endl << curr_product << endl;

    int idx_prod_in_receipt = this->Find_product(curr_product.code);
    if (idx_prod_in_receipt != -1)
    {
        ((*this)[idx_prod_in_receipt]).Set_count((
            (*this)[idx_prod_in_receipt]).Get_count() + 1);

        ((*this)[idx_prod_in_receipt]).Set_sum_cost
        (((*this)[idx_prod_in_receipt]).Get_sum_cost() + curr_product.price);
    }
    else
    {
        TReceiptLine curr_rec_line(curr_product, 1, curr_product.price);
        (*this).Add_new_prod(curr_rec_line);
    }
    db.Updating_remove(curr_product);
}