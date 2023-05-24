#include"encoding/qb1t6.hpp"
namespace qencoding{
	/*! 
	 * \brief Binary To Ternary Encoding following this
	 * [TIP](https://github.com/iotaledger/tips/blob/main/tips/TIP-0005/tip-0005.md)
	 *
	 */
	namespace qb1t6{
		/*!
		 *
		 * \fn QByteArray intToTrits(const qint8& value)  
		 * Converts a signed integer value into its corresponding balanced ternary representation in little-endian order 
		 *
		 */

		QByteArray intToTrits(const qint8& value) {


			QByteArray    trits(6,0);
			int      sign          = (value > 0) - (value < 0);
			quint8 absoluteValue = value * sign;

			int i=0;
			while (absoluteValue > 0) {
				int8_t remainder = absoluteValue % 3;
				absoluteValue    = absoluteValue / 3;

				if (remainder > 1) {
					remainder = -1;
					absoluteValue++;
				}

				trits[i]=(remainder * sign);
				i++;
			}

			return trits;
		}
		/*!
		 *
		 * \fn QByteArray get_Trits_from_Bytes(const QByteArray& bytes)  
		 * Converts a QByteArray value into its corresponding balanced ternary representation  
		 *
		 */

		QByteArray get_Trits_from_Bytes(const QByteArray& bytes)
		{

			QByteArray trits;
			std::for_each(bytes.begin(),bytes.end(),[&](const qint8& v){
					auto trits6=intToTrits(v);
					trits.push_back(trits6);
					});
			return trits;

		}
		/*!
		 *
		 * \fn QByteArray get_Trytes_from_Trits(const QByteArray& trits)  
		 * Converts a QByteArray of trits to the corresponding tryte alphabet string 
		 *
		 */
		QByteArray get_Trytes_from_Trits(const QByteArray& trits)
		{
			auto trytes=QByteArray();

			const auto Tryte_Alphabet=QByteArray("9ABCDEFGHIJKLMNOPQRSTUVWXYZ");

			for (std::size_t i = 0; i < trits.size(); i += 3) {
				qint8 idx = trits[i] + trits[i + 1] * 3 + trits[i + 2] * 9;

				if (idx < 0) {
					idx += 27;
				}
				trytes.push_back(Tryte_Alphabet[idx]);
			}
			return trytes;
		}
		/*!
		 *
		 * \fn QByteArray get_Trytes_from_Bytes(const QByteArray& bytes)  
		 * Converts a QByteArray  to the corresponding tryte alphabet string 
		 *
		 */
		QByteArray get_Trytes_from_Bytes(const QByteArray& bytes)
		{

			auto trits=get_Trits_from_Bytes(bytes);

			return get_Trytes_from_Trits(trits);

		}

	}
}
