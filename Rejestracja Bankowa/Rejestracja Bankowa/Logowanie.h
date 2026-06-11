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
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->TopMost = true;

				id = emittedId2;

				processTimer = gcnew System::Windows::Forms::Timer();
				processTimer->Interval = 4000; // Ustaw interwa³ na 4 sekundy
				processTimer->Tick += gcnew System::EventHandler(this, &Logowanie::OnProcessTimerTick);
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
				this->Personaltxt->Location = System::Drawing::Point(169, 132);
				this->Personaltxt->Mask = L"00-000-000-000";
				this->Personaltxt->Name = L"Personaltxt";
				this->Personaltxt->Size = System::Drawing::Size(123, 25);
				this->Personaltxt->TabIndex = 15;
				// 
				// IDtxt
				// 
				this->IDtxt->Location = System::Drawing::Point(181, 101);
				this->IDtxt->Mask = L"000-000-000";
				this->IDtxt->Name = L"IDtxt";
				this->IDtxt->Size = System::Drawing::Size(111, 25);
				this->IDtxt->TabIndex = 14;
				// 
				// regRedirect
				// 
				this->regRedirect->Location = System::Drawing::Point(158, 331);
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
				this->label5->Location = System::Drawing::Point(82, 309);
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
				this->Passwordtxt->Location = System::Drawing::Point(158, 69);
				this->Passwordtxt->Name = L"Passwordtxt";
				this->Passwordtxt->Size = System::Drawing::Size(134, 25);
				this->Passwordtxt->TabIndex = 8;
				// 
				// Usertxt
				// 
				this->Usertxt->Location = System::Drawing::Point(158, 35);
				this->Usertxt->Name = L"Usertxt";
				this->Usertxt->Size = System::Drawing::Size(134, 25);
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
				this->label4->Location = System::Drawing::Point(111, 135);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(52, 19);
				this->label4->TabIndex = 5;
				this->label4->Text = L"PESEL:";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(18, 104);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(151, 19);
				this->label3->TabIndex = 4;
				this->label3->Text = L"Numer identyfikacyjny:";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(97, 72);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(48, 19);
				this->label2->TabIndex = 3;
				this->label2->Text = L"Has³o:";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(6, 38);
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
		public:
			System::Drawing::Image^ LoadImageFromObrazy(System::String^ fileName) {
				System::String^ path = System::IO::Path::Combine(Application::StartupPath, "Obrazy", fileName);// Utwórz pe³n¹ œcie¿kê do pliku obrazu
				//[System::IO::Path::Combine]³¹czy fragmenty œcie¿ki w jedn¹ poprawnie sformatowan¹ œcie¿kê plikow¹ (dodaje separator katalogu tam, gdzie potrzeba). Nie odwo³uje siê do dysku — tylko tworzy ³añcuch znaków.
				if (!System::IO::File::Exists(path)) return nullptr;// SprawdŸ, czy plik istnieje
				return System::Drawing::Image::FromFile(path);
			}

		private: System::Void Logowanie_Load(System::Object^ sender, System::EventArgs^ e) {
			this->process->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;

			this->access->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;

			this->access->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		}

		private:System::Drawing::Image^ processingGif;
		private:System::Drawing::Image^ processFullGif;
		private:System::Windows::Forms::Timer^ processTimer;
		private:System::Drawing::Image^ accessDeniedImg;
		private:System::Drawing::Image^ accessGrantedImg;

		private: System::Void OnProcessTimerTick(System::Object^ sender, System::EventArgs^ e) {
			try {
				System::Drawing::ImageAnimator::UpdateFrames(this->processingGif);// Aktualizuj klatki animacji GIF
				System::Drawing::ImageAnimator::UpdateFrames(this->processFullGif);// Aktualizuj klatki animacji GIF
				this->process->Invalidate(); // Wymuœ ponowne narysowanie PictureBox
			}
			catch (Exception^ ex) {
				MessageBox::Show("B³¹d animacji GIF: " + ex->Message);
			}
		}

		public:void CzyszczeniePól() {
			Usertxt->Clear();
			Passwordtxt->Clear();
			IDtxt->Clear();
			Personaltxt->Clear();
		};
			  bool accessGrantedFlag = true;

		private: System::Void LogInBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ u¿ytkownik = Usertxt->Text->Trim();

			String^ has³o = Passwordtxt->Text->Trim();
			String^ has³o1 = Regex::Replace(has³o, "[^0-9]", "");

			String^ ID = IDtxt->Text->Trim();
			Object^ ID1 = Regex::Replace(ID, "[^0-9]", "");

			String^ PESEL = Personaltxt->Text->Trim();
			String^ PESEL1 = Regex::Replace(PESEL, "[^0-9]", "");

			array< String^ >^ pola = { u¿ytkownik, has³o1, safe_cast<String^>(ID1), PESEL1 };
			for (int existingChar = 0; existingChar < pola->Length; ++existingChar) {
				String^ value = pola[existingChar]->Trim();
				if (value->Length == 0) continue;// Pomijaj puste pola
				if (!System::Text::RegularExpressions::Regex::IsMatch(value, "^[\\p{L}0-9\\-]+$")) {
					MessageBox::Show("Dane zawieraj¹ niedozwolone znaki.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
					DataAuth->Enabled = false;
					return;
				}
			};
			if (u¿ytkownik->Length < 3 || has³o1->Length < 12 || safe_cast<String^>(ID1)->Length < 9 || PESEL1->Length < 11) {
				MessageBox::Show("Dane s¹ niepe³ne lub nie zosta³y wpisane", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->access->Image = this->accessDeniedImg;
				if (this->access->Image != nullptr) { delete this->access->Image; }// Usuniêcie poprzedniego obrazu,jeœli istnieje
				this->access->Image = this->accessDeniedImg != nullptr
					? this->accessDeniedImg : LoadImageFromObrazy("accessout.png");
				this->access->Visible = true;
				this->access->Refresh();
				System::Threading::Thread::Sleep(4000);
				Application::DoEvents();
				return;
			}
			else {
				LogInBtn->Enabled = true;
			}
			OdbcConnection^ connection = gcnew OdbcConnection(konfiguracja);
			try {
				OdbcCommand^ command = connection->CreateCommand();
				OdbcTransaction^ transakcja;
				connection->Open();
				transakcja = connection->BeginTransaction(IsolationLevel::ReadCommitted);
				command->Connection = connection;
				command->Transaction = transakcja;

				command->CommandText = "SELECT dk.`Rejes_Login_u¿yt` , dk.`Rejes_Has³o` , dk.`Nr_id_klienta` , dk.`Rejes_PESEL` "
					"FROM `D_klienta` AS dk "
					"JOIN `Rejes` AS r ON "
					"r.`Login_u¿yt` = dk.`Rejes_Login_u¿yt` "
					"AND r.`Has³o`  = dk.`Rejes_Has³o` "
					"AND r.`PESEL`  = dk.`Rejes_PESEL` "
					"WHERE r.`Login_u¿yt` = ? AND r.`Has³o` = ? AND dk.`Nr_id_klienta` = ? AND r.`PESEL` = ?";

				command->Parameters->Clear();
				command->Parameters->AddWithValue("p1", u¿ytkownik);
				command->Parameters->AddWithValue("p2", has³o1);
				OdbcParameter^ IdParameter = gcnew OdbcParameter("p3", OdbcType::BigInt);
				IdParameter->Value = static_cast<long long>(Convert::ToInt64(ID1));
				command->Parameters->Add(IdParameter);
				command->Parameters->AddWithValue("p4", PESEL1);

				OdbcDataAdapter^ dane = gcnew OdbcDataAdapter(command);
				DataTable^ tabela = gcnew DataTable();
				dane->Fill(tabela);

				int input1 = tabela->Rows->Count;// Sprawdzenie liczby wierszy zwróconych przez zapytanie,co pozwala oceniæ, czy dane uwierzytelniaj¹ce s¹ poprawne i istniej¹ w bazie danych

				if (input1 > 0) {
					DataAuth->DataSource = tabela;
					DataAuth->Visible = true;

					// Pobierz id u¿ytkownika z pierwszego wiersza (kolumna 2 zgodnie z SELECT)
					long long id_u¿ytkownika = 0;
					try {
						Object^ idObj = (static_cast<DataRow^>(tabela->Rows[0]))[2];// Pobierz wartoœæ z kolumny 2 (Nr_id_klienta),rzutowanie statyczne sprawia,¿e zak³adamy, ¿e tabela ma odpowiedni¹ strukturê i kolumna 2 zawiera dane typu,który mo¿na przekonwertowaæ na long long. Jeœli struktura tabeli jest inna lub dane s¹ nieprawid³owe,mo¿e to spowodowaæ wyj¹tek.
						if (idObj != nullptr) id_u¿ytkownika = static_cast<long long>(Convert::ToInt64(idObj));
					}
					catch (...) {}// Obs³uga b³êdów konwersji lub rzutowania,czyli brak danych lub nieprawid³owy format danych

					if (DataRecognising != nullptr) {
						for (int previous = 0; previous < DataRecognising->Items->Count; previous++) {
							DataRecognising->SetItemChecked(previous, false);// Resetowanie wszystkich zaznaczeñ
						}
					}
					process->Visible = true;
					this->process->Refresh();
					this->process->Image = this->processingGif;
					this->process->Image = this->processingGif != nullptr
						? this->processingGif : LoadImageFromObrazy("Processing.gif");
					this->process->Visible = true;
					this->process->Refresh();
					System::Threading::Thread::Sleep(4000);
					Application::DoEvents();

					// Przetwarzanie wierszy w DataAuth,tak aby ustawiæ odpowiednie pola w DataRecognising
					for (int g = 0; g < DataAuth->Rows->Count; g++) {
						if (DataAuth->Rows[g]->IsNewRow) continue;// Pomijaj wiersz nowy,poniewa¿ nie zawiera danych
						Object^ loginObj = DataAuth->Rows[g]->Cells[0]->Value;
						Object^ passwordObj = DataAuth->Rows[g]->Cells[1]->Value;
						Object^ idObj = DataAuth->Rows[g]->Cells[2]->Value;
						Object^ personalObj = DataAuth->Rows[g]->Cells[3]->Value;

						bool dataExistence = loginObj != nullptr && passwordObj != nullptr && idObj != nullptr && personalObj != nullptr;
						if (dataExistence) {
							DataRecognising->SetItemChecked(0, true);
						}
						else {
							MessageBox::Show("Niektóre dane s¹ puste lub null,co mo¿e œwiadczyæ o ich nieistnieniu w bazie danych.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
							throw;
						}

						bool dataRelevance =
							loginObj != nullptr && loginObj->ToString() == u¿ytkownik &&
							passwordObj != nullptr && passwordObj->ToString() == has³o1 &&
							idObj != nullptr && Convert::ToInt64(idObj) == Convert::ToInt64(ID1) &&
							personalObj != nullptr && personalObj->ToString() == PESEL1;
						if (dataRelevance) {
							DataRecognising->SetItemChecked(1, true);
						}
						else {
							MessageBox::Show("Niektóre dane nie s¹ zgodne z wprowadzonymi danymi,co mo¿e œwiadczyæ o ich niezgodnoœci z danymi w bazie danych.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
							throw;
						}

						bool dataCorrectness =
							loginObj != nullptr && loginObj->ToString() != "" &&
							passwordObj != nullptr && passwordObj->ToString() != "" &&
							idObj != nullptr && idObj->ToString() != "" &&
							personalObj != nullptr && personalObj->ToString() != "";// Sprawdzenie, czy dane s¹ niepuste i nie null,co mo¿e œwiadczyæ o ich poprawnoœci
						if (dataCorrectness) {
							DataRecognising->SetItemChecked(2, true);
						}
						else {
							MessageBox::Show("Niektóre dane s¹ puste lub null,co mo¿e œwiadczyæ o ich niepoprawnoœci w bazie danych.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
							throw;
						}
						if (idObj != nullptr && idObj->ToString() != "") {
							DataRecognising->SetItemChecked(3, true);
						}
						else {
							MessageBox::Show("Id u¿ytkownika jest puste lub null,co mo¿e œwiadczyæ o braku rozpoznania danych w bazie danych.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
							throw;
						}
					}
				}
				else {
					// brak wyników — input1 = 0, pozostaw DataAuth niewidoczne
					DataAuth->Visible = false;
				}
				if (input1 > 0 && DataAuth->Visible == true) {
					command->Parameters->Clear();
					command->CommandText = "INSERT INTO `Uwierzytelnienie` (`D_klienta_Nr_id_klienta` , `D_klienta_Rejes_Imiê` , `D_klienta_Rejes_Nazwisko` , `D_klienta_Rejes_PESEL` , `D_klienta_Rejes_Has³o` , `D_klienta_Rejes_Login_u¿yt`) "
						"SELECT d.`Nr_id_klienta` , r.`Imiê` , r.`Nazwisko` , r.`PESEL` , r.`Has³o` , r.`Login_u¿yt` "
						"FROM `D_klienta` AS d "
						"JOIN `Rejes` AS r ON "
						"r.`Login_u¿yt` = d.`Rejes_Login_u¿yt` "
						"AND r.`Has³o` = d.`Rejes_Has³o` "
						"AND r.`PESEL` = d.`Rejes_PESEL` "
						"WHERE r.`PESEL` IS NOT NULL;";

					int input2 = command->ExecuteNonQuery();

					if (input2 > 0) {
						transakcja->Commit();
						MessageBox::Show("Dane zosta³y zweryfikowane w bazie danych!");
					}
					else {
						transakcja->Rollback();
						MessageBox::Show("Nie uda³o siê zweryfikowaæ danych w bazie !");
						this->access->Image = this->accessDeniedImg;
						if (this->access->Image != nullptr) { delete this->access->Image; }// Usuniêcie poprzedniego obrazu,jeœli istnieje
						this->access->Image = this->accessDeniedImg != nullptr
							? this->accessDeniedImg : LoadImageFromObrazy("accessout.png");
						this->access->Visible = true;
						this->access->Refresh();
						System::Threading::Thread::Sleep(4000);
						Application::DoEvents();
						return;
					}
				}
				else {
					transakcja->Rollback();
					MessageBox::Show("Nie uda³o siê zweryfikowaæ danych w bazie !");
					this->access->Image = this->accessDeniedImg;
					if (this->access->Image != nullptr) { delete this->access->Image; }// Usuniêcie poprzedniego obrazu,jeœli istnieje
					this->access->Image = this->accessDeniedImg != nullptr
						? this->accessDeniedImg : LoadImageFromObrazy("accessout.png");
					this->access->Visible = true;
					this->access->Refresh();
					System::Threading::Thread::Sleep(4000);
					Application::DoEvents();
					return;
				}

				process->Visible = true;
				this->process->Refresh();
				System::Drawing::Image^ processFull = this->processFullGif != nullptr
					? this->processFullGif
					: LoadImageFromObrazy("processfull.gif");

				if (processFull != nullptr) {
					this->process->Image = processFull; // ustaw obraz
					System::Drawing::ImageAnimator::Animate(processFull, gcnew System::EventHandler(this, &Logowanie::OnProcessTimerTick));//tutaj ponownie animujemy,aby mieæ pewnoœæ,¿e animacja zacznie siê od pocz¹tku po zmianie obrazu
					this->process->Visible = true;
					this->process->Refresh();
					System::Threading::Thread::Sleep(4000);
					Application::DoEvents();
				}

				OdbcCommand^ command2 = gcnew OdbcCommand("Select Nr_id_klienta from `D_klienta`", connection);
				OdbcDataReader^ reader = nullptr;//inicjalizacja czytnika danych jako nullptr,aby unikn¹æ b³êdów w bloku finally

				try {
					this->accessGrantedFlag = true;
					this->access->Image = this->accessGrantedImg;
					this->access->Image = this->accessGrantedImg != nullptr//tutaj ustawiamy obraz dostêpu przyznanego,jeœli jest dostêpny,jeœli nie to ³adujemy domyœlny obraz z katalogu Obrazy
						? this->accessGrantedImg : LoadImageFromObrazy("accessgranted.png");

					if (this->accessGrantedFlag) {
						reader = command2->ExecuteReader();
						if (reader->Read()) {
							this->access->Visible = true;
							this->access->Refresh();// Odœwie¿enie PictureBox,aby natychmiast pokazaæ obraz dostêpu przyznanego
							System::Threading::Thread::Sleep(4000);// OpóŸnienie 4 sekundy,aby u¿ytkownik móg³ zobaczyæ obraz dostêpu przyznanego
							Application::DoEvents(); // Przetwarzanie wszystkich oczekuj¹cych komunikatów,aby UI móg³ siê odœwie¿yæ przed przejœciem do nastêpnego formularza
							long long colUser = static_cast<long long>(reader->GetOrdinal("Nr_id_klienta"));
							long long id_u¿ytkownika = reader->IsDBNull(colUser) ? -1 : static_cast<long long>(reader->GetInt64(colUser));
							reader->Close();
							this->Hide();
							Nawigacja::otwórzG³ównyFormularz(this, id_u¿ytkownika);
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
				throw;
			}
			if (process) {
				access->Visible = true;
				this->access->Refresh();
				this->access->Image = this->accessGrantedImg;
				if (this->access->Image != nullptr) { delete this->access->Image; }// Usuniêcie poprzedniego obrazu,jeœli istnieje
				this->access->Image = this->accessGrantedImg != nullptr
					? this->accessGrantedImg : LoadImageFromObrazy("accessgranted.png");
				this->access->Visible = true;
				this->access->Refresh();
				System::Threading::Thread::Sleep(4000);
				Application::DoEvents();
			}
			if (this->processTimer != nullptr && this->processTimer->Enabled == true) {
				if (this->processTimer->Enabled == false) {
					this->processTimer->Enabled = true;
					this->processTimer->Start();
				}
			}
			CzyszczeniePól();
			connection->Close();
		};
		public:
			String^ konfiguracja = L"Driver={MySQL ODBC 9.4 Unicode Driver};Server=localhost;Database=rejestracja_bankowa;port=3306;user=root;Password=09041976Polska04@;CharSet=utf8mb4;Option=3;AllowMultiQueries=1";

		private: System::Void regRedirect_Click(System::Object^ sender, System::EventArgs^ e);
		};
	}
}

