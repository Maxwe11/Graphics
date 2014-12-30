#ifndef BEZIER_H
#define BEZIER_H

#include <QtCore/QPointF>

template<int N>
class Bezier
{
    static_assert(N > 0, "N should be positive number");
public:
    Bezier();
    QPointF& operator [] (int index);
    const QPointF& operator [] (int index) const;
    QPointF getPoint(qreal u) const;
private:
    int m_order;
    QPointF m_point[N + 1];
};

#include <stdexcept>
#include <QtCore/qmath.h>

template<int N>
inline Bezier<N>::Bezier()
    : m_order(N)
{
}

template<int N>
inline QPointF& Bezier<N>::operator [] (int index)
{
    if (index < 0 || index > N)
        throw std::out_of_range("Bezier::operator []: index is out of range");

    return m_point[index];
}

template<int N>
inline const QPointF& Bezier<N>::operator [] (int index) const
{
    if (index < 0 || index > N)
        throw std::out_of_range("Bezier::operator []: index is out of range");

    return m_point[index];
}

template<int N>
inline QPointF Bezier<N>::getPoint(qreal u) const
{
    QPointF point;

    for (int i = N, j = 0; j <= N; --i, ++j)
    {
        point += m_point[j] * qPow(1.0 - u, qreal(i)) * qPow(u, qreal(j));
    }

    return point;
}

#endif // BEZIER_H
