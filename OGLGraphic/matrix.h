#ifndef MATRIX_H
#define MATRIX_H

class QPointF;

class Matrix {
public:
    Matrix(double v11 = 1.0, double v12 = 0.0, double v13 = 0.0,
           double v21 = 0.0, double v22 = 1.0, double v23 = 0.0,
           double v31 = 0.0, double v32 = 0.0, double v33 = 1.0);

    QPointF map(const QPointF&) const;

    void setMatrix(double v11, double v12,
                   double v21, double v22,
                   double v31, double v32);

    void setMatrix(double v11, double v12, double v13,
                   double v21, double v22, double v23,
                   double v31, double v32, double v33);

    double& M11() { return m11; }
    double& M12() { return m12; }
    double& M13() { return m13; }
    double& M21() { return m21; }
    double& M22() { return m22; }
    double& M23() { return m23; }
    double& M31() { return m31; }
    double& M32() { return m32; }
    double& M33() { return m33; }

    const double& M11() const { return m11; }
    const double& M12() const { return m12; }
    const double& M13() const { return m13; }
    const double& M21() const { return m21; }
    const double& M22() const { return m22; }
    const double& M23() const { return m23; }
    const double& M31() const { return m31; }
    const double& M32() const { return m32; }
    const double& M33() const { return m33; }

    void reset();

    Matrix  operator *  (const Matrix&) const;

    Matrix& operator *= (const Matrix&);

    ~Matrix() {}
private:
    double m11, m12, m13, m21, m22, m23, m31, m32, m33;
};

#endif // MATRIX_H
