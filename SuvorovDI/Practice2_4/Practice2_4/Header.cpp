#include "Header.h"

// TProductsDatabase:
TProductsDatabase::TProductsDatabase(const std::string& filename) {
    int count = try_to_open_file(filename);
    productsInStock = new TContainer<TInfoProduct>(count);
    std::ifstream file(filename);

    int i = 0;
    while (i < count) {
        std::string line;
        TInfoProduct tmp;

        getline(file, line, ';');
        tmp.SetCode(std::stol(line));

        getline(file, line, ';');
        tmp.SetName(line);

        getline(file, line, ';');
        tmp.SetCost(stod(line));

        getline(file, line, ';');
        tmp.SetCount(stoi(line));

        productsInStock->insert(tmp);

        i++;
        file.get();
    }

    file.close();
}

int TProductsDatabase::try_to_open_file(const std::string& fname) const {
    int c = -1;
    while (c == -1) { 
        getline(std::cin, const_cast<std::string&>(fname));
        c = find_num_univ(fname);

        if (c == -1) {
            std::cout << "Such file doesn't exist" << std::endl;
        }
    }
    return c;
}

int TProductsDatabase::find_num_univ(const std::string& fname) const {
    std::string line;
    int c = 0;

    std::ifstream file(fname);

    if (file.fail())
        return - 1;

    while (getline(file, line)) {
        c++;
    }

    file.close();
    return c;
}

void TProductsDatabase::print() {
    productsInStock->print_elements();
}

// TInfoProduct:
TInfoProduct::TInfoProduct() {
    code = -1;
    name = "";
    cost = -1;
    count = -1;
}

const TInfoProduct& TInfoProduct::operator=(const TInfoProduct& prod) {
    if (this == &prod) {
        return *this;
    }

    code = prod.code;
    name = prod.name;
    cost = prod.cost;
    count = prod.count;

    return *this;
}

void TInfoProduct::SetCode(const long code) {
    this->code = code;
}

void TInfoProduct::SetName(const std::string& name) {
    this->name = name;
}

void TInfoProduct::SetCost(const double cost) {
    this->cost = cost;
}

void TInfoProduct::SetCount(const int count) {
    this->count = count;
}

long TInfoProduct::GetCode() const {
    return code;
}

std::string TInfoProduct::GetName() const {
    return name;
}

double TInfoProduct::GetCost() const {
    return cost;
}

int TInfoProduct::GetCount() const {
    return count;
}

std::ostream& operator<<(std::ostream& out, const TInfoProduct& product) {
    out << "\n";
    out << "Product barcode: " << product.GetCode() << "\n";
    out << "Product name: " << product.GetName() << "\n";
    out << "Unit price: " << product.GetCost() << "\n";
    out << "Quantity of product in stock: " << product.GetCount();

    return out;
}

// TReceipt:
//TReceipt::TReceipt() {
//    code = 0000001;
//    products = nullptr;
//}
//
//TReceipt::TReceipt(int msize) {
//    code = 1000001;
//    products = new TContainer<TReceiptLine>(msize);
//}