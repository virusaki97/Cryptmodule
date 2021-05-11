#pragma once
#include "crypt.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Decrypt
	/// </summary>
	public ref class Decrypt : public System::Windows::Forms::Form
	{
	public: Crypting ^CryptFile = gcnew Crypting;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label1;


	public:
	protected: System::Windows::Forms::Form ^ newform;
	public:
		Decrypt(System::Windows::Forms::Form ^ frm)
		{
			newform = frm;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Decrypt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Decrypt::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(153, 79);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Decrypt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Decrypt::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Add File";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Decrypt::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 41);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Add Key";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Decrypt::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(93, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(179, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(93, 44);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(179, 20);
			this->textBox2->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(35, 79);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(96, 36);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Back";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Decrypt::button4_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 166);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(260, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Progress:";
			// 
			// Decrypt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 201);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Decrypt";
			this->Text = L"Decrypt";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Decrypt::Decrypt_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog4 = gcnew OpenFileDialog;
		openFileDialog4->ShowDialog();
		textBox1->Text = openFileDialog4->FileName;
		CryptFile->SetInfile(openFileDialog4->FileName);
		CryptFile->FileLenght();
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ openFileDialog5 = gcnew OpenFileDialog;
	openFileDialog5->ShowDialog();
	textBox2->Text = openFileDialog5->FileName;
	CryptFile->SetKey(openFileDialog5->FileName);
}
private: System::Void Decrypt_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	Application::Exit();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (CryptFile->GetInfile() == L"" || CryptFile->GetKey() == L"")
	{
		MessageBox::Show("The files were not loaded!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		if (CryptFile->GetInfile() != L"" && CryptFile->GetKey() != L"")
		{
			CryptFile->Decrypt(progressBar1);
			MessageBox::Show("Decrypt successful!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			progressBar1->Value = 0;
			textBox2->Text = L"";
			CryptFile->SetKey(L"");
		}
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	newform->Show();
}
};
}
//
