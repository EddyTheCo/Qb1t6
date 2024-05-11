#pragma once
#include <QByteArray>

namespace qencoding
{
/*!
 * \brief Binary To Ternary Encoding following this
 * [TIP](https://github.com/iotaledger/tips/blob/main/tips/TIP-0005/tip-0005.md)
 *
 */
namespace qb1t6
{

/*!
 *
 * Converts a signed integer value into its corresponding balanced ternary representation in little-endian order
 *
 */
QByteArray intToTrits(const qint8 &value);
/*!
 *
 * Converts a QByteArray value into its corresponding balanced ternary representation
 *
 */
QByteArray get_Trits_from_Bytes(const QByteArray &bytes);
/*!
 *
 * \fn QByteArray get_Trytes_from_Bytes(const QByteArray& bytes)
 * Converts a QByteArray  to the corresponding tryte alphabet string
 *
 */
QByteArray get_Trytes_from_Bytes(const QByteArray &bytes);
/*!
 *
 * Converts a QByteArray of trits to the corresponding tryte alphabet string
 *
 */
QByteArray get_Trytes_from_Trits(const QByteArray &trits);

} // namespace qb1t6
} // namespace qencoding
