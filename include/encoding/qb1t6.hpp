#pragma once
/**
 *  https://github.com/iotaledger/tips/blob/main/tips/TIP-0005/tip-0005.md
 *
 **/

#include<QByteArray>
#include<QDebug>
namespace qencoding{
namespace qb1t6{

	QByteArray intToTrits(const qint8& value);
	QByteArray get_Trits_from_Bytes(const QByteArray& bytes);
	QByteArray get_Trytes_from_Bytes(const QByteArray& bytes);
	QByteArray get_Trytes_from_Trits(const QByteArray& trits);


}
}
