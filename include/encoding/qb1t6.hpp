#pragma once
#include<QByteArray>


namespace qencoding{
	namespace qb1t6{

		
		QByteArray intToTrits(const qint8& value);
		QByteArray get_Trits_from_Bytes(const QByteArray& bytes);
		QByteArray get_Trytes_from_Bytes(const QByteArray& bytes);
		QByteArray get_Trytes_from_Trits(const QByteArray& trits);


	}
}
