#include <stdio.h>
#include <stdlib.h>

#include "article.h"

/* #####################################################################
 * 							ARTICLES
 * #####################################################################
 */

/**** Constructeurs, Destructeur *****/
/*************************************/
Article::Article()
{
	
}


/************ Accesseurs *************/
/*************************************/
int Article::GetReferenceInt()
{
	int ref = GetCategoryInt() * 10000000;
	ref += GetTypeInt() * 100000;
	ref += GetModelInt() * 10000;
	ref += GetSizeInt() * 100;
	ref += GetColorInt();
	return ref;
}

Ref Article::GetReferenceRef()
{
	Ref ref = {
		GetCategoryInt(),
		GetTypeInt(),
		GetModelInt(),
		GetSizeInt(),
		GetColorInt()
	};
	return ref;
}

QString Article::GetReferenceString()
{
	QString refca = GetCategoryString();
	QString reft = GetTypeString();
	QString refm = GetModelString();
	QString refs = GetSizeString();
	QString refco = GetColorString();
	
	return refca.append(reft).append(refm).append(refs).append(refco);
}

int Article::GetCategoryInt()
{
    return cat;
}

QString Article::GetCategoryString()
{
    return QString::number(GetCategoryInt());
}

int Article::GetTypeInt()
{
    return type;
}

QString Article::GetTypeString()
{
    QString reft = QString::number(GetTypeInt());
	return reft.rightJustified(2, '0');
}

int Article::GetModelInt()
{
    return model;
}

QString Article::GetModelString()
{
    return QString::number(GetModelInt());
}

int Article::GetStock()
{
    return qty;
}

QString Article::GetStockString()
{
    return QString::number(GetStock());
}

float Article::GetBuyPrice()
{
	return bprice;
}

float Article::GetSellPrice()
{
	return sprice;
}

int Article::GetDiscountPercent()
{
    return discount;
}

float Article::GetDiscountPrice()
{
	return GetSellPrice() * (GetDiscountPercent() / 100);
}

QDate Article::GetDeliveryDate()
{
	return delivery;
}

int Article::GetDaysInStock()
{
	return GetDeliveryDate().daysTo(QDate::currentDate());
}

int Article::GetColorInt()
{
    return color;
}

QString Article::GetColorString()
{
    QString refco = QString::number(GetColorInt());
	return refco.rightJustified(2, '0');
}

RGB Article::GetColorRGB()
{
	return color_rgb[GetColorInt()];
}

QString Article::GetColorHexa()
{
	return color_hexa[GetColorInt()];
}

int Article::GetSizeInt()
{
    return size;
}

QString Article::GetSizeString()
{
    QString refs = QString::number(GetSizeInt());
	return refs.rightJustified(2, '0');
}

QString Article::GetCategoryName()
{
	return category[GetCategoryInt()];
}

QString Article::GetTypeName()
{
	return vetements[GetCategoryInt()][GetTypeInt()];
}

QString Article::GetSizeName()
{
	return size_name[size_num[GetSizeInt()]];
}

QString Article::GetColorName()
{
	return color_name[GetColorInt()];
}


/********** Modificateurs ************/
/*************************************/
void Article::ApplyDiscount(bool apply)
{
	static float old_sprice;
	static char old_discount;
	
	if (apply == true)
	{
		old_sprice = GetSellPrice();
		old_discount = GetDiscountPercent();
		
		sprice = GetDiscountPrice();
		discount = 0;
	}
	else
	{
		sprice = old_sprice;
		discount = old_discount;
	}
}


/************* Testeurs **************/
/*************************************/
bool Article::HasReference(int r)
{
	if (r == ALL)
		return true;
	else
		return (GetReferenceInt() == r);
}

bool Article::HasReference(Ref r)
{
	return (
		HasCategory(r.c) &&
		HasType(r.t)     &&
		HasModel(r.m)    &&
		HasSize(r.s)     &&
		HasColor(r.o)
	);
}

//~ bool Article::HasReference(QString r)
//~ {
	//~ return (GetReferenceString().compare(r) == 0);
//~ }

bool Article::HasCategory(int c)
{
	if (c == NR)
		return true;
	else
		return (GetCategoryInt() == c);
}

//~ bool Article::HasCategory(QString c)
//~ {
	//~ return (GetCategoryString().compare(c) == 0);
//~ }

bool Article::HasType(int t)
{
	if (t == NR)
		return true;
	else
		return (GetTypeInt() == t);
}

//~ bool Article::HasType(QString t)
//~ {
	//~ return (GetTypeString().compare(t) == 0);
//~ }

bool Article::HasModel(int m)
{
	if (m == NR)
		return true;
	else
		return (GetModelInt() == m);
}

//~ bool Article::HasModel(QString m)
//~ {
	//~ return (GetModelString().compare(m) == 0);
//~ }

bool Article::HasSize(int s)
{
	if (s == NR)
		return true;
	else
		return (GetSizeInt() == s);
}

//~ bool Article::HasSize(QString s)
//~ {
	//~ return (GetSizeString().compare(s) == 0);
//~ }

bool Article::HasColor(int c)
{
	if (c == NR)
		return true;
	else
		return (GetColorInt() == c);
}

//~ bool Article::HasColor(QString c)
//~ {
	//~ return (GetColorString().compare(c) == 0);
//~ }

bool Article::HasQuantity(int q)
{
	if (q == ALL)
		return true;
	else
		return (GetStock() == q);
}

bool Article::HasMore(int q)
{
	return (GetStock() >= q);
}

bool Article::HasLess(int q)
{
	return (GetStock() < q);
}

bool Article::Costs(float p)
{
	if (p == NR)
		return true;
	else
		return (GetSellPrice() == p);
}

bool Article::CostsMore(float p)
{
	return (GetSellPrice() > p);
}

bool Article::CostsLess(float p)
{
	return (GetSellPrice() <= p);
}

bool Article::Bought(float p)
{
	if (p == NR)
		return true;
	else
		return (GetBuyPrice() == p);
}

bool Article::BoughtMore(float p)
{
	return (GetBuyPrice() > p);
}

bool Article::BoughtLess(float p)
{
	return (GetBuyPrice() <= p);
}

bool Article::HasDiscount(int d)
{
	if (d == NR)
		return true;
	else
		return (GetDiscountPercent() == d);
}

bool Article::HasDiscountMore(int d)
{
	return (GetDiscountPercent() >= d);
}

bool Article::HasDiscountLess(int d)
{
	return (GetDiscountPercent() < d);
}

bool Article::Delivered(QDate d)
{
	if (d.isNull())
		return true;
	else
		return (GetDeliveryDate().operator==(d));
}

bool Article::DeliveredEarly(QDate d)
{
	return (GetDeliveryDate().operator<=(d));
}

bool Article::DeliveredLately(QDate d)
{
	return (GetDeliveryDate().operator>=(d));
}

bool Article::InStockFor(int days)
{
	return (GetDaysInStock() >= days);
}

bool Article::EquivalentTo(Article a)
{
	return (
		HasReference(a.GetReferenceRef())   &&
		HasQuantity(a.GetStock())           &&
		Bought(a.GetBuyPrice())             &&
		Costs(a.GetSellPrice())             &&
		HasDiscount(a.GetDiscountPercent()) &&
		Delivered(a.GetDeliveryDate())
	);
}

bool Article::SameAs(Article sa)
{
	return (
		HasSameCategory(sa) &&
		HasSameType(sa)     &&
		HasSameModel(sa)    &&
		HasSameSize(sa)     &&
		HasSameColor(sa)
	);
}

bool Article::HasSameCategory(Article sa)
{
	return (GetCategoryInt() == sa.GetCategoryInt());
}

bool Article::HasSameType(Article sa)
{
	return (GetTypeInt() == sa.GetTypeInt());
}

bool Article::HasSameModel(Article sa)
{
	return (GetModelInt() == sa.GetModelInt());
}

bool Article::HasSameSize(Article sa)
{
	return (GetSizeInt() == sa.GetSizeInt());
}

bool Article::HasSameColor(Article sa)
{
	return (GetColorInt() == sa.GetColorInt());
}

float Article::CompareBuyPrice(Article sa)
{
	return (GetBuyPrice() - sa.GetBuyPrice());
}

float Article::CompareSellPrice(Article sa)
{
	return (GetSellPrice() - sa.GetSellPrice());
}

int Article::CompareDiscount(Article sa)
{
	return (GetDiscountPercent() - sa.GetDiscountPercent());
}

float Article::CompareDiscountPrice(Article sa)
{
	return (GetDiscountPrice() - sa.GetDiscountPrice());
}

int Article::CompareStock(Article sa)
{
	return (GetStock() - sa.GetStock());
}

int Article::CompareDelivery(Article sa)
{
	return (GetDaysInStock() - sa.GetDaysInStock());
}

bool Article::IsValid()
{
	return (
		HasValidReference() &&
		HasValidQuantity()  &&
		HasValidBuyPrice()  &&
		HasValidSellPrice() &&
		HasValidDelivery()
	);
}

bool Article::HasValidReference()
{
	return (
		HasValidCategory() &&
		HasValidType()     &&
		HasValidModel()    &&
		HasValidSize()     &&
		HasValidColor()
	);
}

bool Article::HasValidCategory()
{
	return (GetCategoryInt() != NR);
}

bool Article::HasValidType()
{
	return (GetTypeInt() != NR);
}

bool Article::HasValidModel()
{
	return (GetModelInt() != NR);
}

bool Article::HasValidSize()
{
	return (GetSizeInt() != NR);
}

bool Article::HasValidColor()
{
	return (GetColorInt() != NR);
}

bool Article::HasValidQuantity()
{
	return (GetStock() != NR);
}

bool Article::HasValidBuyPrice()
{
	return (GetBuyPrice() != NR);
}

bool Article::HasValidSellPrice()
{
	return (GetSellPrice() != NR);
}

bool Article::HasValidDiscount()
{
	return (GetDiscountPercent() != NR);
}

bool Article::HasValidDelivery()
{
	return ( !GetDeliveryDate().isNull() );
}


/* #####################################################################
 * 						ARTICLES DU STOCK
 * #####################################################################
 */

/**** Constructeurs, Destructeur *****/
/*************************************/
StockArticle::StockArticle(int reference, int quantity, float buyprice, float sellprice, int discount_p, QDate delivery)
: Article()
{
	SetArticle(reference, quantity, buyprice, sellprice, discount_p, delivery);
}

StockArticle::StockArticle(Ref reference, int quantity, float buyprice, float sellprice, int discount_p, QDate delivery)
: Article()
{
	SetArticle(reference, quantity, buyprice, sellprice, discount_p, delivery);
}

//~ StockArticle::StockArticle(QString reference, int quantity, int buyprice, int sellprice, int discount_p, QDate delivery)
//~ : Article()
//~ {
	//~ SetArticle(reference, quantity, buyprice, sellprice, discount_p, delivery);
//~ }


/********** Modificateurs ************/
/*************************************/
void StockArticle::SetArticle(int reference, int quantity, float buyprice, float sellprice, int discount_p, QDate delivery)
{
	SetReference(reference);
	SetQtyAndPrices(quantity, buyprice, sellprice, discount_p);
	SetDeliveryDate(delivery);
}

void StockArticle::SetArticle(Ref reference, int quantity, float buyprice, float sellprice, int discount_p, QDate delivery)
{
	SetReference(reference);
	SetQtyAndPrices(quantity, buyprice, sellprice, discount_p);
	SetDeliveryDate(delivery);
}

//~ void StockArticle::SetArticle(QString reference, int quantity, float buyprice, float sellprice, int discount_p, QDate delivery)
//~ {
	//~ SetReference(reference);
	//~ SetQtyAndPrices(quantity, buyprice, sellprice, discount_p);
	//~ SetDeliveryDate(delivery);
//~ }

void StockArticle::SetQtyAndPrices(int q, float bp, float sp, int d)
{
	SetQuantity(q);
	SetBuyPrice(bp);
	SetSellPrice(sp);
	SetDiscountPercent(d);
}

void StockArticle::SetReference(int r)
{
    int c, t, m, s;

	SetCategory(r / 10000000);
    c = GetCategoryInt() * 10000000;
    SetType((r-c) / 100000);
    t = GetTypeInt() * 100000;
    SetModel((r-c-t) / 10000);
    m = GetModelInt() * 10000;
    SetSize((r-c-t-m) / 100);
    s = GetSizeInt() * 100;
    SetColor(r-c-t-m-s);
}

void StockArticle::SetReference(Ref r)
{
	SetCategory(r.c);
	SetType(r.t);
	SetModel(r.m);
	SetSize(r.s);
	SetColor(r.o);
}

//~ void StockArticle::SetReference(QString r)
//~ {
	//~ SetCategory(r.left(1).toInt());
	//~ SetType(r.left(3).right(2).toInt());
	//~ SetModel(r.left(4).right(1).toInt());
	//~ SetSize(r.right(4).left(2).toInt());
	//~ SetColor(r.right(2).toInt());
//~ }

void StockArticle::SetCategory(int c)
{
    cat = c;
}

void StockArticle::SetType(int t)
{
    type = t;
}

void StockArticle::SetModel(int m)
{
    model = m;
}

void StockArticle::SetSize(int s)
{
    size = s;
}

void StockArticle::SetColor(int c)
{
    color = c;
}

void StockArticle::SetQuantity(int q)
{
    qty = q;
}

void StockArticle::IncrementQty()
{
	SetQuantity(GetStock()+1);
}

void StockArticle::DecrementQty()
{
	int q = GetStock()-1;
	if (q < 0)
		SetQuantity(0);
	else
		SetQuantity(q);
}

void StockArticle::AddQty(int q)
{
	SetQuantity(GetStock()+q);
}

void StockArticle::SubQty(int q)
{
	int tq = GetStock()-q;
	if (tq < 0)
		SetQuantity(0);
	else
		SetQuantity(tq);
}

void StockArticle::SetBuyPrice(float p)
{
	bprice = p;
}

void StockArticle::SetSellPrice(float p)
{
	sprice = p;
}

void StockArticle::SetDiscountPercent(int p)
{
    discount = p;
}

void StockArticle::SetDeliveryDate(QDate d)
{
	delivery = d;
}

void StockArticle::Replace(StockArticle sa)
{
	SetReference(sa.GetReferenceRef());
	SetQtyAndPrices(sa.GetStock(), sa.GetBuyPrice(), sa.GetSellPrice(), sa.GetDiscountPercent());
	SetDeliveryDate(sa.GetDeliveryDate());
}


/* #####################################################################
 * 						ARTICLES VENDUS
 * #####################################################################
 */

/**** Constructeurs, Destructeur *****/
/*************************************/
SoldArticle::SoldArticle(StockArticle sa, int quantity, QDate sell_date)
    : Article()
{
    cat = sa.GetCategoryInt();
    type = sa.GetTypeInt();
    model = sa.GetModelInt();
    size = sa.GetSizeInt();
    color = sa.GetColorInt();
	
	qty = quantity;
	
	bprice = sa.GetBuyPrice();
	sprice = sa.GetSellPrice();
    discount = sa.GetDiscountPercent();
	delivery = sa.GetDeliveryDate();
	
	selldate = sell_date;
}


/************ Accesseurs *************/
/*************************************/
QDate SoldArticle::GetSellDate()
{
	return selldate;
}

int SoldArticle::GetDaysSinceSold()
{
	return GetSellDate().daysTo(QDate::currentDate());
}

int SoldArticle::GetDaysToSell()
{
	return GetDeliveryDate().daysTo(GetSellDate());
}


/************* Testeurs **************/
/*************************************/
bool SoldArticle::Sold(QDate d)
{
	if (d.isNull())
		return true;
	else
		return (GetSellDate().operator==(d));
}

bool SoldArticle::SoldEarly(QDate d)
{
	return (GetSellDate().operator<=(d));
}

bool SoldArticle::SoldLately(QDate d)
{
	return (GetSellDate().operator>=(d));
}

bool SoldArticle::SoldSince(int days)
{
	return (GetDaysSinceSold() >= days);
}

bool SoldArticle::SoldIn(int days)
{
	return (GetDaysToSell() <= days);
}

int SoldArticle::CompareSellDay(SoldArticle sa)
{
	return (GetDaysSinceSold() - sa.GetDaysSinceSold());
}

int SoldArticle::CompareSellTime(SoldArticle sa)
{
	return (GetDaysToSell() - sa.GetDaysToSell());
}

bool SoldArticle::EquivalentTo(SoldArticle a)
{
	return (
        Article::EquivalentTo((Article)a) &&
		Sold(a.GetSellDate())
	);
}