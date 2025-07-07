#pragma once

#include "../Prerequisites.h"
#include <Vectors/Vector2.h>
//#include <"Vector.h">

/**
 * @file Matrix2x2.h
 * @brief Representa una matriz 2x2 con operaciones algebraicas comunes para transformaciones 2D
 */
class
  Matrix2x2 {
public:

  float m00, m01;
  float m10, m11;

  // Constructores

  /**
   * @brief Constructor por defecto. Inicializa como matriz identidad
   */
  Matrix2x2()
    : m00(1.f), m01(0.f),
    m10(0.f), m11(1.f) {
  }

  /**
   * @brief Constructor con parámetros
   * @param m00 Valor superior izquierdo
   * @param m01 Valor superior derecho
   * @param m10 Valor inferior izquierdo
   * @param m11 Valor inferior derecho
   */
  Matrix2x2(float m00, float m01, float m10, float m11)
    : m00(m00), m01(m01),
    m10(m10), m11(m11) {
  }

  // Operaciones aritméticas

  Matrix2x2
  operator+(const Matrix2x2& other) const {
    return Matrix2x2(
      m00 + other.m00, m01 + other.m01,
      m10 + other.m10, m11 + other.m11
    );
  }

  Matrix2x2
  operator-(const Matrix2x2& other) const {
    return Matrix2x2(
      m00 - other.m00, m01 - other.m01,
      m10 - other.m10, m11 - other.m11
    );
  }

  Matrix2x2
  operator*(float scalar) const {
    return Matrix2x2(
      m00 * scalar, m01 * scalar,
      m10 * scalar, m11 * scalar
    );
  }

  Matrix2x2
  operator*(const Matrix2x2& other) const {
    return Matrix2x2(
      m00 * other.m00 + m01 * other.m10, m00 * other.m01 + m01 * other.m11,
      m10 * other.m00 + m11 * other.m10, m10 * other.m01 + m11 * other.m11
    );
  }

  /**
   * @brief Multiplica la matriz por un vector 2D
   * @param vec El vector a transformar
   * @return Vector transformado
   */
  CVector2
    operator*(const CVector2& vec) const {
    return CVector2(
      m00 * vec.x + m01 * vec.y,
      m10 * vec.x + m11 * vec.y
    );
  }

  // Operadores de asignación compuesta

  Matrix2x2& operator+=(const Matrix2x2& other) {
    m00 += other.m00; m01 += other.m01;
    m10 += other.m10; m11 += other.m11;
    return *this;
  }

  Matrix2x2& operator-=(const Matrix2x2& other) {
    m00 -= other.m00; m01 -= other.m01;
    m10 -= other.m10; m11 -= other.m11;
    return *this;
  }

  Matrix2x2& operator*=(float scalar) {
    m00 *= scalar; m01 *= scalar;
    m10 *= scalar; m11 *= scalar;
    return *this;
  }

  // Acceso por índices

  /**
   * @brief Accede a un elemento específico (fila, columna)
   * @param row Fila (0 o 1)
   * @param col Columna (0 o 1)
   * @return Referencia al valor
   */
  float& operator()(int row, int col) {
    return *((&m00) + row * 2 + col);
  }

  const
    float& operator()(int row, int col) const {
    return *((&m00) + row * 2 + col);
  }

  // Funciones de utilidad

  /**
   * @brief Calcula el determinante de la matriz
   * @return Determinante escalar
   */
  float
  determinant() const {
    return m00 * m11 - m01 * m10;
  }

  /**
   * @brief Retorna la matriz transpuesta
   * @return Matriz transpuesta
   */
  Matrix2x2
  transpose() const {
    return Matrix2x2(
      m00, m10,
      m01, m11
    );
  }

  /**
   * @brief Retorna la inversa de esta matriz
   * @return Matriz invertida o identidad si no es invertible
   */
  Matrix2x2
  inverse() const {
    float det = determinant();
    if (det == 0.f) return Matrix2x2(); // No invertible, retorna identidad

    float invDet = 1.f / det;
    return Matrix2x2(
      m11 * invDet, -m01 * invDet,
      -m10 * invDet, m00 * invDet
    );
  }

  /**
   * @brief Establece esta matriz como identidad
   */
  void
  setIdentity() {
    m00 = 1.f; m01 = 0.f;
    m10 = 0.f; m11 = 1.f;
  }

  /**
   * @brief Establece esta matriz como una de escala
   * @param scaleX Escala en X
   * @param scaleY Escala en Y
   */
  void
  setScale(float scaleX, float scaleY) {
    m00 = scaleX; m01 = 0.f;
    m10 = 0.f;    m11 = scaleY;
  }

  /**
   * @brief Establece esta matriz como una de rotación
   * @param radians Ángulo en radianes
   */
  void
  setRotation(float radians) {
    float c = cos(radians);
    float s = sin(radians);
    m00 = c;  m01 = -s;
    m10 = s;  m11 = c;
  }

  /**
   * @brief Retorna una matriz llena de ceros
   */
  static
  Matrix2x2 zero() {
    return Matrix2x2(0.f, 0.f, 0.f, 0.f);
  }

  /**
   * @brief Retorna una matriz identidad
   */
  static
  Matrix2x2 identity() {
    return Matrix2x2();
  }

private:

  /**
   * @brief Aproximación de la función seno usando serie de Taylor
   * @param x Ángulo en radianes
   */
  float sin(float x) const {
    while (x > 3.14159265f) x -= 2.f * 3.14159265f;
    while (x < -3.14159265f) x += 2.f * 3.14159265f;

    float x2 = x * x;
    return x
      - (x2 * x) / 6.f
      + (x2 * x2 * x) / 120.f
      - (x2 * x2 * x2 * x) / 5040.f;
  }

  /**
   * @brief Aproximación de la función coseno usando serie de Taylor
   * @param x Ángulo en radianes
   */
  float cos(float x) const {
    while (x > 3.14159265f) x -= 2.f * 3.14159265f;
    while (x < -3.14159265f) x += 2.f * 3.14159265f;

    float x2 = x * x;
    return 1.f
      - x2 / 2.f
      + (x2 * x2) / 24.f
      - (x2 * x2 * x2) / 720.f;
  }
};
