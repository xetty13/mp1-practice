#include <string>
#ifndef _BOOK_H
#define _BOOK_H

using namespace std;

class TBook
{
	private:
		int Couaut;
		string* Author;
		string Name;
		string Publishing;
		string Section;
		bool Availability;
		int Score;
	public:
		TBook();
		~TBook();
		TBook(const TBook& book);
		TBook& operator=(const TBook&);
		friend ostream& operator << (ostream& out, TBook& book);
		
		void SetBook( const int TCouaut, const  string* TAuthor, const string TName,
			const  string TPublishing, const string TSection, const bool TAvailability,
			const  int TScore);
		string GetSection();
		
};
struct TLib
{
	private:
		TBook* books;
		int count;
		int CountUnic;
		string* unic_section;

	public:
		TLib();
		TLib(const string& path);
		TLib(const TLib& lib);
		TLib& operator=(const TLib&);
		~TLib();
		int count_books(const string& path) const;
		int count_unic() const;
		void create_section();
		void print_unique_sections();
		TLib search_by_section(const string section_name);
		friend ostream& operator << (ostream& out, TLib& lib);
		void Set_unic(int unic);
		TBook GetBook(int i) const;
		int GetCountUnic() const;
		void SetUnicSection(string* Unic_Section);
		string GetUnicSection(int i) const;

		
};

string get_path();



#endif _BOOK_H

