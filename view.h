#pragma once

#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>

#include "encryption.h"

namespace lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для view
	/// </summary>
	public ref class view : public System::Windows::Forms::Form
	{
	public:
		view(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~view()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выбрать исходный файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &view::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(12, 93);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 46);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Выбрать файл результата";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &view::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(462, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 145);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(463, 22);
			this->textBox2->TabIndex = 3;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 308);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(65, 21);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Гефе";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(12, 335);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(57, 21);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"RC4";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(83, 308);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(181, 48);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Зашифровать (расшифровать)";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &view::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 170);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(262, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Начальное значение регистра LFSR1:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 190);
			this->textBox3->MaxLength = 26;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(463, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &view::textBox3_KeyPress);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 379);
			this->textBox4->MaxLength = 65535;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(463, 22);
			this->textBox4->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 359);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Ключ:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 215);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(262, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Начальное значение регистра LFSR2:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 235);
			this->textBox5->MaxLength = 34;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(463, 22);
			this->textBox5->TabIndex = 12;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &view::textBox5_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 260);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(262, 17);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Начальное значение регистра LFSR3:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 280);
			this->textBox6->MaxLength = 24;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(463, 22);
			this->textBox6->TabIndex = 14;
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &view::textBox6_KeyPress);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(395, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 46);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Bin";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &view::button4_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(395, 93);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 46);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Bin";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &view::button5_Click);
			// 
			// view
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(487, 411);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"view";
			this->Text = L"Потоковое шифрование";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		char c = e->KeyChar;
		if (textBox3->Text->Length != 0 &&
			(c > '1' && c <= '~') ||
			c < '0'
		) {
			e->Handled = true;
		}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox1->Text = openFileDialog1->FileName;
		button2->Enabled = true;
		button4->Enabled = true;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	saveFileDialog1->Filter = "Зашифрованные файлы (*.encr)|*.encr|Все файлы (*.*)|*.*";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox2->Text = saveFileDialog1->FileName;
		textBox3->Enabled = true;
		button3->Enabled = true;
		button5->Enabled = true;
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox3->Text->Length != textBox3->MaxLength) {
		MessageBox::Show("Начальное значение регистра введено некорректно.");
		return;
	}

	if (checkBox1->Checked) {

		if (textBox5->Text->Length != textBox5->MaxLength) {
			MessageBox::Show("Начальное значение регистра введено некорректно.");
			return;
		}

		if (textBox6->Text->Length != textBox6->MaxLength) {
			MessageBox::Show("Начальное значение регистра введено некорректно.");
			return;
		}
	}

	std::string fname = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::FILE* inputfile = fopen(fname.c_str(), "rb");
	std::vector<unsigned char> msg;
	while (!feof(inputfile)) {
		msg.push_back(fgetc(inputfile));
	}
	msg.pop_back();
	fclose(inputfile);

	std::vector<bool>lfsr_init(26, 1);
	std::string lfsr_init_str = msclr::interop::marshal_as<std::string>(textBox3->Text);
	for (int i = 0; i < lfsr_init.size(); ++i) {
		if (lfsr_init_str[i] == '0')
			lfsr_init[i] = 0;
	}

	std::vector<bool>lfsr2_init(34, 1);
	std::vector<bool>lfsr3_init(24, 1);

	if (checkBox1->Checked) {
		
		lfsr_init_str = msclr::interop::marshal_as<std::string>(textBox5->Text);
		for (int i = 0; i < lfsr2_init.size(); ++i) {
			if (lfsr_init_str[i] == '0')
				lfsr2_init[i] = 0;
		}

		lfsr_init_str = msclr::interop::marshal_as<std::string>(textBox6->Text);
		for (int i = 0; i < lfsr3_init.size(); ++i) {
			if (lfsr_init_str[i] == '0')
				lfsr3_init[i] = 0;
		}
	}
	std::vector<unsigned char> cph = encode(msg, lfsr_init, lfsr2_init, lfsr3_init, checkBox1->Checked, checkBox2->Checked);

	fname = msclr::interop::marshal_as<std::string>(textBox2->Text);
	FILE* encrfile = fopen(fname.c_str(), "wb");
	for (int i = 0; i < cph.size(); ++i) {
		fputc(cph[i], encrfile);
	}
	fclose(encrfile);

	extern std::string KEY;
	textBox4->Text = msclr::interop::marshal_as<System::String^>(KEY);
}
private: System::Void textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	char c = e->KeyChar;
	if (textBox5->Text->Length != 0 &&
		(c > '1' && c <= '~') ||
		c < '0'
		) {
		e->Handled = true;
	}
}
private: System::Void textBox6_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	char c = e->KeyChar;
	if (textBox6->Text->Length != 0 &&
		(c > '1' && c <= '~') ||
		c < '0'
		) {
		e->Handled = true;
	}
}


private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	
	std::string fname = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::FILE* inputfile = fopen(fname.c_str(), "rb");
	std::vector<unsigned char> msg;
	while (!feof(inputfile)) {
		msg.push_back(fgetc(inputfile));
	}
	msg.pop_back();

	std::string nstr = "";
	for (int i = 0; i < msg.size(); ++i) {
		
		int tmp = msg[i];
		std::vector<int> v(8, 0);
		int j = 7;
		while (tmp != 0) {
			v[j] = tmp % 2;
			j--;
			tmp /= 2;
		}
		for (int j = 0; j < 8; ++j)
			nstr += v[j] + '0';
	}

	MessageBox::Show(msclr::interop::marshal_as<System::String^>(nstr));
	fclose(inputfile);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string fname = msclr::interop::marshal_as<std::string>(textBox2->Text);
	std::FILE* inputfile = fopen(fname.c_str(), "rb");
	std::vector<unsigned char> msg;
	while (!feof(inputfile)) {
		msg.push_back(fgetc(inputfile));
	}
	msg.pop_back();

	std::string nstr = "";
	for (int i = 0; i < msg.size(); ++i) {

		int tmp = msg[i];
		std::vector<int> v(8, 0);
		int j = 7;
		while (tmp != 0) {
			v[j] = tmp % 2;
			j--;
			tmp /= 2;
		}
		for (int j = 0; j < 8; ++j)
			nstr += v[j] + '0';
	}

	MessageBox::Show(msclr::interop::marshal_as<System::String^>(nstr));
	fclose(inputfile);
}
};
}
