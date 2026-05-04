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
	/// Summary for searchItem
	/// </summary>
	public ref class searchItem : public System::Windows::Forms::Form
	{
	public:
		searchItem(void)
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
		~searchItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbUserInfo;

	private: System::Windows::Forms::Button^ btnCancel;

	private: System::Windows::Forms::TextBox^ tbItem;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





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
			this->lbUserInfo = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->tbItem = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(92, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search for an item";
			// 
			// lbUserInfo
			// 
			this->lbUserInfo->AutoSize = true;
			this->lbUserInfo->Location = System::Drawing::Point(137, 30);
			this->lbUserInfo->Name = L"lbUserInfo";
			this->lbUserInfo->Size = System::Drawing::Size(29, 13);
			this->lbUserInfo->TabIndex = 1;
			this->lbUserInfo->Text = L"User";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(107, 237);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"CANCEL";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &searchItem::btnCancel_Click);
			// 
			// tbItem
			// 
			this->tbItem->Location = System::Drawing::Point(23, 55);
			this->tbItem->Name = L"tbItem";
			this->tbItem->Size = System::Drawing::Size(159, 20);
			this->tbItem->TabIndex = 4;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(187, 55);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 5;
			this->btnSearch->Text = L"SEARCH";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &searchItem::btnSearch_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(23, 81);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 6;
			// 
			// searchItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbItem);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lbUserInfo);
			this->Controls->Add(this->label1);
			this->Name = L"searchItem";
			this->Text = L"searchItem";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ item = this->tbItem->Text;

	if (item->Length == 0) {
		MessageBox::Show("Item field is empty.",
			"Please fill out all fields", MessageBoxButtons::OK);
		return;
	}

	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		SqlDataAdapter^ dataAD = gcnew SqlDataAdapter("SELECT [item], [des], [pri], [qua] FROM [dbo].[itemInfo] WHERE [item] = @item;", % sqlConn);
		dataAD->SelectCommand->Parameters->AddWithValue("@item", item);
		DataTable^ dTable = gcnew DataTable();
		dataAD->Fill(dTable);
		dataGridView1->DataSource = dTable;

	}
	catch (Exception^ e) {
		MessageBox::Show("Failed to Search for Item",
			"Database Connection Error", MessageBoxButtons::OK);
	}
}
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
