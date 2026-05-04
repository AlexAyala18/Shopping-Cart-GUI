#pragma once
#include "User.h"
#include "Welcome.h"
#include "showMenu.h"

namespace ShoppingCart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for updateQuantity
	/// </summary>
	public ref class updateQuantity : public System::Windows::Forms::Form
	{
	public:
		updateQuantity(void)
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
		~updateQuantity()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;






	private: System::Windows::Forms::Button^ btnBack;

	private: System::Windows::Forms::Button^ btnUpdate;

	private: System::Windows::Forms::Label^ lbUserInfo;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbItem;
	private: System::Windows::Forms::TextBox^ tbQua;




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
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->lbUserInfo = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbItem = (gcnew System::Windows::Forms::TextBox());
			this->tbQua = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(26, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(246, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Choose which item to update quantity";
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(164, 226);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"GO BACK";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &updateQuantity::btnBack_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(42, 226);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 5;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &updateQuantity::btnUpdate_Click);
			// 
			// lbUserInfo
			// 
			this->lbUserInfo->AutoSize = true;
			this->lbUserInfo->Location = System::Drawing::Point(122, 47);
			this->lbUserInfo->Name = L"lbUserInfo";
			this->lbUserInfo->Size = System::Drawing::Size(29, 13);
			this->lbUserInfo->TabIndex = 7;
			this->lbUserInfo->Text = L"User";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Item Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"New Quantity";
			// 
			// tbItem
			// 
			this->tbItem->Location = System::Drawing::Point(139, 97);
			this->tbItem->Name = L"tbItem";
			this->tbItem->Size = System::Drawing::Size(100, 20);
			this->tbItem->TabIndex = 10;
			// 
			// tbQua
			// 
			this->tbQua->Location = System::Drawing::Point(139, 147);
			this->tbQua->Name = L"tbQua";
			this->tbQua->Size = System::Drawing::Size(100, 20);
			this->tbQua->TabIndex = 11;
			// 
			// updateQuantity
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->tbQua);
			this->Controls->Add(this->tbItem);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbUserInfo);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label1);
			this->Name = L"updateQuantity";
			this->Text = L"updateQuantity";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ item = this->tbItem->Text;
	String^ qua = this->tbQua->Text;

	if (item->Length == 0 || qua->Length == 0) {
		MessageBox::Show("One or more fields are empty.",
			"Please fill out all fields", MessageBoxButtons::OK);
		return;
	}
	int^ quantity = Convert::ToInt32(qua);
	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "UPDATE [dbo].[itemInfo] SET [qua] = @quantity WHERE [item] = @item;";
		SqlCommand command(sqlQuery, % sqlConn);

		command.Parameters->AddWithValue("@item", item);
		command.Parameters->AddWithValue("@quantity", quantity);
		command.ExecuteNonQuery();

		MessageBox::Show("Item Quantity Updated!",
			"Success!", MessageBoxButtons::OK);
		this->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show("Failed to Update Quantitiy",
			"Database Connection Error", MessageBoxButtons::OK);
	}
}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
