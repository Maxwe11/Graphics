#ifndef CARTESIANLEAF_H
#define CARTESIANLEAF_H

#include <QObject>

#include "primitives.h"

class CartesianLeaf : public QObject {
    Q_OBJECT
public:
    explicit CartesianLeaf(QObject* parent = 0);
    ~CartesianLeaf() {}
    void drawLeaf(const QMatrix&);
    void drawAsymptote(const QMatrix&);
    void drawJasmine(const QMatrix&);
    double square() const;
private:
    double r(double cos_fi, double sin_fi) const;
    double dr(double cos_fi, double sin_fi) const;
signals:
    void Update();
    void SquareChanged(QString);
    void LengthChanged(QString);
public slots:
    void AChanged(double);
    void DrawTangLine(bool);
    void ChangeHotDot(int);
private:
    double coef; //a
    double step;
    int hot_dot;
    bool tang_line;
};

#endif // CARTESIANLEAF_H
