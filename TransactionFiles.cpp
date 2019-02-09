#include "TransactionFiles.h"

void TransactionFiles::addTransactionToFile (Transaction transaction, string filename) {
    CMarkup xml;
    xml.Load(filename);
    xml.AddElem( "TRANSACTION" );
    xml.IntoElem();
    {
        xml.AddElem( "ID", transaction.getId() );
        xml.AddElem( "USERID", transaction.getUserId() );
        xml.AddElem( "DATE", transaction.getDate() );
        xml.AddElem( "ITEM", transaction.getItem() );
        xml.AddElem( "VALUE", transaction.getStringValue() );
    }
    xml.OutOfElem();
    xml.Save(filename);
}
vector<Transaction> TransactionFiles::loadTransactionsFromFile(string filename, int loggedUserId) {
    vector<Transaction> transactions;
    CMarkup xml;
    xml.Load(filename);
    while (xml.FindElem("TRANSACTION")) {
        Transaction transaction;
        xml.IntoElem();
        xml.FindElem("USERID");
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (userId == loggedUserId) {
            transaction.setUserId(userId);
            xml.FindElem("ID");
            transaction.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("DATE");
            transaction.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("ITEM");
            transaction.setItem(xml.GetData());
            xml.FindElem("VALUE");
            transaction.setValue(Interface::stringToDouble(xml.GetData()));
            transactions.push_back(transaction);
        }
        xml.OutOfElem();
    }
    return transactions;
}

//
