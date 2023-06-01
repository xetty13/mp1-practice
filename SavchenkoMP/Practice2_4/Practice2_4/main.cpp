#include <iostream>
#include <clocale>
#include "windows.h"
#include "container.h"
#include "products.h"
#include "database.h"
#include "receipt.h"
#include "display.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");

	try {
		TDataBase data;
		
		int data_update = 0;	// 0 - файлы базы данных обновляться/архивироваться не будут								
		int data_archive = 0;	// 1 - Вносятся изменения в файл базы данных / создается архив базы данных
		
		TContainer<TReceipt> check;
		string code;

		int ans = -1;
		int startmenu_ans = 1;
		int scanmode = 0;

		if (data_archive) {
			data.ArchiveData();
		}

		while (1) {
			TReceipt tmp_check;
			check.Add(tmp_check);
			int ind = check.Count() - 1;

			system("cls");
			dsp::StartMenu();
			cin >> startmenu_ans;

			// Если 0 - удаление пустого чека из контейнера и выход из цикла
			if (!startmenu_ans) { 
				check.Del(ind);
				break;
			}

			while (1) {
				system("cls");
				dsp:: MainMenu();
				dsp::ScanAns(ans);

				// Отсканировать товары
				if (ans == 1) { 
					while (1) {
						int scan_ans = 0;
						system("cls");
						
						if (check[ind].Count()) {
							cout << "Последний отсканированный товар: " << endl;
							check[ind].Show();
							cout << endl;
						}
						cout << "1. Начать сканирование." << endl;
						cout << "2. Режим: ";
						if (scanmode) {
							cout << "Вводить количество продукта" << endl;
						} 
						else {
							cout << "Не вводить количество продукта" << endl;
						}

						cout << "Чтобы закончить сканирование, введите 0.\n" << endl;
						
						dsp::MenuScanAns(scan_ans);
						if (scan_ans == 1) {
							while (1) {
								system("cls");
								if (check[ind].Count()) {
									cout << "Последний отсканированный товар: " << endl;
									check[ind].LastScan();
									cout << endl;
								}
								cout << "Введите код товара:" << endl;
								cin >> code;
								if (code == "0") break;
								else {
									TReceiptLine prod;
									int count = 1;
									if (scanmode && (data.Check(code) != -1)) {
										cout << "Введите количество продукта:" << endl;
										do {
											cin >> count;
										} while (count <= 0);
									}
									if (prod.Scan(data, code, count)) {
										int tottal_pcount = check[ind].FindCount(prod) + count;
										int data_pcount = data.GetProductCount(code);
										
										if (tottal_pcount > data_pcount) {
											cout << "Недостаточно товара на складе." << endl;
											dsp::Press2Continue();
										}
										else {
											check[ind].Add(prod, count);
										}
									}
								}
							}
						}
						else if (scan_ans == 2) {
							if (scanmode) scanmode = 0;
							else scanmode = 1;
						}
						else {
							break;
						}
					}
				}
				
				// Оплатить
				if (ans == 2) { 
					system("cls");

					if (!check[ind].Count()) {
						cout << "Ваша корзина пуста." << endl;
						dsp::Press2Continue();
					}
					else {
						check[ind].Cart();
						cout << "Сумма к оплате: " << check[ind].GetSum() << endl;
						cout << "\nОплата: ";

						double money;
						cin >> money;
						if (money < check[ind].GetSum()) {
							cout << "ОШИБКА. Недостаточно денег.";
							dsp::Press2Continue();
						}
						else {
							system("cls");
							check[ind].SetCLOCK();
							check[ind].SetCode(check.Count());

							check[ind].Payment(data, money);

							dsp::Press2Continue();
							break;
						}
					}
				}

				// Посмотреть корзину
				else if (ans == 3) { 
					system("cls");
					if (!check[ind].Count()) {
						cout << "Ваша корзина пуста." << endl;
						dsp::Press2Continue();
					}
					else {
						check[ind].Cart();
						cout << "Сумма: " << check[ind].GetSum() << endl;
						dsp::Press2Continue();
					}
				}

				// Удалить товар из корзины
				else if (ans == 4) { 
					if (!check[ind].Count()) {
						system("cls");
						cout << "Ваша корзина пуста." << endl;
						dsp::Press2Continue();
					}
					else {
						int del_ans = 0;
						while (1) {
							system("cls");
							check[ind].Cart();
							cout << "Сумма: " << check[ind].GetSum() << endl;
							cout << "\nВведите номер товара, который хотите удалить." << endl;
							cout << "Для выхода введите 0.\n" << endl;

							cin >> del_ans;
							if (del_ans)
								check[ind].Del(del_ans - 1);
							else
								break;
						}
					}
				}
				else if (ans == 0) {
					check.Del(ind);
					break;
				}
			}
		}

		if (data_update) {
			data.UpdateData();
		}
	}
	catch (const std::exception &exp) {
		cout << exp.what() << endl;
	}

	cout << "END!" << endl;
	return 0;
}