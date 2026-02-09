#include "Nawigacja.h"
#include "Logowanie.h"
#include "Rejestracja1.h"

using namespace RejestracjaBankowa;
using namespace System::Windows::Forms;

//Nawigacja jest u¿ywana tylko do prze³¹czania miêdzy formularzami logowania i rejestracji w aplikacji RejestracjaBankowa,nie zawiera ¿adnej logiki biznesowej ani przetwarzania danych,poniwa¿ jej jedynym celem jest zarz¹dzanie nawigacj¹ miêdzy tymi dwoma formularzami.

void RejestracjaBankowa::Nawigacja::otwórzLogowanie(Form^ form, int id_u¿ytkownika) {
	Logowanie::Logowanie^ panel2 = gcnew Logowanie::Logowanie(1);
	panel2->ShowDialog();
	if (form != nullptr) { try { form->Close(); } catch (...) {} }
}

void Nawigacja::otwórzRejestracje(Form^ form2) {
	Rejestracja1::Rejestracja1^ panel1 = gcnew Rejestracja1::Rejestracja1();
	panel1->ShowDialog();
	if (form2 != nullptr) { try { form2->Close(); } catch (...) {} }
}

