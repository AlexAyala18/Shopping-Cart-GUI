#pragma once
#include "User.h"

namespace ShoppingCart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Welcome
	/// </summary>
	public ref class Welcome : public System::Windows::Forms::Form
	{
	public:
		Welcome(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Welcome()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	protected:

	private: System::Windows::Forms::Button^ btnCancel;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbDate;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbDate = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(64, 226);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &Welcome::btnLogin_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(155, 226);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Welcome::btnCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"WELCOME";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(35, 167);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Date";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(35, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Name";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(110, 110);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(147, 20);
			this->tbName->TabIndex = 5;
			// 
			// tbDate
			// 
			this->tbDate->Location = System::Drawing::Point(110, 167);
			this->tbDate->Name = L"tbDate";
			this->tbDate->Size = System::Drawing::Size(137, 20);
			this->tbDate->TabIndex = 6;
			// 
			// Welcome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(291, 261);
			this->Controls->Add(this->tbDate);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Name = L"Welcome";
			this->Text = L"Welcome";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: bool cancel = cancel;
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	cancel = true;
	MessageBox::Show("Please come again!",
		"Login Cancelled!", MessageBoxButtons::OK);
	this->Close();
}

public: User^ user = nullptr;
public: bool contin = false;
private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
	contin = true;
	String^ name = this->tbName->Text;
	String^ date = this->tbDate->Text;

	if (name->Length == 0 || date->Length == 0) {
		MessageBox::Show("One or more fields are empty.",
			"Please enter both your name and today's date", MessageBoxButtons::OK);
		return;
	}
	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "SELECT * FROM users WHERE name=@name AND date=@date;";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@name", name);
		command.Parameters->AddWithValue("@date", date);

		SqlDataReader^ reader = command.ExecuteReader();
		if (reader->Read()) {
			user = gcnew User;
			user->id = reader->GetInt32(0);
			user->name = reader->GetString(1);
			user->date = reader->GetString(2);

			this->Close();
		}
		else {
			MessageBox::Show("Name or Date field left empty",
				"Please complete all fields to access the store", MessageBoxButtons::OK);
		}
	}
	catch (Exception^ e) {
		MessageBox::Show("Failed to connect to database",
			"Database Connection Error", MessageBoxButtons::OK);
	}

}

};
}
