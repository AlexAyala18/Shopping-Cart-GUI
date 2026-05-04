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
	/// Summary for removeItem
	/// </summary>
	public ref class removeItem : public System::Windows::Forms::Form
	{
	public:
		removeItem(void)
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
		~removeItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbUserInfo;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnRem;



	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::Label^ label2;




	private: System::ComponentModel::IContainer^ components;

	protected:

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
			this->lbUserInfo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnRem = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbUserInfo
			// 
			this->lbUserInfo->AutoSize = true;
			this->lbUserInfo->Location = System::Drawing::Point(123, 53);
			this->lbUserInfo->Name = L"lbUserInfo";
			this->lbUserInfo->Size = System::Drawing::Size(29, 13);
			this->lbUserInfo->TabIndex = 0;
			this->lbUserInfo->Text = L"User";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(255, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select which items to remove from your cart";
			// 
			// btnRem
			// 
			this->btnRem->Location = System::Drawing::Point(39, 216);
			this->btnRem->Name = L"btnRem";
			this->btnRem->Size = System::Drawing::Size(75, 23);
			this->btnRem->TabIndex = 3;
			this->btnRem->Text = L"Remove Item";
			this->btnRem->UseVisualStyleBackColor = true;
			this->btnRem->Click += gcnew System::EventHandler(this, &removeItem::btnRem_Click);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(164, 216);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"Go Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &removeItem::btnBack_Click);
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(131, 125);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(136, 20);
			this->tbName->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Item Name";
			// 
			// removeItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnRem);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbUserInfo);
			this->Name = L"removeItem";
			this->Text = L"removeItem";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
	private: System::Void btnRem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ item = this->tbName->Text;

		if (item->Length == 0) {
			MessageBox::Show("Please enter all fields.",
				"Field is empty", MessageBoxButtons::OK);
			return;
		}
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "DELETE FROM [dbo].[itemInfo] WHERE [item] = @item;";
			SqlCommand command(sqlQuery, % sqlConn);

			command.Parameters->AddWithValue("@item", item);
			command.ExecuteNonQuery();
			MessageBox::Show("Items Successfully Removed!",
				"Success!", MessageBoxButtons::OK);
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to remove item",
				"Database Connection Error", MessageBoxButtons::OK);
		}
	}
};
}
