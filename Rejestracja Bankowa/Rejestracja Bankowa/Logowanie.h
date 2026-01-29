#pragma once
#include "Rejestracja.h"
#include "Nawigacja.h"
#include "Rejestracja1.h"

namespace RejestracjaBankowa {
	namespace Logowanie {

		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::Odbc;
		using namespace System::Data::SqlClient;

		/// <summary>
		/// Podsumowanie informacji o Logowanie
		/// </summary>
		public ref class Logowanie : public System::Windows::Forms::Form
		{
		private:
			int id;
		public:
			Logowanie(int emittedId2)
			{
				InitializeComponent();
				id = emittedId2;
				//
				//TODO: W tym miejscu dodaj kod konstruktora
				//
			}

		protected:
			/// <summary>
			/// Wyczyœæ wszystkie u¿ywane zasoby.
			/// </summary>
			~Logowanie()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::GroupBox^ groupBox1;
		protected:
		private: System::Windows::Forms::GroupBox^ groupBox2;
		private: System::Windows::Forms::DataGridView^ DataAuth;
		private: System::Windows::Forms::PictureBox^ process;




		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ Passwordtxt;
		private: System::Windows::Forms::TextBox^ Usertxt;
		private: System::Windows::Forms::Button^ LogInBtn;
		private: System::Windows::Forms::Button^ regRedirect;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::ImageList^ ImList1;
		private: System::Windows::Forms::ImageList^ ImList2;


		private: System::Windows::Forms::CheckedListBox^ DataRecognising;
		private: System::Windows::Forms::MaskedTextBox^ IDtxt;
		private: System::Windows::Forms::MaskedTextBox^ Personaltxt;
		private: System::Windows::Forms::PictureBox^ access;



		private: System::ComponentModel::IContainer^ components;

		private:
			/// <summary>
			/// Wymagana zmienna projektanta.
			/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Logowanie::typeid));
				this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				this->Personaltxt = (gcnew System::Windows::Forms::MaskedTextBox());
				this->IDtxt = (gcnew System::Windows::Forms::MaskedTextBox());
				this->regRedirect = (gcnew System::Windows::Forms::Button());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->LogInBtn = (gcnew System::Windows::Forms::Button());
				this->Passwordtxt = (gcnew System::Windows::Forms::TextBox());
				this->Usertxt = (gcnew System::Windows::Forms::TextBox());
				this->access = (gcnew System::Windows::Forms::PictureBox());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				this->DataRecognising = (gcnew System::Windows::Forms::CheckedListBox());
				this->process = (gcnew System::Windows::Forms::PictureBox());
				this->DataAuth = (gcnew System::Windows::Forms::DataGridView());
				this->ImList1 = (gcnew System::Windows::Forms::ImageList(this->components));
				this->ImList2 = (gcnew System::Windows::Forms::ImageList(this->components));
				this->groupBox1->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->access))->BeginInit();
				this->groupBox2->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->process))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataAuth))->BeginInit();
				this->SuspendLayout();
				// 
				// groupBox1
				// 
				this->groupBox1->Controls->Add(this->Personaltxt);
				this->groupBox1->Controls->Add(this->IDtxt);
				this->groupBox1->Controls->Add(this->regRedirect);
				this->groupBox1->Controls->Add(this->label5);
				this->groupBox1->Controls->Add(this->LogInBtn);
				this->groupBox1->Controls->Add(this->Passwordtxt);
				this->groupBox1->Controls->Add(this->Usertxt);
				this->groupBox1->Controls->Add(this->access);
				this->groupBox1->Controls->Add(this->label4);
				this->groupBox1->Controls->Add(this->label3);
				this->groupBox1->Controls->Add(this->label2);
				this->groupBox1->Controls->Add(this->label1);
				this->groupBox1->Font = (gcnew System::Drawing::Font(L"Noto Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				this->groupBox1->Location = System::Drawing::Point(0, 0);
				this->groupBox1->Name = L"groupBox1";
				this->groupBox1->Size = System::Drawing::Size(298, 376);
				this->groupBox1->TabIndex = 0;
				this->groupBox1->TabStop = false;
				this->groupBox1->Text = L"Logowanie u¿ytkownika";
				// 
				// Personaltxt
				// 
				this->Personaltxt->Location = System::Drawing::Point(202, 132);
				this->Personaltxt->Mask = L"00-000-000-000";
				this->Personaltxt->Name = L"Personaltxt";
				this->Personaltxt->Size = System::Drawing::Size(90, 25);
				this->Personaltxt->TabIndex = 15;
				// 
				// IDtxt
				// 
				this->IDtxt->Location = System::Drawing::Point(214, 101);
				this->IDtxt->Mask = L"000-000-000";
				this->IDtxt->Name = L"IDtxt";
				this->IDtxt->Size = System::Drawing::Size(78, 25);
				this->IDtxt->TabIndex = 14;
				// 
				// regRedirect
				// 
				this->regRedirect->Location = System::Drawing::Point(167, 331);
				this->regRedirect->Name = L"regRedirect";
				this->regRedirect->Size = System::Drawing::Size(120, 29);
				this->regRedirect->TabIndex = 13;
				this->regRedirect->Text = L"Zarejestruj siê";
				this->regRedirect->UseVisualStyleBackColor = true;
				this->regRedirect->Click += gcnew System::EventHandler(this, &Logowanie::regRedirect_Click);
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"Noto Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
				this->label5->Location = System::Drawing::Point(91, 309);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(196, 19);
				this->label5->TabIndex = 12;
				this->label5->Text = L"Je¿eli nie posiadasz konta !!";
				// 
				// LogInBtn
				// 
				this->LogInBtn->Location = System::Drawing::Point(187, 163);
				this->LogInBtn->Name = L"LogInBtn";
				this->LogInBtn->Size = System::Drawing::Size(105, 28);
				this->LogInBtn->TabIndex = 11;
				this->LogInBtn->Text = L"Zaloguj siê";
				this->LogInBtn->UseVisualStyleBackColor = true;
				this->LogInBtn->Click += gcnew System::EventHandler(this, &Logowanie::LogInBtn_Click);
				// 
				// Passwordtxt
				// 
				this->Passwordtxt->Location = System::Drawing::Point(145, 69);
				this->Passwordtxt->Name = L"Passwordtxt";
				this->Passwordtxt->Size = System::Drawing::Size(147, 25);
				this->Passwordtxt->TabIndex = 8;
				// 
				// Usertxt
				// 
				this->Usertxt->Location = System::Drawing::Point(145, 35);
				this->Usertxt->Name = L"Usertxt";
				this->Usertxt->Size = System::Drawing::Size(147, 25);
				this->Usertxt->TabIndex = 7;
				// 
				// access
				// 
				this->access->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"access.ErrorImage")));
				this->access->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"access.InitialImage")));
				this->access->Location = System::Drawing::Point(31, 188);
				this->access->Name = L"access";
				this->access->Size = System::Drawing::Size(138, 108);
				this->access->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				this->access->TabIndex = 6;
				this->access->TabStop = false;
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(144, 135);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(52, 19);
				this->label4->TabIndex = 5;
				this->label4->Text = L"PESEL:";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(45, 104);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(151, 19);
				this->label3->TabIndex = 4;
				this->label3->Text = L"Numer identyfikacyjny:";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(91, 72);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(48, 19);
				this->label2->TabIndex = 3;
				this->label2->Text = L"Has³o:";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(0, 38);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(139, 19);
				this->label1->TabIndex = 2;
				this->label1->Text = L"Nazwa u¿ytkownika:";
				// 
				// groupBox2
				// 
				this->groupBox2->Controls->Add(this->DataRecognising);
				this->groupBox2->Controls->Add(this->process);
				this->groupBox2->Controls->Add(this->DataAuth);
				this->groupBox2->Font = (gcnew System::Drawing::Font(L"Noto Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				this->groupBox2->Location = System::Drawing::Point(304, 0);
				this->groupBox2->Name = L"groupBox2";
				this->groupBox2->Size = System::Drawing::Size(349, 376);
				this->groupBox2->TabIndex = 1;
				this->groupBox2->TabStop = false;
				this->groupBox2->Text = L"Uwierzytelnienie";
				// 
				// DataRecognising
				// 
				this->DataRecognising->FormattingEnabled = true;
				this->DataRecognising->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
					L"1.Obecnoœæ danych ", L"2.Zgodnoœæ danych",
						L"3.Poprawnoœæ danych", L"4.Rozpoznanie danych"
				});
				this->DataRecognising->Location = System::Drawing::Point(15, 192);
				this->DataRecognising->Name = L"DataRecognising";
				this->DataRecognising->Size = System::Drawing::Size(182, 104);
				this->DataRecognising->TabIndex = 2;
				// 
				// process
				// 
				this->process->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"process.ErrorImage")));
				this->process->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"process.InitialImage")));
				this->process->Location = System::Drawing::Point(203, 190);
				this->process->Name = L"process";
				this->process->Size = System::Drawing::Size(140, 106);
				this->process->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				this->process->TabIndex = 1;
				this->process->TabStop = false;
				// 
				// DataAuth
				// 
				this->DataAuth->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->DataAuth->Location = System::Drawing::Point(3, 21);
				this->DataAuth->Name = L"DataAuth";
				this->DataAuth->RowHeadersWidth = 51;
				this->DataAuth->RowTemplate->Height = 24;
				this->DataAuth->Size = System::Drawing::Size(340, 163);
				this->DataAuth->TabIndex = 0;
				// 
				// ImList1
				// 
				this->ImList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"ImList1.ImageStream")));
				this->ImList1->TransparentColor = System::Drawing::Color::Transparent;
				this->ImList1->Images->SetKeyName(0, L"accessgranted.png");
				this->ImList1->Images->SetKeyName(1, L"accessout.png");
				// 
				// ImList2
				// 
				this->ImList2->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"ImList2.ImageStream")));
				this->ImList2->TransparentColor = System::Drawing::Color::Transparent;
				this->ImList2->Images->SetKeyName(0, L"Processing.gif");
				this->ImList2->Images->SetKeyName(1, L"processfull.gif");
				// 
				// Logowanie
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(665, 388);
				this->Controls->Add(this->groupBox2);
				this->Controls->Add(this->groupBox1);
				this->Name = L"Logowanie";
				this->Text = L"Logowanie";
				this->Load += gcnew System::EventHandler(this, &Logowanie::Logowanie_Load);
				this->groupBox1->ResumeLayout(false);
				this->groupBox1->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->access))->EndInit();
				this->groupBox2->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->process))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataAuth))->EndInit();
				this->ResumeLayout(false);

			}
#pragma endregion
		private: System::Void Logowanie_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		public:void CzyszczeniePól() {
			Usertxt->Clear();
			Passwordtxt->Clear();
			IDtxt->Clear();
			Personaltxt->Clear();
		};

		private:System::Void oknoG³ówneApliakcji(System::Object^ sender, System::EventArgs^ e) {
			Logowanie::FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		}

		private:System::Void przypnijOkno(System::Object^ sender, System::EventArgs^ e) {
			Logowanie::FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			TopMost = true;
		}

		private: System::Void LogInBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ u¿ytkownik = Usertxt->Text->Trim();

			String^ has³o = Passwordtxt->Text->Trim();
			String^ has³o1 = Regex::Replace(has³o, "[^0-9]", "");

			String^ ID = IDtxt->Text->Trim();
			String^ ID1 = Regex::Replace(ID, "[^0-9]", "");

			String^ PESEL = Personaltxt->Text->Trim();
			String^ PESEL1 = Regex::Replace(PESEL, "[^0-9]", "");

			array< String^ >^ pola = { u¿ytkownik, has³o1, ID1, PESEL1 };
			for (int existingChar = 0; existingChar < pola->Length; ++existingChar) {
				if (!System::Text::RegularExpressions::Regex::IsMatch(pola[existingChar], "^\\p{L}\\d+$")) {
					MessageBox::Show("Dane zawieraj¹ niedozwolone znaki.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
					DataAuth->Enabled = false;
					return;
				}
			};
			if (u¿ytkownik->Length < 3 || has³o1->Length < 12 || ID1->Length < 9 || PESEL1->Length < 11) {
				MessageBox::Show("Dane s¹ niepe³ne lub nie zosta³y wpisane", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
				access->Image = ImList1->Images["accessout.png"];
				return;
			}
			else {
				LogInBtn->Enabled = true;
			}
			OdbcConnection^ connection = gcnew OdbcConnection(konfiguracja);
			try {
				process->Visible = true;
				process->Image = ImList2->Images["Processing.gif"];
				OdbcCommand^ command = connection->CreateCommand();
				OdbcTransaction^ transakcja;
				connection->Open();
				transakcja = connection->BeginTransaction(IsolationLevel::ReadCommitted);
				command->Connection = connection;
				command->Transaction = transakcja;

				for (int d = 0; d < 4; d++) {
					command->CommandText = "Select `Rejes._Login_u¿yt.`,`Rejes._Has³o`,Nr_id_klienta,`Rejes._PESEL` from `D._klienta` where `Rejes._Login_u¿yt.` = ? and `Rejes._Has³o` = ? and Nr_id_klienta = ? and `Rejes._PESEL` = ?";
					command->Parameters->Clear();
					command->Parameters->AddWithValue("p1", u¿ytkownik);
					command->Parameters->AddWithValue("p2", has³o1);
					command->Parameters->AddWithValue("p3", ID1);
					command->Parameters->AddWithValue("p4", PESEL1);

					OdbcDataAdapter^ dane = gcnew OdbcDataAdapter(command);
					DataTable^ tabela = gcnew DataTable();
					dane->Fill(tabela);

					int input1 = tabela->Rows->Count;

					// Wype³nij widok danych i wykonaj walidacje na istniej¹cych wierszach
					if (input1 > 0) {
						DataAuth->DataSource = tabela;
						DataAuth->Visible = true;

						// Pobierz id u¿ytkownika z pierwszego wiersza (kolumna 2 zgodnie z SELECT)
						int id_u¿ytkownika = 0;
						try {
							Object^ idObj = (safe_cast<DataRow^>(tabela->Rows[0]))[2];//Rzzutowanie na DataRow i pobranie wartoœci kolumny 2
							if (idObj != nullptr) id_u¿ytkownika = Convert::ToInt32(idObj);
						}
						catch (...) {}// Obs³uga b³êdów konwersji lub rzutowania

						// Przetwarzanie wierszy w DataAuth,tak aby ustawiæ odpowiednie pola w DataRecognising
						for (int g = 0; g < DataAuth->Rows->Count; g++) {
							if (DataAuth->Rows[g]->IsNewRow) continue;// Pomijaj wiersz nowy,poniewa¿ nie zawiera danych
							Object^ loginObj = DataAuth->Rows[g]->Cells[0]->Value;
							Object^ passwordObj = DataAuth->Rows[g]->Cells[1]->Value;
							Object^ idObj = DataAuth->Rows[g]->Cells[2]->Value;
							Object^ personalObj = DataAuth->Rows[g]->Cells[3]->Value;

							bool dataExistence = loginObj != nullptr && passwordObj != nullptr && idObj != nullptr && personalObj != nullptr;
							if (dataExistence) {
								DataRecognising->SetSelected(0, true);
							}

							bool dataRelevance =
								loginObj != nullptr && loginObj->ToString() == Usertxt->Text &&
								passwordObj != nullptr && passwordObj->ToString() == Passwordtxt->Text &&
								idObj != nullptr && idObj->ToString() == IDtxt->Text &&
								personalObj != nullptr && personalObj->ToString() == Personaltxt->Text;
							if (dataRelevance) {
								DataRecognising->SetSelected(1, true);
							}

							bool dataCorrectness =
								loginObj != nullptr && loginObj->ToString() != "" &&
								passwordObj != nullptr && passwordObj->ToString() != "" &&
								idObj != nullptr && idObj->ToString() != "" &&
								personalObj != nullptr && personalObj->ToString() != "";
							if (dataCorrectness) {
								DataRecognising->SetSelected(2, true);
							}
							if (idObj != nullptr && idObj->ToString() != "") {
								DataRecognising->SetSelected(3, true);
							}
						}
					}
					else {
						// brak wyników — input1 = 0, pozostaw DataAuth niewidoczne
						DataAuth->Visible = false;
					}

					if (input1 > 0 && DataAuth->Visible == true) {
						command->CommandText = "INSERT INTO Uwierzytelnienie " +
							"(`D._klienta_Nr_id_klienta`, " +
							"`D._klienta_Rejes_Login_u¿yt.`, " +
							"`D._klienta_PESEL`, " +
							"`D._klienta_Rejes.Has³o`)" +
							"SELECT `Nr_id_klienta`, `Login_u¿yt.`, `PESEL`, `Has³o` " +
							"FROM `D_klienta` " +
							"WHERE PESEL IS NOT NULL;";

						int input2 = command->ExecuteNonQuery();

						if (input2 > 0) {
							transakcja->Commit();
							MessageBox::Show("Dane zosta³y dodane do bazy!");
						}
						else {
							transakcja->Rollback();
							MessageBox::Show("Nie uda³o siê dodaæ danych do bazy !");
						}
					}
					else {
						transakcja->Rollback();
						MessageBox::Show("Nie uda³o siê dodaæ danych do bazy !");
					}
				}

				process->Visible = true;
				process->Image = ImList2->Images["processfull.gif"];

				OdbcCommand^ command2 = gcnew OdbcCommand("Select Nr_id_klienta from `D._klienta`", connection);
				OdbcDataReader^ reader = nullptr;//inicjalizacja czytnika danych jako nullptr,aby unikn¹æ b³êdów w bloku finally

				try {
					String^ keyOfPicture = "accessgranted.png";
					int idIndex = ImList1->Images->IndexOfKey(keyOfPicture);

					if (idIndex >= 0) {
						reader = command2->ExecuteReader();
						if (reader->Read()) {
							int id_u¿ytkownika = reader->GetInt32(0);
							reader->Close();
							this->Hide();
							RejestracjaBankowa::Nawigacja::otwórzLogowanie(this);
						}
					}
				}
				catch (Exception^ ex) {
					if (reader != nullptr) { try { reader->Close(); } catch (...) {} }// Zamkniêcie readera w przypadku b³êdu
					MessageBox::Show("B³¹d podczas odczytu danych: " + ex->Message);
					throw; // przekazujemy dalej do zewnêtrznego catcha
				}
				finally {
					if (reader != nullptr) { try { reader->Close(); } catch (...) {} }//catch (...) oznacza z³apanie wszystkich wyj¹tków i ich zignorowanie,aby unikn¹æ przerwania dzia³ania programu
				}
			}
			catch (Exception^ komunikat) {
				MessageBox::Show("B³¹d podczas po³¹czenia z baz¹" + komunikat->Message);
			}
			if (process) {
				access->Visible = true;
				access->Image = ImList1->Images["accessfull.gif"];
			}
			CzyszczeniePól();
			connection->Close();
		};

		public:
			String^ konfiguracja = L"Driver={MySQL ODBC 9.4 Unicode Driver};Server=localhost;Database=rejestracja_bankowa;port=3306;user=root;Password=09041976Polska04@;CharSet=utf8mb4;Option=3";

		private: System::Void regRedirect_Click(System::Object^ sender, System::EventArgs^ e);
		};
	}
}
