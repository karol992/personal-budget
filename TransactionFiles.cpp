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
vector<Transaction> TransactionFiles::loadIncomesFromFile() {
    vector<Transaction> incomes;
    CMarkup xml;
    xml.Load(INCOMES_FILENAME);
    while (xml.FindElem("INCOME")) {
        Transaction income;
        xml.IntoElem();
        xml.FindElem("ID");
        income.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("USERID");
        income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("DATE");
        income.setDate(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("ITEM");
        income.setItem(xml.GetData());
        xml.FindElem("VALUE");
        income.setValue(Interface::stringToDouble(xml.GetData()));
        xml.OutOfElem();
        incomes.push_back(income);
    }
    return incomes;
}
