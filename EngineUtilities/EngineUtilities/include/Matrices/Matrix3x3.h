#pragma once

#include "../Prerequisites.h"
#include <Vectors/Vector2.h>
#include <Vectors/Vector3.h>
#include <Math/EngineMath.h>

/**
 * @file Matrix3x3.h
 * @brief Represents a 3x3 matrix with algebraic operations for 2D/3D transformations.
 */

namespace EU {

  /**
   * @class Matrix3x3
   * @brief Provides a 3x3 matrix structure and common operations for graphics and physics.
   */
  class
  Matrix3x3 {
  public:

    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;

    /**
     * @brief Default constructor. Initializes as identity matrix.
     */
    Matrix3x3();

    /**
     * @brief Parameterized constructor.
     * @param m00 Top-left element.
     * @param m01 Top-middle element.
     * @param m02 Top-right element.
     * @param m10 Middle-left element.
     * @param m11 Center element.
     * @param m12 Middle-right element.
     * @param m20 Bottom-left element.
     * @param m21 Bottom-middle element.
     * @param m22 Bottom-right element.
     */
    Matrix3x3(
    float m00, float m01, float m02,
      float m10, float m11, float m12,
      float m20, float m21, float m22);

    /**
     * @brief Adds two matrices.
     * @param other Matrix to add.
     * @return Resulting matrix.
     */
    Matrix3x3
    operator+(const Matrix3x3& other) const;

    /**
     * @brief Subtracts two matrices.
     * @param other Matrix to subtract.
     * @return Resulting matrix.
     */
    Matrix3x3
    operator-(const Matrix3x3& other) const;

    /**
     * @brief Multiplies the matrix by a scalar.
     * @param scalar Scalar value.
     * @return Scaled matrix.
     */
    Matrix3x3
    operator*(float scalar) const;

    /**
     * @brief Multiplies two matrices.
     * @param other Right-hand side matrix.
     * @return Product matrix.
     */
    Matrix3x3
    operator*(const Matrix3x3& other) const;

    /**
     * @brief Multiplies the matrix by a 2D vector (homogeneous).
     * @param vec 2D vector.
     * @return Transformed 2D vector.
     */
    CVector2
    operator*(const CVector2& vec) const;

    /**
     * @brief Multiplies the matrix by a 3D vector.
     * @param vec 3D vector.
     * @return Transformed 3D vector.
     */
    CVector3
    operator*(const CVector3& vec) const;

    /**
     * @brief Adds another matrix to this matrix.
     * @param other Matrix to add.
     * @return Reference to this matrix.
     */
    Matrix3x3&
    operator+=(const Matrix3x3& other);

    /**
     * @brief Subtracts another matrix from this matrix.
     * @param other Matrix to subtract.
     * @return Reference to this matrix.
     */
    Matrix3x3&
    operator-=(const Matrix3x3& other);

    /**
     * @brief Multiplies this matrix by a scalar.
     * @param scalar Scalar value.
     * @return Reference to this matrix.
     */
    Matrix3x3&
    operator*=(float scalar);

    /**
     * @brief Accesses a matrix element.
     * @param row Row index (0 to 2).
     * @param col Column index (0 to 2).
     * @return Reference to the element.
     */
    float&
    operator()(int row, int col);

    /**
     * @brief Accesses a matrix element (const version).
     * @param row Row index (0 to 2).
     * @param col Column index (0 to 2).
     * @return Const reference to the element.
     */
    const
    float& operator()(int row, int col) const;

    /**
     * @brief Calculates the determinant of the matrix.
     * @return Determinant value.
     */
    float
    determinant() const;

    /**
     * @brief Returns the transpose of the matrix.
     * @return Transposed matrix.
     */
    Matrix3x3
    transpose() const;

    /**
     * @brief Returns the inverse of the matrix.
     * @return Inverted matrix. Returns identity if determinant is 0.
     */
    Matrix3x3
    inverse() const;

    /**
     * @brief Sets this matrix as the identity matrix.
     */
    void
    setIdentity();

    /**
     * @brief Sets this matrix as a 2D scale matrix.
     * @param scaleX Scale along X.
     * @param scaleY Scale along Y.
     */
    void
    setScale(float scaleX, float scaleY);

    /**
     * @brief Sets this matrix as a 2D translation matrix.
     * @param tx Translation along X.
     * @param ty Translation along Y.
     */
    void
    setTranslation(float tx, float ty);

    /**
     * @brief Sets this matrix as a 2D rotation matrix.
     * @param radians Rotation angle in radians.
     */
    void
    setRotation(float radians);

    /**
     * @brief Returns a matrix filled with zeros.
     * @return Zero matrix.
     */
    static
    Matrix3x3 zero();

    /**
     * @brief Returns an identity matrix.
     * @return Identity matrix.
     */
    static
    Matrix3x3 identity();
  };

} // namespace EU
