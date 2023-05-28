#include "Header.h"

// TProductsDatabase:
TProductsDatabase::TProductsDatabase(const std::string& filename) {
    get_correct_file_name(filename);
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        std::stringstream f_line(line);
        std::string info_unit;
        TInfoProduct tmp;
        TProduct curr_prod;

        getline(f_line, info_unit, ';');
        curr_prod.code = stol(info_unit);

        getline(f_line, info_unit, ';');
        curr_prod.name = info_unit;

        getline(f_line, info_unit, ';');
        curr_prod.cost = stod(info_unit);

        tmp.product = curr_prod;

        getline(f_line, info_unit, ';');
        tmp.count = stoi(info_unit);

        productsInStock.insert(tmp);

        /*file.get();*/
    }

    file.close();
}
void TProductsDatabase::get_correct_file_name(const std::string& fname) const {
    bool file_exist;
    do {
        getline(std::cin, const_cast<std::string&>(fname));
        file_exist = check_file_name(fname);
        if (!file_exist)
            std::cout << "Such file doesn't exist" << std::endl;
    } while (!file_exist);
}
bool TProductsDatabase::check_file_name(const std::string& fname) const {
    std::ifstream fin(fname);
    return !fin.fail();
}
void TProductsDatabase::print() {
    std::cout << productsInStock;
}
TInfoProduct& TProductsDatabase::operator[](int ind) {
    return productsInStock[ind];
}
int TProductsDatabase::Get_num_prods() {
    return productsInStock.Get_size();
}
int TProductsDatabase::barcode_search(const long barcode) {
    for (int i = 0; i < productsInStock.Get_size(); i++) {
        if (productsInStock[i].product.code == barcode) {
            return i;
        }
    }
    return -1;
}

// TInfoProduct:
std::ostream& operator<<(std::ostream& out, const TInfoProduct& prod) {
    out << "\n";
    out << "Product: \n" << prod.product;
    out << "Quantity of product in stock: " << prod.count;

    return out;
}
bool TInfoProduct::operator==(const TInfoProduct& p) {
    return (product == p.product and count == p.count);
}

// TProduct:
bool TProduct::operator==(const TProduct& p) {
    return (code == p.code and name == p.name and cost == p.cost);
}
std::ostream& operator<<(std::ostream& out, const TProduct& p) {
    out << "Product code: " << p.code << "   ";
    out << "Product name: " << p.name << "   ";
    out << "Cost per unit: " << p.cost;

    return out;
}

//TReceiptLine:
TReceiptLine::TReceiptLine() {
    count = 0;
    sum_cost = 0;
}

TReceiptLine::TReceiptLine(TProduct& product, int count, double sum_cost) {
    this->product = product;
    this->count = count;
    this->sum_cost = sum_cost;
}

TProduct& TReceiptLine::Get_product() {
    return product;
}
int TReceiptLine::Get_count() {
    return count;
}
double TReceiptLine::Get_sum_cost() {
    return sum_cost;
}

void TReceiptLine::Set_count(int c) {
    count = c;
}

void TReceiptLine::Set_sum_cost(double s) {
    sum_cost = s;
}

const TReceiptLine& TReceiptLine::operator=(const TReceiptLine& rec_line) {
    this->product = rec_line.product;
    this->count = rec_line.count;
    this->sum_cost = rec_line.sum_cost;

    return (*this);
}

std::ostream& operator<<(std::ostream& out, const TReceiptLine& rec_line) {
    out << rec_line.product << "\n";
    out << rec_line.count << " pieces\n";
    out << "total cost:" << rec_line.sum_cost << "rubles\n\n";

    return out;
}

// TReceipt:
long TReceipt::code = -1;
void TReceipt::Code_increase() {
    code++;
}

int TReceipt::Get_num_products() {
    return products.Get_size();
}

TReceipt::TReceipt() {
    Code_increase();
    
}

void TReceipt::Add_new_prod(const TReceiptLine& rec_line) {
    products.insert(rec_line);
}

//TReceipt::TReceipt(TReceipt& rec) {
//    rec.Get_num_products();
//    for (int i = 0; i < rec.Get_num_products(); i++) {
//        this->products.insert(rec.products[i]);
//    }
//    this->code = rec.code;
//    
//}

TReceiptLine& TReceipt::operator[](int ind) {
    return products[ind];
}

const TReceipt& TReceipt::operator= (const TReceipt& rec) {
    this->code = rec.code;
    this->products = rec.products;

    return (*this);
}

int TReceipt::Find_product(const TProduct& prod) {
    for (int i = 0; i < products.Get_size(); i++) {
        if (products[i].Get_product() == prod) {
            return i;
        }
    }
    return -1;
}

std::ostream& operator<<(std::ostream& out, const TReceipt& rec) {
    out << "\n------------------------------------------\n";
    out << "Receipt code: " << rec.code << "\n\n";
    out << "Yout products: \n";

    out << rec.products;

    out << "------------------------------------------\n";

    return out;
}