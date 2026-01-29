#pragma once

using namespace System::Windows::Forms;

//Tutaj jest deklaracja klasy Nawigacja,która zarz¹dza nawigacj¹ miêdzy formularzami Logowania i Rejestracji w aplikacji RejestracjaBankowa.
namespace RejestracjaBankowa {
	namespace Logowanie { ref class Logowanie; };// Deklaracja wstêpna klasy Logowanie,aby unikn¹æ problemów z zale¿noœciami cyklicznymi.
	namespace Rejestracja1 { ref class Rejestracja1; }// Deklaracja wstêpna klasy Rejestracja1 wewn¹trz przestrzeni nazw Rejestracja1.Jest to konieczne,poniewa¿ klasa Rejestracja1 znajduje siê w oddzielnej przestrzeni nazw.

	public ref class Nawigacja abstract sealed {// Klasa statyczna Nawigacja do zarz¹dzania nawigacj¹ miêdzy formularzami.Nie mo¿e byæ instanciowana ani dziedziczona.
	public:
		static void otwórzLogowanie(System::Windows::Forms::Form^ form);//Metoda,która otwiera widok Logowania
		static void otwórzRejestracje(Form^ parentForm,int id_u¿ytkownika);//Metoda,która otwiera widok Rejestracji
	};
};
