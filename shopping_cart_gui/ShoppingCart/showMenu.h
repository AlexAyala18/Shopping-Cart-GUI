#pragma once
#include "User.h"
#include "Welcome.h"

namespace ShoppingCart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for showMenu
	/// </summary>
	public ref class showMenu : public System::Windows::Forms::Form
	{
	public:
		showMenu(void)
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
		~showMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnRem;
	private: System::Windows::Forms::Button^ btnDesc;
	private: System::Windows::Forms::Button^ btnQuan;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Button^ btnCheckout;
	private: System::Windows::Forms::Button^ btnExit;







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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRem = (gcnew System::Windows::Forms::Button());
			this->btnDesc = (gcnew System::Windows::Forms::Button());
			this->btnQuan = (gcnew System::Windows::Forms::Button());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnCheckout = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(104, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MENU";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(65, 101);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"Add Item";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &showMenu::btnAdd_Click);
			// 
			// btnRem
			// 
			this->btnRem->Location = System::Drawing::Point(158, 101);
			this->btnRem->Name = L"btnRem";
			this->btnRem->Size = System::Drawing::Size(75, 23);
			this->btnRem->TabIndex = 3;
			this->btnRem->Text = L"Remove Item";
			this->btnRem->UseVisualStyleBackColor = true;
			this->btnRem->Click += gcnew System::EventHandler(this, &showMenu::btnRem_Click);
			// 
			// btnDesc
			// 
			this->btnDesc->Location = System::Drawing::Point(65, 130);
			this->btnDesc->Name = L"btnDesc";
			this->btnDesc->Size = System::Drawing::Size(75, 23);
			this->btnDesc->TabIndex = 4;
			this->btnDesc->Text = L"Descriptions";
			this->btnDesc->UseVisualStyleBackColor = true;
			this->btnDesc->Click += gcnew System::EventHandler(this, &showMenu::btnDesc_Click);
			// 
			// btnQuan
			// 
			this->btnQuan->Location = System::Drawing::Point(158, 130);
			this->btnQuan->Name = L"btnQuan";
			this->btnQuan->Size = System::Drawing::Size(75, 23);
			this->btnQuan->TabIndex = 5;
			this->btnQuan->Text = L"Quantity";
			this->btnQuan->UseVisualStyleBackColor = true;
			this->btnQuan->Click += gcnew System::EventHandler(this, &showMenu::btnQuan_Click);
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(65, 159);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 6;
			this->btnSearch->Text = L"Checkout";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &showMenu::btnSearch_Click);
			// 
			// btnCheckout
			// 
			this->btnCheckout->Location = System::Drawing::Point(158, 159);
			this->btnCheckout->Name = L"btnCheckout";
			this->btnCheckout->Size = System::Drawing::Size(75, 23);
			this->btnCheckout->TabIndex = 7;
			this->btnCheckout->Text = L"Search";
			this->btnCheckout->UseVisualStyleBackColor = true;
			this->btnCheckout->Click += gcnew System::EventHandler(this, &showMenu::btnCheckout_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(109, 207);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 8;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &showMenu::btnExit_Click);
			// 
			// showMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnCheckout);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->btnQuan);
			this->Controls->Add(this->btnDesc);
			this->Controls->Add(this->btnRem);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label1);
			this->Name = L"showMenu";
			this->Text = L"showMenu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: bool add = false;
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		add = true;
		this->Close();
	}

public: bool remove = false;
private: System::Void btnRem_Click(System::Object^ sender, System::EventArgs^ e) {
	remove = true;
	this->Close();
}

public: bool descript = false;
private: System::Void btnDesc_Click(System::Object^ sender, System::EventArgs^ e) {
	descript = true;
	this->Close();
}

public: bool quan = false;
private: System::Void btnQuan_Click(System::Object^ sender, System::EventArgs^ e) {
	quan = true;
	this->Close();
}

public: bool search = false;
private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	search = true;
	this->Close();
}

public: bool quit = false;
private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	quit = true;
	this->Close();
}

public: bool total = false;
private: System::Void btnCheckout_Click(System::Object^ sender, System::EventArgs^ e) {
	total = true;
	this->Close();
}
};
}
