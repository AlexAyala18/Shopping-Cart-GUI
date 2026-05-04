#pragma once
#include "Welcome.h"
#include "User.h"
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
	/// Summary for addItems
	/// </summary>
	public ref class addItems : public System::Windows::Forms::Form
	{
	public:
		addItems(void)
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
		~addItems()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::TextBox^ tbItem;

	private: System::Windows::Forms::TextBox^ tbDes;
	private: System::Windows::Forms::TextBox^ tbPri;
	private: System::Windows::Forms::TextBox^ tbQua;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->tbItem = (gcnew System::Windows::Forms::TextBox());
			this->tbDes = (gcnew System::Windows::Forms::TextBox());
			this->tbPri = (gcnew System::Windows::Forms::TextBox());
			this->tbQua = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(73, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Select items to add to cart";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(77, 221);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 3;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &addItems::btnAdd_Click);
			// 
			// btnBack
			// 
			this->btnBack->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnBack->Location = System::Drawing::Point(219, 221);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"Go Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &addItems::btnBack_Click);
			// 
			// tbItem
			// 
			this->tbItem->Location = System::Drawing::Point(194, 106);
			this->tbItem->Name = L"tbItem";
			this->tbItem->Size = System::Drawing::Size(100, 20);
			this->tbItem->TabIndex = 5;
			// 
			// tbDes
			// 
			this->tbDes->Location = System::Drawing::Point(193, 132);
			this->tbDes->Name = L"tbDes";
			this->tbDes->Size = System::Drawing::Size(100, 20);
			this->tbDes->TabIndex = 6;
			// 
			// tbPri
			// 
			this->tbPri->Location = System::Drawing::Point(194, 158);
			this->tbPri->Name = L"tbPri";
			this->tbPri->Size = System::Drawing::Size(100, 20);
			this->tbPri->TabIndex = 7;
			// 
			// tbQua
			// 
			this->tbQua->Location = System::Drawing::Point(194, 184);
			this->tbQua->Name = L"tbQua";
			this->tbQua->Size = System::Drawing::Size(100, 20);
			this->tbQua->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(90, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Item name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(90, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Item description";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(90, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Item price";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(93, 190);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Item quantity";
			// 
			// addItems
			// 
			this->AcceptButton = this->btnAdd;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnBack;
			this->ClientSize = System::Drawing::Size(381, 261);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbQua);
			this->Controls->Add(this->tbPri);
			this->Controls->Add(this->tbDes);
			this->Controls->Add(this->tbItem);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label1);
			this->Name = L"addItems";
			this->Text = L"addItems";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ item = this->tbItem->Text;
		String^ des = this->tbDes->Text;
		String^ pri = this->tbPri->Text;
		String^ qua = this->tbQua->Text;

		if (item->Length == 0 || des->Length == 0 || pri->Length == 0 || qua->Length == 0) {
		MessageBox::Show("One or more fields are empty.",
			"Please fill out all fields", MessageBoxButtons::OK);
		return;
		}
		
		int^ price = Convert::ToInt32(pri);
		int^ quantity = Convert::ToInt32(qua);

		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "INSERT [dbo].[itemInfo] ([item], [des], [pri], [qua]) VALUES (@item, @des, @price, @quantity);";
			SqlCommand command(sqlQuery, % sqlConn);

			command.Parameters->AddWithValue("@item", item);
			command.Parameters->AddWithValue("@des", des);
			command.Parameters->AddWithValue("@price", price);
			command.Parameters->AddWithValue("@quantity", quantity);
			command.ExecuteNonQuery();

			MessageBox::Show("Items Successfully Added!",
				"Success!", MessageBoxButtons::OK);
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to Add Item",
				"Database Connection Error", MessageBoxButtons::OK);
		}
	}
};
}
