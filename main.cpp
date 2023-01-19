#include <iostream>
#include <pqxx/pqxx> 
#include <string>

using namespace std;
using namespace pqxx;

string translator_ru_en (string originalWord) {
   try {
      connection C("dbname = cpp user = postgres \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) 
      {
         pqxx::work worker(C);
         string output = "";
         string query = "SELECT en FROM nouns WHERE id in (SELECT id FROM nouns WHERE ru = '" + originalWord + "') LIMIT 3;";
         result response = worker.exec(query);

         output += to_string(response[0][0]);
         for (int i = 1; i < response.size(); i++)
         {
            output += " / ";
            output += to_string(response[i][0]);
         }
         return output;
      }
      else {
         return "error #1 can't open database :(";
      }

      C.close();
   } 
   catch (exception &e) {
      cerr << e.what() << std::endl;
      return "error #2";
   }  
   return "error #3";
}

string translator_en_ru (string originalWord) {
   try {
      connection C("dbname = cpp user = postgres \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) 
      {
         work worker(C);
         string output = "";
         string query = "SELECT ru FROM nouns WHERE id in (SELECT id FROM nouns WHERE en = '" + originalWord + "') LIMIT 3;";
         result response = worker.exec(query);

         output += to_string(response[0][0]);
         for (int i = 1; i < response.size(); i++)
         {
            output += " / ";
            output += to_string(response[i][0]);
         }
         return output;
      }
      else {
         return "error #1 can't open database :(";
      }

      C.close();
   } 
   catch (exception &e) {
      cerr << e.what() << std::endl;
      return "error #2";
   }  
   return "error #3";
}

int main(int argc, char* argv[]) {

   string word;
   string switcher;

   cout << "Выберите направление перевода: Русский-английский [1]\nАнглийский-русский [2]" << endl;
   cin >> switcher;

   swith(switcher) {
      case 1:
         cout << "Введите слово на русском: ";
         cin >> word;
         cout << '\n' << translator_ru_en(word) << endl;
         break;
      case 2:
         cout << "Введите слово на английском: ";
         cin >> word;
         cout << '\n' << translator_en_ru(word) << endl;     
         break;
   }

   return 0;
}
