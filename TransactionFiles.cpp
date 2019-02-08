#include "TransactionFiles.h"

void TransactionFiles::addIncomeToFile(Transaction income) {
    CMarkup xml;
    xml.Load(INCOMES_FILENAME);
    xml.AddElem( "INCOME" );
    xml.IntoElem();
    {
        xml.AddElem( "ID", income.getId() );
        xml.AddElem( "USERID", income.getUserId() );
        xml.AddElem( "DATE", income.getDate() );
        xml.AddElem( "ITEM", income.getItem() );
        xml.AddElem( "VALUE", income.getStringValue() );
    }
    xml.OutOfElem();
    xml.Save(INCOMES_FILENAME);
}
