#include "addItems.h"
#include "removeItem.h"
#include "searchItem.h"
#include "showMenu.h"
#include "total.h"
#include "updateDes.h"
#include "updateQuantity.h"
#include "Welcome.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ShoppingCart::Welcome form;
	form.ShowDialog();
	while (form.contin)
	{
		ShoppingCart::showMenu form2;
		form2.ShowDialog();
		if (form2.add)
		{
			ShoppingCart::addItems form3;
			form3.ShowDialog();
			continue;
		}
		if (form2.remove)
		{
			ShoppingCart::removeItem form4;
			form4.ShowDialog();
			continue;
		}
		if (form2.descript)
		{
			ShoppingCart::updateDes form5;
			form5.ShowDialog();
			continue;
		}
		if (form2.quan)
		{
			ShoppingCart::updateQuantity form6;
			form6.ShowDialog();
			continue;
		}
		if (form2.search)
		{
			ShoppingCart::total form7;
			form7.ShowDialog();
			continue;
		}
		if (form2.total)
		{
			ShoppingCart::searchItem form8;
			form8.ShowDialog();
			continue;
		}
		if (form2.quit)
		{
			break;
		}
	}

}