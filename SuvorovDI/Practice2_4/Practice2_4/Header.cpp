#include "Header.h"

bool isDigit(const std::string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (std::isdigit(s[i]) == 0)
            return false;
    }
    return true;
}


int TReceipt::get_barcode_add(TProductsDatabase& db) {
    std::string barcode;
    int search_result = 0;
    bool isAvaliable = true;

    getline(std::cin, barcode);
    if (isDigit(barcode)) {
        search_result = db.barcode_search(stol(barcode));
        if (search_result == -1) {
            std::cout << "In our store there are not the product with this barcode. Try again!\n  >>> ";
        }
        else if (db[search_result].count == 0) {
            isAvaliable = false;
        }
    }
    if (!isDigit(barcode)) {
        std::cout << "Barcodes consists only of digits! Try again!\n\n  >>> ";
    }
    if (!isAvaliable) {
        std::cout << "Unfortunately, the product is out of stock. Take something else.\n\n  >>> ";
    }

    if (search_result != -1 and isDigit(barcode) and isAvaliable) {
        return search_result;
    }
    else {
        return -1;
    }
}

int TReceipt::get_barcode_delete(TProductsDatabase& db) {
    std::string barcode;
    int search_result = 0;

    getline(std::cin, barcode);
    if (isDigit(barcode)) {
        search_result = this->Find_product(stol(barcode));
        if (search_result == -1) {
            std::cout << "You did not add a product with this barcode to the receipt. Try again\n\n  --- ";
        }
    }
    if (!isDigit(barcode)) {
        std::cout << "Barcodes consists only of digits! Try again\n\n  --- ";
    }
    
    if (search_result != -1 and isDigit(barcode)) {
        return search_result;
    }
    else {
        return -1;
    }
}

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
int TProductsDatabase::Get_num_prods() const {
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

void TProductsDatabase::Updating_data_remove(const TProduct& prod) {
    int ind_such_prod = this->barcode_search(prod.code);
    (*this)[ind_such_prod].count -= 1;
}

void TProductsDatabase::Updating_data_add(const TProduct& prod, int count) {
    int ind_such_prod = this->barcode_search(prod.code);
    (*this)[ind_such_prod].count += count;
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
    out << "Cost per unit: " << p.cost << "\n";

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

TReceiptLine::TReceiptLine(const TReceiptLine& rec_line) {
    this->product = rec_line.product;
    this->count = rec_line.count;
    this->sum_cost = rec_line.sum_cost;
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

bool TReceiptLine::operator==(const TReceiptLine& rec_line) {
    return (this->product == rec_line.product);
}

std::ostream& operator<<(std::ostream& out, const TReceiptLine& rec_line) {
    out << rec_line.product << "\n";
    out << rec_line.count << " pieces\n";
    out << "total cost:" << rec_line.sum_cost << "rubles\n\n";

    return out;
}

// Time & Data
TTime::TTime() {
    hour = 0;
    minute = 0;
    second = 0;
}

TDate::TDate() {
    year = 0;
    month = 0;
    day = 0;
}

// TReceipt:
long TReceipt::code = -1;
void TReceipt::Code_increase() {
    code++;
}

TReceipt::TReceipt() {}

TReceipt::TReceipt(const TReceipt& rec) {
    this->code = rec.code;
    this->time = rec.time;
    this->date = rec.date;
    this->products = rec.products;
}

TReceiptLine& TReceipt::operator[](int ind) {
    return products[ind];
}

const TReceipt& TReceipt::operator= (const TReceipt& rec) {
    if (this == &rec)
        return (*this);

    this->code = rec.code;
    this->time = rec.time;
    this->date = rec.date;
    this->products = rec.products;

    return (*this);
}

std::ostream& operator<<(std::ostream& out, TReceipt& rec) {
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

int TReceipt::Get_num_products() const {
    return products.Get_size();
}

void TReceipt::Add_new_prod(const TReceiptLine& rec_line) {
    products.insert(rec_line);
}

int TReceipt::Find_product(const long code) {
    for (int i = 0; i < products.Get_size(); i++) {
        if (products[i].Get_product().code == code) {
            return i;
        }
    }
    return -1;
}

double TReceipt::Get_total_sum() {
    double total_sum = 0;
    int count = this->Get_num_products();

    for (int i = 0; i < count; i++) {
        total_sum += this->products[i].Get_sum_cost();
    }

    return total_sum;
}

void TReceipt::Get_data_n_time() {
    std::time_t mil = std::time(0);
    std::tm* now = std::localtime(&mil);
    this->time.hour = now->tm_hour;
    this->time.minute = now->tm_min;
    this->time.second = now->tm_sec;

    this->date.day = now->tm_mday;
    this->date.month = now->tm_mon + 1;
    this->date.year = now->tm_year + 1900;
}

void TReceipt::Delete_prod(const int ind) {
    std::cout << "This product was deleted: " << this->products[ind].Get_product() << "\n";
    this->products.remove(ind);
}

void TReceipt::Delete(TProductsDatabase& db) {
    if (this->Get_num_products() == 0) {
        std::cout << "The receipt is empty, there is nothing to delete!\n"; \
    }
    else {
        std::cout << "Enter product barcode that you want to delete:\n\n  --- ";
        int search_result = this->get_barcode_delete(db);
        
        if (search_result != -1) {
            db.Updating_data_add((*this)[search_result].Get_product(), (*this)[search_result].Get_count());
            this->Delete_prod(search_result);
        }
    }
}

void TReceipt::Add(TProductsDatabase& db) {
    std::cout << "Enter barcode you want to add\n\n  >>> ";

    int search_result = this->get_barcode_add(db);

    if (search_result != -1) {

        TProduct curr_p = db[search_result].product;
        std::cout << "\n" << curr_p << "\n";

        // Search such prod in receipt

        int idx_prod_in_receipt = this->Find_product(curr_p.code);
        if (idx_prod_in_receipt != -1) {
            ((*this)[idx_prod_in_receipt]).Set_count(
                ((*this)[idx_prod_in_receipt]).Get_count() + 1
            );

            ((*this)[idx_prod_in_receipt]).Set_sum_cost(
                ((*this)[idx_prod_in_receipt]).Get_sum_cost() + curr_p.cost
            );
        }
        else {
            TReceiptLine curr_rec_line(curr_p, 1, curr_p.cost);
            this->Add_new_prod(curr_rec_line);
        }

        db.Updating_data_remove(curr_p);
    }
}