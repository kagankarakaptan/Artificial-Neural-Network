#pragma once

namespace ODEV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ dis;
	private: System::Windows::Forms::Button^ con;
	private: System::Windows::Forms::Button^ init;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	protected:

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->dis = (gcnew System::Windows::Forms::Button());
			this->con = (gcnew System::Windows::Forms::Button());
			this->init = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pictureBox1->Location = System::Drawing::Point(25, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(645, 139);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(89, 17);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Normalization";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// dis
			// 
			this->dis->BackColor = System::Drawing::Color::DarkGray;
			this->dis->Location = System::Drawing::Point(505, 256);
			this->dis->Name = L"dis";
			this->dis->Size = System::Drawing::Size(100, 50);
			this->dis->TabIndex = 5;
			this->dis->Text = L"Discrete";
			this->dis->UseVisualStyleBackColor = false;
			this->dis->Click += gcnew System::EventHandler(this, &MyForm::dis_Click);
			// 
			// con
			// 
			this->con->BackColor = System::Drawing::Color::DarkGray;
			this->con->Location = System::Drawing::Point(645, 256);
			this->con->Name = L"con";
			this->con->Size = System::Drawing::Size(100, 50);
			this->con->TabIndex = 6;
			this->con->Text = L"Continuous";
			this->con->UseVisualStyleBackColor = false;
			this->con->Click += gcnew System::EventHandler(this, &MyForm::con_Click);
			// 
			// init
			// 
			this->init->BackColor = System::Drawing::Color::DarkGray;
			this->init->Location = System::Drawing::Point(505, 121);
			this->init->Name = L"init";
			this->init->Size = System::Drawing::Size(100, 50);
			this->init->TabIndex = 7;
			this->init->Text = L"Initialize";
			this->init->UseVisualStyleBackColor = false;
			this->init->Click += gcnew System::EventHandler(this, &MyForm::init_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Class 1", L"Class 2", L"Class 3", L"Class 4",
					L"Class 5", L"Class 6"
			});
			this->comboBox1->Location = System::Drawing::Point(693, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(89, 21);
			this->comboBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(600, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Choose Class";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkGray;
			this->button1->Location = System::Drawing::Point(596, 373);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Restart";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(444, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Cycle Count :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(539, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(444, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Vector Count :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(539, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(444, 51);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Class Count :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(539, 51);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(834, 461);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->con);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->init);
			this->Controls->Add(this->dis);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		//fonksiyonlar

			//koordinat düzleminin çizdirilmesi
	private: System::Void pictureBox1_Paint(System::Object^, System::Windows::Forms::PaintEventArgs^);

		   //noktalarýn çizilip kaydedilmesi
	private: System::Void pictureBox1_Click(System::Object^, System::Windows::Forms::MouseEventArgs^);

		   //initialize
	private: System::Void init_Click(System::Object^, System::EventArgs^);

		   //Normalizasyon
	private: System::Double* normalization(double*);

		   //discrete
	private: System::Void dis_Click(System::Object^, System::EventArgs^);

		   //continuous
	private: System::Void con_Click(System::Object^, System::EventArgs^);

		   //çizdirme
	private: System::Void myDrawLine(Graphics^, Pen^, double*);

		   //classlarý sayma
	private: System::Int32 classCounter(double*);

		   //restart
	private: System::Void button1_Click(System::Object^, System::EventArgs^);




	};
}