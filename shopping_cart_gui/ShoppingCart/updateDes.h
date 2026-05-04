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
	/// Summary for updateDes
	/// </summary>
	public ref class updateDes : public System::Windows::Forms::Form
	{
	public:
		updateDes(void)
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
		~updateDes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnUpdate;
	protected:
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Label^ lbUserInfo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbItem;
	private: System::Windows::Forms::TextBox^ tbDes;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

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
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lbUserInfo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbItem = (gcnew System::Windows::Forms::TextBox());
			this->tbDes = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(41, 220);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 0;
			this->btnUpdate->Text = L"UPDATE";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &updateDes::btnUpdate_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(164, 220);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"CANCEL";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &updateDes::btnCancel_Click);
			// 
			// lbUserInfo
			// 
			this->lbUserInfo->AutoSize = true;
			this->lbUserInfo->Location = System::Drawing::Point(124, 55);
			this->lbUserInfo->Name = L"lbUserInfo";
			this->lbUserInfo->Size = System::Drawing::Size(29, 13);
			this->lbUserInfo->TabIndex = 2;
			this->lbUserInfo->Text = L"User";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Select which item to update description";
			// 
			// tbItem
			// 
			this->tbItem->Location = System::Drawing::Point(112, 100);
			this->tbItem->Name = L"tbItem";
			this->tbItem->Size = System::Drawing::Size(100, 20);
			this->tbItem->TabIndex = 4;
			// 
			// tbDes
			// 
			this->tbDes->Location = System::Drawing::Point(112, 144);
			this->tbDes->Name = L"tbDes";
			this->tbDes->Size = System::Drawing::Size(160, 20);
			this->tbDes->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Item Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Item Description";
			// 
			// updateDes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbDes);
			this->Controls->Add(this->tbItem);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbUserInfo);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnUpdate);
			this->Name = L"updateDes";
			this->Text = L"updateDes";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
	}

private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ item = this->tbItem->Text;
	String^ des = this->tbDes->Text;

	if (item->Length == 0 || des->Length == 0) {
		MessageBox::Show("One or more fields are empty.",
			"Please fill out all fields", MessageBoxButtons::OK);
		return;
	}

	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "UPDATE [dbo].[itemInfo] SET [des] = @des WHERE [item] = @item;";
		SqlCommand command(sqlQuery, % sqlConn);

		command.Parameters->AddWithValue("@item", item);
		command.Parameters->AddWithValue("@des", des);

		command.ExecuteNonQuery();

		MessageBox::Show("Item Description Updated!",
			"Success!", MessageBoxButtons::OK);
		this->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show("Failed to Update Item Description",
			"Database Connection Error", MessageBoxButtons::OK);
	}
}
};
}
